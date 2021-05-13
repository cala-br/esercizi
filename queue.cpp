#include <iostream>

using namespace std;


const int MAX_QUEUE_LENGTH = 10;
struct Queue {
    int _buffer[MAX_QUEUE_LENGTH];
    int _first;
    int _count;
};


Queue queueCreate() {
    return {};
}


bool queueIsFull(const Queue& queue) {
    return queue._count == MAX_QUEUE_LENGTH;
}

bool queueIsEmpty(const Queue& queue) {
    return queue._count == 0;
}


void _queueIncrementIndex(int& index) {
    ++index %= MAX_QUEUE_LENGTH;
}

int _queueGetLastIndex(const Queue& queue) {
    const int last = 
        queue._first - queue._count;
    
    return last < 0
        ? MAX_QUEUE_LENGTH + last
        : last;
}


bool queueTryAdd(Queue& queue, int value) {
    if (queueIsFull(queue))
        return false;

    queue._buffer[queue._first] = value;

    _queueIncrementIndex(queue._first);
    queue._count++;
    return true;
}


bool queueTryRemove(Queue& queue, int& value) {
    if (queueIsEmpty(queue))
        return false;

    const int last = 
        _queueGetLastIndex(queue);

    value = queue._buffer[last];
    queue._count--;
    return true;
}



void queueTestAdd(Queue& queue, const int mult, const int max) 
{
    cout << "\nAdding\n";
    for (int i = 0; i < max; i++) {
        const int elem = mult * (i + 1);
        if (queueTryAdd(queue, elem))
            cout << elem << '\n';
    }
}

void queueTestRemove(Queue& queue, const int max)
{
    cout << "\nRemoving\n";
    for (int i = 0; i < max; i++) 
    {
        int n;
        if (queueTryRemove(queue, n))
            cout << n << '\n';
    }
} 


int main()
{
    Queue q = queueCreate();

    queueTestAdd(q, 10, 15);
    queueTestRemove(q, 6);

    queueTestAdd(q, 100, 15);
    queueTestRemove(q, 10);
    
    queueTestAdd(q, 1, 10);
    queueTestRemove(q, 10);
    
    queueTestAdd(q, 20, 1);
    queueTestRemove(q, 1);

    queueTestAdd(q, 30, 1);
    queueTestRemove(q, 1);

    queueTestAdd(q, 40, 1);
    queueTestRemove(q, 1);

    queueTestAdd(q, 50, 1);
    queueTestRemove(q, 1);

    cout << endl;
}

