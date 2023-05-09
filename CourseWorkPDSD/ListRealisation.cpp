#include "List.h"

// F1 Создать пустое множество.
SetList::SetList() {
	Set = list<int>();
}
// F2 Проверка на пустое множество.
bool SetList::isEmpty() {
	return Set.empty();
}
// F3 Проверка на принадлежность элемента множеству.
bool SetList::isInSet(int value) {
	return find(Set.begin(), Set.end(), value) != Set.end();
}
// F4 Добавление нового элемента в начало множества.
void SetList::addElement(int value) {
	if (isInSet(value)) {
		return;
	}
	else {
		Set.push_front(value);
	}
}

int rndList(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

// F5 Создание множества.
SetList::SetList(int length, int minValue, int maxValue) {
	SetList();
	if (length > 0 && maxValue > minValue && length < maxValue - minValue) {
		list<int>::iterator firstElement = Set.begin();
		while (length > 0) {
			int value = rndList(minValue, maxValue);
			 
			addElement(value);
			
			if (Set.begin() != firstElement) {
				length--;
			}
			firstElement = Set.begin();
		}
	}
}
// F6 Мощность множества.
int SetList::setSize() {
	return Set.size();
}
// F7 Вывод элементов множества.
string SetList::printSet(char separator) {
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
SetList::~SetList() {
	Set.clear();
}
//F9 Подмножество А-В.
bool SetList::isSubset(SetList* secondSet) {
	if (isEmpty()) {
		return true;
	}
	for (int elem : secondSet->Set) {
		if (!isInSet(elem)) {
			return false;
		}
	}
	return true;
}
//F10 Равенство двух множеств А-В.
bool SetList::areEqual(SetList* secondSet) {
	return isSubset(secondSet) && secondSet->isSubset(this);
}
//F11 Объединение двух множеств.
SetList* SetList::unionSet(SetList* secondSet) {
	SetList* resultSet = new SetList();
	for (int elem : Set) {
		resultSet->addElement(elem);
	}
	for (int elem : secondSet->Set) {
		resultSet->addElement(elem);
	}
	return resultSet;
}
//F12 Пересечение двух множеств.
SetList* SetList::intersectionSet(SetList* secondSet) {
	SetList* resultSet = new SetList();
	for (int elem : secondSet->Set) {
		if (isInSet(elem)) {
			resultSet->addElement(elem);
		}
	}
	return resultSet;
}
//F13 Разность множеств.
SetList* SetList::differenceSet(SetList* secondSet) {
	SetList* resultSet = new SetList();
	for (int elem : Set) {
		if (!secondSet->isInSet(elem)) {
			resultSet->addElement(elem);
		}
	}
	return resultSet;
}
//F14 Симметричная разность.
SetList* SetList::symmetricDifferenceSet(SetList* secondSet) {
	SetList* setUnion = unionSet(secondSet);
	SetList* setIntersection = intersectionSet(secondSet);
	return setUnion->differenceSet(setIntersection);
}