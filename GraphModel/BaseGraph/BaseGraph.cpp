#include "BaseGraph.h"

namespace GraphModel
{
/*
    BaseEdge::BaseEdge() {}

    BaseEdge::(const VertexId& front_vertex_id, const VertexId& tail_vertex_id):front_vertex_id_(front_vertex_id), tail_vertex_id_(tail_vertex_id)
    {
    }

    BaseEdge::(const VertexId& front_vertex_id, const VertexId& tail_vertex_id, double weight)::front_vertex_id_(front_vertex_id), tail_vertex_id_(tail_vertex_id), weight_(weight)
    {
    }

    BaseEdge::~BaseEdge(){}

    bool BaseEdge::isSameEdge(const BaseEdge& edge) const
    {
        if (VertexIdComp(edge.front_vertex_id_, front_vertex_id_) == 0)
            return VertexIdComp(edge.tail_vertex_id_, tail_vertex_id_) == 0;
        else if (VertexIdComp(edge.front_vertex_id_,tail_vertex_id_))
            return VertexIdComp(edge.tail_vertex_id_, front_vertex_id_) == 0;
        else
            return false;
    }

    bool BaseEdge::operator(const BaseEdge& edge) const
    {
        return isSameEdge(edge);
    }


    BaseVertex::Vertex() {}

    BaseVertex::Vertex(const VertexId& vid):vid_(vid) {}

    BaseVertex::~Vertex();

    void BaseVertex::addEdge(Edge * edge)
    {
        adj_edges_.insert(edge);
    }

    void BaseVertex::removeEdge(Edge * edge)
    {
        EdgeSet::const_iterator itr = adj_edges_.find(edge);
        if (itr != adj_edges_.end())
            adj_edges_.erase(itr);
    }

    bool BaseEdge::isAdjVertex(Vertex * vertex) const
    {
        EdgeSet::const_iterator itr;
        for (itr=adj_edges_.begin();itr!=adj_edges_.end();itr++)
        {
            const Edge * edge = *itr;
            const VertexId& vid = edge->getAdjVertex(vertex->vid_);
            if (vid !=ERROR_VERTEX_ID  && VertexIdComp(vid, vid_) == 0)
                return true;
        }

        return false;
    }

    bool BaseVertex::operator==(const Vertex& vertex) const
    {
        return VertexIdComp(vertex.vid_, vid_) == 0;
    }


    BaseGraph::Graph() {}

    bool BaseGraph::addEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id)
    {
        if (VertexIdComp(front_vertex_id, tail_vertex_id) == 0)
        {
            //这里需要打印具体的节点内容
            fprintf(stderr, "[Error][Same VertexId]\n");
            return false;
        }

        Vertex * f_vertex;
        Vertex * t_vertex;
        IdToVertexMap::iterator itr = vertex_map_.find(front_vertex_id);
        if (itr == vertex_map_.end())
        {
            f_vertex = new Vertex(front_vertex_id);
            vertex_map_[front_vertex_id] = f_vertex;
        }
        else
        {
            f_vertex = itr->second;
        }

        itr = vertex_map_.find(tail_vertex_id);
        if (itr == vertex_map_.end())
        {
            t_vertex = new Vertex(tail_vertex_id);
            vertex_map_[tail_vertex_id] = t_vertex;
        }
        else
        {
            t_vertex = itr->second;
        }

        if (f_vertex->isAdjVertex(t_vertex))
        {
            fprintf(stderr, "[Error][Edge is exist]\n");
            return false;
        }

        Edge * edge = new Edge(front_vertex_id, tail_vertex_id);
        f_vertex->addEdge(edge);
        t_vertex->addEdge(edge);

        edge_num_ ++;
        return true;
    }

    bool BaseGraph::addEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id, double weight)
    {

        if (VertexIdComp(front_vertex_id, tail_vertex_id) == 0)
        {
            //这里需要打印具体的节点内容
            fprintf(stderr, "[Error][Same VertexId]\n");
            return false;
        }

        Vertex * f_vertex;
        Vertex * t_vertex;
        IdToVertexMap::iterator itr = vertex_map_.find(front_vertex_id);
        if (itr == vertex_map_.end())
        {
            f_vertex = new Vertex(front_vertex_id);
            vertex_map_[front_vertex_id] = f_vertex;
        }
        else
        {
            f_vertex = itr->second;
        }

        itr = vertex_map_.find(tail_vertex_id);
        if (itr == vertex_map_.end())
        {
            t_vertex = new Vertex(tail_vertex_id);
            vertex_map_[tail_vertex_id] = t_vertex;
        }
        else
        {
            t_vertex = itr->second;
        }

        if (f_vertex->isAdjVertex(t_vertex))
        {
            fprintf(stderr, "[Error][Edge is exist]\n");
            return false;
        }

        Edge * edge = new Edge(front_vertex_id, tail_vertex_id);
        edge->weight = weight
        f_vertex->addEdge(edge);
        t_vertex->addEdge(edge);

        edge_num_ ++;
        return true;
    }

    bool BaseGraph::isVertexExist(const Vertex * vertex) const
    {
        IdToVertexMap::const_iterator itr = vertex_map_.find(vertex->vid_);
        if(itr == vertex_map_.end())
            return true;
        else
            return false;
    }
*/
}
