#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include "Edge.h"

/**
 * A weighted graph
 *
 * @tparam Weight the class of the Graph's Edge weight
 * @tparam Label the class of the Graph's Node label
 * @tparam Data the class of the Graph's Node data
 */
template<class Weight, class Label, class Data>
class Graph {
public:

	/**
	 * Default Constructor
	 *
	 * Generates an empty graph
	 */
	Graph();

	/**
	 * Class Destructor
	 */
	virtual ~Graph();

	/**
	 * Helper Method: Indicates whether a node exists in a graph
	 *
	 * @param n a pointer to Node to search for in this graph
	 * @param graph a pointer to Graph to search in
	 * @return true if node is in this graph
	 */
	template<class W, class L, class D>
	friend bool node_exists(Node<L, D> *node, Graph<W, L, D> *g);

	/**
	 * Helper Method: Indicates whether an edge exists in a graph
	 *
	 * @param from a pointer to Node forming one end point of the Edge to look for
	 * @param to a pointer to Node forming another end point of the Edge to look for
	 * @param graph a pointer to Graph to search in
	 * @return true if edge is in this graph
	 */
	template<class W, class L, class D>
	friend bool edge_exists(Node<L, D> *from, Node<L, D> *to,
			Graph<W, L, D> *g);

	/**
	 * Retrieve a Node from this Graph
	 *
	 * @param node_label the label of the Node to get
	 * @return a pointer to the Node
	 * @throws GraphIllegalAccessException if the Node does not exist
	 */
	Node<Label, Data>* get_node(Label node_label);

	/**
	 * Retrieves a list of all Nodes in this Graph
	 *
	 * @return a Vector of pointers to Node for all Nodes in this Graph
	 */
	std::vector<Node<Label, Data>*> list_nodes();

	/**
	 * The size of this Graph
	 *
	 * @return the number of Nodes in this Graph
	 */
	unsigned int num_nodes();

	/**
	 * Retrieves an Edge in this Graph
	 *
	 * @param from a pointer to a Node in this Graph
	 * @param to a pointer to a Node in this Graph
	 * @return an Edge in this Graph connecting the supplied Nodes
	 *
	 * @throws GraphIllegalAccessException if the Edge is not in the Graph
	 */
	Edge<Weight, Label, Data>* get_edge(Node<Label, Data> *from,
			Node<Label, Data> *to);

	/**
	 * The number of Edges in this Graph
	 *
	 * @return the number of Edges in this Graph
	 */
	unsigned int num_edges();

	/**
	 * Checks if 2 Nodes are connected by an Edge in this Graph
	 *
	 * @param from a pointer to Node in this Graph
	 * @param to a pointer to Node in this Graph
	 * @return true if there is an Edge connecting the Nodes in this Graph
	 */
	bool is_adjacent(Node<Label, Data> *from, Node<Label, Data> *to);

	/**
	 * Lists all Nodes that are neighbours of the given Node
	 *
	 * @param node a pointer to Node whose neighbours are wanted
	 * @return a Vector of pointers to Node neighbouring the given Node
	 * @throws GraphIllegalAccessException if the given Node is not in the Graph
	 */
	std::vector<Node<Label, Data>*> neighbours(Node<Label, Data> *node);

	/**
	 * A text representation of the graph
	 *
	 * Displays the adjacency matrix
	 */
	void print_graph();

	/**
	 * Adds a Node to this Graph
	 *
	 * Replaces an existing Node if the Label is the same
	 *
	 * @param node a pointer to Node of the inserted Node
	 */
	void insert_node(Node<Label, Data> *node);

	/**
	 * Add an Edge to this Graph
	 *
	 * Replaces an existing Edge if the added Edge's endpoints are already connected
	 * @param edge a pointer to Edge of the inserted Edge
	 * @throws GraphInvalidInsertionException if at least one Node on this Edge
	 * 		does not exist in the Graph
	 */
	void insert_edge(Edge<Weight, Label, Data> *edge);

	/**
	 * Delete an Edge from this Graph
	 *
	 * If the supplies Edge is not in this Graph, nothing changes.
	 *
	 * @param edge a pointer to Edge of the Edge to delete
	 */
	void delete_edge(Edge<Weight, Label, Data> *edge);

protected:
	unsigned int nodes;
	unsigned int edges;
	std::vector<Node<Label, Data>*> node_list;
	std::vector<std::vector<Edge<Weight, Label, Data>*>> adjacency_list;
};

#endif /* GRAPH_H_ */
