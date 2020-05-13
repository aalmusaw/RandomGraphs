#ifndef RANDOMGRAPH_H_
#define RANDOMGRAPH_H_

#include "Graph.h"

/**
 * A derived specialized template class
 *
 * Edges are randomly generated according to a density between 0 and 1.
 * If density = 1, a clique is generated. If density = 0, no edge is in the graph.
 * Nodes are labelled sequentially by integers, and their data are initialized to
 * MAX_INT in <limits>.
 */
class RandomGraph: public Graph<int, int, int> {
public:
	const unsigned int DEFAULT_NODES = 50;
	/**
	 * Default Constructor
	 *
	 * Generates an undirected graph with the minimum (50) number of nodes,
	 * sets the graph density randomly, and the edge weights range
	 * between 0 and MAX_INT in <limits>
	 */
	RandomGraph();

	/**
	 * Class Constructor
	 *
	 * @param size the number of nodes
	 * @param density the ratio of the number of edges to the maximum possible
	 * 		number of edges in a simple graph
	 * @param min_weight the minimum weight of an edge
	 * @param max_weight the maximum weight of an edge
	 * @param directed true if the generated graph has directed edges
	 * @param loops true if the generated graph can contain self-loops
	 */
	RandomGraph(unsigned int size, double density, int min_weight,
			int max_weight, bool directed, bool loops);

	/**
	 * Class Destructor
	 */
	virtual ~RandomGraph();

protected:
	double density;
};

#endif /* RANDOMGRAPH_H_ */
