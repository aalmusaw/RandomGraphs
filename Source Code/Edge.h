#ifndef EDGE_H_
#define EDGE_H_

#include "Node.h"

/**
 * A weighted edge in a graph
 *
 * @tparam Weight the class of the edge weight
 * @tparam Label the class of an edge's node label
 * @tparam Data the class of an edge's node data
 *
 */
template<class Weight, class Label, class Data>
class Edge {
public:
	/**
	 * Default Constructor
	 *
	 * Generates an Edge with NULL Node pointers.
	 * The weight is set to 0.
	 */
	Edge();

	/**
	 * Class Constructor
	 *
	 * @param edge_weight the weight of this edge
	 * @param end1 a pointer to a node on one end
	 * @param end2 a pointer to a node on the other end
	 */
	Edge(Weight edge_weight, Node<Label, Data> *end1, Node<Label, Data> *end2);

	/**
	 * Class Destructor
	 */
	virtual ~Edge();

	/**
	 * Sets the weight of this edge
	 *
	 * @param edge_weight the weight to set for this edge
	 */
	void set_weight(Weight edge_weight);

	/**
	 * Sets a node to one end of this edge
	 *
	 * @param node a reference to the Node to append to this edge
	 * @param first_endpoint true if node replaces the first_endpoint
	 * 		and false if the node replaces the second_endpoint
	 */
	void reset_end(Node<Label, Data> *node, bool first_endpoint);

	/**
	 * Retrieves the weight of this edge
	 *
	 * @return the weight of this edge
	 */
	Weight get_weight();

	/**
	 * Retrieves a node from one end of this edge
	 *
	 * @param first_endpoint true if the node wanted is
	 * 		the first endpoint, otherwise the second
	 * 		endpoint is returned
	 * @return a pointer to the node specified on this edge
	 */
	Node<Label, Data>* get_end(bool first_endpoint);

protected:
	Weight weight;
	Node<Label, Data> *first_endpoint;
	Node<Label, Data> *second_endpoint;
};

#endif /* EDGE_H_ */
