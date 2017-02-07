/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"
#include "strlib.h"

PriorityQueue::PriorityQueue() {
    entries = NULL;
    counter = 0;
}

PriorityQueue::~PriorityQueue() {
    while (entries != NULL){
        EntryT *next = entries->next;
        delete entries;
        entries = next;
    }
}

int PriorityQueue::size() {
    return counter;
}

bool PriorityQueue::isEmpty() {
    return (counter == 0);
}

void PriorityQueue::enqueue(int newElem) {
    EntryT *newOne = new EntryT;
    newOne->value = newElem;
    newOne->next = NULL;
    insertSorted(entries, newOne);
    counter++;
}

int PriorityQueue::peek() {
    return entries->value;
}

int PriorityQueue::dequeueMax() {
    if (isEmpty()) error("Attempt to dequeue from an empty Queue.");
    EntryT *firstEntry = entries;
    int value = entries->value;
    entries = entries->next;
    delete firstEntry;
    return value;
}

void PriorityQueue::insertSorted(EntryT *&list, EntryT *newOne){
    if (list == NULL || newOne->value > list->value){
        newOne->next = list;
        list = newOne;
    }else{
        insertSorted(list->next, newOne);
    }
}

string PriorityQueue::toString(){
    string str = "{";
    for (EntryT *current = entries; current != NULL; current = current->next){
        str += ("->" + integerToString(current->value));
    }
    return (str + "}");
}
