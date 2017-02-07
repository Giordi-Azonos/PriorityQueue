/**********************************************
 * File: pqueue-vector.h
 *
 * A priority queue class backed by an unsorted
 * vector.
 */
#ifndef PQueue_Vector_Included
#define PQueue_Vector_Included

#include <string>
#include "vector.h"
#include "console.h"
#include <iostream>
using namespace std;

/* A class representing a priority queue backed by an
 * unsorted Vector.
 */
class PriorityQueue {
public:
	/* Constructs a new, empty priority queue backed by a vector. */
	PriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~PriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
    /* Enqueues a new integer into the priority queue. */
    void enqueue(int newElem);
	
    /* Returns, but does not remove, the maximum integer in the
	 * priority queue.
	 */
    int peek();
	
    /* Returns and removes the maximum integer in the
	 * priority queue.
	 */
    int dequeueMax();

    /*
     * Returns a string representation of the Queue.
     */
    string toString();

private:
    Vector<int> elements;
    int Max(Vector<int> &v);
};

#endif
