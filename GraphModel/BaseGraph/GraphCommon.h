#ifndef __GRAPH__CONMON_H__
#define __GRAPH__CONMON_H__

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <stddef.h>
//#include <ext/hash_map>
//using namespace __gnu_cxx;

namespace GraphModel
{
    #ifdef STRING_VERTEXID
    typedef std::string VertexId;
    const VertexId ERROR_VERTEX_ID = "ADJ_VERTEX_ERROR";
    #else
    typedef uint32_t VertexId;
    const VertexId ERROR_VERTEX_ID = 0;
    #endif

    inline int VertexIdComp(const VertexId& vid1, const VertexId& vid2)
    {
        if (vid1 == vid2) return 0;
        else if (vid1 < vid2) return -1;
        else return 1;  
    }
}
#endif //__GRAPH__CONMON_H__
