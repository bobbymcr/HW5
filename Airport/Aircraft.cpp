// Aircraft.cpp : definition of the Aircraft class functions

#include <cstdlib>

#include "Aircraft.h"

Aircraft::Aircraft () {
	display = NULL;
}


int Aircraft::getX () const {
	return x;
}


int Aircraft::getY () const {
	return y;
}


bool Aircraft::isFacingLeftOrNot () const {
	return isFacingLeft;
}


void Aircraft::setX (int x) {
	this->x = x;
}


void Aircraft::setY (int y) {
	this->y = y;
}


void Aircraft::changeX (int deltaX) {
	x += deltaX;
}


void Aircraft::changeY (int deltaY) {
	y += deltaY;
}


int Aircraft::getVelocity () const {
	return velocity;
}


Aircraft::~Aircraft () {
	// Nothing to do :-)
}