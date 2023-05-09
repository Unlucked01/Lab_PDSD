#pragma once
#include "Node.h"
#include <list>

class SetList {
private:
	list<int> Set;
public:
	SetList();//F1
	bool isEmpty();//F2
	bool isInSet(int);//F3
	void addElement(int);//F4
	SetList(int, int, int);//F5
	int setSize();//F6
	string printSet(char);//F7
	~SetList();//F8
	bool isSubset(SetList*);//F9
	bool areEqual(SetList*);//F10
	SetList* unionSet(SetList*);//F11
	SetList* intersectionSet(SetList*);//F12
	SetList* differenceSet(SetList*);//F13
	SetList* symmetricDifferenceSet(SetList*);//F14
};


