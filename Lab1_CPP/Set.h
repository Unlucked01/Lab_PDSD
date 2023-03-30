#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    int value;
    Node* next;
};

class Set {
public:
    Set();//F1
    Set(int, int, int, int);//F5
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
    Set* symmetricDifference(Set*);//F14

private:
    Node* head;
};

//struct Node {
//	int value;
//	Node* next;
//};
//
////F1-F8
//
//bool isEmpty(Node*);
//bool isInSet(Node*, int);
//Node* addElement(Node*, int);
//Node* createSet(int, int, int,char);
//int setSize(Node*);
//std::string printSet(Node*, char);
//
////F9-F14
//bool isSubset(Node*, Node*);
//bool areEqual(Node*, Node*);
//
//Node* intersectionSet(Node*, Node*);
//Node* differenceSet(Node*, Node*);
//Node* symmetricDifference(Node*, Node*);
