#include "RandomGraph.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	// create a Graph that holds int weights, with Nodes
	// labelled by char, and hold bool data
	Graph<int, char, bool> graph;
	// this is a pool for the label of the Nodes
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; ++i) {
		// create a Node dynamically and insert it
		Node<char, bool> *node = new Node<char, bool>(alphabet[i],
				static_cast<bool>(i % 2));
		graph.insert_node(node);
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = i; j < 26; ++j) {
			// get the nodes to use them to create edges
			Node<char, bool> *node1 = graph.get_node(alphabet[i]);
			Node<char, bool> *node2 = graph.get_node(alphabet[j]);
			// create an edge connecting the above nodes
			Edge<int, char, bool> *edge = new Edge<int, char, bool>(i * j,
					node1, node2);
			// insert the edge into the graph
			graph.insert_edge(edge);
		}
	}
	// display the graph
	graph.print_graph();

	// create two random graphs
	RandomGraph rgraph1;
	RandomGraph rgraph2;

	// print the two random graphs
	cout << "Random Graph 1: " << endl;
	rgraph1.print_graph();
	cout << "Random Graph 2: " << endl;
	rgraph2.print_graph();

	// create a random directed graph with density 0.1,
	// weight range 0-10, 50 Nodes, and allow self-loops
	RandomGraph rgraph3(50, 0.1, 0, 10, true, true);
	cout << "Random Graph 3: " << endl;
	rgraph3.print_graph();

	// create a random undirected graph with density 1,
	// weight range 0-100, 5 Nodes, and allow self-loops
	RandomGraph rgraph4(5, 0.1, 0, 100, false, true);
	cout << "Random Graph 4: " << endl;
	rgraph4.print_graph();

	// create a random undirected graph with density 1,
	// weight range 0-100, 10 Nodes, and no self-loops
	RandomGraph rgraph5(5, 0.1, 0, 10, false, false);
	cout << "Random Graph 5: " << endl;
	rgraph5.print_graph();

	// Connect Node 2 to 4 (and 4 to 3) in Graph 5 using weight = 30
	// note we do both directions to preserve bidirectionality
	Node<int, int> *node2 = rgraph5.get_node(2);
	Node<int, int> *node4 = rgraph5.get_node(4);
	Edge<int, int, int> *edge1 = new Edge<int, int, int>(30, node2, node4);
	Edge<int, int, int> *edge2 = new Edge<int, int, int>(30, node4, node2);
	rgraph5.insert_edge(edge1);
	rgraph5.insert_edge(edge2);

	// retrieve the contents of edge1 from the graph using nodes only!
	Edge<int, int, int> *my_edge = rgraph5.get_edge(node2, node4);
	int my_weight = my_edge->get_weight();
	cout << "weight is: " << my_weight << endl;

	// print the graph to see the effects of insertion
	// note there is a chance that nodes 2 and 4 are already connected!
	// in that case, we only have changed the edge weight
	cout << "Graph 5 after insertion: " << endl;
	rgraph5.print_graph();

	// delete the inserted edges and print graph
	cout << "Graph 5 after deletion: " << endl;
	rgraph5.delete_edge(edge1);
	rgraph5.delete_edge(edge2);
	rgraph5.print_graph();

	// any graph components made using pointers do not need to be deleted!
	// this is because at the end of main(), the destructor of class Graph
	// is called, and it deletes all the pointers we make here as long as they
	// a part of the graph (i.e. Node, Edge).

}

