#ifndef __CFKERNEL__H_
#define __CFKERNEL__H_

#include "RecInterface.h"
#include <tr1/unordered_map>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::tr1::unordered_map;


namespace RecSys
{

	class UserResult
	{
	public:
		uint32_t user_id;
		float sim;
		
		static bool SimGreater(const UserResult& user1, const UserResult& user2)
		{
			 return user1.sim >= user2.sim;
		}
	};

	typedef struct
	{
		uint32_t user_id;
		float score;
	}ReverseIndexNode;

	typedef unordered_map<uint32_t, vector<ReverseIndexNode> > ReverseIndex;

	class CfKernel	
	{
	public:
		CfKernel();
		bool addNewEntity(uint32_t user_id, vector<Entity> entities);

		bool calcUserSim(const vector<Entity>& user, float threshold, uint32_t top_n, vector<UserResult>& result) const;

		bool getItemAvg();
	public:
		uint32_t user_num_;
		ReverseIndex index_;
		unordered_map<uint32_t, float> user_avg_score_map;
		unordered_map<uint32_t, float> item_avg_score_map;
	};
}


#endif // __CFKERNEL__H_
