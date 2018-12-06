//Map_graph.h

#ifndef MAP_GRAPH_H
#define MAP_GRAPH_H

template <class node_type, class edge_type>
class Map_graph
{
public:
typedef edge_type Edge_Type;
typedef node_type Node_Type;

typedef std::vector<node_type> node_vec;
typedef std::list<edge_type> edgle_list;
typedef std::vector<edgle_list> edge_list_vec;

private:

node_vec      _nodez;
edge_list_vec _edgez;
int           _next_node_index;
bool unique_edge(int from, int to)const;

public:

Map_graph(): _next_node_index(0){}

~Map_graph()

 const Node_Type& get_node(int idx)const;
 Node_Type& get_node(int idx);

 const Edge_Type&  get_edge(int from,  in to) const;
  Edge_Type& get_edge(int from,int to);

    int   GetNextFreeNodeIndex()const{return _next_node_index ;}

    int   AddNode(node_type node);

    void RemoveNode(int node);
void Set_line_Distance(int from, int to, double distance);

int NumNodes()const{return node_vec.size();}

int   NumActiveNodes()const
  {
    int count = 0;

    for (unsigned int n=0; n<node_vec.size(); ++n) if (node_vec[n].Index() != -1) ++count;

    return count;
}


int   NumEdges()const
{
  int tot = 0;

  for (edge_list_vec::const_iterator curEdge = _edgez.begin();
       curEdge != _edgez.end();
       ++curEdge)
  {
    tot += curEdge->size();
  }

  return tot;
}

 bool	isEmpty()const
 {return m_Nodes.empty();}

 bool isNodePresent(int nd)const;

 bool isEdgePresent(int from, int to)const;

 void Clear(){ _next_node_index = 0; _nodez.clear(); _edges.clear();}



void RemoveEdges()
  {
    for (EdgeListVector::iterator it = _edgez.begin(); it != _edgez.end(); ++it)
    {
      it->clear();
    }
}

}


class EdgeIterator
      {
      private:

        typename EdgeList::iterator         curEdge;

        Map_graph<node_type, edge_type>&  G;

        const int  NodeIndex;

public:




#endif
