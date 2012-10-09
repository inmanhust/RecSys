#include "Cf.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

namespace RecSys
{
	CF::CF()
	{
		
	}

	/**
	 * load index
	 * @param [in] char* filename
	 * @return 
	 *		true | false
	 **/
	bool CF::loadIndex(const char * filename)
	{
		ifstream fin(filename);
		if(!fin)
		{
			fprintf(stderr, "[Error][]load file %s faile", filename);	
			return false;
		}

		string line;
		vector<string> tokens;
		vector<Entity> entities;
		while( getline(fin,line) )
		{
			split_string(line, '\t', &tokens);

			string& user_id_str = tokens[0];
			string& item_id_str = tokens[1];
			string score_str = tokens[2];


			uint32_t user_id = atoi(user_id_str.c_str());
			Entity entity;
			entity.user_id = user_id;
			entity.item_id = atoi(item_id_str.c_str());
			entity.score = atof(score_str.c_str());

			user_index_[user_id].push_back(entity);
		}

		return true;
	}

	bool CF::writeIndexToBibaryFile(const char * filename)
	{
		FILE * fp = fopen(filename, "wb");

		unordered_map<uint32_t, vector<Entity> >::const_iterator iter;
		for(iter=user_index_.begin();iter!=user_index_.end();iter++)
		{
			uint32_t user_id = iter->first;
			const vector<Entity>& entities = iter->second;

			if(entities.size() == 0)
				continue;
			float sum = 0.0;
			for(uint32_t i=0;i<entities.size();i++)
			{
				sum += entities[i].score;
			}

			uint32_t num = entities.size();
			float avg = sum / (float)num;

			fwrite(&user_id, sizeof(uint32_t), 1, fp);
			fwrite(&avg, sizeof(float), 1, fp);
			fwrite(&num, sizeof(uint32_t), 1, fp);
			fwrite(&((iter->second)[0]), sizeof(Entity), num, fp);
		}

		fclose(fp);
		return true;
	}

	bool CF::loadIndexFromBinaryFile(const char * filename)
	{
		FILE * fp = fopen(filename, "rb");
		if(fp == NULL)
		{
			fprintf(stderr, "can not open file %s\n", filename);
			return false;
		}
		
		fseeko(fp, 0, SEEK_END);
		uint32_t total_len = ftello(fp);
		rewind(fp);
		char * buffer = new char[total_len];
		if(fread(buffer, sizeof(char), total_len, fp) != total_len)
		{
			fprintf(stderr,"File length error");	
			return false;
		}
		fclose(fp);

		const char * buffer_end = buffer + total_len;
		char * p = buffer;
		while(p<buffer_end)
		{
			uint32_t user_id = (*(uint32_t *)p);
			p += sizeof(uint32_t);

			float avg = (*(float *)p);
			p += sizeof(float);

			uint32_t num = (*(uint32_t *)p);
			p += sizeof(uint32_t);

			vector<Entity> * entities = new vector<Entity>();
			entities->resize(num);
			memcpy((&(*entities)[0]), p, num*sizeof(Entity));
			p += num*sizeof(Entity);
			cf_kernel_.addNewEntity(user_id, *entities);
			cf_kernel_.user_avg_score_map[user_id] = avg;
		}

		delete [] buffer;

		fprintf(stderr, "load index success");
	}

	bool CF::loadReverseIndex()
	{
		unordered_map<uint32_t, vector<Entity> >::const_iterator iter;
		for(iter=user_index_.begin();iter!=user_index_.end();iter++)
		{
			cf_kernel_.addNewEntity(iter->first, iter->second);
		}
	}



	bool CF::getNeighbors(const vector<Entity>& user, float threshold, uint32_t top_n)
	{
		vector<UserResult> tmp_result;
		cf_kernel_.calcUserSim(user, threshold, top_n, tmp_result);
		for(uint32_t i=0;i<tmp_result.size();i++)
		{
			printf("sim rank: %u, sim: %f\n",tmp_result[i].user_id,tmp_result[i].sim)	;
		}

		return true;
	}

	bool CF::recommender()
	{
		vector<UserResult> tmp_result;
		unordered_map<uint32_t, vector<Entity> >::const_iterator iter;
		for(iter=user_index_.begin();iter!=user_index_.end();iter++)
		{
			const vector<Entity>& entities = iter->second;
			uint32_t user_id = iter->first;

			tmp_result.clear();
			cf_kernel_.calcUserSim(entities, 1000, 20, tmp_result);
		}
		
	}

	void CF::print()
	{
		unordered_map<uint32_t, vector<Entity> >::const_iterator iter;
		for(iter=user_index_.begin();iter!=user_index_.end();iter++)
		{
			printf("user id:\t%u\n",iter->first);	
			const vector<Entity>& entities = iter->second;
			for(uint32_t i=0;i<entities.size();i++)
			{
				printf("(%u,%f)\t",entities[i].item_id, entities[i].score);	
			}
			printf("\n");

		}
		
		/*
		const ReverseIndex& index = cf_kernel_.index_;
		ReverseIndex::const_iterator iter;
		for(iter=index.begin();iter!=index.end();iter++)
		{
			printf("customer id%u\n",iter->first);	
			const vector<ReverseIndexNode>& nodes = iter->second;
			for(uint32_t i=0;i<nodes.size();i++)
			{
				printf("(%u,%f)\t",nodes[i].user_id, nodes[i].score);	
			}
			printf("\n");
		}
		*/
	}


}
