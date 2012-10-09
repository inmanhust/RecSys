#ifndef __RECCONFIG_h__
#define __RECCONFIG_h__
namespace RecSys
{
	class RecConfig
	{
	public:
		RecConfig();
		~RecConfig();

	public:
		float sim_threshold; /* =  0.5 */
		uint32_t top_n; /* = 30 */
	}
	
}

#endif //__RECCONFIG_h__
