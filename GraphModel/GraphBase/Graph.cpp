#include "GraphInterface.h"
#include "GraphCommon/CommonTools.h"
#include <fstream>
#include <iostream>
using namespace std;

namespace GraphModel
{
    Graph::Graph(){}
    Graph::~Graph(){}

    bool Graph::isVertexExist(Vertex * vertex) const
    {
        map<uint32_t, Vertex *>::const_iterator iter = vertex_map_.find(vertex->vid_);
        if(iter == vertex_map_.end())
            return true;
        else
            return false;
    }

    bool Graph::addEdge(Vertex * f_vertex, Vertex * t_vertex)
    {
/*
        if(*f_vertex == *t_vertex)
        {
            fprintf(stderr, "[Info][same vertex, vertex id:\t%u]\n", f_vertex->getID());
            return false;
        }

        if(!isVertexExist(f_vertex))
        {
            vertex_map_.insert(pair<uint32_t, Vertex *>(f_vertex->getID(),f_vertex));
        }

        if(!isVertexExist(t_vertex))
        {
            vertex_map_.insert(pair<uint32_t, Vertex *>(t_vertex->getID(),t_vertex));
        }

        if(f_vertex->isAdjVertex(t_vertex))
        {
            fprintf(stderr,"[Info][edge is exist]\n");
            return false;
        }

       Edge * edge = new Edge(f_vertex->getID(), t_vertex->getID());
       f_vertex->addEdge(edge);
       t_vertex->addEdge(edge);
       edge_set_.insert(edge);
*/
       return true;
    }



    bool Graph::addEdge(VERTEX_TYPE_T f_vertex_id, VERTEX_TYPE_T t_vertex_id)
    {
        if(f_vertex_id == t_vertex_id)
        {
            fprintf(stderr, "[Info][same vertex, vertex id:\t%u]\n", f_vertex_id);
            return false;
        }

        Vertex * f_vertex;
        Vertex * t_vertex;
        map<uint32_t, Vertex *>::iterator iter = vertex_map_.find(f_vertex_id);
        if(iter == vertex_map_.end())
        {
            f_vertex = new Vertex(f_vertex_id);
            vertex_map_.insert(pair<uint32_t, Vertex *>(f_vertex_id,f_vertex));
        }
        else
        {
            f_vertex = iter->second;
        }

        iter = vertex_map_.find(t_vertex_id);
        if(iter == vertex_map_.end())
        {
            t_vertex = new Vertex(t_vertex_id);
            vertex_map_.insert(pair<uint32_t, Vertex *>(t_vertex_id,t_vertex));
        }
        else
        {
            t_vertex = iter->second;
        }

        if(f_vertex->isAdjVertex(t_vertex))
        {
            fprintf(stderr,"[Info][edge is exist]\n");
            return false;
        }

        Edge * edge = new Edge(f_vertex->vid_, t_vertex->vid_);
        f_vertex->addEdge(edge);
        t_vertex->addEdge(edge);
        edge_set_.insert(edge);

        return true;
    }

    bool Graph::readGraph(const char * filepath)
    {
        ifstream fin(filepath);
        if(!fin)
        {
            fprintf(stderr, "[error][Can not Open file: %s]\n",filepath);
            return false;
        }

        string line;
        vector<string> fields;
        while(getline(fin, line))
        {
            split_string(line,'\t',&fields);
            if(fields.size() != 2)
                continue;

            int f_vertex_id = atoi(fields[0].c_str());
            int t_vertex_id = atoi(fields[1].c_str());

            addEdge(f_vertex_id, t_vertex_id);
        }

        fin.close();
        return true;
    }

    void Graph::printGraphInfo() const
    {
        cout << "Total Node Num:\t" << vertex_map_.size() << endl;
        cout << "Total Edge Num:\t" << edge_set_.size() << endl;
        return;
        cout << "Vertex are as follows:" << endl;
        map<VERTEX_TYPE_T, Vertex*>::const_iterator map_iter = vertex_map_.begin();
        while(map_iter != vertex_map_.end())
        {
            cout << "vertex id: " << map_iter->first << endl;
            map_iter ++;
        }

        cout << "Edge are as follows:"<< endl;
        set<Edge*, EdgeLess<Edge*> >::iterator iter = edge_set_.begin();       
        while(iter != edge_set_.end())
        {
            cout << (*iter)->front_vertex_id_ << "\t" << (*iter)->tail_vertex_id_ << endl;
            iter++;
        }
    }
}
