#pragma once
#include "Node.h"

Node* createEmptySet();
bool isEmpty(Node*);
bool isInSet(Node*,int);
Node* addElement(Node*,int);
Node* createSet(int,int,int);
int powerSet(Node*);
string toString(Node*,char);
Node* deleteSet(Node*);
bool isSubset(Node*,Node*);
bool areEqual(Node*,Node*);
Node* unionSet(Node*,Node*);
Node* intersectionSet(Node*,Node*);
Node* differenceSet(Node*,Node*);
Node* symmetricDifferenceSet(Node*,Node*);