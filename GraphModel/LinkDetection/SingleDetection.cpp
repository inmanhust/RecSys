#include "SingleDetection.h"

namespace CommunityDetection
{
    SingleDetection::SingleDetection(Graph * graph):graph_(graph)
    {

    }

    SingleDetection::SingleDetection(Graph * graph, double gamma, uint32_t iterations)
    {
        graph_ = graph;
        gamma_ = gamma;
        iterations_ = iterations;
        pool = new CommunityPool(graph_);
    }

/*
    uint32_t SingleDetection::findCommunities(set<Community>& communities)
    {
        pool->initCommunityPool();

        uint32_t edge_num = graph_.edge_set_.size();
        map<Community*, double> comm_stat_map;
        double old_modularity = pool.getModularity();
        for (uint32_t idx=0; idx<iterations_; idx++)
        {
            const map<uint32_t, Vertex*>& vertexs = graph_.vertex_map_;
            map<uint32_t, Vertex*>::iterator itr = vertexs.begin();
            while (itr != vertexs.end())
            {
                Vertex * v =  iter->second;
                double degree = v->getDegree();
                Community * ori_comm = pool.getCommunity(v->vid_);
                pool.removeVertexFromCommunity(v, ori_comm);
                
                Community * best_comm = ori_comm;
                double best_increase = 0.0;
                
                comm_stat_map.clear();

                set<Edge*>::iterator edge_itr = (v->adj_edge_).begin();
                while(edge_itr != v->(adj_edge_).end())
                {
                    Edge * edge = *edge_itr;
                    uint32_t vid = edge->getAdjVertex(v->vid);
                    Community * adj_comm = pool.getCommunity(vid);
                   
                    if (comm_stat_map.find(adj_comm) != comm_stat_map.end()) 
                    {
                        comm_stat_map[adj_comm] += 1.0;
                    }
                    else
                    {
                        comm_stat_map[adj_comm] = 1.0;
                    }
                }

                map<Community*, double>::iterator adj_com_itr = comm_stat_map.begin();
                while (adj_com_itr != comm_stat_map.end())
                {
                    double mc = adj_com_itr->second;
                    Community * com = adj_com_itr->first;

                    uint32_t totla_degree = community->totla_degree_;
                    uint32_t m2 = 2 * edge_num;
                    
                    double increase = mc - gamma_* totla_degree_ *degree /m2;
                    if (increase > best_increase)
                    {
                        best_increase = increase;
                        best_comm = community;
                    }
                }

                pool.addVertexToCommunity(v, best_comm);
            }

            double new_modularity = pool.getModularity();
            if(new_modularity - old_modularity < delta)
            {
                break;
            }
            else
            {
                old_modularity = new_modularity;
            }
        }

        //copy pool's vertex_community_map_ to communities

        return communities.size();
    }
*/
}
