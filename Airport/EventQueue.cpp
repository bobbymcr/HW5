// EventQueue.cpp : definition of the EventQueue class functions

#include <cstdlib>
#include <cassert>

#include "EventQueue.h"
#include "Aircraft.h"
#include "Event.h"

EventQueue::EventQueue () {
    length = 0;
    front = NULL;
    rear = NULL;
}


// = true if the queue is empty
bool EventQueue::isEmpty () const {
    return (length == 0);
}


// Inserts the event pointed to by 'e' into the queue
// *** at present enqueue is implemented using just 'front'.You ***
// *** have to implement enqueue using both 'front' and 'rear'  ***
// *** In other words, you should not traverse the entire queue ***
// *** like a linked list to insert an event at the end of the  ***
// *** linked list. Instead YOU SHOULD KEEP A REAR POINTER AND  ***
// *** USE THAT                                                 ***                                        
void EventQueue::enqueue (Event *e) {
    assert (e != NULL);

    QueueNode *temp, *newNode;
    temp = front;

    newNode = new QueueNode;// create the new node that will be added to the queue
    newNode->e = e;
    newNode->next = NULL;

    // if the queue is empty
    if (temp == NULL) {
        front = newNode;
        length = 1;            // queue was intially empty, so new length is 1
        return;
    }

    // if the queue is not empty, the go till the end of the queue to insert the element
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    length = length + 1;    // update the length of the queue
    return;

}


// The usual dequeue function for a queue. It returns NULL if the queue is empty
// *** implement this using 'front' and 'rear' ***
Event* EventQueue::dequeue () {
    if (isEmpty ())
        return NULL;        // return NULL if the queue is empty

    QueueNode *temp = front;
    front = front->next;    // remove the first element of the queue        
    length = length - 1;    // update the length of the queue

    Event *event = temp->e;
    delete temp;            // release the memory used up by the node just dequeued
    temp = NULL;

    return event;

}


// = returns the length of the queue
int EventQueue::getLength () const {
    return length;
}


// = returns the i-th (counted from front) event from the queue
// If i is less than one or greater than the length, it returns NULL
Event* EventQueue::getIthEvent (int i) {
    if (i < 1 || i > length)
        return NULL;

    int count = 1;
    QueueNode *temp = front;
    while (count < i) {
        temp = temp->next;
        count++;
    }

    return temp->e;
}


// the destructor, which invokes a helper function, deleteQueue 
EventQueue::~EventQueue () {
    deleteQueue (front);
}


// a helper function used by the destructor. It deletes all the nodes in the queue
void EventQueue::deleteQueue (QueueNode *n) {
    if (n != NULL) {
        deleteQueue (n->next);
        delete n->e;    // delete the event contained in the node
        delete n;        // delete the node itself
    }
}

