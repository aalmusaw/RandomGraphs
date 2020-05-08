#include "GraphInvalidInsertionException.h"

GraphInvalidInsertionException::GraphInvalidInsertionException() {
}

const char* GraphInvalidInsertionException::what() const throw() {
	return "Graph Invalid Insertion: You have tried to insert an Edge \n"
			"with Nodes that do not exist in this Graph.";
}
