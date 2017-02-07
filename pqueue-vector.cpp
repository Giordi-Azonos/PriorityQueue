/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"
#include "strlib.h"
#include "console.h"
#include <iostream>


PriorityQueue::PriorityQueue() {}

PriorityQueue::~PriorityQueue() {}

int PriorityQueue::size() {
    return elements.size();
}

bool PriorityQueue::isEmpty() {
    return (elements.size() == 0);
}

void PriorityQueue::enqueue(int newElem) {
    elements.add(newElem);
}

int PriorityQueue::peek() {
    if (isEmpty()) error("Attempt to peek from an empty Queue.");
    return Max(elements);
}

int PriorityQueue::dequeueMax() {
    if (isEmpty()) error("Attempt to dequeue from an empty Queue.");
    int max = elements[0];
    int index = 0;
    for (int i=1; i<size(); i++){
        if (elements[i] > max){
            max = elements[i];
            index = i;
        }
    }
    elements.remove(index);
    return max;

}

string PriorityQueue::toString(){
    string str = "{";
    for (int i=0; i<size(); i++){
        str += (" " + integerToString(elements[i]));
    }
    return (str + " }");
}

int PriorityQueue::Max(Vector<int> &v) {
    int max = v[0];
    for (int i=1; i<v.size(); i++){
        if (v[i] > max) max = v[i];
    }
    return max;
}
