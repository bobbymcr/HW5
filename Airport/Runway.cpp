// Runway.cpp : definitions of the Runway class functions

#include "Runway.h"
#include "Event.h"
#include "TakeOffQueue.h"
#include "gp142display.h"
#include "gp142.h"

Runway::Runway (int y, GP142Display *display) {
	this->y = y;
	this->display = display;
	eventInProgress = NULL;
	takeOffQueue = new TakeOffQueue ();
}

Event* Runway::getEventInProgress () {
	return eventInProgress;
}

void Runway::setEventInProgress (Event *e) {
	eventInProgress = e;
}

void Runway::setEventOver () {
	delete eventInProgress;
	eventInProgress = NULL;
}

int Runway::getY () const {
	return y;
}

TakeOffQueue* Runway::getTakeOffQueue () {
	return takeOffQueue;
}

void Runway::draw () const {
	int offset = DISTANCE_BETWEEN_PLANES + DISPLAY_OCCUPIED_BY_TAKEOFF_QUEUE;

	// draw the actual runway
    display->drawRectangle (-GP142_XMAX+offset, y - (RUNWAY_WIDTH)*1.2/2, GP142_XMAX, y + (RUNWAY_WIDTH)*0.8/2, MedGray, 0);
	display->drawLine (-GP142_XMAX + offset, y, GP142_XMAX, y, White, 2);

	// draw the queuing portion of the runway
	display->drawRectangle (-GP142_XMAX, y - (RUNWAY_WIDTH)*1.2/2, -GP142_XMAX+offset, y , MedGray, 0);

	// draw the taxiing portion of the runway
	display->drawTriangle (-GP142_XMAX, y + (RUNWAY_WIDTH)*1.0/2, -GP142_XMAX+offset, y + (RUNWAY_WIDTH)*0.8/2, -GP142_XMAX, y + (RUNWAY_WIDTH)*1.0, MedGray, 0);
	display->drawTriangle (-GP142_XMAX, y + (RUNWAY_WIDTH)*1.0/2, -GP142_XMAX+offset, y + (RUNWAY_WIDTH)*0.8/2, -GP142_XMAX + offset, y, MedGray, 0);

	takeOffQueue->draw ();
}

Runway::~Runway () {
	delete takeOffQueue;
	if (eventInProgress != NULL) 
		delete eventInProgress;
}