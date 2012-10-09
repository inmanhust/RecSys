#include "CfKernel.h"
#include <string.h>
#include <algorithm>
#include <math.h>

namespace RecSys
{
	CfKernel::CfKernel()	
	{
		
	}

	bool CfKernel::addNewEntity(uint32_t user_id, vector<Entity> entities)
	{
		ReverseIndexNode idx_node;	
		idx_node.user_id = user_id;

		for(uint32_t k=0;k<entities.size();k++)
		{
			idx_node.score = entities[k].score;
			index_[entities[k].item_id].push_back(idx_node);
		}

		user_num_ ++;
		return true;
	}

	bool CfKernel::calcUserSim(const vector<Entity>& user, float threshold, uint32_t top_n, vector<UserResult>& result) const
	{
		printf("index user num: %u", user_num_);

		float * tmp_result = new float[user_num_];
		memset(tmp_result, 0, user_num_);

		ReverseIndex::const_iterator iter;
		for(uint32_t k=0; k<user.size(); k++)
		{
			const Entity& entity = user[k];
			iter = index_.find(entity.item_id);
			if(iter == index_.end())
			{
				continue;	
			}

			const vector<ReverseIndexNode>& nodes = iter->second;
			for(uint32_t i=0;i<nodes.size();i++)
			{
				const ReverseIndexNode& node = nodes[i];
				tmp_result[node.user_id] += node.score*entity.score;
			}
		}

			for(uint32_t i=0;i<user_num_;i++)
			{
				if (tmp_result[i] > threshold)
				{
					UserResult user_res;
					user_res.user_id = i;
					user_res.sim = tmp_result[i];
					result.push_back(user_res);
				}
			}

			delete [] tmp_result;

			if(top_n>0 && top_n < result.size())
			{
				std::partial_sort(result.begin(),result.begin()+top_n,result.end(),UserResult::SimGreater);
				result.erase(result.begin()+top_n,result.end());
			}
			else
			{
				std::sort(result.begin(), result.end(), UserResult::SimGreater);
			}

			return true;
	}

	bool CfKernel::getItemAvg()
	{
		const ReverseIndex& index = index_;
		ReverseIndex::const_iterator iter;
		for(iter=index.begin();iter!=index.end();iter++)
		{
			uint32_t item_id = iter->first;
			const vector<ReverseIndexNode>& nodes = iter->second;

			if(nodes.size() == 0)
				continue;

			float sum = 0.0;
			for(uint32_t i=0;i<nodes.size();i++)
			{
					sum += nodes[i].score;
			}

			float avg = sum / (float)nodes.size();
			item_avg_score_map[item_id] = avg;
		}

		return true;
	}
}
