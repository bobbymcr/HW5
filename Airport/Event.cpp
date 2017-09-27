// Event.cpp : definition of the functions in the Event class

#include <cstdlib>

#include "Event.h"
#include "Aircraft.h"

Event::Event () {
    aircraft = NULL;
}

Aircraft* Event::getAircraft () {
    return aircraft;
}

Event::~Event () {
    // do nothing 
}