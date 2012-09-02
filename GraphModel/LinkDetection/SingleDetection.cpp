#include "SingleDetection.h"
using std::tr1::unordered_map;

namespace CommunityDetection
{
    SingleDetection::SingleDetection(Graph * graph):graph_(graph)
    {

    }

    SingleDetection::SingleDetection(Graph * graph, double gamma, uint32_t iterations)
    {
        graph_ = graph;
        gamma_ = gamma;
        delta_ = 0.00000001;
        iterations_ = iterations;
        pool = new CommunityPool(graph_);
    }


    uint32_t SingleDetection::findCommunities(std::tr1::unordered_map<uint32_t, Community*>& communities)
    {
        pool->initCommunityPool();
        //pool->printPool();

        uint32_t edge_num = graph_->edge_num_;
        std::tr1::unordered_map<Community*, double> comm_stat_map;
        double old_modularity = pool->getModularity();
        //printf("modularity: %f\n", old_modularity);
        for (uint32_t idx=0; idx<iterations_; idx++)
        {
            printf("[Info][iteration: %u ]\n",idx);          

            IdToVertexMap& vertexs = graph_->vertex_map_;
            IdToVertexMap::iterator itr = vertexs.begin();
            while (itr != vertexs.end())
            {
                Vertex * v =  (Vertex*)itr->second;
                double degree = v->getDegree();
                Community * ori_comm = pool->getCommunity(v->vid_);
                pool->removeVertexFromCommunity(v, ori_comm);
                
                Community * best_comm = ori_comm;
                double best_increase = 0.0;
                
                comm_stat_map.clear();

                EdgeSet::iterator edge_itr = (v->adj_edges_).begin();
                while(edge_itr != (v->adj_edges_).end())
                {
                    Edge * edge = (Edge*)*edge_itr;
                    uint32_t vid = edge->getAdjVertex(v->vid_);
                    Community * adj_comm = pool->getCommunity(vid);
                   
                    if (comm_stat_map.find(adj_comm) != comm_stat_map.end()) 
                    {
                        comm_stat_map[adj_comm] += 1.0;
                    }
                    else
                    {
                        comm_stat_map[adj_comm] = 1.0;
                    }

                    edge_itr ++;
                }

                unordered_map<Community*, double>::iterator adj_com_itr = comm_stat_map.begin();
                while (adj_com_itr != comm_stat_map.end())
                {
                    double mc = adj_com_itr->second;
                    Community * com = adj_com_itr->first;

                    uint32_t total_degree = com->total_degree_;
                    uint32_t m2 = 2 * edge_num;
                    
                    double increase = mc - gamma_ * ((double)(total_degree * degree)) /(double)m2;
                    if (increase > best_increase)
                    {
                        best_increase = increase;
                        best_comm = com;
                    }
                    
                    adj_com_itr ++;
                }

                pool->addVertexToCommunity(v, best_comm);
                itr ++;
            }

            double new_modularity = pool->getModularity();
            if(new_modularity - old_modularity < delta_)
            {
                break;
            }
            else
            {
                old_modularity = new_modularity;
            }
        }

        return pool->getCommunitySet(communities);
    }

}
