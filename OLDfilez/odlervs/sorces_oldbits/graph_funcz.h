

template <class graph_type>

void Nav_graph_node_edgez(graph_type& graph)







#ifndef GRAPH_FUNCZ_H
 #define GRAPH_FUNCZ_H

//----------------------- CreateAllPairsTable ---------------------------------
//
// creates a lookup table encoding the shortest path info between each node
// in a graph to every other
//-----------------------------------------------------------------------------
template <class graph_type>
std::vector<std::vector<int> > CreateAllPairsTable(const graph_type& G)
{
 enum {no_path = -1};

 std::vector<int> row(G.NumNodes(), no_path);

 std::vector<std::vector<int> > ShortestPaths(G.NumNodes(), row);

 for (int source=0; source<G.NumNodes(); ++source)
 {
   //calculate the SPT for this node
   Graph_SearchDijkstra<graph_type> search(G, source);

   std::vector<const graph_type::edge_type*> spt = search.GetSPT();

   //now we have the SPT it's easy to work backwards through it to find
   //the shortest paths from each node to this source node
   for (int target = 0; target<G.NumNodes(); ++target)
   {
     //if the source node is the same as the target just set to target
     if (source == target)
     {
       ShortestPaths[source][target] = target;
     }

     else
     {
       int nd = target;

       while ((nd != source) && (spt[nd] != 0))
       {
         ShortestPaths[spt[nd]->From][target]= nd;

         nd = spt[nd]->From;
       }
     }
   }//next target node
 }//next source node

 return ShortestPaths;
}
//tempalted functions from

-- WeightNavGraphNodeEdges -------------------------
//
//  Given a cost value and an index to a valid node this function examines
//  all a node's edges, calculates their length, and multiplies
//  the value with the weight. Useful for setting terrain costs.
//------------------------------------------------------------------------

void WeightNavGraphNodeEdges(graph_type& graph, int node, double weight)
{
 //make sure the node is present
 assert(node < graph.NumNodes());

 //set the cost for each edge
 graph_type::ConstEdgeIterator ConstEdgeItr(graph, node);
 for (const graph_type::EdgeType* pE=ConstEdgeItr.begin();
      !ConstEdgeItr.end();
      pE=ConstEdgeItr.next())
 {
   //calculate the distance between nodes
   double dist = Vec2DDistance(graph.GetNode(pE->From()).Pos(),
                              graph.GetNode(pE->To()).Pos());

   //set the cost of this edge
   graph.SetEdgeCost(pE->From(), pE->To(), dist * weight);

   //if not a digraph, set the cost of the parallel edge to be the same
   if (!graph.isDigraph())
   {
     graph.SetEdgeCost(pE->To(), pE->From(), dist * weight);
   }
 }
}

//----------------------- CreateAllPairsCostsTable -------------------------------
//
//  creates a lookup table of the cost associated from traveling from one
//  node to every other
//-----------------------------------------------------------------------------
template <class graph_type>
std::vector<std::vector<double> > CreateAllPairsCostsTable(const graph_type& G)
{
 //create a two dimensional vector
 std::vector<double> row(G.NumNodes(), 0.0);
 std::vector<std::vector<double> > PathCosts(G.NumNodes(), row);

 for (int source=0; source<G.NumNodes(); ++source)
 {
   //do the search
   Graph_SearchDijkstra<graph_type> search(G, source);

   //iterate through every node in the graph and grab the cost to travel to
   //that node
   for (int target = 0; target<G.NumNodes(); ++target)
   {
     if (source != target)
     {
       PathCosts[source][target]= search.GetCostToNode(target);
     }
   }//next target node

 }//next source node

 return PathCosts;
}

#endif
