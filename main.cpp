#include "Targets.hpp"
#include "Circle.hpp"
#include "Point2d.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string targetFile = "";
	int tCount, bCount, eCount;
	tCount = 0;
	bCount = 0;
	eCount = 0;
	
	cout << "Enter target file: " << endl;
	cin >> targetFile;
	
	ifstream in;
	
	in.open(targetFile);
	
	if(in.fail())
	{
		cout << "Cannot open" << endl;
		exit(1);
	}
	
	in >> tCount;
	in >> bCount;
	in >> eCount;
	
	Target *tArr = new Target[tCount];
	Bubble *bArr = new Bubble[bCount];
	Emoji *eArr = new Emoji[eCount];
	
	Target inT;
	Bubble inB;
	Emoji inE;
	
	int tCountIn = 0;
	int bCountIn = 0;
	int eCountIn = 0;
	
	string inType = "";
	
	Point2d cent;
	double rad;
	
	int countSum = tCount + bCount + eCount;
	
	for(int i = 0; i < countSum; i++)
	{
		in >> inType;
		if(inType == "target")
		{
			in >> inT;
			tArr[tCountIn] = inT;
			tCountIn++;
		}
		else if(inType == "bubble")
		{
			in >> cent;
			inB.setCenter(cent);
			in >> rad;
			inB.setRadius(rad);
			bArr[bCountIn] = inB;
			bCountIn++;
		}
		else if(inType == "emoji")
		{
			in >> cent;
			inE.setCenter(cent);
			eArr[eCountIn] = inE;
			eCountIn++;
		}
	}
	// works up to here 
	
	// dart loop
	Point2d dartThrow;
	int pointCount = 0;
	for(int dartNum = 1; dartNum < 4; dartNum++)
	{
		bool here = false;
		cout << "Dart: " << dartNum << endl;
		cout << "Insert dart (x y): ";
		cin >> dartThrow;
		
		for(int i = 0; i < tCount; i++)
		{
			if(tArr[i].contains(dartThrow))
			{
				tArr[i].hitTarget(pointCount);
				cout << "Points: " << pointCount << endl;
				here = true;
			}
		}
		
		for(int i = 0; i < bCount; i++)
		{
			if(bArr[i].contains(dartThrow))
			{
				bArr[i].hitBubble(pointCount);
				cout << "Points: " << pointCount << endl;
				here = true;
			}
		}
		
		for(int i = 0; i < eCount; i++)
		{
			if(eArr[i].contains(dartThrow))
			{
				eArr[i].hitEmoji(pointCount);
				cout << "Points: " << pointCount << endl;
				here = true;
			}
		}
		
		if(here == false)
		{
			cout << "Miss!" << endl;
			cout << "Points: " << pointCount << endl;
		}
	}
	cout << "Game Over!" << endl;
		
	in.close();
}
