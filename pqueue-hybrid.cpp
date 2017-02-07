/*************************************************************
 * File: pqueue-hybrid.cpp
 *
 * Implementation file for the chunklist implementation, which is a hybrid array/linked-list approach.
 * The chinklist combines the array and linked-list concepts into a singly-linked list of blocks containing a
 * constant-sized array that holds several elements.
 */
 
#include "pqueue-hybrid.h"
#include "error.h"
#include "strlib.h"

/*Constructor*/
PriorityQueue::PriorityQueue() {
    blocks = NULL;
    nElems = 0;
}

/*Destructor*/
PriorityQueue::~PriorityQueue() {
    while (blocks != NULL) {
            blockT *next = blocks->next;
            delete blocks;
            blocks = next;
        }
}

int PriorityQueue::size() {
    return nElems;
}

bool PriorityQueue::isEmpty() {
    return (nElems == 0);
}

void PriorityQueue::enqueue(int newElem) {
    if (newElem < 0) error ("Attempt to enque a value with a negative priority");
    nElems ++;
    lookForPlace(blocks, newElem);
}

int PriorityQueue::peek() {
    return blocks->array[0];
}

int PriorityQueue::dequeueMax() {
    if (nElems == 0) error ("Attempt to dequeue from an empty queue.");
    nElems --;
    blocks->count --;
    int temp = blocks->array[0];
    shuffleUp();
    return temp;
}

string PriorityQueue::toString(){
    string str = "{ ";
        if (blocks != NULL){
            for (blockT *current = blocks; current != NULL; current = current->next){
                str += arrayToString(current->array);
            }
        }
        return (str + "}");
}

/*Private methods:*/
void PriorityQueue::lookForPlace(blockT *&list, int newElem){
    if (list == NULL || compareRange(newElem, list->range) == 1){ // -> Compare range = 1 means the value is greater than the range.
        //Create a new block.
        blockT  *newOne = initBlock();
        // -> To compute the new range you must first make sure that the new range doesn't already have some other range included somewhere on the list.
        newOne->range = getRange(newElem);
        if(list != NULL)
            if (isContained(list->range, newOne->range))
                newOne->range.low = list->range.high + 1;
        insertInBlock(newOne, newElem);
        newOne->next = list;
        list = newOne;
    }else if (compareRange(newElem, list->range) == 0){
        insertInBlock(list, newElem);
    }else{
        lookForPlace(list->next, newElem);
    }
}

bool PriorityQueue::isContained(rangeT range1, rangeT range2){
    if (range1.low >= range2.low && range1.high <= range2.high) return true;
    else return false;
}

rangeT PriorityQueue::getRange(int elem){
    rangeT range;
    int n = elem / INITIAL_RANK_SIZE;
    range.low = INITIAL_RANK_SIZE * n;
    range.high = INITIAL_RANK_SIZE * (n + 1) - 1;
    return range;
}


int PriorityQueue::compareRange(int value, rangeT range){
    if (value > range.low && value > range.high) return 1;
    else if (value >= range.low && value <= range.high) return 0;
    else return -1;
}

blockT *PriorityQueue::initBlock(){
    blockT *newBlock = new blockT;
    newBlock->array = new int[ELEMS_PER_BLOCK];
    for (int i=0; i<ELEMS_PER_BLOCK; i++){
        newBlock->array[i] = -1;
    }
    newBlock->count = 0;
    newBlock->next = NULL;
    return newBlock;
}

void PriorityQueue::insertInBlock(blockT *&block, int newElem){
    if (block->count == block->capacity){ // -> full block
        blockT  *newOne = initBlock();
        newOne->next = block->next;
        block->next = newOne;
        split(newOne, newElem);
    }else{
        block->count++;
        insertInArray(newElem, block->array, 0);
    }
}

void PriorityQueue::split(blockT *&newOne, int newElem){
    for (int i=((blocks->capacity) / 2); i<=blocks->capacity-1; i++){
        newOne->array[i - (blocks->capacity / 2)] = blocks->array[i];
        newOne->count++;
        blocks->array[i] = -1;
        blocks->count--;
    }
    newOne->range.high = newOne->array[0];
    newOne->range.low = blocks->range.low;
    blocks->range.low = newOne->range.high + 1;
    if (compareRange(newElem, blocks->range) == 0){
        blocks->count++;
        insertInArray(newElem, blocks->array, 0);
    }else{
        newOne->count++;
        insertInArray(newElem, newOne->array, 0);
    }
}

void PriorityQueue::insertInArray(int newElem, int array[], int index){
    if (array[index] > newElem) insertInArray(newElem, array, index + 1); // -> Keep recursing
    else if (array[index] == -1) array[index] = newElem; // -> It is an empty slot, so just overwrite it. (Base Case)
    else{ // -> Otherwise you have to shuffle the elements of the array down.
        int temp = array[index];
        array[index] = newElem;
        insertInArray(temp, array, index + 1);
    }
}

string PriorityQueue::arrayToString(int array[]){
    string str = "";
    for (int i=0; i<ELEMS_PER_BLOCK; i++){
        if (array[i] != -1) str += (integerToString(array[i]) + " ");
    }
    return str;
}

void PriorityQueue::shuffleUp(){
    if (blocks->count == 0){ // -> Case where the element you dequeued was the last one.
        blockT *next = blocks->next; // -> Save next pointer before deleting the block.
        delete blocks;
        blocks = next;
    }else{
        for (int i=0; i<ELEMS_PER_BLOCK - 1; i++){
            blocks->array[i] = blocks->array[i + 1];
        }
        blocks->array[ELEMS_PER_BLOCK - 1] = -1;
    }
}
