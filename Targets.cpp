#include "Targets.hpp"
#include <iostream>

using namespace std;

void Target::hitTarget(int &currentPoints)
{
	if(getColor() == "Red")
	{
		cout << "Hit: Red Target" << endl;
		currentPoints += 10;
	}
	else if(getColor() == "Yellow")
	{
		cout << "Hit: Yellow Target" << endl;
		currentPoints += 5;
	}
	else if(getColor() == "Green")
	{
		cout << "Hit: Green Target" << endl;
		currentPoints += 2;
	}
	else 
	{
		currentPoints += 1;
	}
}	

Bubble::Bubble()
{
	setColor("Blue");
	isPopped = false;
}

void Bubble::hitBubble(int &currentPoints)
{
	if(isPopped == false)
	{
		cout << "Pop!" << endl;
		currentPoints += 20;
		isPopped = true;
	}
	else 
	{
		cout << "Plunk!" << endl;
	}
}

Emoji::Emoji()
{
	setRadius(10);
	setColor("Yellow");
	currentMood = "happy";
}

void Emoji::hitEmoji(int &currentPoints)
{
	cout << "Hit: " << currentMood << " emoji" << endl;
	if(currentMood == "happy")
	{
		currentMood = "sad";
		cout << "Now it's " << currentMood << endl;
	}
	else if(currentMood == "sad")
	{
		currentMood = "mad";
		cout << "Now it's " << currentMood << endl;
	}
	else if(currentMood == "mad")
	{
		currentMood = "happy";
		cout << "you should not have done that" << endl;
		currentPoints -= 1000; 
		cout << "Now it's " << currentMood << endl;
	}
	
}
