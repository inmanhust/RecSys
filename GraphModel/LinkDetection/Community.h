#ifndef __COMMUNITY__H__
#define __COMMUNITY__H__

#include "GraphBase/GraphInterface.h"
using namespace GraphBase;

namespace CommunityDetection
{
    class Community
    {
    public:
        Community(Graph * graph, Vertex * vertex);
        Community(Graph * graph, set<Vertex*> nodes);
        ~Community();

    public:
        uint32_t getInLinkNum(const Vertex * vertex) const;
        uint32_t getOutDegree() const;
        bool insertVertex(const Vertex * vertex);
        bool removeVertex(const Vertex * vertex);

    public:
        Graph * graph_;
        set<Vertex*> nodes_;
        uint32_t community_id_;
        uint32_t in_degree_;
        uint32_t total_degree_;
    };
}

#endif //__COMMUNITY__H__
