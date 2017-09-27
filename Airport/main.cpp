// HW5 Code -- Airport simulation

#include <ctime>
#include <cstdlib>
#include <cassert>

#include "gp142display.h"
#include "Airport.h"
#include "Controller.h"
#include "Runway.h"
#include "TakeOffEvent.h"


// number of periodic time intervals to wait before generating a new Event
const int EVENT_SCHEDULE_PERIOD = 20;

// true every EVENT_SCHEDULE_PERIOD Periodic events. resets time to 0 when true
bool timeUp (int &time);

int main () {
	bool quit = false;			// = the Quit event occured
	int mouseX, mouseY;			// location of a mouse click
	char keyPress;				// which key was pressed to cause the Key event

	int currentTime = 0;		// how many periodic events have passed

	srand ((int) time (NULL));	// initialize the random number generator

	GP142Display display;		// screen everything appears

    display.clear (White);
	display.setAnimation (Run);

	Airport seaTac (&display);	// create an instance of airport

	// adding a runway to the airport
	seaTac.addRunway (15);
	
	EventType type;
	int runwayNumber;
	Runway *runway;
	Event *e;

	// Note that Airport::getNextEvent not only returns the type of event to be 
	// generated. It also sets the integer runwayNumber to the runway on which
	// the event will be simulated
	type = seaTac.getNextEvent (runwayNumber);
	runway = seaTac.getRunway (runwayNumber);
	assert (runway != NULL);
	// without looking at the 'type' of event returned by getNextEvent, we go ahead
	// and generate a TakeOffEvent because in the current simulation, this is the only
	// event that exists. When, you have more than one kind of events, you have
	// to take a look at the value of 'type' before deciding what kind of event
	// to generate
	e = new TakeOffEvent (runway->getY(), &display);
	if (e != NULL) {
		runway->getTakeOffQueue()->enqueue(e);
	} 

	// the main event loop
	while (!quit) {
		switch (display.getNextEvent (mouseX, mouseY, keyPress)) {
		case Quit:
			quit = true;	
			break;
		case Key:			
			break;
		case Periodic:
			// slow down the generation of new events
			if (timeUp (currentTime)) {
				// add code here to generate events periodically
				switch (type) {
				case TakeOff:
					break;
				case Error:
					break;
				default:
					break;
				}	
			}
			seaTac.simulate ();		// simulate the airport 
			break;
		case Mouse:
			break;
		default:
			break;
		}
	}

	return 0;
}


// true after very EVENT_SCHEDULE_PERIOD periods, false otherwise
bool timeUp (int &time) {
	if (time == EVENT_SCHEDULE_PERIOD) {
		time = 0;
		return true;
	}
	time++;
	return false;
}

		
		

		


