#include "Modularity.h"
#include <math.h>

namespace CommunityDetection
{
    double Modularity::getQualityScore(const Graph * graph, map<uint32_t, Community*>& communities, double gamma)
    {
     	const uint32_t communityNum = communities.size();

	double Q = 0.0;
	uint32_t edge_num = graph->edge_set_.size();
	for(uint32_t idx=0;idx<communityNum;idx++)
	{
                Community * community = communities[idx];
		uint32_t in_degree = community->in_degree_;
		uint32_t total_degree = community->total_degree_;

		Q += (double)in_degree/(double)edge_num + pow((double)total_degree/2*edge_num, 2);
	}

	return Q;
    }
}
