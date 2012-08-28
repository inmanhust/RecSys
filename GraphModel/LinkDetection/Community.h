#ifndef __COMMUNITY__H__
#define __COMMUNITY__H__

#include "GraphBase/GraphInterface.h"
using namespace GraphModel;

namespace CommunityDetection
{
    class Community
    {
    public:
        Community(Graph * graph, Vertex * vertex, uint32_t id);
        //Community(Graph * graph, set<Vertex*> nodes);
        ~Community();

    public:
        uint32_t getInLinkNum(const Vertex * vertex) const;
        uint32_t getOutDegree() const;
        bool insertVertex(Vertex * vertex);
        bool removeVertex(Vertex * vertex);

    public:
        Graph * graph_;
        set<Vertex*, VertexLess<Vertex*> > nodes_;
        uint32_t community_id_;
        uint32_t in_degree_;
        uint32_t total_degree_;
    };
}

#endif //__COMMUNITY__H__
