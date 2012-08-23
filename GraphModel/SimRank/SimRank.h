#ifndef _SIMRANK_H_
#define _SIMRANK_H_

#include "GraphInterface.h"
namespace GraphModel
{
    class SimRank
    {
        public:
            SimRank(Graph * graph);
            ~SimRank();
        public:
            bool init();
            void calcSimRank(uint32_t step);

        private:
            Graph * graph_;
    };
}

#endif //_SIMRANK_H_
