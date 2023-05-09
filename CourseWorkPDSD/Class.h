#pragma once
#include "Node.h"

class Set {
public:
    Set();//F1
    Set(int, int, int);//F5
    ~Set();//F8
    bool isEmpty();//F2
    bool isInSet(int);//F3
    void addElement(int);//F4
    int setSize();//F6
    string printSet(char);//F7
    bool isSubset(Set*);//F9
    bool areEqual(Set*);//F10
    Set* unionSet(Set*);//F11
    Set* intersectionSet(Set*);//F12
    Set* differenceSet(Set*);//F13
    Set* symmetricDifferenceSet(Set*);//F14

private:
    Node* head;
};