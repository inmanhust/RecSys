#include "GraphCommon/CommonTools.h"
#include "LinkDetection/CommunityGraph.h"
#include "LinkDetection/SingleDetection.h"
#include <iostream>

using namespace std;
using namespace GraphModel;
using namespace CommunityDetection;


int main()
{
    Graph graph;
    graph.readGraph("data/g_data.txt");
   // graph.printGraphMsg();

	std::tr1::unordered_map<uint32_t, Community*> communities;
    SingleDetection detection(&graph, 1.0, 30);
    detection.findCommunities(communities);

    printf("output final community\n");
	std::tr1::unordered_map<uint32_t, Community*>::iterator itr = communities.begin();
    while (itr != communities.end())
    {
            Community * community = itr->second;
            VertexSet& nodes = community->nodes_;
            VertexSet::iterator node_itr;
            printf("Community id: \t%u, nodes:\n",community->community_id_);
            for (node_itr=nodes.begin();node_itr!=nodes.end(); node_itr++)
            {
                printf("%u\t",(*node_itr)->vid_);
            }
            printf("\n");
            itr ++;
    }

    cout << "Done..." << endl;
    return 0;
}
