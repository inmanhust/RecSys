#ifndef __MODULARITY__H__
#define __MODULARITY__H__

namespace CommunityDetection
{
    class Modularity
    {
    public static double getQualityScore(const Graph * graph, set<Community*> communities, double gamma) const;
    };
}

#endif //__MODULARITY__H__
