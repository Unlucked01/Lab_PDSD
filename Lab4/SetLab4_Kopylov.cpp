#include "SetLab4_Kopylov.h"

// F1 Создать пустое множество.
SetList::SetList() {
	Set = list<int>();
}
// F2 Проверка на пустое множество.
bool SetList::isEmpty() {
	return Set.empty();
}
// F3 Проверка на принадлежность элемента множеству.
bool SetList::isInSet(int val) {
	list<int>::iterator it = find(Set.begin(), Set.end(), val);
	if (it != Set.end()) {
		return true;
	}
	return false;
}
// F4 Добавление нового элемента в начало множества.
void SetList::addElement(int val) {
	if (isInSet(val)) {
		return;
	}
	else {
		Set.push_front(val);
	}
}
// F5 Создание множества.
SetList::SetList(int length, int minValue, int maxValue, int delim) {
	Set = list<int>();
	if (length > 0 && maxValue > minValue && length < maxValue - minValue) {
		list<int>::iterator pred_node = Set.begin();
		while (length > 0) {
			srand(time(NULL));
			int value = minValue + rand() % (maxValue - minValue);
			if (value % delim == 0) {
				addElement(value);
			}
			if (Set.begin() != pred_node) {
				length--;
			}
			pred_node = Set.begin();
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
		int length = result.length();
		return result.erase(length - 1, length);
	}
	return "";
}
// F8 Удаление множества.
SetList::~SetList() {
	Set.clear();
}
//F9 Подмножество А-В.
bool SetList::isSubset(SetList* subSet) {
	if (isEmpty()) {
		return true;
	}
	for (int elem : Set) {

		if (!isInSet(elem)) {
			return false;
		}
	}
	return true;
}
//F10 Равенство двух множеств А-В.
bool SetList::areEqual(SetList* second_set) {
	return isSubset(second_set) && second_set->isSubset(this);
}
//F11 Объединение двух множеств.
SetList* SetList::unionSet(SetList* second_set) {
	SetList* result_set = new SetList();
	for (int elem : Set) {
		result_set->addElement(elem);
	}
	for (int elem : second_set->Set) {
		result_set->addElement(elem);
	}
	return result_set;
}
//F12 Пересечение двух множеств.
SetList* SetList::intersectionSet(SetList* second_set) {
	SetList* result_set = new SetList();
	for (int elem : second_set->Set) {

		if (isInSet(elem)) {
			result_set->addElement(elem);
		}
	}
	return result_set;
}
//F13 Разность множеств.
SetList* SetList::differenceSet(SetList* second_set) {

	SetList* result_set = new SetList();
	for (int elem : Set) {
		if (!second_set->isInSet(elem)) {
			result_set->addElement(elem);
		}
	}
	return result_set;
}
//F14 Симметричная разность.
SetList* SetList::symmetricDifferenceSet(SetList* second_set) {
	SetList* setUnion = unionSet(second_set);
	SetList* setIntersection = intersectionSet(second_set);
	return setUnion->differenceSet(setIntersection);
}