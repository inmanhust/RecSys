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
    typedef uint32_t VertexId;
    const VertexId ERROR_VERTEX_ID = 0;

    inline int VertexIdComp(const VertexId& vid1, const VertexId& vid2)
    {
        if (vid1 == vid2) return 0;
        else if (vid1 < vid2) return -1;
        else return 1;  
    }

#ifdef String_VertexId
    struct StrHash
    {
        size_t operator()(const VertexId& vid) const
        {
			get_md5_64(vid.c_str());
            //return __gnu_cxx::__stl_hash_string(vid.c_str());
        }
    };

    struct StrEqual
    {
        bool operator()(const VertexId& vid1, const VertexId& vid2) const
        {
            return VertexIdComp(vid1, vid2) == 0;
        }
    };
#endif
}
#endif //__GRAPH__CONMON_H__
