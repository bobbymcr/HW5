// TakeOffQueue class

// TakeOffQueue represents the queue of the planes which are waiting to take off
// This class is derived from the abstract class EventQueue. It implements the
// draw function, which draws out the takeoff queue on the runway. 

#ifndef TAKEOFFQUEUE_H
#define TAKEOFFQUEUE_H

#include "EventQueue.h"

// two constants which are used for drawing out the queue of the planes

// distance between the x-coordinates of the two planes
const int DISTANCE_BETWEEN_PLANES = 40;
const int DISPLAY_OCCUPIED_BY_TAKEOFF_QUEUE = 125;

class TakeOffQueue : public EventQueue {
public:
    // draws the takeoff queue on the display screen
    virtual void draw ();

    // the enqueue for the takeoff queue has to do two tasks.
    // 1. add the event e to the queue
    // 2. assign proper values to the x and y coordinates of the aircraft
    //    object associated with the event e, so that when the queue is 
    //    draw on the display screen, the plane gets displayed in correct position
    // For doing task 1, this function invokes the EventQueue::enqueue function
    // It provides implementation for task 2
    virtual void enqueue (Event *e);

    // the dequeue (like the enqueue above) has two tasks to do
    // 1. remove the element at the head of the queue
    // 2. update the x coordinates of the aircraft objects associated with
    //    the remaining events in the queue.
    // For doing task 1, this function invokes the EventQueue::dequeue function
    // It provides implementation for task 2
    virtual Event* dequeue ();
};

#endif