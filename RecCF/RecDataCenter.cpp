#include "RecDataCenter.h"

namespace 
{
	RecDataCenter::RecDataCenter()	
	{
	
	}

	bool RecDataCenter::Init(const char * base_dir, RecConfig * config)
	{
		string full_file_name;
		config_ = config;

	}

	bool RecDataCenter::loadRecDataObjs(const char * filename)
	{
		ifstream fin(filename)	
		if(!fin)
		{
			fprintf(stderr, "[Error][load file %s error]", filename);
			return false;
		}

		string line;
		vector<string> tokens;
		Obj object;
		while( getline(fin, line) )
		{
			split_string(line, '\t', tokens);
			if(tokens.size() < 3)
			{
				fprintf(stderr, "[Error][File line %s Error]", line.c_str());	
				continue;
			}
			
			string& user_id_str = tokens[0];
			string& item_id_str = tokens[1];
			string score_str = tokens[2];

			obj.user_id = atoi(user_id_str.c_str());
			obj.item_id = atoi(item_id_str.c_str());
			obj.score = atof(score_str.c_str());

			rec_data_objs_.push_back(obj);
		}

		return true;
	}
}
