#ifndef GRAPHILLEGALACCESSEXCEPTION_H_
#define GRAPHILLEGALACCESSEXCEPTION_H_

#include <bits/exception.h>

/**
 * An Edge Exception Class
 *
 * Thrown if a Graph is accessed through non-existent Edge/Node
 */
class GraphIllegalAccessException: public std::exception {
public:
	/**
	 * Default Constructor
	 */
	GraphIllegalAccessException();

	/**
	 * Generates Exception message
	 * @return the message of the exception
	 */
	virtual const char* what() const throw ();
};

#endif /* GRAPHILLEGALACCESSEXCEPTION_H_ */
