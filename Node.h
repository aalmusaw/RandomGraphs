#ifndef NODE_H_
#define NODE_H_
#include <iostream>
/**
 * A labelled node in graph that stores data
 *
 * @tparam Label the class of the node label
 * @tparam Data the class of the node data
 */
template<class Label, class Data>
class Node {
public:
	/**
	 * Default Constructor
	 *
	 * The member fields are initialized to default value.
	 */
	Node();

	/**
	 * Class Constructor
	 *
	 * @param node_label the name of the node
	 * @param node_data the data to store in the node
	 */
	Node(Label node_label, Data node_data);

	/**
	 * Class Destructor
	 */
	virtual ~Node();

	/**
	 * Changes the label of the node
	 *
	 * @param node_label the new label of the node
	 */
	void set_label(Label node_label);

	/**
	 * Changes the data stored in the node
	 *
	 * @param node_data the data to store in the node
	 */
	void set_data(Data node_data);

	/**
	 * A method to retrieve the node label
	 *
	 * @returns the label of this node
	 */
	Label get_label();

	/**
	 * A method to retrieve the node data
	 *
	 * @returns the data stored in this node
	 */
	Data get_data();

	/**
	 * A text representation of the Node
	 */
	void print_node();

private:
	Label label;  // node label
	Data data;  // node data
};

#endif /* NODE_H_ */
