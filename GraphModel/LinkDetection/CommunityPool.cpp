#include "CommunityPool.h"
#include "Modularity.h"

using std::pair;
namespace CommunityDetection
{
    CommunityPool::CommunityPool(Graph * graph):graph_(graph)
    {

    }

    void CommunityPool::initCommunityPool()
    {
        const map<VERTEX_TYPE_T, Vertex*>& vertexs = graph_->vertex_map_;
        map<uint32_t, Vertex*>::const_iterator itr = vertexs.begin();
        while (itr != vertexs.end())
        {
            Vertex * v = itr->second;
            Community * community = new Community(graph_, v);
            vertex_community_map_.insert(pair<uint32_t, Community*>(v->vid_, community));
            itr ++;
        }
    }

    bool CommunityPool::addVertexToCommunity(Vertex * vertex, Community * community)
    {
        CommunityIndex::iterator itr = vertex_community_map_.find(vertex->vid_);
        if(itr != vertex_community_map_.end())
        {
            Community * old_community = itr->second;
            old_community->removeVertex(vertex);
        }
        else
        {
            fprintf(stderr, "[Warning][Vertex[id: %u] is not Exist in the Community Pool]\n", vertex->vid_);
        }
        community->insertVertex(vertex);          
        vertex_community_map_[vertex->vid_] = community;
        
        return true;
    }

    bool CommunityPool::removeVertexFromCommunity(Vertex * vertex, Community * community)
    {
        CommunityIndex::iterator itr = vertex_community_map_.find(vertex->vid_);
        
        if(itr != vertex_community_map_.end())
        {
            Community * old_community = itr->second;
            old_community->removeVertex(vertex);
            vertex_community_map_.erase(itr);
            return true;
        }
        else
        {
            fprintf(stderr, "[Error][Can not Be Removed ,Vertex[id: %u] is not Exist.]\n", vertex->vid_);
            return false;
        }
    }

/*
    uint32_t getNeighborCommunities(const Vertex * vertex, set<Community*>& neighbors) const
    {
        neighbors.clear();
        const set<Edge*, EdgeLess<Edge*> >& adj_edges = vertex->adj_edge_;
        set<Edge*, EdgeLess<Edge*>::iterator itr = adj_edges.begin();
        CommunityIndex::iterator idx_itr;
        while (itr !=adj_edges.end())
        {
            Edge * edge = *itr;
            uint32_t adj_vid = edge->getAdjVertex(vertex->vid_);
            
            idx_itr = vertex_community_map_.find(vertex->vid_);
            if (idx_itr == vertex_community_map_.end())
            {
                fprintf(stderr, "[Warning][vertex(id: %u) is not exist in pool]", vertex->vid_);
                continue;
            }
            Community * community = idx_itr->second;
            neighbors.add(community)
            itr ++;
        }

        return neighbors.size();
    }
*/
    Community * CommunityPool::getCommunity(uint32_t vertex_id)
    {
        return vertex_community_map_[vertex_id];
    }

    double CommunityPool::getModularity()
    {
        map<uint32_t, Community*> communities;
        /*
        CommunityIndex::iterator itr = vertex_community_map_.begin();
        while (itr != vertex_community_map_.end())
        {
            Community * community = itr->second;
            communities.insert(community);
            itr ++;
        }
        */
        double modularity = Modularity::getQualityScore(graph_, communities,  1.0);
        
        return modularity;
    }
}

