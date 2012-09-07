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
			community->printCommunityMsg();
            itr ++;
    }

	sleep(100);

    cout << "Done..." << endl;
    return 0;
}
