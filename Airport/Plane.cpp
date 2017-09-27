// Plane.cpp : definitions of the Plane class functions

#include <cstdlib>

#include "Plane.h"
#include "utils.h"

Plane::Plane (int x, int y, bool isFacingLeft, GP142Display *display) {
	this->x = x;
	this->y = y;
	this->display = display;
	this->velocity = randomNumber (MIN_VELOCITY, MAX_VELOCITY);
	this->isFacingLeft = isFacingLeft;
}

void Plane::draw () const {

	if (isFacingLeft) {	
		// draws the landing plane (place land from right to left)
		// draw the tail of the plane
		display->drawTriangle (x + 16, y - 5, x + 4, y - 5, x + 16, y + 14, White, 0);

		//draw the nose of the plane
		display->drawTriangle (x - 9, y - 5, x - 19, y - 5, x - 9, y + 5, White, 0);

		//draw out the body of the plane
		display->drawRectangle (x - 9, y - 5, x + 16, y + 5, White, 0);

		//draw out the two wings of the plane
		display->drawRectangle (x - 4, y + 5, x + 4, y + 9, LightGray, 0);
		display->drawRectangle (x - 4, y - 2, x + 4, y - 11, LightGray, 0);

		// add two wheels to the plane
		display->drawCircle (x - 9, y - 5, 2, Black);
		display->drawCircle (x + 7, y - 5, 2, Black);
	} 
	else {
		// draws the taking off plane (planes take off from left to right)
		// draw the tail of the plane
		display->drawTriangle (x - 16, y - 5, x - 4, y - 5, x - 16, y + 14, White, 0);

		//draw the nose of the plane
		display->drawTriangle (x + 9, y - 5, x + 19, y - 5, x + 9, y + 5, White, 0);

		//draw out the body of the plane
		display->drawRectangle (x - 16, y - 5, x + 9, y + 5, White, 0);

		//draw out the two wings of the plane
		display->drawRectangle (x - 4, y + 5, x + 4, y + 9, LightGray, 0);
		display->drawRectangle (x - 4, y - 2, x + 4, y - 11, LightGray, 0);

		// add two wheels to the plane
		display->drawCircle (x + 9, y - 5, 2, Black);
		display->drawCircle (x - 7, y - 5, 2, Black);
	}
}