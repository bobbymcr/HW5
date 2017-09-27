// TakeOffEvent class : definition of the functions in the TakeOffEvent class

#include "TakeOffEvent.h"
#include "EventQueue.h"
#include "Plane.h"
#include "Runway.h"
#include "gp142.h"

TakeOffEvent::TakeOffEvent (int y, GP142Display *display) {
	// here initX and initY are initialized to the point on the display from
	// where the take off of the plane would being. ie, the leftmost end of the runway
	// note that the region in which the planes queue up for take off is not the part
	// of the actual runway
	this->initX = -GP142_XMAX + DISTANCE_BETWEEN_PLANES + DISPLAY_OCCUPIED_BY_TAKEOFF_QUEUE;
	this->initY = y - RUNWAY_WIDTH*0.2;

	// here finalX and finalY have been initialized to the point on the display at which
	// the plane disappears from the display
	this->finalX = GP142_XMAX;
	this->finalY = y + MAX_HEIGHT_AFTER_TAKEOFF;

	// *** if you want to simulate some other kind of aircraft (that you derive from the
	// Aircraft class in part II of the HW), the randomNumber function again comes to
	// your rescue. Just generate a random number and use it to decide what kind of 
	// aircraft object do you want to simulate takeoff on. You can do this not just
	// for takeoff, but for any kind of event that you decide to simulate ***

	// Note that we set the aircraft to face to the right (isFacingLeft = false)
	// Note that the x and y-coordinates of the plane have been initialized to the point
	// on the display from where the take off begins, However, when this TakeOffEvent
	// is added to the takeoff queue, the value of initX is changed depending how many 
	// planes are ahead of it in the queue, so that when the takeoff queue gets displayed,
	// the plane is displayed at correct position
	aircraft = new Plane (initX, initY, false, display);
}


// returns true if the event being simulated is over. This function does not 
// simulate the entire event in one invocation. Every time this function gets
// called, it  simulates the takeoff for one unit of time.
bool TakeOffEvent::doEvent () {
	int deltaX, deltaY;

	if (aircraft->getX() >= finalX)  // landing process is over
		return true;

	// if the landing process is not over, then continue with its simulation
	// in one unit of time, the plane moves 'velocity' units of distance to the right
	deltaX = aircraft->getVelocity ();
	aircraft->changeX (deltaX);

	// if the plane has lifted off the runway, change y-coordinate of the plane too
	if (aircraft->getX () > initX + (finalX - initX)*(1 - FRACTION_RUNWAY_REMAINED_TAKEOFF)) { // plane has left the runway
		deltaY = deltaX * MAX_HEIGHT_AFTER_TAKEOFF/(FRACTION_RUNWAY_REMAINED_TAKEOFF * (finalX - initX));
		aircraft->changeY (deltaY);
	}

	return false;
}

void TakeOffEvent::draw () {
	aircraft->draw ();
}

TakeOffEvent::~TakeOffEvent () {
	delete aircraft;
}
