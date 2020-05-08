#ifndef GRAPHINVALIDINSERTIONEXCEPTION_H_
#define GRAPHINVALIDINSERTIONEXCEPTION_H_

#include <bits/exception.h>

/**
 * An Edge Exception Class
 *
 * Thrown if an Edge is inserted into a Graph and
 * at least 1 Node on the Edge is not in the Graph
 */
class GraphInvalidInsertionException: public std::exception {
public:
	/**
	 * Default Constructor
	 */
	GraphInvalidInsertionException();

	/**
	 * Generates Exception message
	 * @return the message of the exception
	 */
	virtual const char* what() const throw ();
};

#endif /* GRAPHINVALIDINSERTIONEXCEPTION_H_ */
