#include "Graph.h"
#include "GraphIllegalAccessException.h"
#include "GraphInvalidInsertionException.h"
#include <vector>

/**
 * Implementation of a weighted graph
 *
 * @author Ali Al-Musawi
 */

// Default Constructor
template<class Weight, class Label, class Data>
Graph<Weight, Label, Data>::Graph() {
	nodes = edges = 0;
}

// Class Destructor
template<class Weight, class Label, class Data>
Graph<Weight, Label, Data>::~Graph() {
	for (auto vector : adjacency_list) {
		for (auto edge : vector) {
			delete edge;
		}
		vector.clear();
	}
	adjacency_list.clear();
	for (auto node : node_list) {
		delete node;
	}
	node_list.clear();
}

// helper function
template<class W, class L, class D>
bool node_exists(Node<L, D> *node, Graph<W, L, D> *graph) {
	for (auto n : (graph->node_list)) {
		if (n->get_label() == node->get_label())
			return true;
	}
	return false;
}

// helper function
template<class W, class L, class D>
bool edge_exists(Node<L, D> *from, Node<L, D> *to, Graph<W, L, D> *graph) {
	for (auto vector : graph->adjacency_list) {
		// if the first has the same 'from' node as the supplied edge
		// then this is where it should be
		if (vector.size() > 0) {
			if (vector[0]->get_end(true)->get_label() == from->get_label()) {
				// return the edge that has the same 'to' node as the supplied edge
				for (auto edge : vector) {
					if (edge->get_end(false)->get_label() == to->get_label())
						return true;
				}
			}
		}
	}
	return false;
}

// Accessor Methods
template<class Weight, class Label, class Data>
Node<Label, Data>* Graph<Weight, Label, Data>::get_node(Label node_label) {
	// a node exists in this graph if the same label is found
	for (auto node : node_list) {
		if (node->get_label() == node_label)
			return node;
	}
	// since no such node exists, throw an exception
	GraphIllegalAccessException e;
	throw e;
}

template<class Weight, class Label, class Data>
std::vector<Node<Label, Data>*> Graph<Weight, Label, Data>::list_nodes() {
	return node_list;
}

template<class Weight, class Label, class Data>
unsigned int Graph<Weight, Label, Data>::num_nodes() {
	return nodes;
}

template<class Weight, class Label, class Data>
Edge<Weight, Label, Data>* Graph<Weight, Label, Data>::get_edge(
		Node<Label, Data> *from, Node<Label, Data> *to) {
	// search through the adjacency list
	for (auto vector : adjacency_list) {
		// if the first has the same 'from' node as the supplied edge
		// then this is where it should be
		if (vector.size() > 0) {
			if (vector[0]->get_end(true)->get_label() == from->get_label()) {
				// return the edge that has the same 'to' node as the supplied edge
				for (auto edge : vector) {
					if (edge->get_end(false)->get_label() == to->get_label())
						return edge;
				}
			}
		}
	}
	// since no edge with the same attributes is found, throw an exception
	GraphIllegalAccessException e;
	throw e;
}

template<class Weight, class Label, class Data>
unsigned int Graph<Weight, Label, Data>::num_edges() {
	return edges;
}

template<class Weight, class Label, class Data>
bool Graph<Weight, Label, Data>::is_adjacent(Node<Label, Data> *from,
		Node<Label, Data> *to) {
	// see if an edge exists between the given nodes
	try {
		// throws an exception if no such edge exists
		get_edge(from, to);
		return true;
	}
	// therefore it does not exist
	catch (const GraphIllegalAccessException &e) {
		return false;
	}

}

template<class Weight, class Label, class Data>
std::vector<Node<Label, Data>*> Graph<Weight, Label, Data>::neighbours(
		Node<Label, Data> *node) {
	// check if the node is in the graph
	if (node_exists(node, this)) {
		for (auto vector : adjacency_list) {
			// if the first edge has the same first endpoint, the list is found
			if (vector[0]->get_end(true)->get_label() == node->get_label()) {
				std::vector<Node<Label, Data>*> result;
				for (auto edge : vector) {
					result.push_back(edge->get_end(false));
				}
				return result;
			}
		}
	}
	GraphIllegalAccessException e;
	throw e;
}

template<class Weight, class Label, class Data>
void Graph<Weight, Label, Data>::print_graph() {
	std::cout << "Neighbourhhood of All Nodes in Graph: \n";
	for (unsigned int i = 0; i < nodes; ++i) {
		if (adjacency_list[i].size() > 0) {
			Node<Label, Data> *node = adjacency_list[i][0]->get_end(true);
			std::cout << "Node (" << node->get_label() << "): ";
			std::vector<Node<Label, Data>*> others = neighbours(node);
			if (others.size() > 0) {
				for (auto v : others) {
					std::cout << " " << v->get_label();
				}
			}
			std::cout << "\n";
		}
	}
}

// Mutator Methods

