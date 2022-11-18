/* @file: abstractqueue.h
 * Definition of a templated class queue
 * implementing A.D.T. Queue
 * @C - Galaxy Express Software
 *
 * Version 23.3.0
 */

/* ____________________
  /                    \
  | AbstractQueue Class |
  \____________________/

	PURPOSE: Defines Functionality of a Queue ADT.

	ERROR HANDLING: Whenever a function is given invalid parameter values
        it THROWS an 'Oops' object.

*/
#ifndef ABSTRACTQUEUE_H
#define ABSTRACTQUEUE_H

#include <string>

using namespace std;

/* 
================ 'Oops' Class  ===============================

PURPOSE: Class thrown whenever an error is encountered.
         Member 'm_errormsg' stores an error message.
*/
class Oops
{
	string m_errormsg;
public:
	Oops(const string &msg) : m_errormsg(msg) {}
	const string& getMsg() const
	{
		return m_errormsg;
	}
};


/* =============  Abstract Class AbstractQueue ================ */
template < typename T >
class AbstractQueue
{
public:
  // PURPOSE: Checks if a queue is empty
  // RETURNS: 'true' if the queue is empty
  //   'false' otherwise
	virtual bool isEmpty() const = 0;


  // PURPOSE: looks at the front of the queue
  // RETURNS: a reference to the element currently in front of the queue
  // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
  //   message!!!
	virtual const T& front() const throw (Oops) = 0;


  // PURPOSE: looks at the back of the queue
  // RETURNS: a reference to the element currently in the back of the queue
  // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
  //   message!!!
	virtual const T& back() const throw (Oops) = 0;


  // PURPOSE: enqueue an element into the queue
  // PARAMETERS: x is the item to add to the queue
  // POSTCONDITIONS: x is now the element at the end of the queue,
	virtual void enqueue(const T& x) = 0;


  // PURPOSE: dequeues an elemet from the queue
  // POSTCONDITIONS: the element formerly at the front of the queue has
  //     been removed.
  // NOTE: Dequeueing an empty queue results in an empty queue.
	virtual void dequeue() = 0;


  // PURPOSE: clears the queue
  // POSTCONDITIONS: the queue is now empty
	virtual void clear() = 0;


  // PURPOSE: Base destructor
	virtual ~AbstractQueue() {}

};

#endif
