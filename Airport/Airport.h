// Airport Class 

// Airport class is the class which contains a bunch of other objects, like
// runways and the controller. The runways in turn contain EventQueues, which
// in turn contain events, which in turn contain aircrafts.

#ifndef AIRPORT_H
#define AIRPORT_H

#include "GP142display.h"
#include "Runway.h"
#include "Controller.h"
#include "gp142.h"

// This is the maximum number of runways that the airport may have
const int MAX_RUNWAYS = 3;

// Details of the background 
const int SKY_LEFTX = -GP142_XMAX;
const int SKY_BOTTOMY = 125;
const int SKY_RIGHTX = GP142_XMAX;
const int SKY_TOPY = GP142_YMAX;

const int FIELD_LEFTX = -GP142_XMAX;
const int FIELD_BOTTOMY = -GP142_YMAX;
const int FIELD_RIGHTX = GP142_XMAX;
const int FIELD_TOPY = SKY_BOTTOMY;

// Details of the airport buidling
const int BUILD1_LEFTX = -250;
const int BUILD1_BOTTOMY = 70;
const int BUILD1_RIGHTX = -100;
const int BUILD1_TOPY = 210;
const int TEXTHEIGHT = 20;

class Airport {
public:
    // the constructor
    Airport (GP142Display *display);

    // = number of runways in the airport
    int getNumRunways ();

    // = returns pointer to the i-th runway in the airport. 
    // NULL is returned if the number of runways is less than i
    Runway* getRunway (int i);

    // periodically invoked from the main event loop.
    // *** Note that the argument to this function is passed by reference ***
    EventType getNextEvent (int &runwayNumber);

    // adds a runway to the airport. On the screen, the centre of the runway has 
    // coordinate y. If already MAX_RUNWAYS runways exist, then the attempt to add 
    // another runway is simply ignored and returns false. If a new runway is 
    // added, true is returned
    bool addRunway (int y);

    // simulates the airport, by simulating events on each of the runways
    void simulate ();

    // draws the airport building and the background and the runways
    void draw ();

    // the destructor
    ~Airport ();

private:
    GP142Display *display;            // screen to draw things on to
    Runway *runways[MAX_RUNWAYS];    // store pointers to the runway objects
    int numRunways;                    // number of runways in the airport
    Controller *airTrafficController; // the Controller object associated with the airport

};

#endif
