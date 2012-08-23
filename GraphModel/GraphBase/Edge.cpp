#include "GraphInterface.h"

namespace GraphModel
{
    Edge::Edge(){}

    Edge::Edge(T_VERTEX_TYPE front_vertex_id, T_VERTEX_TYPE tail_vertex_id):front_vertex_id_(front_vertex_id),tail_vertex_id_(tail_vertex_id)
    {
    }

    Edge::~Edge(){}

    void Edge::setFrontVertexID(T_VERTEX_TYPE vertex_id)
    {
        front_vertex_id_ = vertex_id;
    }

    T_VERTEX_TYPE Edge::getFrontVertexID() const
    {
        return front_vertex_id_;
    }

    void Edge::setTailVertexID(T_VERTEX_TYPE vertex_id)
    {
        tail_vertex_id_ = vertex_id;
    }

    T_VERTEX_TYPE Edge::getTailVertexID() const
    {
        return tail_vertex_id_;
    }

    void Edge::setWeight(double weight)
    {
        weight_ = weight;
    }

    double Edge::getWeight()
    {
        return weight_;
    }

    T_VERTEX_TYPE Edge::getAdjVertex(T_VERTEX_TYPE vertex_id)
    {
        if(vertex_id == front_vertex_id_)
            return tail_vertex_id_;
        else if(vertex_id == tail_vertex_id_)
            return front_vertex_id_;
        else
            return 0;
    }


    bool Edge::operator==(const Edge& edge) const
    {
        if((edge.getFrontVertexID()==front_vertex_id_ &&edge.getTailVertexID()==tail_vertex_id_)&&(edge.getFrontVertexID()==tail_vertex_id_ && edge.getTailVertexID()==front_vertex_id_))
            return true;

        return false;
    }

    void Edge::print()
    {
        fprintf(stderr, "[Info][Edge front id:%u, tail id:%u, weight:%f]\n",front_vertex_id_, tail_vertex_id_, weight_);
    }

}
