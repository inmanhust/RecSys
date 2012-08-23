#include "GraphInterface.h"

namespace GraphModel
{    
    Vertex::Vertex(){}

    Vertex::Vertex(uint32_t vid):vid_(vid)
    {
    }

    Vertex::~Vertex(){}

    void Vertex::setID(uint32_t vid)
    {
        vid_ = vid;
    }

    uint32_t Vertex::getID() const
    {
        return vid_;
    }

    void Vertex::setType(uint32_t type)
    {
        type_ = type;
    }

    uint32_t Vertex::getType() const
    {
        return type_;
    }

    void Vertex::addEdge(Edge * edge)
    {
        adj_edge_.insert(edge);
    }

    void Vertex::removeEdge(Edge * edge)
    {
        set<Edge*, EdgeLess<Edge*> >::iterator iter = adj_edge_.find(edge);
        if(iter != adj_edge_.end())
        {
            adj_edge_.erase(iter);
        }
    }

    uint32_t Vertex::getDegree() const
    {
        return adj_edge_.size();
    }

    bool Vertex::isAdjVertex(Vertex * vertex) const
    {
        for(set<Edge*, EdgeLess<Edge*> >::iterator iter=adj_edge_.begin();iter!=adj_edge_.end();iter++)
        {
            Edge * edge = *iter;
            T_VERTEX_TYPE v = edge->getAdjVertex(vertex->getID());
            if(v!=0 && v==vid_)
                return true;
        }
        return false;
    }

    bool Vertex::operator==(const Vertex& vertex) const
    {
        return vertex.getID() == vid_;
    }

    void Vertex::print()
    {
        fprintf(stderr,"[Vertex Info][type: \t%u,ID:\t%u,degree:\t%u]\n",type_, vid_, (uint32_t)adj_edge_.size());
    }
}
