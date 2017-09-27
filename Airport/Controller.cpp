// Controller.cpp : definitions of the Controller class functions

#include "Controller.h"
#include "Airport.h"
#include "utils.h"

#include <cstdlib>

Controller::Controller (Airport *airport) {
    this->airport = airport;
}

// generates the runway to which the event will be assigned
int Controller::getRunwayNumber () const {
    return randomNumber(0,airport->getNumRunways());
}

// *** Note that the parameter of this function is PASS BY REFERENCE ***
EventType Controller::generateEvent (int &runwayNumber) const {
    runwayNumber = getRunwayNumber ();

    // Decide which event to generate. We have just one possible
    // event at present. So, the second argument to randomNumber
    // is 1.
    switch (randomNumber(0,1)) {
    case 0:
        return TakeOff;
    default:
        return Error;
    }
}