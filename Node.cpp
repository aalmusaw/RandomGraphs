/**
 * Implementation of a graph node
 *
 * @author Ali Al-Musawi
 */

#include "Node.h"
#include <iostream>

// default constructor
template<class Label, class Data>
Node<Label, Data>::Node() {
	Label label;
	Data data;
}

// class constructor
template<class Label, class Data>
Node<Label, Data>::Node(Label node_label, Data node_data) {
	data = node_data;
	label = node_label;
}

// class destructor
template<class Label, class Data>
Node<Label, Data>::~Node() {

}

// mutator methods
template<class Label, class Data>
void Node<Label, Data>::set_label(Label node_label) {
	label = node_label;
}

template<class Label, class Data>
void Node<Label, Data>::set_data(Data node_data) {
	data = node_data;
}

// accessor methods
template<class Label, class Data>
Label Node<Label, Data>::get_label() {
	return label;
}

template<class Label, class Data>
Data Node<Label, Data>::get_data() {
	return data;
}

template<class Label, class Data>
void Node<Label, Data>::print_node() {
	std::cout << "(" << label << ")";
}

template class Node<int, int> ;
template class Node<int, double> ;
template class Node<int, float> ;
template class Node<int, char> ;
template class Node<int, bool> ;
template class Node<char, int> ;
template class Node<char, double> ;
template class Node<char, float> ;
template class Node<char, char> ;
template class Node<char, bool> ;
template class Node<bool, int> ;
template class Node<bool, double> ;
template class Node<bool, float> ;
template class Node<bool, char> ;
template class Node<bool, bool> ;
