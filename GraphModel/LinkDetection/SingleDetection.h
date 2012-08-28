#ifndef __SINGLE__DETECTION_H__
#define __SINGLE__DETECTION_H__
#include "CommunityPool.h"

namespace CommunityDetection
{
    class SingleDetection
    {
    public:
        SingleDetection(Graph * graph);
        SingleDetection(Graph * graph, double gamma, uint32_t iterations);
    public:
        uint32_t findCommunities(map<uint32_t, Community*>& communities);
    public:
        Graph * graph_;
        CommunityPool * pool;
        double gamma_;
        double delta_;
        uint32_t iterations_;
    };
}

#endif //__SINGLE__DETECTION_H__
