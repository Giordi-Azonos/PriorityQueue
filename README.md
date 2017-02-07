# PriorityQueue

A priority queue is a variation of the standard queue. The standard queue processes elements in the 
first-in, first-out ("FIFO") manner typical of ordinary waiting lines. In a priority queue elements 
are prioritized relative to each other and when asked to dequeue one, it is the highest priority 
element in the queue that is removed.

In this project, the Priority Queue Class is implemented using different Data Structures.

pqueue-hybrid -> combines the array and linked-list concepts into a singly-linked list of blocks, 
	where each block contains a constant-sized array capable of holding several elements.
	
	By storing several elements in each block, 
	
	By storing several elements in each block, the storage overhead get reduced because the pointers 
	take up a smaller fraction of the data. However, because the blocks are of a fixed maximum size, 
	inserting an element into a block never requires shifting more than k elements, where k is the 
	block size or maximum number of elements per block. The time it takes to find the right block in 
	which to insert a new element is also reduced by the added ability to step over entire blocks 
	of elements, rather than examining each element one by one.

pqueue-heap -> 
	
	Using a heap makes reordering and removing elements from the heap faster.
	A heap is a binary tree that has these two properties:
	
		* It is a complete binary tree, i.e. one that is full in all levels (all nodes have two children),
		except for possibly the bottom-most level which is filled in from left to right with no gaps.
		* The value of each node is greater than or equal to the value of its children.

pqueue-linkedlist -> Here the Linked list is implemented using a recursive singly-linked list. Benefical over
	the vector implementation, but slower when traversing the Linked List. i.e. inserting, removing and 
	reordering the queue.

pqueue-vector -> Priority Queue backended by Stanford's Vector data structure.
