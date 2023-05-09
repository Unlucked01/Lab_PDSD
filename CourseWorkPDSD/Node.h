#pragma once
#include <string>
#include <regex>
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <stdio.h>
#include <windows.h>
#include <chrono>

using namespace std;

struct Node {
	int value;
	Node* next;
};