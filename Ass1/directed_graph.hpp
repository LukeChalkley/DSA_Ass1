#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

//A large selection of data structures from the standard
//library. You need not feel compelled to use them all,
//but as you can't add any, they're all here just in case.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <cstddef>
#include <string>

//Forward declarations for classes below so they can be used below without worrying too much about the ordering.
template <typename vertex> class vertex_iterator;
template <typename vertex> class neighbour_iterator;
template <typename vertex> class directed_graph;


template <typename vertex>
class directed_graph
{
private:

  //You will need to add some data members here
  //to actually represent the graph internally,
  //and keep track of whatever you need to.


public:


  directed_graph(); //A constructor for directed_graph. The graph should start empty.
  ~directed_graph(); //A destructor. Depending on how you do things, this may
  //not be necessary.
  
  bool contains(const vertex&) const; //Returns true if the given vertex is in the graph, false otherwise.

  bool adjacent(const vertex&, const vertex&) const; //Returns true if the first vertex is adjacent to the second, false otherwise.

  void add_vertex(const vertex&); //Adds the passed in vertex to the graph (with no edges).
  void add_edge(const vertex&, const vertex&); //Adds an edge from the first vertex to the second.

  void remove_vertex(const vertex&); //Removes the given vertex. Should also clear any incident edges.
  void remove_edge(const vertex&, const vertex&); //Removes the edge between the two vertices, if it exists.

  std::size_t in_degree(const vertex&) const; //Returns number of edges coming in to a vertex.
  std::size_t out_degree(const vertex&) const; //Returns the number of edges leaving a vertex.
  std::size_t degree(const vertex&) const; //Returns the degree of the vertex (both in and out edges).
  
  std::size_t num_vertices() const; //Returns the total number of vertices in the graph.
  std::size_t num_edges() const; //Returns the total number of edges in the graph.

  std::vector<vertex> get_vertices(); //Returns a vector containing all the vertices.
  std::vector<vertex> get_neighbours(const vertex&); //Returns a vector containing the neighbours of the given vertex.

  vertex_iterator<vertex> begin(); //Returns a graph_iterator pointing to the start of the vertex set.
  vertex_iterator<vertex> end(); //Returns a graph_iterator pointing to one-past-the-end of the vertex set.

  neighbour_iterator<vertex> nbegin(const vertex&); //Returns a neighbour_iterator pointing to the start of the neighbour set for the given vertex.
  neighbour_iterator<vertex> nend(const vertex&); //Returns a neighbour_iterator pointing to one-past-the-end of the neighbour set for the given vertex.

