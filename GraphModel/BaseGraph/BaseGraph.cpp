#include "BaseGraph.h"
#include <iostream>

namespace GraphModel
{

    BaseEdge::BaseEdge() {}

    BaseEdge::BaseEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id):front_vertex_id_(front_vertex_id), tail_vertex_id_(tail_vertex_id)
    {
    }

    BaseEdge::BaseEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id, double weight):front_vertex_id_(front_vertex_id), tail_vertex_id_(tail_vertex_id), weight_(weight)
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

    bool BaseEdge::operator==(const BaseEdge& edge) const
    {
        return isSameEdge(edge);
    }

    void BaseEdge::printEdgeMsg() const 
	{
	    //fprintf(stderr, "[Info][front: %u, tail: %u, weight: %f]\n", front_vertex_id_, tail_vertex_id_, weight_);	
		std::cout << "[Info][front: " << front_vertex_id_ << ", tail: " << tail_vertex_id_ << ", weight: " << weight_ << "]\n";
    }


    BaseVertex::BaseVertex() {}

    BaseVertex::BaseVertex(const VertexId& vid):vid_(vid) {}

    BaseVertex::~BaseVertex() {}

    void BaseVertex::addEdge(BaseEdge * edge)
    {
        adj_edges_.insert(edge);
    }

    void BaseVertex::removeEdge(BaseEdge * edge)
    {
        EdgeSet::const_iterator itr = adj_edges_.find(edge);
        if (itr != adj_edges_.end())
            adj_edges_.erase(itr);
    }

    bool BaseVertex::isAdjVertex(BaseVertex * vertex) const
    {
        EdgeSet::const_iterator itr;
        for (itr=adj_edges_.begin();itr!=adj_edges_.end();itr++)
        {
            const BaseEdge * edge = *itr;
            const VertexId& vid = edge->getAdjVertex(vertex->vid_);
            if (vid !=ERROR_VERTEX_ID  && VertexIdComp(vid, vid_) == 0)
                return true;
        }

        return false;
    }

    bool BaseVertex::operator==(const BaseVertex& vertex) const
    {
        return VertexIdComp(vertex.vid_, vid_) == 0;
    }

    void BaseVertex::printVertexMsg() const 
	{
	    //fprintf(stderr, "[Info][vid: %u, edge size: %u]", vid_, adj_edges_.size());	
		std::cout << "[Info][vid: " << vid_ << ", edge size: " << adj_edges_.size() << "]\n";
	}


    BaseGraph::BaseGraph():edge_num_(0) {}

    BaseGraph::~BaseGraph() {}

    bool BaseGraph::addEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id)
    {
        if (VertexIdComp(front_vertex_id, tail_vertex_id) == 0)
        {
		    std::cout << "[Error][Same VertexId: " << front_vertex_id << "]\n";
        //    fprintf(stderr, "[Error][Same VertexId]\n");
            return false;
        }

        BaseVertex * f_vertex;
        BaseVertex * t_vertex;
        IdToVertexMap::iterator itr = vertex_map_.find(front_vertex_id);
        if (itr == vertex_map_.end())
        {
            f_vertex = new BaseVertex(front_vertex_id);
            vertex_map_[front_vertex_id] = f_vertex;
        }
        else
        {
            f_vertex = itr->second;
        }

        itr = vertex_map_.find(tail_vertex_id);
        if (itr == vertex_map_.end())
        {
            t_vertex = new BaseVertex(tail_vertex_id);
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

        BaseEdge * edge = new BaseEdge(front_vertex_id, tail_vertex_id);
        f_vertex->addEdge(edge);
        t_vertex->addEdge(edge);

        edge_num_ ++;
        return true;
    }

    bool BaseGraph::addEdge(const VertexId& front_vertex_id, const VertexId& tail_vertex_id, double weight)
    {

        if (VertexIdComp(front_vertex_id, tail_vertex_id) == 0)
        {
            fprintf(stderr, "[Error][Same VertexId]\n");
            return false;
        }

        BaseVertex * f_vertex;
        BaseVertex * t_vertex;
        IdToVertexMap::iterator itr = vertex_map_.find(front_vertex_id);
        if (itr == vertex_map_.end())
        {
            f_vertex = new BaseVertex(front_vertex_id);
            vertex_map_[front_vertex_id] = f_vertex;
        }
        else
        {
            f_vertex = itr->second;
        }

        itr = vertex_map_.find(tail_vertex_id);
        if (itr == vertex_map_.end())
        {
            t_vertex = new BaseVertex(tail_vertex_id);
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

        BaseEdge * edge = new BaseEdge(front_vertex_id, tail_vertex_id);
        edge->weight_ = weight;
        f_vertex->addEdge(edge);
        t_vertex->addEdge(edge);

        edge_num_ ++;
        return true;
    }

    bool BaseGraph::isVertexExist(const BaseVertex * vertex) const
    {
        IdToVertexMap::const_iterator itr = vertex_map_.find(vertex->vid_);
        if(itr == vertex_map_.end())
            return true;
        else
            return false;
    }

    void BaseGraph::printGraphMsg() const {}

    bool BaseGraph::readGraph(const char * filepath)
    {
        return true;
    }
}
