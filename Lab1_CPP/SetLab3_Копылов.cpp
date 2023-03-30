//#include "Node.h"
//
//// F1 Создать пустое множество.
////Node* createEmptySet() {
////	return nullptr;
////}
//// F2 Проверка на пустое множество.
//bool Set::isEmpty(Node* head) {
//	return head == nullptr;
//}
//// F3 Проверка на принадлежность элемента множеству.
//bool isInSet(Node* head, int element) {
//	if (isEmpty(head)) {
//		return false;
//	}
//	Node* current = head;
//	while (current != nullptr) {
//		if (current->value == element) {
//			return true;
//		}
//		current = current->next;
//	}
//	return false;
//}
//// F4 Добавление нового элемента в начало множества.
//Node* addElement(Node* head, int element) {
//	if (!isInSet(head, element)) {
//		Node* newNode = new Node;
//		newNode->value = element;
//		newNode->next = head;
//		head = newNode;
//	}
//	return head;
//}
//// F5 Создание множества.
//Node* createSet(int numElements, int minValue, int maxValue, char setIdentifier) {
//	Node* head = createEmptySet();
//	if (minValue > maxValue || numElements <= 0 || maxValue - minValue < numElements) {
//		return head;
//	}
//	srand(time(NULL));
//	Node* prevHead;
//	while (numElements) {
//		prevHead = head;
//		int value = minValue + rand() % (maxValue - minValue);
//		if (setIdentifier == 'A' && value % 3 == 0) {
//			head = addElement(head, value);
//		}
//		else if (setIdentifier == 'B' && value % 6 == 0) {
//			head = addElement(head, value);
//		}
//		if (prevHead != head) {
//			numElements--;
//		}
//	}
//	return head;
//}
//// F6 Мощность множества.
//int setSize(Node* head) {
//	if (isEmpty(head)) {
//		return 0;
//	}
//	int size = 0;
//	for (Node* current = head; current != nullptr; current = current->next) {
//		size++;
//	}
//	return size;
//}
//// F7 Вывод элементов множества.
//std::string printSet(Node* head, char separator) {
//	std::string output;
//	if (isEmpty(head)) {
//		return output += "\n";
//	}
//	while (head != nullptr) {
//		output += std::to_string(head->value);
//		output += separator;
//		head = head->next;
//	}
//	return output.erase(output.length() - 1,output.length()) += "\n";
//}
//// F8 Удаление множества.
//Node* deleteSet(Node* head) {
//	while (head != nullptr) {
//		Node* next = head->next;
//		delete head;
//		head = next;
//	}
//	return head;
//}
////F9 Подмножество А-В.
//bool isSubset(Node* subSetA, Node* setB) {
//	if (isEmpty(subSetA)) {
//		return true;
//	}
//	while (subSetA != nullptr) {
//		if (!isInSet(setB, subSetA->value)) {
//			return false; 
//		}
//		subSetA = subSetA->next;
//	}
//	return true;
//}
////F10 Равенство двух множеств А-В.
//bool areEqual(Node* setA, Node* setB) {
//	return isSubset(setA, setB) && isSubset(setB, setA);
//}
////F11 Объединение двух множеств.
//Node* unionSet(Node* setA, Node* setB) {
//	Node* result = createEmptySet();
//	while (setA != nullptr) {
//		result = addElement(result,setA->value);
//		setA = setA->next;
//	}
//	while (setB != nullptr) {
//		result = addElement(result, setB->value);
//		setB = setB->next;
//	}
//	return result;
//}
////F12 Пересечение двух множеств.
//Node* intersectionSet(Node* setA, Node* setB) {
//	Node* result = createEmptySet();
//	while (setA != nullptr) {
//		if (isInSet(setB, setA->value)) {
//			result = addElement(result, setA->value);
//		}
//		setA = setA->next;
//	}
//	return result;
//}
////F13 Разность множеств.
//Node* differenceSet(Node* setA, Node* setB) {
//	Node* result = createEmptySet();
//	for (Node* current = setA; current != nullptr; current = current->next) {
//		if (!isInSet(setB, current->value)) {
//			result = addElement(result, current->value);
//		}
//	}
//	return result;
//}
////F14 Симметричная разность.
//Node* symmetricDifference(Node* setA, Node* setB) {
//	return differenceSet(unionSet(setA, setB), intersectionSet(setA, setB));
//}
//

#include "Set.h"

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
// F5 Создание множества.
Set::Set(int numElements, int minValue, int maxValue, int delimeter) {
    if (minValue > maxValue || numElements <= 0 || maxValue - minValue < numElements) {
    	return;
    }
    Node* prevHead = head;
    while (numElements) {
        int value = minValue + rand() % (maxValue - minValue);
        if (value % delimeter == 0) {
        	addElement(value);
            if (head != prevHead) {
                numElements--;
            }
            prevHead = head;
        }
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
string Set::printSet(char separator) {
    string output = "";
    if (isEmpty()) {
        return output;
    }
    for (Node* current = head; current != nullptr; current = current->next) {
        output += to_string(current->value);
        output += separator;
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
Set* Set::symmetricDifference(Set* otherSet) {
    Set* interSet = intersectionSet(otherSet);
    Set* unSet = unionSet(otherSet);
    return unSet->differenceSet(interSet);
}