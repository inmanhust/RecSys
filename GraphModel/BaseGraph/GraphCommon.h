#ifndef __GRAPH__CONMON_H__
#define __GRAPH__CONMON_H__

#include <stdint.h>
#include <string>

namespace GraphModel
{
    typedef uint32_t VertexId;
    const VertexId ERROR_VERTEX_ID = 0;

    int VertexIdComp(const VertexId& vid1, const VertexId& vid2)
    {
        if (vid1 == vid2) return 0;
        else if (vid1 < vid2) return -1;
        else return 1;  
    }
}

#endif //__GRAPH__CONMON_H__
