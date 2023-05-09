#include "Deque.h"

SetDeque::SetDeque() {
	this->Set = deque<int>();
}

bool SetDeque::isEmpty() {
	return Set.empty();
}

bool SetDeque::isInSet(int value) {
	return find(Set.begin(), Set.end(), value) != Set.end();
}

bool SetDeque::addElement(int value) {
	if (!isInSet(value)) {
		Set.push_front(value);
		return true;
	}
	return false;
}

int rndDeque(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

SetDeque::SetDeque(int len, int min, int max) {
	Set = deque<int>();
	if (len > 0 && max > min && len < max - min) {
		while (len > 0) {
			int value = rndDeque(min, max);
			if (addElement(value)) {
				len--;
			}
		}
	}
}

int SetDeque::setSize() {
	return Set.size();
}

string SetDeque::printSet(char delim) {
	if (!isEmpty()) {
		string result = "";
		for (int elem : Set) {
			result += to_string(elem);
			result += delim;
		}
		int len = result.length();
		return result.erase(len - 1, len);
	}
	return "";
}

SetDeque::~SetDeque() {
	Set.clear();
}

bool SetDeque::isSubset(SetDeque* subSet) {
	if (isEmpty()) {
		return true;
	}
	for (int elem : subSet->Set) {
		if (!isInSet(elem)) {
			return false;
		}
	}
	return true;
}

bool SetDeque::areEqual(SetDeque* otherSet) {
	return isSubset(otherSet) && otherSet->isSubset(this);
}

SetDeque* SetDeque::unionSet(SetDeque* otherSet) {
	SetDeque* result = new SetDeque();
	for (int elem : Set) {
		result->addElement(elem);
	}
	for (int elem : otherSet->Set) {
		result->addElement(elem);
	}
	return result;
}

SetDeque* SetDeque::intersectionSet(SetDeque* otherSet) {
	SetDeque* result = new SetDeque();
	for (int elem : otherSet->Set) {
		if (isInSet(elem)) {
			result->addElement(elem);
		}
	}
	return result;
}

SetDeque* SetDeque::differenceSet(SetDeque* otherSet) {
	SetDeque* result = new SetDeque();
	for (int elem : Set) {
		if (!otherSet->isInSet(elem)) {
			result->addElement(elem);
		}
	}
	return result;
}

SetDeque* SetDeque::symmetricDifferenceSet(SetDeque* otherSet) {
	SetDeque* setUnion = unionSet(otherSet);
	SetDeque* setIntersection = intersectionSet(otherSet);
	return setUnion->differenceSet(setIntersection);
}