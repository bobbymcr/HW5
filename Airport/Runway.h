// Runway Class

// This class represents a runway in the airport object. Each runway (on the screen) is a
// rectangular patch from left to right. On the left end, it forks out into two parts, one
// of which is used by the planes to queue up while waiting to take off and the other
// one is used by the planes to taxi after landing. The y-coordinate of the center of this
// patch represents the runway object. Each runway has one or more queue of events waiting
// to be simulated on this particular runway. Also each runway, also has a pointer to the 
// event that is currently being simulated on the runway. This pointer is set to NULL
// once the simulation of the event gets over. 

#ifndef RUNWAY_H
#define RUNWAY_H

#include "gp142display.h"
#include "Event.h"
#include "TakeOffQueue.h"

// width of the runway
const int RUNWAY_WIDTH = 45;

class Runway {
public:
	// constructor 
	Runway (int y, GP142Display *display);
	
	// draws the runway on the display
	void draw () const;

	// = y-coordinate of the center of the runway
	int getY () const;

	// = pointer to the takeOffQueue associated with the runway
	TakeOffQueue* getTakeOffQueue ();

	// marks the finishing of the event being simulated on the runway
	// sets the value of eventInProgress to NULL
	void setEventOver ();

	// = pointer to the event object which represent the event being currenly
	// simulated on the runway.
	Event* getEventInProgress ();

	// sets the event which is going to be simulated next on the runway
	void setEventInProgress (Event *e);

	// the destructor
	~Runway ();

private:
	int y;						// y-coordinate of the runway on the display
	GP142Display *display;		// the screen on which the runway will be displayed

	// pointer to the event which is being simulated on the runway currently.
	// it is NULL, if there is no event being simulated on the runway
	Event *eventInProgress;		

	// the queue associated with taking off
	// *** You can have more queues when you have more types of events ***
	// *** In particular, you will have a landingQueue, when you add a ***
	// *** landing event											   ***
	TakeOffQueue *takeOffQueue;
	
};

#endif