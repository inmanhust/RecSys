#include "GraphInterface.h"

namespace GraphModel
{
    Edge::Edge(){}

    Edge::Edge(VERTEX_TYPE_T front_vertex_id, VERTEX_TYPE_T tail_vertex_id):front_vertex_id_(front_vertex_id),tail_vertex_id_(tail_vertex_id)
    {
    }

    Edge::~Edge(){}

    VERTEX_TYPE_T Edge::getAdjVertex(VERTEX_TYPE_T vertex_id) const
    {
        if(vertex_id == front_vertex_id_)
            return tail_vertex_id_;
        else if(vertex_id == tail_vertex_id_)
            return front_vertex_id_;
        else
            return 0;
    }

    bool Edge::isSameEdge(const Edge& edge) const
    {

        if ((edge.front_vertex_id_ == front_vertex_id_ && edge.tail_vertex_id_ == tail_vertex_id_) || 
            (edge.front_vertex_id_ == tail_vertex_id_ && edge.tail_vertex_id_ == front_vertex_id_))
            return true;
        return false;
    }

    bool Edge::operator==(const Edge& edge) const
    {
        if(isSameEdge(edge))
            return true;

        return false;
    }

    uint32_t Edge::getEdgeUniqID() const
    {
        return front_vertex_id_*front_vertex_id_ + tail_vertex_id_*tail_vertex_id_ + front_vertex_id_*tail_vertex_id_;
    }

    void Edge::printEdgeInfo() const
    {
        fprintf(stderr, "[Info][Edge front id:%u, tail id:%u, weight:%f]\n",front_vertex_id_, tail_vertex_id_, weight_);
    }

}
