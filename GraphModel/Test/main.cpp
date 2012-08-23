#include "GraphCommon/CommonTools.h"
#include "SimRank/GraphInterface.h"
#include <iostream>
using namespace std;
using namespace GraphModel;
int main()
{
    Graph graph;
    graph.readGraph("data/movielens");
    graph.print();

    return 0;
}
