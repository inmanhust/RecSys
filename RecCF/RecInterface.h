#ifndef _RECINTERFACE_H_
#define _RECINTERFACE_H_

#include "CommonTools.h"

namespace RecSys
{
	typedef struct
	{
		const char * username;
		int age;
	}UserInfo;

	typedef struct
	{
		const char * item_name;
		int price;
	}ItemInfo;

	typedef struct
	{
		uint32_t user_id;
		const UserInfo * user;
	}User;

	typedef struct
	{
		uint32_t item_id;
		const ItemInfo * item_info;
	}Item;

	typedef struct
	{
		uint32_t user_id;
		uint32_t item_id;
		float score;
	}Entity;
}
#endif //_RECINTERFACE_H_
