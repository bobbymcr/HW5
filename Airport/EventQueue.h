// EventQueue class

// EventQueue is queue of events. This is an abstract class. It has got one pure virtual 
// function, draw. This is implemented by the classes that are derived from it. This is 
// a queue which has just the 'front' pointer. 

#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "Event.h"

class EventQueue {
public:
    // the constructor, creates an empty queue of Events
    EventQueue ();

    // = true if the queue is empty
    virtual bool isEmpty () const;

    // add a new event e, at the end of the queue
    virtual void enqueue (Event *e);

    // = returns a pointer to event object at the front of the queue. And the object
    // is removed from the queue. If the queue is empty, it returns NULL
    virtual Event *dequeue ();

    // = length of the queue
    virtual int getLength () const;

    // draw out the queue
    virtual void draw () = 0;

    // the destructor for the queue
    virtual ~EventQueue ();

protected:
    // node in the queue
    struct QueueNode {
        Event *e;            // the event
        QueueNode *next;    // pointer to the next node in the queue
    };

    QueueNode *front;        // pointer to the first element in the queue
    QueueNode *rear;        // pointer to the last element of the queue
    int length;                // length of the queue

    // returns the i-the element (counting starts from 'front') of the queue
    virtual Event *getIthEvent (int i);

private:
    // a helper function used by the destructor. This function calls itself
    // recursively to delete the queue
    void deleteQueue (QueueNode *n);
};

#endif