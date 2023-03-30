#include "SetLab4_Kopylov.h"

void delim();

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	SetList* setA = new SetList((rand() % 4) + 6, 10, 99, 3);
	SetList* setB = new SetList((rand() % 4) + 6, 10, 99, 6);
	delim();
	cout << "Вывод множества A, элементы которого кратны 3 - " << setA->printSet(' ') << " (мощность множества - " << setA->setSize() << ")\n";
	cout << "Вывод множества B, элементы которого кратны 6 - " << setB->printSet(' ') << " (мощность множества - " << setB->setSize() << ")\n";
	delim();
    cout << "A является подмножеством B: " << boolalpha << setA->isSubset(setB) << "\n";
    cout << "A является подмножеством A: " << boolalpha << setA->isSubset(setA) << "\n";
    delim();
    cout << "A равняется B: " << boolalpha << setA->areEqual(setB) << "\n";
    cout << "A равняется A: " << boolalpha << setA->areEqual(setA) << "\n";
    delim();
    cout << "Обьединение множеств A и B - " << setA->unionSet(setB)->printSet(' ') << "\n";
    delim();
    cout << "Пересечение множеств A и B - " << setA->intersectionSet(setB)->printSet(' ') << "\n";
    delim();
    cout << "Разность множеств A и B - " << setA->differenceSet(setB)->printSet(' ') << "\n";
    cout << "Разность множеств B и A - " << setB->differenceSet(setA)->printSet(' ') << "\n";
    delim();
    cout << "Симметричная разность множеств A и B - " << setA->symmetricDifferenceSet(setB)->printSet(' ') << "\n";
    delim();
}

void delim() {
	cout << string(100, '-') << endl;
}