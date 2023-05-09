#include "Class.h"

// F1 Создать пустое множество.
Set::Set() {
    head = nullptr;
}
// F8 Удаление множества.
Set::~Set() {
    while (head != nullptr)
    {
        Node* next = head->next;
        delete head;
        head = next;
    }
}
// F2 Проверка на пустое множество.
bool Set::isEmpty() {
    return head == nullptr;
}
// F3 Проверка на принадлежность элемента множеству.
bool Set::isInSet(int element) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->value == element) {
            return true;
        }
    }
    return false;
}
// F4 Добавление нового элемента в начало множества.
void Set::addElement(int element) {
    if (!isInSet(element)) {
        Node* newNode = new Node;
        newNode->value = element;
        newNode->next = head;
        head = newNode;
    }
}

int rndClass(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

// F5 Создание множества.
Set::Set(int numElements, int minValue, int maxValue) {
    head = nullptr;
    if (minValue > maxValue || numElements <= 0 || maxValue - minValue < numElements) {
        return;
    }
    Node* prevHead = head;
    while (numElements) {
        int value = rndClass(minValue, maxValue);
        addElement(value);
        if (head != prevHead) {
            numElements--;
        }
        prevHead = head;
    }
}
// F6 Мощность множества.
int Set::setSize() {
    if (isEmpty()) {
        return 0;
    }
    int len = 0;
    for (Node* temp = head; temp != nullptr; temp = temp->next) {
        len++;
    }
    return len;
}
// F7 Вывод элементов множества.
string Set::printSet(char delim) {
    string output = "";
    if (isEmpty()) {
        return output;
    }
    for (Node* current = head; current != nullptr; current = current->next) {
        output += to_string(current->value);
        output += delim;
    }
    return output.erase(output.length() - 1, output.length());
}
//F9 Подмножество А-В.
bool Set::isSubset(Set* otherSet) {
    if (isEmpty()) return true;
    for (Node* current = otherSet->head; current != nullptr; current = current->next) {
        if (!isInSet(current->value)) {
            return false;
        }
    }
    return true;
}
//F10 Равенство двух множеств А-В.
bool Set::areEqual(Set* otherSet) {
    return isSubset(otherSet) && otherSet->isSubset(this);
}
//F11 Объединение двух множеств.
Set* Set::unionSet(Set* otherSet) {
    Set* resultSet = new Set();
    Node* current = head;
    while (current != nullptr) {
        resultSet->addElement(current->value);
        current = current->next;
    }
    current = otherSet->head;
    while (current != nullptr) {
        resultSet->addElement(current->value);
        current = current->next;
    }
    return resultSet;
}
//F12 Пересечение двух множеств.
Set* Set::intersectionSet(Set* otherSet) {
    Set* resultSet = new Set();
    for (Node* current = otherSet->head; current != nullptr; current = current->next) {
        if (isInSet(current->value)) {
            resultSet->addElement(current->value);
        }
    }
    return resultSet;
}
//F13 Разность множеств.
Set* Set::differenceSet(Set* otherSet) {
    Set* resultSet = new Set();
    for (Node* current = head; current != nullptr; current = current->next) {
        if (!otherSet->isInSet(current->value)) {
            resultSet->addElement(current->value);
        }
    }
    return resultSet;
}
//F14 Симметричная разность.
Set* Set::symmetricDifferenceSet(Set* otherSet) {
    Set* interSet = intersectionSet(otherSet);
    Set* unSet = unionSet(otherSet);
    return unSet->differenceSet(interSet);
}