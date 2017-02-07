/*******************************************************
 * File: pqueue-linkedlist.h
 *
 * A priority queue class backed by a sorted, singly-linked
 * list.
 */
#ifndef PQueue_LinkedList_Included
#define PQueue_LinkedList_Included

#include <string>
using namespace std;

/* A class representing a priority queue backed by a sorted,
 * singly-linked list.
 */
class PriorityQueue {
public:
	/* Constructs a new, empty priority queue backed by a sorted linked list. */
    PriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
    ~PriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new string into the priority queue. */
    void enqueue(int newElem);
	
	/* Returns, but does not remove, the lexicographically first string in the
	 * priority queue.
	 */
    int peek();
	
	/* Returns and removes the lexicographically first string in the
	 * priority queue.
	 */
    int dequeueMax();

    string toString();
	
private:

    //DISALLOW_COPYING(PQueue);

    struct EntryT{
        int value;
        EntryT *next;
    };

    EntryT *entries;
    int counter;

    void insertSorted(EntryT *&list, EntryT *newOne);
};

#endif
