#pragma once
#include "Node.h"
#include <set>

class SetSet {
private:
	set<int> Set;
public:
	SetSet();//F1
	bool isEmpty();//F2
	bool isInSet(int);//F3
	bool addElement(int);//F4
	SetSet(int, int, int);//F5
	int setSize();//F6
	string printSet(char);//F7
	~SetSet();//F8
	bool isSubset(SetSet*);//F9
	bool areEqual(SetSet*);//F10
	SetSet* unionSet(SetSet*);//F11
	SetSet* intersectionSet(SetSet*);//F12
	SetSet* differenceSet(SetSet*);//F13
	SetSet* symmetricDifferenceSet(SetSet*);//F14
};


