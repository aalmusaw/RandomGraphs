/**
 * Implementation of a random weighted graph edge
 *
 * @author Ali Al-Musawi
 */

#include "RandomEdge.h"
#include <random>
#include <ctime>
#include <limits>

// Default Constructor
template<class Label, class Data>
RandomEdge<Label, Data>::RandomEdge() {
	seed = rand();
	min_weight = 0;
	max_weight = std::numeric_limits<int>::max();
	this->set_random_weight(seed);
}

// Class Constructor
template<class Label, class Data>
RandomEdge<Label, Data>::RandomEdge(Node<Label, Data> *end1,
		Node<Label, Data> *end2, int min_weight, int max_weight,
		unsigned int seed) :
		Edge<int, Label, Data>(0, end1, end2) {
	this->min_weight = min_weight;
	this->max_weight = max_weight;
	this->seed = seed;
	set_random_weight(seed);
}

// Class Destructor
template<class Label, class Data>
RandomEdge<Label, Data>::~RandomEdge() {
}

// Mutator Method
template<class Label, class Data>
void RandomEdge<Label, Data>::set_random_weight(unsigned int seed) {
	std::srand(seed);
	this->weight = std::rand() % (max_weight - min_weight) + min_weight;
}

template class RandomEdge<int, int> ;
