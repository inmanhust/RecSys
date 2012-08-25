#include "Community.h"

namespace CommunityDetection
{
    Community::Community(Graph * graph, Vertex * vertex)
    {
        graph_ = graph;
        nodes.add(vertex);
        community_id_ = 0;
        in_degree_ = 0;
        total_degree_ = vertex.getDegree();
    }
    
    Community(Graph * graph, set<Vertex*> nodes):graph_(graph),nodes_(nodes),total_degree_(0),in_degree_(0)
    {
        //need process
        community_id_ = 0;
        set<Vertex*>::const_iterator itr = nodes_.begin();
        while(itr != nodes_.end())
        {
            const Vertex * v = *iter;
            total_degree_ += v->getDegree();
            in_degree_ += getInLinkNum(v);
            itr ++;
        }
    }

    uint32_t Community::getInLinkNum(const Vertex * vertex) const
    {
        uint32_t count = 0;
        set<Vertex*>::const_iterator itr = nodes_.begin();
        while (itr != nodes_.end())
        {
            if (vertex->isAdjVertex(*itr))
                count ++;
            itr ++;
        }

        return count;
    }

    uint32_t Community::getOutDegree() const
    {
        return total_degree_ - in_degree_;
    }

    bool Community::insertVertex(const Vertex * vertex)
    {
        if(nodes_.find(vertex) == nodes_.end())
        {
            uint32_t in_links = getInLinkNum(vertex);
            in_degree_ += 2 * in_links;
            total_degree_ += vertex->getDegree();
            nodes.add(vertex);
            return true;
        }
        else
        {
            fprintf(stderr, "Node[id: %u] is Exist in the Community\n",vertex->vid_);
            return false;
        }
    }

    bool Community::removeVertex(const Vertex * vertex)
    {
        if (nodes_.find(vertex) != nodes_.end())
        {
            uint32_t in_links = getInLinkNum(vertex);
            in_degree_ -= 2 * in_links;
            total_degree_ -= v.getDegree();

            if (in_degree_ < 0)
            {
                fprintf(stderr, "[Error][in_degree_ < 0]\n");
                return false;
            }

            if (total_degree_ < 0)
            {
                fprintf(stderr, "[Error][total_degree_ < 0]\n");
                return false;
            }

            nodes_.erase(vertex);
            return true;
        }
        else
        {
            fprintf(stderr, "[Error][Vertex[id: %u] is not Exist in th Community]\n",vertex->vid_);
            return false;
        }
    }
 
}
