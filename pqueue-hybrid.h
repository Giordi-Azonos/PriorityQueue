/*******************************************************
 * File: pqueue-hybrid.h
 *
 * A priority queue class backed by a linked-list of blocks, where each block
 * contains a constant-sized array capable of holding several elements.
 */
#ifndef _PriorityQueue_h
#define _PriorityQueue_h

#include <string>
using namespace std;


/*Constants:*/
    const int ELEMS_PER_BLOCK = 4;
    const int INITIAL_RANK_SIZE = 10;

/*Holds the range of numbers each block holds. This way it is easier
 *to see in which block a certain number goes.*/
struct rangeT{
    int low;
    int high;
};

/*Holds all the information of a certain block.*/
struct blockT{
    int capacity = ELEMS_PER_BLOCK; // -> number of slots each block has.
    rangeT range;
    int count; // -> Number of slots occupied.
    int *array; // -> array that holds the values
    blockT *next;
};


/* A class representing a priority queue backed by a linked-list of blocks containing an array.*/
class PriorityQueue {
public:
	/* Constructs a new, empty priority Queue. */
	PriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~PriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new integer value into the priority queue. */
	void enqueue(int newElem);
	
	/* Returns, but does not remove, the frist element in the
	 * priority queue, corresponding to the max integer.*/
	int peek();
	
    /* Returns and removes the frist element in the
     * priority queue, corresponding to the max integer.*/
    int dequeueMax();

    /*Returns a string representation of the queue.*/
    string toString();

private:

/*Instance variables:*/

    blockT *blocks; // -> Linked list of the blocks.
    int nElems; // -> Counter of the total elements stored in the queue.

/*Private Helper Methods:*/

    rangeT getRange(int elem);
    /*Receives an element and computes the range where it falls according to the initial rank size.
     *For example: With an initial rank size of 10; the range of 16 is [10,29].*/

    void lookForPlace(blockT *&list, int newElem);
    /*Recursive method that receives an ascendeding ordered linked list of blocks, and one element.
     *Searches through the ranges of the blocks of the linked list looking for the range where the
     *given element falls, and inserts the element on that block.
     *If there is no such range, then it creates a new block with the range of the given element and
     *inserts that block on its proper place on the linked list, and the given element in the array
     *of that new block.*/

    int compareRange(int value, rangeT range);
    /*This is a comparison function that helps testing if a given value falls on a given range.
     *Returns 0 when the value falls on the range, 1 when the value is greater that the range
     *(that is, when the value is greater than the low range, and also greater than the high range.),
     *and -1 when the value is lower than the range. */

    blockT *initBlock();
    /*Returns a new pointer to a blockT with all its internal elements initialized.
     *The array of the block is initialized to hold -1 integers.*/

    void insertInBlock(blockT *&block, int newElem);
    /*Once the range of the element has been found, this function gets into action.
     *It inserts an element on a given block. That is, gets the array of a given block and
     *inserts the element in it's proper place so the array is in descending order.
     *(Does this with the help of insertInArray function). If the array of the block is
     *already full, it splits half of the elements on a new block (Does this with the split helper function).*/

    void split(blockT *&newOne, int newElem);
    /*Receives a new block, and an element to be inserted. It divides the elements of
     *the current full block with the new block, and updates their ranges.
     *The upper half of the elements stay on the current block, and the lower half is sent to
     *the new block. It then updates the range of the blocks, and inserts the element on the
     *block holding the new range where the element belongs.*/

    void insertInArray(int newElem, int array[], int index);
    /*Recursive method that receives a descendeding ordered array, and one element.
     *Searches through the ranges of the blocks of the linked list looking for the place where the
     *given element goes, and inserts the element on that place shuffling down the remaining elements
     *one place.*/

    string arrayToString(int array[]);
    /*Converts the array of a block to a string representation, having its elements separated by commas.
     *Example. array: [1, 2, -1, -1] ---> string: 1, 2
     *(Note how the slots having -1 aren't added to the string since the -1 indicates an empty slot).*/

    void shuffleUp();
    /*Shuffles up the elements of an array by one slot, and inserts -1 on the last slot to indicate
     *that slot is now available. If the element you dequeued was the last element of that block,
     *then the block is deleted and the linked list updated.*/

    bool isContained(rangeT range1, rangeT range2);
    /*Tests if range 1 is contained in range 2, in which case returns true.*/

};

#endif
