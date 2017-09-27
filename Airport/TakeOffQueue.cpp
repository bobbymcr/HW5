// TakeOffQueue.cpp : implementation of the function in the TakeOffQueue class

#include <cstdlib>

#include "Event.h"
#include "TakeOffQueue.h"
#include "EventQueue.h"
#include "Aircraft.h"
#include "gp142.h"

// the enqueue for the takeoff queue has to do two tasks.
// 1. add the event e to the queue
// 2. assign proper values to the x and y coordinates of the aircraft
//    object associated with the event e, so that when the queue is 
//    draw on the display screen, the plane gets displayed in correct position
// For doing task 1, this function invokes the EventQueue::enqueue function    
// It provides implementation for task 2
void TakeOffQueue::enqueue (Event *e) {
    // add the event to the queue
    EventQueue::enqueue (e);
    // position the plane correctly on the display.
    e->getAircraft()->changeX (-length*DISTANCE_BETWEEN_PLANES);
}

// the dequeue (like the enqueue above) has two tasks to do
// 1. remove the event element at the head of the queue
// 2. update the x coordinates of the aircraft objects associated with
//    the remaining events in the queue.
// For doing task 1, this function invokes the EventQueue::dequeue function
// It provides implementation for task 2
Event* TakeOffQueue::dequeue () {
    // update the x-coordinates of all the planes in the queue (All the planes
    // will move to the right by DISTANCE_BETWEEN_PLANES amount.
    for (int i = 1; i <= length; i++) {
        Event *e = this->getIthEvent (i);
        Aircraft *a = e->getAircraft ();
        a->changeX(DISTANCE_BETWEEN_PLANES);
    }    
    // dequeue the event and return it
    return EventQueue::dequeue ();    
}

// This function draws out the takeoff queue on the runway
void TakeOffQueue::draw () {
    // one by one, get an event from the queue and draw out the corresponding aircraft
    for (int i = 1; i <= length; i++) {
        Event *e = this->getIthEvent (i);        // get the event
        Aircraft *a = e->getAircraft();            // get the correspoding aircraft
        a->draw();                                // draw out the aircraft
    }

}