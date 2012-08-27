#ifndef __MODULARITY__H__
#define __MODULARITY__H__

#include "Community.h"


namespace CommunityDetection
{
    class Modularity
    {
    public:
        static double getQualityScore(const Graph * graph, map<uint32_t, Community*>& communities, double gamma);
    };
}

#endif //__MODULARITY__H__
