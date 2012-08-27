#ifndef __COMMUNITY__POOL__
#define __COMMUNITY__POOL__
#include "Community.h"
#include "Modularity.h"

namespace CommunityDetection
{
   typedef map<uint32_t, Community*> CommunityIndex;

    class CommunityPool
    {
    public:
        CommunityPool(Graph * graph);

    public:
        void initCommunityPool();
        bool addVertexToCommunity(Vertex * vertex, Community * community);
        bool removeVertexFromCommunity(Vertex * vertex,  Community * community);
 //       uint32_t getNeighborCommunities(const Vertex * vertex, set<Community*>& neighbors);
        Community * getCommunity(uint32_t vertex_id);
        double getModularity();
   

    public:
        Graph * graph_;
        CommunityIndex vertex_community_map_;
    };
}

#endif //__COMMUNITY__POOL__
