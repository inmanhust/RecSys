#include "Modularity"
#include <math.h>

namespace CommunityDetection
{
    double Modularity::getQualityScore(const Graph * graph, const map<uint32_t, Community*>& communities, double gamma) const
    {
     	const uint32_t communityNum = communities.size();

	double Q = 0.0;
	uint32_t edge_num = graph->edge_set_.size();
	for(uint32_t idx=0;idx<communityNum;idx++)
	{
		uint32_t in_degree = communities->in_degree_;
		uint32_t total_degree = communities->total_degree_;

		Q += (double)in_degree/(double)edge_num + pow((double)total_degree/2*edge_num, 2);
	}

	return Q;
    }
}
