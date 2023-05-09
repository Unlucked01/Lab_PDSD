#include "Struct.h"

Node* createEmptySet() {
	return nullptr;
}

bool isEmpty(Node* head) {
	return head == nullptr;
}

bool isInSet(Node* head, int value) {
	if (!isEmpty(head)) {
		for (Node* item = head; item != nullptr; item = item->next) {
			if (item->value == value) {
				return true;
			}
		}
	}
	return false;
}

Node* addElement(Node* head, int value) {
	if (isInSet(head, value)) {
		return head;
	}
	else {
		Node* node = new Node();
		node->next = head;
		node->value = value;
		return node;
	}
}

int rnd(int min, int max) {
	std::random_device rd;  
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

Node* createSet(int len, int min, int max) {
	Node* set = createEmptySet();
	if (len > 0 && max > min && len < max - min) {
		Node* pred_node = set;
		while (len > 0) {
			int value = rnd(min, max);
			set = addElement(set, value);
			
			if (set != pred_node) {
				len--;
			}
			pred_node = set;
		}
	}
	return set;
}

int powerSet(Node* head) {
	if (isEmpty(head)) {
		return 0;
	}
	else {
		int len = 0;
		for (Node* item = head; item != nullptr; item = item->next) {
			len++;
		}
		return len;
	}
}

string toString(Node* head, char delim) {
	if (!isEmpty(head)) {
		std::string result = "";
		for (Node* item = head; item != nullptr; item = item->next) {
			result += to_string(item->value);
			result += delim;
		}
		int len = result.length();
		return result.erase(len - 1, len);
	}
	return "";
}

Node* deleteSet(Node* head) {
	if (!isEmpty(head)) {
		Node* result_ptr = deleteSet(head->next);
		delete head;
		head = result_ptr;
	}
	else {
		return nullptr;
	}
}

bool isSubset(Node* A, Node* B) {
	if (isEmpty(A)) {
		return true;
	}
	for (Node* sub_elem = A; sub_elem != nullptr; sub_elem = sub_elem->next) {
		if (!isInSet(B, sub_elem->value)) {
			return false;
		}
	}
	return true;
}

bool areEqual(Node* A, Node* B) {
	return isSubset(A,B) && isSubset(B,A);
}

Node* unionSet(Node* A, Node* B) {
	Node* result = createEmptySet();
	for (Node* first_elem = A; first_elem != nullptr; first_elem = first_elem->next) {
		if (isInSet(B, first_elem->value)) {
			result = addElement(result, first_elem->value);
		}
	}
	return result;
}

Node* intersectionSet(Node* A, Node* B) {
	Node* result = createEmptySet();
	for (Node* first_elem = A; first_elem != nullptr; first_elem = first_elem->next) {
		if (isInSet(B, first_elem->value)) {
			result = addElement(result, first_elem->value);
		}
	}
	return result;
}

Node* differenceSet(Node* A, Node* B) {
	Node* result = createEmptySet();
	for (Node* first_elem = A; first_elem != nullptr; first_elem = first_elem->next) {
		if (!isInSet(B, first_elem->value)) {
			result = addElement(result, first_elem->value);
		}
	}
	return result;
}

Node* symmetricDifferenceSet(Node* A, Node* B) {
	return differenceSet(unionSet(A,B),intersectionSet(A,B));
}