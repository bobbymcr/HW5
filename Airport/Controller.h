// Controller class

// Controller class : This class controls the sequence of events generated 
// on the airport. It generates random numbers to choose amongst one of the many
// possible events

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Airport;		// to avoid circular dependency

// possible event types
// *** Modify this when you add more events *** 
enum EventType {TakeOff, Error};

class Controller {
public:
	// constructor : constructs a controller for the 'airport'
	Controller (Airport *airport);

	// *** Note that the parameter of this function is pass by reference ***
	// = returns the type of event generated. It also sets its argument 
	// runwayNumber to the runway on which the event has been scheduled
	EventType generateEvent (int &runwayNumber) const;

private:
	// airport object associated with the controller
	Airport *airport;
	
	// = chooses which runway to schedule the event on
	int getRunwayNumber () const;  
};

#endif
