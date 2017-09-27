// TakeOffEvent class : represents a takeoff event

// TakeOffEvent class has been derived from the Event class which is an abstract class
// This class provides definition for the doEvent() and draw() functions which were
// pure virtual in Event class. This class represents a takeOffEvent. 

#ifndef TAKEOFFEVENT_H
#define TAKEOFFEVENT_H

#include "Event.h"

// these are some constants used in simulation of takeoff
// the height above the runway (in terms of y-coordinates on the display) to which the 
// plane rises after takeoff
const int MAX_HEIGHT_AFTER_TAKEOFF = 125;

// the fraction of the runway for which remains the moment plane rises off from the runway
const double FRACTION_RUNWAY_REMAINED_TAKEOFF = 0.35;

class TakeOffEvent : public Event{
public:
	// constructor for TakeOffEvent. It takes the y-coordinate of the runway
	// on which the plane will land as the first parameter. The second parameter
	// is the screen on which the event will be displayed
	TakeOffEvent (int y, GP142Display *display);

	// simulates the TakeOffEvent for one unit of time
	virtual bool doEvent ();

	// invokes the draw method of the aircraft object associated with the 
	// TakeOffEvent
	virtual void draw ();

	// the destructor : deallocates the memory for the dynamically allocated 
	// aircraft object
	virtual ~TakeOffEvent();

private:
	// coordinates of the aircraft object when it is just about to move from the waiting
	// queue on to the runway.
	int initX, initY; 

	// approximately, the coordinates of the aircraft object when it leaves the display
	// screen
	int finalX, finalY;
};

#endif

