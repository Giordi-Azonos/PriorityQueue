#include <iostream>
#include "pqueue-heap.h"
using namespace std;

int main() {
    PriorityQueue pq;
    pq.enqueue(5);
    pq.enqueue(3);
    pq.enqueue(20);
    pq.enqueue(4);
    pq.enqueue(4);
    pq.enqueue(17);
    pq.enqueue(45);
    cout << pq.toString() << endl;
    pq.dequeueMax();
    cout << pq.toString() << endl;
    pq.dequeueMax();
    cout << pq.toString() << endl;
    pq.dequeueMax();
    cout << pq.toString() << endl;
    pq.dequeueMax();
    cout << pq.toString() << endl;
    pq.dequeueMax();
    cout << pq.toString() << endl;
    pq.dequeueMax();
    cout << pq.toString() << endl;
    pq.dequeueMax();
    cout << pq.toString() << endl;
    pq.enqueue(100);
    cout << pq.toString() << endl;

    return 0;
}
