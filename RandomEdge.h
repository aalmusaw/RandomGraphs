#ifndef RANDOMEDGE_H_
#define RANDOMEDGE_H_

#include "Edge.h"

/**
 * A derived specialized template class
 *
 * Edge weights are sampled from a distribution
 */
template<class Label, class Data>
class RandomEdge: public Edge<int, Label, Data> {
public:
	/**
	 * Default Constructor
	 *
	 * Generates an edge randomly.
	 * The range of the weights is within the supported
	 * integers.
	 */
	RandomEdge();

	/**
	 * Class Constructor
	 *
	 * @param end1 a pointer to a node on one end
	 * @param end2 a pointer to a node on the other end
	 * @param min_weight a minimum bound on the generated weight
	 * @param max_weight a maximum bound on the generated weight
	 * @param seed a seed for reproducibility
	 */
	RandomEdge(Node<Label, Data> *end1, Node<Label, Data> *end2, int min_weight,
			int max_weight, unsigned int seed);

	/**
	 * Class Destructors
	 */
	virtual ~RandomEdge();

	/**
	 * Resets the weight of this edge randomly
	 *
	 * The range of the weight is established during construction
	 * @param seed a seed for reproducibility
	 */
	void set_random_weight(unsigned int seed);

protected:
	int min_weight;
	int max_weight;
	unsigned int seed;
};

#endif /* RANDOMEDGE_H_ */
