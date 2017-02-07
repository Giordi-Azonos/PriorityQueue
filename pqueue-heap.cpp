/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"
#include "strlib.h"

PriorityQueue::PriorityQueue() {
    array = new int[INITIAL_ARRAY_SIZE];
    sizeOfArray = INITIAL_ARRAY_SIZE;
    initArray(array, sizeOfArray);
    nStored = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] array;
}

int PriorityQueue::size() {
    return nStored;
}

bool PriorityQueue::isEmpty() {
    return (nStored == 0);
}

void PriorityQueue::enqueue(int value) {
    if (value < 0) error("Attempt to enqueue a value with a negative priority.");
    if (nStored == sizeOfArray) expandArray();
    nStored++;
    array[nStored - 1] = value;
    bubbleUp(nStored - 1);
}

int PriorityQueue::peek() {
    return array[0];
}

int PriorityQueue::dequeueMax() {
    if (isEmpty()) error("Attempt to dequeue from an empty queue.");
    int maxValue = array[0];
    array[0] = array[nStored - 1];
    array[nStored - 1] = -1;
    nStored--;
    heapify(1);
    return maxValue;
}

string PriorityQueue::toString() {
    string str = "{";
        for (int i=0; i<size(); i++){
            if (array[i] != -1) // -> Ignores empty slots
                str += (" " + integerToString(array[i]));
        }
        return (str + " }");
}

void PriorityQueue::expandArray() {
    int newSize = (sizeOfArray + 1) * 2;
    int *newArray = new int[newSize];
    initArray(newArray, newSize);
    for (int i=0; i<nStored; i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    sizeOfArray = newSize;
}

void PriorityQueue::bubbleUp(int index){
    if (index != 0){
        int parentIndex = (index - 1) / 2;
        if (array[parentIndex] < array[index]){
            int temp = array[parentIndex];
            array[parentIndex] = array[index];
            array[index] = temp;
            bubbleUp(parentIndex);
        }
    }
}

void PriorityQueue::initArray(int array[], int size){
    for (int i=0; i<size; i++){
        array[i] = -1;
    }
}

void PriorityQueue::heapify(int index){
    if (index * 2 <= sizeOfArray){
        int leftChildIndex = (index * 2) - 1;
        int rightChildIndex = leftChildIndex + 1;
        int leftValue = array[leftChildIndex];
        int rightValue = array[rightChildIndex];
        int indexToCompare = leftChildIndex;
        if (rightValue > leftValue) indexToCompare = rightChildIndex;
        if (array[indexToCompare] > array[index - 1]){
            int temp = array[indexToCompare];
            array[indexToCompare] = array[index - 1];
            array[index - 1] = temp;
            heapify(indexToCompare + 1);
        }
    }
}
