#include "GraphInterface.h"

namespace GraphModel
{    
    Vertex::Vertex(){}

    Vertex::Vertex(uint32_t vid):vid_(vid)
    {
    }

    Vertex::~Vertex(){}

    void Vertex::addEdge(Edge * edge)
    {
        adj_edge_.insert(edge);
    }

    void Vertex::removeEdge(Edge * edge)
    {
        set<Edge*, EdgeLess<Edge*> >::const_iterator iter = adj_edge_.find(edge);
        if(iter != adj_edge_.end())
        {
            adj_edge_.erase(iter);
        }
    }

    uint32_t Vertex::getDegree() const
    {
        return adj_edge_.size();
    }

    // this function can be optimazed
    bool Vertex::isAdjVertex(Vertex * vertex) const
    {
        for(set<Edge*, EdgeLess<Edge*> >::const_iterator iter=adj_edge_.begin();iter!=adj_edge_.end();iter++)
        {
            const Edge * edge = *iter;
            VERTEX_TYPE_T v = edge->getAdjVertex(vertex->vid_);
            if(v!=0 && v==vid_)
                return true;
        }
        return false;
    }

    bool Vertex::operator==(const Vertex& vertex) const
    {
        return vertex.vid_ == vid_;
    }

    void Vertex::printVertexInfo() const
    {
        fprintf(stderr,"[Vertex Info][ID:\t%u,degree:\t%u]\n", vid_, adj_edge_.size());
    }
}
