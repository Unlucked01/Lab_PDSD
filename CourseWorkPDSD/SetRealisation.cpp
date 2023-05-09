#include "Set.h"

// F1 Создать пустое множество.
SetSet::SetSet() {
	Set = set<int>();
}
// F2 Проверка на пустое множество.
bool SetSet::isEmpty() {
	return Set.empty();
}
// F3 Проверка на принадлежность элемента множеству.
bool SetSet::isInSet(int val) {
	return Set.contains(val);
}
// F4 Добавление нового элемента в начало множества.
bool SetSet::addElement(int val) {
	return Set.insert(val).second;
}

int rndSet(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

// F5 Создание множества.
SetSet::SetSet(int length, int minValue, int maxValue) {
	SetSet();
	if (length > 0 && maxValue > minValue && length < maxValue - minValue) {
		while (length > 0) {
			srand(time(NULL));
			int value = rndSet(minValue, maxValue);
			if (addElement(value)) {
				length--;
			}
		}
	}
}
// F6 Мощность множества.
int SetSet::setSize() {
	return Set.size();
}
// F7 Вывод элементов множества.
string SetSet::printSet(char separator) {
	if (!isEmpty()) {
		string result = "";
		for (int elem : Set) {
			result += to_string(elem);
			result += separator;
		}
		return result.erase(result.length() - 1, result.length());
	}
	return "";
}
// F8 Удаление множества.
SetSet::~SetSet() {
	Set.clear();
}
//F9 Подмножество А-В.
bool SetSet::isSubset(SetSet* subSet) {
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
//F10 Равенство двух множеств А-В.
bool SetSet::areEqual(SetSet* secondSet) {
	return isSubset(secondSet) && secondSet->isSubset(this);
}
//F11 Объединение двух множеств.
SetSet* SetSet::unionSet(SetSet* secondSet) {
	SetSet* result_set = new SetSet();
	result_set->Set.insert(Set.begin(), Set.end());
	result_set->Set.insert(secondSet->Set.begin(), secondSet->Set.end());
	return result_set;
}
//F12 Пересечение двух множеств.
SetSet* SetSet::intersectionSet(SetSet* secondSet) {
	SetSet* result_set = new SetSet();
	for (int elem : secondSet->Set) {
		if (isInSet(elem)) {
			result_set->addElement(elem);
		}
	}
	return result_set;
}
//F13 Разность множеств.
SetSet* SetSet::differenceSet(SetSet* secondSet) {
	SetSet* result_set = new SetSet();
	for (int elem : Set) {
		if (!secondSet->isInSet(elem)) {
			result_set->addElement(elem);
		}
	}
	return result_set;
}
//F14 Симметричная разность.
SetSet* SetSet::symmetricDifferenceSet(SetSet* secondSet) {
	SetSet* setUnion = unionSet(secondSet);
	SetSet* setIntersection = intersectionSet(secondSet);
	return setUnion->differenceSet(setIntersection);
}