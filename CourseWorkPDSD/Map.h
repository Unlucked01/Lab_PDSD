#pragma once
#include "Node.h"
#include <map>

class SetMap {
private:
	map<int,int> Set;
public:
	SetMap();//F1
	bool isEmpty();//F2
	bool isInSet(int);//F3
	bool addElement(int, int);//F4
	SetMap(int, int, int);//F5
	int setSize();//F6
	string printSet(char);//F7
	~SetMap();//F8
	bool isSubset(SetMap*);//F9
	bool areEqual(SetMap*);//F10
	SetMap* unionSet(SetMap*);//F11
	SetMap* intersectionSet(SetMap*);//F12
	SetMap* differenceSet(SetMap*);//F13
	SetMap* symmetricDifferenceSet(SetMap*);//F14
};


