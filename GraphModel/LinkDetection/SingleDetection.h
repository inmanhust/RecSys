#ifndef __SINGLE__DETECTION_H__
#define __SINGLE__DETECTION_H__
namespace CommunityDetection
{
    class SingleDetection
    {
    public:
        SingleDetection(Graph * graph);
        SingleDetection(Graph * graph, double gamma, uint32_t iterations);
    public:
        uint32_t findCommunities(set<Community*>& communities);
    public:
        Graph * graph_;
        CommunityPool * pool;
        double gamma_;
        uint32_t iterations_;
    };
}

#endif //__SINGLE__DETECTION_H__
