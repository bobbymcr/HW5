// Event class

// Event class represents the events which are going to be simulated on the runway
// A generic event does not have any meaning. So, this is an abstract class.
// It has got two pure virtual functions. You cannot instantitate this class. The 
// functions doEvent and draw will be implemented by the derived classes

#ifndef EVENT_H
#define EVENT_H

#include "Aircraft.h"

class Event {
public:
	// the constructor
	Event ();

	// simulate the event for one period of time. Returns true if the event being 
	// simulated is over, otherwise return false
	virtual bool doEvent () = 0;

	// draw the objects associated with the event on the screen
	virtual void draw () = 0;

	// = aircraft object associated with the event
	virtual Aircraft* getAircraft ();

	// the destructor 
	virtual ~Event();

protected:
	Aircraft *aircraft;		// aircraft object associated with the event

};

#endif

