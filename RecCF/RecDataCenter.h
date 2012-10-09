#ifndef __RECDATACENTER_H__
#define __RECDATACENTER_H__

#include "RecInterface.h"

namespace RecSys
{
	class RecDataCenter
	{
	public:
		RecDataCenter();
		bool Init(const char * base_dir, RecConfig * config);
	
	public:
		bool loadRecDataEntities(const char * filename);
	public:
		vector<Entity> rec_data_entities_;
	private:
		RecConfig * config_;	
	
	};
}
#endif //__RECDATACENTER_H__

