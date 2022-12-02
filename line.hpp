//Author: Logan Markley
//Assignment: HW4 (Queue)
//Class: CS1575
//Semester: Fall 2022
//Due Date: Fri, 12/2/22

#include "abstractqueue.h"
//#include "randomengine.h"
#include <iostream>

using namespace std;

template <typename T>
class Line;

template <typename T>
ostream& operator<<(ostream& os, const Line<T>& line);

template <typename T>
class Line : public AbstractQueue<T>
{
private:
    int m_size;                          // current number of elements
    int m_max;                           // maximum capacity of array m_data
    T* m_data;                           // array to store the customers
    
public:
    Line(int elementsInLine)
    {
        m_size = 0;
        m_max = elementsInLine+2;
        m_data = new T[m_max];
    }
    
    void grow()
    {
        int newMax = m_max * 2;
        T* tmp = new T[newMax];
        for(int i=0; i<m_size; i++)
        {
            tmp[i] = m_data[i];
        }
        delete [] m_data;
        m_data = tmp;
        tmp = NULL;
        m_max = newMax;
        return;
    }


    void shrink()
    {
        int newMax = m_max / 2;
        T* tmp = new T[newMax];
        for(int i=0; i<m_size; i++)
        {
            tmp[i] = m_data[i];
        }
        delete [] m_data;
        m_data = tmp;
        tmp = NULL;
        m_max = newMax;
        return;
    }
    
    
    T& retrieve(int index) const throw (Oops)
	{
	    if(isEmpty())
	        throw Oops("Queue is empty.");
	    if(index>=m_size)
	        throw Oops("That index is not valid.");
	    return m_data[index];
	}
    
    
  // PURPOSE: Checks if a queue is empty
  // RETURNS: 'true' if the queue is empty
  //   'false' otherwise
	bool isEmpty() const
	{
	    return m_size == 0;
	}


  // PURPOSE: looks at the front of the queue
  // RETURNS: a reference to the element currently in front of the queue
  // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
  //   message!!!
	const T& front() const throw (Oops)
	{
	    if(isEmpty())
	        throw Oops("Queue is empty.");
	    return m_data[0];
	}


  // PURPOSE: looks at the back of the queue
  // RETURNS: a reference to the element currently in the back of the queue
  // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
  //   message!!!
	const T& back() const throw (Oops)
	{
	    if(isEmpty())
	        throw Oops("Queue is empty.");
	    return m_data[m_size];
	}


  // PURPOSE: enqueue an element into the queue
  // PARAMETERS: x is the item to add to the queue
  // POSTCONDITIONS: x is now the element at the end of the queue,
	void enqueue(const T& x)
	{
	    m_data[m_size] = x; //places x at the end of the queue
	    m_size++;
        if(m_size == m_max) //grows the array size if needed
            grow();
	    return;
	}


  // PURPOSE: dequeues an elemet from the queue
  // POSTCONDITIONS: the element formerly at the front of the queue has
  //     been removed.
  // NOTE: Dequeueing an empty queue results in an empty queue.
	void dequeue()
    {
    	if(m_size==0) //dont do anything if queue is already empty.
            return;
        
        int tmpIndex = 0; //this is all for shifting data to the left one index
        while(tmpIndex<m_size-1)
        {
            m_data[tmpIndex] = m_data[tmpIndex+1];
            tmpIndex++;
        }
        m_size--;
        if(m_size < m_max/4)
            shrink();
        return;
	}


  // PURPOSE: clears the queue
  // POSTCONDITIONS: the queue is now empty
	void clear()
	{
	    m_size = 0;
	    delete [] m_data;
	    m_max=0;
	    return;
	}


  // PURPOSE: Base destructor
    ~Line()
    {
        m_size=0;
        delete [] m_data;
        m_max=0;
    }
    
    
    friend ostream& operator<< <>(ostream& os, const Line<T>& line);

};


template <typename T>
ostream& operator<<(ostream& os, const Line<T>& line)
{
    os<<"[ ";
    for(int i=0; i<line.m_size; i++)
    {
        os<<line.m_data[i]<<", ";
    }
    os<<"]";
    return os;
}



