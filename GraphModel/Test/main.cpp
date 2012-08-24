#include "GraphCommon/CommonTools.h"
#include "GraphBase/GraphInterface.h"
#include <iostream>
using namespace std;
using namespace GraphModel;
int main()
{
    cout << "run ---->" << endl;
    Graph graph;
    graph.readGraph("data/g_data.txt");
    //graph.printGraphInfo();

    sleep(100);
    return 0;
}
