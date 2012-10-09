#ifndef __CF__H_
#define __CF__H_

#include "CfKernel.h"

namespace RecSys
{
	typedef struct
	{
		uint32_t item_id;
		float score;
	}IndexNode;

	class CF
	{
	public:
		CF();

		bool loadIndex(const char * filename);

	 	bool writeIndexToBibaryFile(const char * filename);

		bool loadIndexFromBinaryFile(const char * filename);

		bool loadReverseIndex();

		bool getNeighbors(const vector<Entity>& user, float threshold, uint32_t top_n);

		bool recommender();

		void print();
	private:
		CfKernel cf_kernel_;
	public:
		unordered_map<uint32_t,vector<Entity> > user_index_;
	};
}

#endif //__CF__H_
