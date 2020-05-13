#include "GraphIllegalAccessException.h"

GraphIllegalAccessException::GraphIllegalAccessException() {
}

const char* GraphIllegalAccessException::what() const throw () {
	return "Graph Illegal Access: You have tried to access a Node/Edge \n"
			"that does not exist in this Graph.";
}
