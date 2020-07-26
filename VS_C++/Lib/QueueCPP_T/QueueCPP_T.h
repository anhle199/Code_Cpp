// File: QueueCPP_T.h
// Use C++ template

#ifndef QUEUE_CPP_T_H_
#define QUEUE_CPP_T_H_

template <class T>
struct Queue {
    void *data;
};

// Print all elements of queue.
template <class T>
void printQueue(Queue<T> &queue);

// Initialize a queue.
template <class T>
void initQueue(Queue<T> &queue);

// Delete a queue.
template <class T>
void closeQueue(Queue<T> &queue);

// Return number of element in the queue.
template <class T>
int sizeQueue(Queue<T> &queue);

// Return true if the queue size is 0, false otherwise.
template <class T>
bool isEmpty(Queue<T> &queue);

// Return a reference to the first element in the queue.
template <class T>
T& firstQueue(Queue<T> &queue);

// Insert a new element at the end of the queue.
template <class T>
void pushQueue(Queue<T> &queue, const T &value);

// Remove the last element in the queue. 
template <class T>
void popQueue(Queue<T> &queue);

#endif // End of file QueueCPP_T.h