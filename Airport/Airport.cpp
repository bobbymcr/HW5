// Airport.cpp : definitions of the Airport class functions

#include <stdlib.h>

#include "Airport.h"
#include "Controller.h"
#include "Event.h"
#include "utils.h"

Airport::Airport(GP142Display *display) {
    // initialize the screen on which the airport will be displayed
    this->display = display;        

    // initialize the number of runways equal to zero
    numRunways = 0;
    for (int i = 0; i < MAX_RUNWAYS; i++) {
        runways[i] = NULL;
    }

    // create an instance of the Controller
    airTrafficController = new Controller (this);
}


// This function invokes Controller::generateEvent 
// *** Note that the argument to getNextEvent is pass by reference 
// This argument in turn is passed to generateEvent, again by reference
// Controller::generateEvent sets the value of runwayNumber. Since
// both Airport::getNextEvent and Controller::generateEvent pass their
// argument by reference, this change gets reflected in the argument
// that was passed to getNextEvent ***
EventType Airport::getNextEvent (int &runwayNumber) {
    return airTrafficController->generateEvent (runwayNumber);
}


int Airport::getNumRunways () {
    return numRunways;
}


Runway* Airport::getRunway (int i) {
    if (i >= numRunways || i < 0)
        return NULL;        // return NULL if i-th runway does not exist
    
    return runways[i];    
}


bool Airport::addRunway (int y) {
    if (numRunways == MAX_RUNWAYS)    {
        // simply ignores if already MAX_RUNWAYS exist and returns false
        return false;        
    }

    runways[numRunways] = new Runway (y, display);
    numRunways++;

    return true;
}


void Airport::simulate () {
    Event *event;

    this->draw();            // draw the airport and the runway 

    for (int i = 0; i < numRunways; i++) {

        // for each runway, get the event that is in progress on it
        event = runways[i]->getEventInProgress();
        if (event == NULL) {
            // if no event is currently in progress on a runway, then
            // get an event from any one of the event queues associated with
            // the runway. The choice of the event queue can again be 
            // random.
            // *** The starter code has just one possible event. So the 
            // second argument to randomNumber is 1. When there two possible
            // events to choose from, then the argument to randomNumber will
            // be 2 ***
            int whatToDo = randomNumber (0,1);
            switch (whatToDo) {
            case 0:
                event = runways[i]->getTakeOffQueue()->dequeue();
                break;
            default:
                break;
            }
            
            // update the event in progress on the runway to the new event just
            // dequeued from the eventqueue
            runways[i]->setEventInProgress (event);
        }

        if (event != NULL) {
            // doEvent returns true if the event gets over. 
            bool retval = event->doEvent();
            event->draw();    // draw the event
            if (retval)    {    
                // if the event got over, mark it in the corresponding runway as over
                runways[i]->setEventOver();
            }
        }
    }
}


void Airport::draw () {
    // clear the display
    display->clear ();

    // draw the sky and the background
    display->drawRectangle (SKY_LEFTX, SKY_BOTTOMY, SKY_RIGHTX, SKY_TOPY, IceBlue, 0);
    display->drawRectangle (FIELD_LEFTX, FIELD_BOTTOMY, FIELD_RIGHTX, FIELD_TOPY, SeaGreen, 0);

    // draw the airport building : got to make some enhancements
    display->drawRectangle (BUILD1_LEFTX, BUILD1_BOTTOMY, BUILD1_RIGHTX, BUILD1_TOPY, Peach, 0);
    display->write (BUILD1_LEFTX, BUILD1_TOPY - TEXTHEIGHT, " Seattle Tacoma ", Black, TEXTHEIGHT);
    
    // draw each of the runways and stuff related with each runway
    for (int i = 0; i < numRunways; i++) {
        runways[i]->draw ();
    }
}


Airport::~Airport() {
    for (int i = 0; i < numRunways; i++) {
        delete runways[i];
    }

    delete airTrafficController;
}
