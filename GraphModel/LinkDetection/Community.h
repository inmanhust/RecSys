#ifndef __COMMUNITY__H__
#define __COMMUNITY__H__

#include "CommunityGraph.h"

using namespace GraphModel;

namespace CommunityDetection
{
	typedef std::tr1::unordered_set<Vertex*> VertexSet;
    class Community
    {
    public:
        Community(Graph * graph, Vertex * vertex, uint32_t id);
        ~Community();

    public:
        uint32_t getInLinkNum(const Vertex * vertex) const;
        uint32_t getOutDegree() const;
        bool insertVertex(Vertex * vertex);
        bool removeVertex(Vertex * vertex);

    public:
        Graph * graph_;
        VertexSet nodes_;
        uint32_t community_id_;
        uint32_t in_degree_;
        uint32_t total_degree_;
    };
}

#endif //__COMMUNITY__H__
