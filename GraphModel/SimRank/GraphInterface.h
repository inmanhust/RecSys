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
    typedef uint32_t T_VERTEX_TYPE;

    class Edge
    {
        public:
            Edge();
            Edge(T_VERTEX_TYPE front_vertex_id, T_VERTEX_TYPE tail_vertex_id);
            ~Edge();

        public:
            void setFrontVertexID(T_VERTEX_TYPE vertex_id);
            T_VERTEX_TYPE getFrontVertexID() const;

            void setTailVertexID(T_VERTEX_TYPE vertex_id);
            T_VERTEX_TYPE getTailVertexID() const;

            void setWeight(double weight);
            double getWeight();
    
            T_VERTEX_TYPE getAdjVertex(T_VERTEX_TYPE vertex_id);

            bool operator==(const Edge& edge) const;

            void print();

        private:
            T_VERTEX_TYPE front_vertex_id_;
            T_VERTEX_TYPE tail_vertex_id_;
            double weight_;
    };

    struct EdgeHash
    {
        size_t operator()(const Edge& edge) const
        {
            uint32_t fvid = edge.getFrontVertexID();
            uint32_t tvid = edge.getTailVertexID();

            return fvid*fvid + fvid*tvid + tvid*tvid;
        }
    };

    struct EdgeEqual
    {
        bool operator()(const Edge& edge1,const Edge& edge2) const
        {
            bool ret = true;
            ret = ret & (edge1.getFrontVertexID()==edge2.getFrontVertexID());
            ret = ret & (edge1.getTailVertexID()==edge2.getTailVertexID());

            return ret;
        }
    };

    template<class EdgeType>
    struct EdgeLess
    {
        bool operator()(const EdgeType& edge1, const EdgeType& edge2) const
        {
            uint32_t sum1 = edge1->getFrontVertexID()*edge1->getFrontVertexID() + edge1->getFrontVertexID()*edge1->getTailVertexID() + edge1->getTailVertexID()*edge1->getTailVertexID();
            uint32_t sum2 = edge2->getFrontVertexID()*edge2->getFrontVertexID() + edge2->getFrontVertexID()*edge2->getTailVertexID() + edge2->getTailVertexID()*edge2->getTailVertexID();

            return sum1>sum2;
        }
    };

    template<class EdgeType>
    struct Less
    {
        bool operator()(const EdgeType& edge1, const EdgeType& edge2) const
        {
            uint32_t sum1 = edge1.getFrontVertexID()*edge1.getFrontVertexID() + edge1.getFrontVertexID()*edge1.getTailVertexID() + edge1.getTailVertexID()*edge1.getTailVertexID();
            uint32_t sum2 = edge2.getFrontVertexID()*edge2.getFrontVertexID() + edge2.getFrontVertexID()*edge2.getTailVertexID() + edge2.getTailVertexID()*edge2.getTailVertexID();

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
            void setID(uint32_t vid);
            uint32_t getID() const;
            void setType(uint32_t type);
            uint32_t getType() const;
            void addEdge(Edge * edge);
            void removeEdge(Edge * edge);
            uint32_t getDegree() const;
            bool isAdjVertex(Vertex * vertex) const;

            bool operator==(const Vertex& vertex) const;

            void print();
        public:
            set<Edge, Less<Edge> > sim_set_;
        private:
            uint32_t vid_;
            uint32_t type_; //node type 0-user 1-item
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
            bool addEdge(uint32_t f_vertex_id, uint32_t t_vertex_id, double weight);
            bool readGraph(const char * filepath);
            void print() const;
        private:
            map<uint32_t, Vertex*> vertex_map_;
            set<Edge*, EdgeLess<Edge*> > edge_set_;       
    };

};

#endif //_GRAPH_INTERFACE_H_
