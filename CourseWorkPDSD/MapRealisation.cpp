#include "Map.h"

SetMap::SetMap() {
	Set = map<int, int>();
}

bool SetMap::isEmpty() {
	return Set.empty();
}

bool SetMap::isInSet(int val) {
	return Set.contains(val);
}

bool SetMap::addElement(int index, int value) {
	if (!isInSet(value)) {
		return Set.emplace(index, value).second;
	}
	return false;
}

int rndMap(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

SetMap::SetMap(int len, int min, int max) {
	Set = map<int,int>();
	if (len > 0 && max > min && len < max - min) {
		while (len > 0) {
			int value = rndMap(min, max);
			if (addElement(value, value)) {
				len--;
			}
		}
	}
}

int SetMap::setSize() {
	return Set.size();
}

string SetMap::printSet(char delim) {
	if (!isEmpty()) {
		string result = "";
		for(const auto& elem : Set) {
			result += to_string(elem.second);
			result += delim;
		}
		int len = result.length();
		return result.erase(len - 1, len);
	}
	return "";
}

SetMap::~SetMap() {
	Set.clear();
}

bool SetMap::isSubset(SetMap* subSet) {
	if (isEmpty()) {
		return true;
	}
	for (const auto& elem : subSet->Set) {
		if (!isInSet(elem.second)) {
			return false;
		}
	}
	return true;
}

bool SetMap::areEqual(SetMap* otherSet) {
	return isSubset(otherSet) && otherSet->isSubset(this);
}

SetMap* SetMap::unionSet(SetMap* otherSet) {
	SetMap* result = new SetMap();
	for (const auto& elem : Set) {
		result->addElement(elem.first, elem.second);
	}

	for (const auto& elem : otherSet->Set) {
		result->addElement(Set.size() + elem.first, elem.second);
	}
	return result;
}

SetMap* SetMap::intersectionSet(SetMap* otherSet) {
	SetMap* result = new SetMap();
	for (const auto& elem : otherSet->Set) {
		if (isInSet(elem.second)) {
			result->addElement(elem.first, elem.second);
		}
	}
	return result;
}

SetMap* SetMap::differenceSet(SetMap* otherSet) {
	SetMap* result = new SetMap();
	for (const auto& elem : Set) {
		if (!otherSet->isInSet(elem.second)) {
			result->addElement(elem.first, elem.second);
		}
	}
	return result;
}

SetMap* SetMap::symmetricDifferenceSet(SetMap* otherSet) {
	SetMap* setUnion = unionSet(otherSet);
	SetMap* setIntersection = intersectionSet(otherSet);
	return setUnion->differenceSet(setIntersection);
}