#include "Modularity.h"
#include <math.h>

namespace CommunityDetection
{
    double Modularity::getQualityScore(const Graph * graph, std::tr1::unordered_map<uint32_t, Community*>& communities, double gamma)
    {
     //	const uint32_t communityNum = communities.size();

	    double Q = 0.0;
	    uint32_t edge_num = graph->edge_num_;
        std::tr1::unordered_map<uint32_t, Community*>::iterator itr;
	    for(itr=communities.begin(); itr!=communities.end(); itr++)
	    {
            Community * community = itr->second;
		    uint32_t in_degree = community->in_degree_;
		    uint32_t total_degree = community->total_degree_;

		    Q += ((double)in_degree)/(2*(double)edge_num) + pow((double)total_degree/((double)(2*edge_num)), 2);
            //printf("Q: %f, indegree: %u, total: %u, edgenum: %u\n",Q,in_degree, total_degree, edge_num);
	    }

	    return Q;
    }
}
