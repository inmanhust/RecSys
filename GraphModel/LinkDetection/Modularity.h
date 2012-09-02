#ifndef __MODULARITY__H__
#define __MODULARITY__H__

#include "Community.h"


namespace CommunityDetection
{
    class Modularity
    {
    public:
        static double getQualityScore(const Graph * graph, std::tr1::unordered_map<uint32_t, Community*>& communities, double gamma);
    };
}

#endif //__MODULARITY__H__
