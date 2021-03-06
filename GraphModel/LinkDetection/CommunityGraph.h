#ifndef __COMMUNITY__GRAPH__H__
#define __COMMUNITY__GRAPH__H__

#include "BaseGraph/BaseGraph.h"

namespace GraphModel
{
    class Edge : public BaseEdge
    {
    public:
        Edge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id);
        ~Edge() {};
    };

    class Vertex : public BaseVertex
    {
    public:
        Vertex(const VertexId& vid);
        ~Vertex() {};
    };

    class Graph : public BaseGraph
    {
    public:
        Graph();
        ~Graph() {};

        bool addEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id);

        bool addEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id, double weight);

        bool readGraph(const char * filepath);  

        bool readBinaryGraph(const char * filepath);

        void printGraphMsg() const;
    };
}

#endif //__COMMUNITY__GRAPH__H__
