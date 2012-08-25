#ifndef _GRAPH_INTERFACE_H_
#define _GRAPH_INTERFACE_H_

#include <stdint.h>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>

using std::vector;
using std::set;
using std::map;

namespace GraphModel
{
    typedef uint32_t VERTEX_TYPE_T;

    class Edge
    {
    public:
        Edge();
        Edge(VERTEX_TYPE_T front_vertex_id, VERTEX_TYPE_T tail_vertex_id);
        ~Edge();

    public:
        VERTEX_TYPE_T getAdjVertex(VERTEX_TYPE_T vertex_id) const;
        bool operator==(const Edge& edge) const;
        void printEdgeInfo() const;
        bool isSameEdge(const Edge& edge) const;
        uint32_t getEdgeUniqID() const;

    public:
        VERTEX_TYPE_T front_vertex_id_;
        VERTEX_TYPE_T tail_vertex_id_;
        double weight_;
    };

    struct EdgeHash
    {
        size_t operator()(const Edge& edge) const
        {
            uint32_t fvid = edge.front_vertex_id_;
            uint32_t tvid = edge.tail_vertex_id_;

            return fvid*fvid + fvid*tvid + tvid*tvid;
        }
    };

    struct EdgeEqual
    {
        bool operator()(const Edge* edge1,const Edge* edge2) const
        {
            if(edge1->isSameEdge(*edge2))
                return true;
            return false;
        }
    };

    template <class EdgeType>
    struct EdgeLess
    {
        bool operator()(const EdgeType& edge1, const EdgeType& edge2) const
        {
            uint32_t sum1 = edge1->getEdgeUniqID();
            uint32_t sum2 = edge2->getEdgeUniqID();

            return sum1>sum2;
        }
    };

    class Vertex
    {
        public:
            Vertex();
            Vertex(uint32_t vid);
            ~Vertex();

        public:
            void addEdge(Edge * edge);
            void removeEdge(Edge * edge);
            uint32_t getDegree() const;
            bool isAdjVertex(Vertex * vertex) const;

            bool operator==(const Vertex& vertex) const;

            void printVertexInfo() const;
        public:
            uint32_t vid_;
            set<Edge*, EdgeLess<Edge*> > adj_edge_;
    };

    class Graph
    {
        public:
            Graph();
            ~Graph();

        public:
            bool isVertexExist(Vertex * vertex) const;
            bool addEdge(Vertex * f_vertex, Vertex * t_vertex);
            bool addEdge(VERTEX_TYPE_T f_vertex_id, VERTEX_TYPE_T t_vertex_id);
            bool readGraph(const char * filepath);
            void printGraphInfo() const;
        public:
            map<VERTEX_TYPE_T, Vertex*> vertex_map_;
            set<Edge*, EdgeLess<Edge*> > edge_set_;       
    };

};

#endif //_GRAPH_INTERFACE_H_