  std::vector<vertex> depth_first(const vertex&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
  std::vector<vertex> breadth_first(const vertex&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

  directed_graph<vertex> out_tree(const vertex&); //Returns a spanning tree of the graph starting at the given vertex using the out-edges.
  directed_graph<vertex> in_tree(const vertex&); //Returns a spanning tree of the graph starting at the given vertex using the in-edges.

  bool reachable(const vertex&, const vertex&) const; //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.

};

//The vertex_iterator class provides an iterator
//over the vertices of the graph.
//This is one of the harder parts, so if you're
//not too comfortable with C++ leave this for last.
//If you are, there are many ways of doing this,
//as long as it passes the tests, it's okay.
//You may want to watch the videos on iterators before starting.
template <typename vertex>
class vertex_iterator {

private:

  //You may need data members here.

public:
  vertex_iterator(const vertex_iterator<vertex>&);
  vertex_iterator(const directed_graph<vertex>&, std::size_t);
  ~vertex_iterator();
  vertex_iterator<vertex> operator=(const vertex_iterator<vertex>&);
  bool operator==(const vertex_iterator<vertex>&) const;
  bool operator!=(const vertex_iterator<vertex>&) const;
  vertex_iterator<vertex> operator++();
  vertex_iterator<vertex> operator++(int);
  vertex operator*();
  vertex* operator->();
};

//The neighbour_iterator class provides an iterator
//over the neighbours of a given vertex. This is
//probably harder (conceptually) than the graph_iterator.
//Unless you know how iterators work.
template <typename vertex>
class neighbour_iterator {

private:

  //You may need data members here.

public:
  neighbour_iterator(const neighbour_iterator<vertex>&);
  neighbour_iterator(const directed_graph<vertex>&, const vertex&, std::size_t);
  ~neighbour_iterator();
  neighbour_iterator<vertex> operator=(const neighbour_iterator<vertex>&);
  bool operator==(const neighbour_iterator<vertex>&) const;
  bool operator!=(const neighbour_iterator<vertex>&) const;
  neighbour_iterator<vertex> operator++();
  neighbour_iterator<vertex> operator++(int);			
  vertex operator*();
  vertex* operator->();
};


//Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
//Although these are just the same names copied from above, you may find a few more clues in the full
//method headers. Note also that C++ is sensitive to the order you declare and define things in - you
//have to have it available before you use it.

template <typename vertex> directed_graph<vertex>::directed_graph() {}
template <typename vertex> directed_graph<vertex>::~directed_graph() {}
template <typename vertex> bool directed_graph<vertex>::contains(const vertex& u) const { return false; }
template <typename vertex> bool directed_graph<vertex>::adjacent(const vertex& u, const vertex& v) const { return false; }
template <typename vertex> void directed_graph<vertex>::add_vertex(const vertex& u) {}
template <typename vertex> void directed_graph<vertex>::add_edge(const vertex& u, const vertex& v) {}
template <typename vertex> void directed_graph<vertex>::remove_vertex(const vertex& u) {}
template <typename vertex> void directed_graph<vertex>::remove_edge(const vertex& u, const vertex& v) {}
template <typename vertex> std::size_t directed_graph<vertex>::in_degree(const vertex& u) const { return 0; }
template <typename vertex> std::size_t directed_graph<vertex>::out_degree(const vertex& u) const { return 0; }
template <typename vertex> std::size_t directed_graph<vertex>::degree(const vertex& u) const { return 0; }
template <typename vertex> std::size_t directed_graph<vertex>::num_vertices() const { return 0; }
template <typename vertex> std::size_t directed_graph<vertex>::num_edges() const { return 0; }
template <typename vertex> std::vector<vertex> directed_graph<vertex>::get_vertices() { return std::vector<vertex>(); }
template <typename vertex> std::vector<vertex> directed_graph<vertex>::get_neighbours(const vertex&) { return std::vector<vertex>(); }
template <typename vertex> vertex_iterator<vertex> directed_graph<vertex>::begin() { return vertex_iterator<vertex>(directed_graph<vertex>(), std::size_t()); }
template <typename vertex> vertex_iterator<vertex> directed_graph<vertex>::end() { return vertex_iterator<vertex>(directed_graph<vertex>(), std::size_t()); }
template <typename vertex> neighbour_iterator<vertex> directed_graph<vertex>::nbegin(const vertex& u) { return neighbour_iterator<vertex>(directed_graph<vertex>(), vertex(), std::size_t()); }
template <typename vertex> neighbour_iterator<vertex> directed_graph<vertex>::nend(const vertex& u) { return neighbour_iterator<vertex>(directed_graph<vertex>(), vertex(), std::size_t()); }
template <typename vertex> std::vector<vertex> directed_graph<vertex>::depth_first(const vertex& u) { return std::vector<vertex>(); }
template <typename vertex> std::vector<vertex> directed_graph<vertex>::breadth_first(const vertex& u) { return std::vector<vertex>(); }
template <typename vertex> directed_graph<vertex> directed_graph<vertex>::out_tree(const vertex& u) { return directed_graph<vertex>(); }
template <typename vertex> directed_graph<vertex> directed_graph<vertex>::in_tree(const vertex& u) { return directed_graph<vertex>(); }
template <typename vertex> bool directed_graph<vertex>::reachable(const vertex& u, const vertex& v) const { return false; }

template <typename vertex> vertex_iterator<vertex>::vertex_iterator(const vertex_iterator<vertex>& other) {}
template <typename vertex> vertex_iterator<vertex>::vertex_iterator(const directed_graph<vertex>& graph, std::size_t position) {}
template <typename vertex> vertex_iterator<vertex>::~vertex_iterator() {}
template <typename vertex> vertex_iterator<vertex> vertex_iterator<vertex>::operator=(const vertex_iterator<vertex>& other) { return vertex_iterator<vertex>(directed_graph<vertex>(), std::size_t()); }
template <typename vertex> bool vertex_iterator<vertex>::operator==(const vertex_iterator<vertex>& other) const { return false; }
template <typename vertex> bool vertex_iterator<vertex>::operator!=(const vertex_iterator<vertex>& other) const { return false; }
template <typename vertex> vertex_iterator<vertex> vertex_iterator<vertex>::operator++() { return vertex_iterator<vertex>(directed_graph<vertex>(), std::size_t()); }
template <typename vertex> vertex_iterator<vertex> vertex_iterator<vertex>::operator++(int) { return vertex_iterator<vertex>(directed_graph<vertex>(), std::size_t()); }
template <typename vertex> vertex vertex_iterator<vertex>::operator*() { return vertex(); }
template <typename vertex> vertex* vertex_iterator<vertex>::operator->() { return &vertex(); }

template <typename vertex> neighbour_iterator<vertex>::neighbour_iterator(const neighbour_iterator<vertex>& other) {}
template <typename vertex> neighbour_iterator<vertex>::neighbour_iterator(const directed_graph<vertex>& graph, const vertex& u, std::size_t position) {}
template <typename vertex> neighbour_iterator<vertex>::~neighbour_iterator() {}
template <typename vertex> neighbour_iterator<vertex> neighbour_iterator<vertex>::operator=(const neighbour_iterator<vertex>& other) { return neighbour_iterator<vertex>(directed_graph<vertex>(), vertex(), std::size_t()); }
template <typename vertex> bool neighbour_iterator<vertex>::operator==(const neighbour_iterator<vertex>& other) const { return false; }
template <typename vertex> bool neighbour_iterator<vertex>::operator!=(const neighbour_iterator<vertex>& other) const { return false; }
template <typename vertex> neighbour_iterator<vertex> neighbour_iterator<vertex>::operator++() { return neighbour_iterator<vertex>(directed_graph<vertex>(), vertex(), std::size_t()); }
template <typename vertex> neighbour_iterator<vertex> neighbour_iterator<vertex>::operator++(int) { return neighbour_iterator<vertex>(directed_graph<vertex>(), vertex(), std::size_t()); }		
template <typename vertex> vertex neighbour_iterator<vertex>::operator*() { return vertex(); }
template <typename vertex> vertex* neighbour_iterator<vertex>::operator->() { return &vertex(); }


#endif
