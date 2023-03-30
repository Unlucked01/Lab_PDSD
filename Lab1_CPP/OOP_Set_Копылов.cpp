#include "Set.h";

void delim();

int main() {
	system("chcp 65001");
	srand(time(NULL));
    Set setA((rand() % 4) + 6, 10, 99, 3);
    Set setB((rand() % 4) + 6, 10, 99, 6);
    delim();
    cout << "Вывод множества A, элементы которого кратны 3 - " << setA.printSet(' ') << " (мощность множества - " << setA.setSize() << ")\n";
    cout << "Вывод множества B, элементы которого кратны 6 - " << setB.printSet(' ') << " (мощность множества - " << setB.setSize() << ")\n";
    delim();
    cout << "A является подмножеством B: " << boolalpha << setA.isSubset(&setB) << "\n";
    cout << "A является подмножеством A: " << boolalpha << setA.isSubset(&setA) << "\n";
    delim();
    cout << "A равняется B: " << boolalpha << setA.areEqual(&setB) << "\n";
    cout << "A равняется A: " << boolalpha << setA.areEqual(&setA) << "\n"; 
    delim();
    cout << "Обьединение множеств A и B - " << setA.unionSet(&setB)->printSet(' ') << "\n";
    delim();
    cout << "Пересечение множеств A и B - " << setA.intersectionSet(&setB)->printSet(' ') << "\n";
    delim();
    cout << "Разность множеств A и B - " << setA.differenceSet(&setB)->printSet(' ') << "\n";
    cout << "Разность множеств B и A - " << setB.differenceSet(&setA)->printSet(' ') << "\n";
    delim();
    cout << "Симметричная разность множеств A и B - " << setA.symmetricDifference(&setB)->printSet(' ') << "\n";
    delim();
}

void delim() {
	cout << string(100, '-') << endl;
}

/*
    Node* A = createSet((rand() % 4) + 6, 10, 99,'A');
    Node* B = createSet((rand() % 4) + 6, 10, 99,'B');
    delim();
    std::cout << "Âûâîä ìíîæåñòâà À, ÷èñëà êðàòíûå 3 - " << printSet(A, ' ');
    std::cout << "Âûâîä ìíîæåñòâà B, ÷èñëà êðàòíûå 6 - " << printSet(B, ' ');
    delim();
    std::cout << "A ÿâëÿåñòñÿ ïîäìíîæåñòâîì B: " << std::boolalpha << isSubset(A, B) << "\n";
    std::cout << "A ÿâëÿåñòñÿ ïîäìíîæåñòâîì A: " << std::boolalpha << isSubset(A, A) << "\n";
    delim();
    std::cout << "A ðàâíÿåòñÿ B: " << std::boolalpha << areEqual(A, B) << "\n";
    std::cout << "A ðàâíÿåòñÿ A: " << std::boolalpha << areEqual(A, A) << "\n";
    delim();
    std::cout << "Îáüåäèíåíèå ìíîæåñòâà À è B - " << printSet(unionSet(A, B), ' ');
    delim();
    std::cout << "Ïåðåñå÷åíèÿ ìíîæåñòâà À è B - " << printSet(intersectionSet(A, B), ' ');
    delim();
    std::cout << "Ðàçíîñòü ìíîæåñòâ À è B - " << printSet(differenceSet(A, B), ' ');
    std::cout << "Ðàçíîñòü ìíîæåñòâ B è A - " << printSet(differenceSet(B, A), ' ');
    delim();
    std::cout << "Ñèììåòðè÷íàÿ ðàçíîñòü ìíîæåñòâà À è B - " << printSet(symmetricDifference(A, B), ' ');
    delim();
    return 0;*/