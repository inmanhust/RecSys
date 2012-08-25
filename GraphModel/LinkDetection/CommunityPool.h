#ifndef __COMMUNITY__POOL__
#define __COMMUNITY__POOL__
#include "Community.h"

namespace CommunityDetection
{
   typedef map<uint32_t, Community * community> CommunityIndex;

    class CommunityPool
    {
    public:
        CommunityPool(const Graph * graph);

    public:
        void initCommunitPool();
        bool addVertexToCommunity(const Vertex * vertex);
        bool removeVertexFrom Community(const Vertex * vertex);
        uint32_t getNeighborCommunities(const Vertex * vertex, set<Community*>& neighbors);
        double getModularity();
   

    public:
        Graph * graph_;
        CommunityIndex vertex_community_map_;
    };
}

#endif //__COMMUNITY__POOL__
