#ifndef __COMMUNITY__POOL__
#define __COMMUNITY__POOL__
#include "Community.h"
#include "Modularity.h"

namespace CommunityDetection
{
    typedef std::tr1::unordered_map<VertexId, Community*> CommunityIndex;
    typedef std::tr1::unordered_set<Community*> CommunitySet;

    class CommunityPool
    {
    public:
        CommunityPool(Graph * graph);

    public:
        void initCommunityPool();
        bool addVertexToCommunity(Vertex * vertex, Community * community);
        bool removeVertexFromCommunity(Vertex * vertex);
//        uint32_t getNeighborCommunities(const Vertex * vertex, CommunitySet& neighbors);
        Community * getCommunity(const VertexId& vertex_id);
        double getModularity();
        uint32_t getCommunitySet(CommunityIndex& communities);
        void printPool() const;
   

    public:
        Graph * graph_;
        CommunityIndex vertex_community_map_;

    private:
        uint32_t max_community_id_;
    };
}

#endif //__COMMUNITY__POOL__
