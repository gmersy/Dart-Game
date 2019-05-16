#ifndef TARGETS_HPP
#define TARGETS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Circle.hpp"


using namespace std;

class Target : public Circle
{
	public:
	void hitTarget(int &currentPoints);	
};

class Bubble : public Circle
{
	private:
	bool isPopped;
	
	public:
	Bubble();
	void hitBubble(int &currentPoints);
	
};

class Emoji : public Circle
{
	private:
	string currentMood;

	public:
	Emoji();
	void hitEmoji(int &currentPoints);
};
#endif


