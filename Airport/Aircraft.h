// Aircraft class

// Aircraft denotes a generic aircraft object. 
// This class is an abstract class as it has a pure virtual function. Hence
// it can't be instantiated. Derived classes are created which correspond to
// particular aircrafts like a plane.

#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "gp142display.h"

class Aircraft {
public:
    // The constructor
    Aircraft ();

    // draws the aircraft object. It must be implemented by a derived class
    virtual void draw () const = 0;

    // = x-coordinate of the plane on the display
    virtual int getX () const;

    // = y-coordinate of the plane on the display
    virtual int getY () const;

    // sets the x-coordinate of the plane to x
    virtual void setX (int x);

    // sets the y-coordinate of the plane to y
    virtual void setY (int y);

    // returns true if the plane is facing left
    virtual bool isFacingLeftOrNot () const;

    // changes the x-coordinate of the plane by deltaX
    virtual void changeX (int deltaX);

    // changes the y-coordinate of the plane by deltaY
    virtual void changeY (int deltaY);

    // = velocity of the plane
    virtual int getVelocity () const;

    // destructor for aircraft
    virtual ~Aircraft ();

protected:
    GP142Display *display;    // screen on which the aircraft will be displayed
    int velocity;            // velocity of the aircraft
    int x, y;                // coordinates of the aircraft on the display
    bool isFacingLeft;        // is the aircraft moving from right to left
};

#endif