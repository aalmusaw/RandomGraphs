#include "Edge.h"
#include "GraphIllegalAccessException.h"

/**
 * Implementation of a weighted graph edge
 *
 * @author Ali Al-Musawi
 */

// Default Constructor
template<class Weight, class Label, class Data>
Edge<Weight, Label, Data>::Edge() {
	this->first_endpoint = 0;
	this->second_endpoint = 0;
	this->weight = 0;
}

// Class Constructor
template<class Weight, class Label, class Data>
Edge<Weight, Label, Data>::Edge(Weight edge_weight, Node<Label, Data> *end1,
		Node<Label, Data> *end2) {
	weight = edge_weight;
	first_endpoint = end1;
	second_endpoint = end2;
}

// Class Destructor
template<class Weight, class Label, class Data>
Edge<Weight, Label, Data>::~Edge() {
}

// Mutator Methods
template<class Weight, class Label, class Data>
void Edge<Weight, Label, Data>::set_weight(Weight edge_weight) {
	weight = edge_weight;
}

template<class Weight, class Label, class Data>
void Edge<Weight, Label, Data>::reset_end(Node<Label, Data> *node,
		bool first_endpoint) {
	if (first_endpoint)
		this->first_endpoint = node;
	else
		this->second_endpoint = node;
}

// Accessor Methods
template<class Weight, class Label, class Data>
Weight Edge<Weight, Label, Data>::get_weight() {
	return weight;
}

template<class Weight, class Label, class Data>
Node<Label, Data>* Edge<Weight, Label, Data>::get_end(bool first_endpoint) {
	if (first_endpoint)
		return this->first_endpoint;
	else
		return this->second_endpoint;
}

template class Edge<int, int, int> ;
template class Edge<int, int, double> ;
template class Edge<int, int, float> ;
template class Edge<int, int, char> ;
template class Edge<int, int, bool> ;
template class Edge<int, char, int> ;
template class Edge<int, char, double> ;
template class Edge<int, char, float> ;
template class Edge<int, char, char> ;
template class Edge<int, char, bool> ;
template class Edge<int, bool, int> ;
template class Edge<int, bool, double> ;
template class Edge<int, bool, float> ;
template class Edge<int, bool, char> ;
template class Edge<int, bool, bool> ;
template class Edge<double, int, int> ;
template class Edge<double, int, double> ;
template class Edge<double, int, float> ;
template class Edge<double, int, char> ;
template class Edge<double, int, bool> ;
template class Edge<double, char, int> ;
template class Edge<double, char, double> ;
template class Edge<double, char, float> ;
template class Edge<double, char, char> ;
template class Edge<double, char, bool> ;
template class Edge<double, bool, int> ;
template class Edge<double, bool, double> ;
template class Edge<double, bool, float> ;
template class Edge<double, bool, char> ;
template class Edge<double, bool, bool> ;
