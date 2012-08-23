#include "SimRank.h"

namespace GraphModel
{
    SimRank::SimRank(Graph * graph):graph_(graph)
    {
    }

    SimRank::~SimRank();

    bool SimRank::init()
    {
        
        return true;
    }
}