template<class Weight, class Label, class Data>
void Graph<Weight, Label, Data>::insert_node(Node<Label, Data> *node) {
	// if the node already exists, it must be replaced
	if (node_exists(node, this)) {
		// throws an exception if it is not there
		Node<Label, Data> *old = get_node(node->get_label());
		for (auto vector : adjacency_list) {
			for (auto edge : vector) {
				// replace all occurrences in the adjacency matrix
				if (edge->get_end(true)->get_label() == node->get_label()) {
					edge->reset_end(node, true);
				}
				if (edge->get_end(false)->get_label() == node->get_label()) {
					edge->reset_end(node, false);
				}
			}
		}
		// replace in the node list
		for (unsigned int i = 0; i < node_list.size(); ++i) {
			if (node_list[i]->get_label() == old->get_label()) {
				node_list[i] = node;
				break;
			}
		}

		// free memory
		delete old;
	}
	// append the node to the graph
	else {
		node_list.push_back(node);
		++nodes;
		std::vector<Edge<Weight, Label, Data>*> edge_list;
		adjacency_list.push_back(edge_list);
	}
}

template<class Weight, class Label, class Data>
void Graph<Weight, Label, Data>::insert_edge(Edge<Weight, Label, Data> *edge) {
	// replace the edge if it exists
	if (edge_exists(edge->get_end(true), edge->get_end(false), this)) {
		// throws an exception if it does not exist
		Edge<Weight, Label, Data> *old = get_edge(edge->get_end(true),
				edge->get_end(false));
		// since it exists, it must be replaced in the adjacency matrix
		for (unsigned int i = 0; i < adjacency_list.size(); ++i) {
			for (unsigned int j = 0; j < adjacency_list[i].size(); ++j) {
				if (adjacency_list[i][j] == old) {
					adjacency_list[i][j] = edge;
					delete old;
					return;
				}
			}
		}
	}
	// append the edge to the graph if possible
	else {
		if (node_exists(edge->get_end(true), this)
				&& node_exists(edge->get_end(false), this)) {
			Node<Label, Data> *from = get_node(
					edge->get_end(true)->get_label());
			// find where this edge should go in the adjacency list and place it there
			for (unsigned int i = 0; i < nodes; ++i) {
				if (adjacency_list[i].size() > 0) {
					if (adjacency_list[i][0]->get_end(true)->get_label()
							== from->get_label()) {
						adjacency_list[i].push_back(edge);
						++edges;
						// terminate function
						return;
					}
				}
			}
			// In case there is no place for this edge
			// pick any empty list and populate it!
			for (unsigned int i = 0; i < nodes; ++i) {
				if (adjacency_list[i].size() == 0) {
					adjacency_list[i].push_back(edge);
					++edges;
					break;
				}
			}
		}
		// At least one node node of this edge is not in this graph
		else {
			GraphInvalidInsertionException e2;
			throw e2;
		}

	}
}

template<class Weight, class Label, class Data>
void Graph<Weight, Label, Data>::delete_edge(Edge<Weight, Label, Data> *edge) {
	// see if this edge is already in this graph
	if (edge_exists(edge->get_end(true), edge->get_end(false), this)) {
		Edge<Weight, Label, Data> *old = get_edge(edge->get_end(true),
				edge->get_end(false));
		// remove it from the adjacency list
		for (unsigned int i = 0; i < nodes; ++i) {
			for (unsigned int j = 0; j < adjacency_list[i].size(); ++j) {
				if (adjacency_list[i][j] == old) {
					adjacency_list[i].erase(adjacency_list[i].begin() + j);
					delete old;
					--edges;
					return; // breaks out of the loop earlier
				}
			}
		}
	}
	// since the edge is not in this graph, nothing needs to be done
}

template class Graph<int, int, int> ;
template class Graph<int, int, double> ;
template class Graph<int, int, float> ;
template class Graph<int, int, char> ;
template class Graph<int, int, bool> ;
template class Graph<int, char, int> ;
template class Graph<int, char, double> ;
template class Graph<int, char, float> ;
template class Graph<int, char, char> ;
template class Graph<int, char, bool> ;
template class Graph<int, bool, int> ;
template class Graph<int, bool, double> ;
template class Graph<int, bool, float> ;
template class Graph<int, bool, char> ;
template class Graph<int, bool, bool> ;
template class Graph<double, int, int> ;
template class Graph<double, int, double> ;
template class Graph<double, int, float> ;
template class Graph<double, int, char> ;
template class Graph<double, int, bool> ;
template class Graph<double, char, int> ;
template class Graph<double, char, double> ;
template class Graph<double, char, float> ;
template class Graph<double, char, char> ;
template class Graph<double, char, bool> ;
template class Graph<double, bool, int> ;
template class Graph<double, bool, double> ;
template class Graph<double, bool, float> ;
template class Graph<double, bool, char> ;
template class Graph<double, bool, bool> ;
