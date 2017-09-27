// Plane class

// Plane IS A kind of Aircraft. 
// Plane class is dervied from Aircraft class, which is an abstract class. 
// This class provides a definition for draw() function, which is pure 
// virtual in Aircraft. Thus instances of Plane class can be created

#ifndef PLANE_H
#define PLANE_H

#include "Aircraft.h"

// minimum and maximum velocities for the aircrafts of type 'Plane'
// a particular instance of Plane gets assigned a velocity between 
// these two limits. This velocity is chosen randomly
const int MIN_VELOCITY = 5;
const int MAX_VELOCITY = 15;

class Plane : public Aircraft {
public:
    // the constructor
    Plane (int x, int y, bool isFacingLeft, GP142Display *display);

    // draw out the plane
    virtual void draw () const;
};

#endif