#pragma once
#include "Node.h"
#include <deque>

class SetDeque {
private:
	deque<int> Set;
public:
	SetDeque();//F1
	bool isEmpty();//F2
	bool isInSet(int);//F3
	bool addElement(int);//F4
	SetDeque(int, int, int);//F5
	int setSize();//F6
	string printSet(char);//F7
	~SetDeque();//F8
	bool isSubset(SetDeque*);//F9
	bool areEqual(SetDeque*);//F10
	SetDeque* unionSet(SetDeque*);//F11
	SetDeque* intersectionSet(SetDeque*);//F12
	SetDeque* differenceSet(SetDeque*);//F13
	SetDeque* symmetricDifferenceSet(SetDeque*);//F14
};


