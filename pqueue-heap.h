/**********************************************
 * File: pqueue-heap.h
 *
 * A priority queue class backed by a binary
 * heap.
 */
#ifndef PQueue_Heap_Included
#define PQueue_Heap_Included

#include <string>
using namespace std;

const int INITIAL_ARRAY_SIZE = 14;

/* A class representing a priority queue backed by an
 * binary heap.*/
class PriorityQueue {
public:

    PriorityQueue(); // -> Constructor
    /* Constructs a new, empty priority queue backed by a binary heap.*/

    ~PriorityQueue(); // -> Destructor
    /* Cleans up all memory allocated by this priority queue.*/
	
	int size();
    /* Returns the number of elements in the priority queue.*/

	bool isEmpty();
    /* Returns whether or not the priority queue is empty.*/
	
    void enqueue(int value);
    /* Enqueues a new integer into the priority queue.*/
	
    int peek();
    /* Returns, but does not remove, the first element in the
     * priority queue, corresponding to the maximun integer stored.*/
	
    int dequeueMax();
    /* Returns and removes the first element in the
     * priority queue, corresponding to the maximun integer stored.*/

    string toString();
    /*Returns a string representation of the queue.*/

private:

    /*Instance Variables:*/
    int *array;
    int nStored;
    int sizeOfArray;

    /*Private helpers:*/

    void expandArray();
    /*Doubles the current capacity of the array when the numbers stored equals the
     *current size of the array. Performs this by creating a new array with double
     *capacity, then copying the values of the old array to the new array, and
     *finally deleting the old array to clear the heap.*/

    void bubbleUp(int index);
    /*Recursively compares a value with its parent on the heap and, if it is greater
     *than its parent, exchanges them, and continues comparing until the index of
     *the value in the array is zero, or the value is less or equal than its parent.*/

    void initArray(int array[], int size);
    /*Initializes an array by assigning -1 on every index. A -1 in the array is used to
     *signal an empty slot*/

    void heapify(int index);
    /*Replaces the root after dequeing. It first replaces the root with the last value added.
     *And then recursiveley compares it with its left-side and its right-side nodes, exchanging the
     *value with the biggest one of those two nodes. Stops recursing when the index of the right-side
     *is greater than the current size of the array, or both the left-side and the right-side nodes
     *hold smaller values than the current value.*/

};


#endif
