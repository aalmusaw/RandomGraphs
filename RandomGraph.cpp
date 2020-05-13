#include "RandomGraph.h"
#include "RandomEdge.h"
#include <ctime>
#include <limits>
#include <random>

// helper function to produce a random number between 0 and 1
double probability() {
	std::default_random_engine generator(std::rand());
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	return distribution(generator);
}

// Default Constructor
RandomGraph::RandomGraph() :
		density { probability() } {
	std::srand(time(0));
	for (unsigned int i = 0; i < DEFAULT_NODES; ++i) {
		Node<int, int> *node = new Node<int, int>(i,
				std::numeric_limits<int>::max());
		insert_node(node);
	}
	for (unsigned int i = 0; i < DEFAULT_NODES; ++i) {
		for (unsigned int j = i; j < DEFAULT_NODES; ++j) {
			if (i != j) {
				if (probability() < density) {
					unsigned int seed = std::rand();
					RandomEdge<int, int> *edge1 = new RandomEdge<int, int>(
							get_node(i), get_node(j), 0,
							std::numeric_limits<int>::max(), seed);
					insert_edge(edge1);
					RandomEdge<int, int> *edge2 = new RandomEdge<int, int>(
							get_node(j), get_node(i), 0,
							std::numeric_limits<int>::max(), seed);
					insert_edge(edge2);
				}
			}
		}
	}

}

RandomGraph::RandomGraph(unsigned int size, double density, int min_weight,
		int max_weight, bool directed, bool loops) :
		density { density } {
	std::srand(time(0));
	for (unsigned int i = 0; i < size; ++i) {
		Node<int, int> *node = new Node<int, int>(i,
				std::numeric_limits<int>::max());
		insert_node(node);
	}
	if (directed) {
		for (unsigned int i = 0; i < size; ++i) {
			for (unsigned int j = 0; j < size; ++j) {
				if (!loops) {
					if (i != j) {
						if (probability() < density) {
							RandomEdge<int, int> *edge =
									new RandomEdge<int, int>(get_node(i),
											get_node(j), min_weight, max_weight,
											std::rand());
							insert_edge(edge);
						}
					}
				}
				// allow self-loops
				else {
					if (probability() < density) {
						RandomEdge<int, int> *edge = new RandomEdge<int, int>(
								get_node(i), get_node(j), min_weight,
								max_weight, std::rand());
						insert_edge(edge);
					}
				}
			}
		}
	}
	// Undirected Graph, i.e. Bidirectional
	else {
		for (unsigned int i = 0; i < size; ++i) {
			for (unsigned int j = i; j < size; ++j) {
				if (!loops) {
					if (i != j) {
						if (probability() < density) {
							unsigned int seed = std::rand();
							RandomEdge<int, int> *edge1 = new RandomEdge<int,
									int>(get_node(i), get_node(j), min_weight,
									max_weight, seed);
							insert_edge(edge1);
							RandomEdge<int, int> *edge2 = new RandomEdge<int,
									int>(get_node(j), get_node(i), min_weight,
									max_weight, seed);
							insert_edge(edge2);
						}
					}
				} else {
					if (probability() < density) {
						unsigned int seed = std::rand();
						RandomEdge<int, int> *edge1 = new RandomEdge<int, int>(
								get_node(i), get_node(j), min_weight,
								max_weight, seed);
						insert_edge(edge1);
						RandomEdge<int, int> *edge2 = new RandomEdge<int, int>(
								get_node(j), get_node(i), min_weight,
								max_weight, seed);
						insert_edge(edge2);
					}
				}
			}
		}
	}
}
// Class Destructor
RandomGraph::~RandomGraph() {
}

