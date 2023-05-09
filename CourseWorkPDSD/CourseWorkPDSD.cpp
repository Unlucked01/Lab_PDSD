#include "Node.h"
#include "Class.h"
#include "Struct.h"
#include "Map.h"
#include "Set.h"
#include "List.h"
#include "Deque.h"

template <typename Func>
long measureTime(Func&&);

int validate();
void printHeaders();
void printData(int N);
void printRow(long);
void printRowName(int);
void delim();

const int col_width = 22;
const char delimiter = '-';
const string row_delimiter = " | ";

int main()
{
    int N = validate();
    printHeaders();
    printData(N);
}

void printData(int N) {
    printRowName(0);
    printRow(measureTime([&] { return new Node * (createSet(N, 0, N * 10)); }));
    printRow(measureTime([&] { return new Set(Set::Set(N, 0, N * 10)); }));
    printRow(measureTime([&] { return new SetList(SetList::SetList(N, 0, N * 10)); }));
    printRow(measureTime([&] { return new SetSet(SetSet::SetSet(N, 0, N * 10)); }));
    printRow(measureTime([&] { return new SetDeque(SetDeque::SetDeque(N, 0, N * 10)); }));
    printRow(measureTime([&] { return new SetMap(SetMap::SetMap(N, 0, N * 10)); }));
    delim();

    Node* setNodeA = createSet(N, 0, N * 10);
    Node* setNodeB = createSet(N, 0, N * 10);

    Set* setA = new Set(N, 0, N * 10);
    Set* setB = new Set(N, 0, N * 10);

    SetList* setListA = new SetList(N, 0, N * 10);
    SetList* setListB = new SetList(N, 0, N * 10);

    SetSet* setSetA = new SetSet(N, 0, N * 10);
    SetSet* setSetB = new SetSet(N, 0, N * 10);

    SetDeque* setDequeA = new SetDeque(N, 0, N * 10);
    SetDeque* setDequeB = new SetDeque(N, 0, N * 10);

    SetMap* setMapA = new SetMap(N, 0, N * 10);
    SetMap* setMapB = new SetMap(N, 0, N * 10);


    printRowName(1);
    printRow(measureTime([&] { return powerSet(setNodeA); }));
    printRow(measureTime([&] { return setA->setSize(); }));
    printRow(measureTime([&] { return setListA->setSize(); }));
    printRow(measureTime([&] { return setSetA->setSize(); }));
    printRow(measureTime([&] { return setDequeA->setSize(); }));
    printRow(measureTime([&] { return setMapA->setSize(); }));
    delim();
    printRowName(2);
    printRow(measureTime([&] { return isSubset(setNodeA, setNodeA); }));
    printRow(measureTime([&] { return setB->isSubset(setA); }));
    printRow(measureTime([&] { return setListB->isSubset(setListA); }));
    printRow(measureTime([&] { return setSetB->isSubset(setSetA); }));
    printRow(measureTime([&] { return setDequeB->isSubset(setDequeA); }));
    printRow(measureTime([&] { return setMapB->isSubset(setMapA); }));
    delim();
    printRowName(3);
    printRow(measureTime([&] { return isSubset(setNodeA, setNodeA); }));
    printRow(measureTime([&] { return setA->areEqual(setA); }));
    printRow(measureTime([&] { return setListA->areEqual(setListA); }));
    printRow(measureTime([&] { return setSetA->areEqual(setSetA); }));
    printRow(measureTime([&] { return setDequeA->areEqual(setDequeA); }));
    printRow(measureTime([&] { return setMapA->areEqual(setMapA); }));
    delim();
    printRowName(4);
    printRow(measureTime([&] { return areEqual(setNodeA, setNodeA); }));
    printRow(measureTime([&] { return setA->areEqual(setA); }));
    printRow(measureTime([&] { return setListA->areEqual(setListA); }));
    printRow(measureTime([&] { return setSetA->areEqual(setSetA); }));
    printRow(measureTime([&] { return setDequeA->areEqual(setDequeA); }));
    printRow(measureTime([&] { return setMapA->areEqual(setMapA); }));
    delim();
    printRowName(5);
    printRow(measureTime([&] { return areEqual(setNodeB, setNodeA); }));
    printRow(measureTime([&] { return setA->areEqual(setA); }));
    printRow(measureTime([&] { return setListA->areEqual(setListA); }));
    printRow(measureTime([&] { return setSetA->areEqual(setSetA); }));
    printRow(measureTime([&] { return setDequeA->areEqual(setDequeA); }));
    printRow(measureTime([&] { return setMapA->areEqual(setMapA); }));
    delim();
    printRowName(6);
    printRow(measureTime([&] { return unionSet(setNodeA, setNodeB); }));
    printRow(measureTime([&] { return setA->unionSet(setA); }));
    printRow(measureTime([&] { return setListA->unionSet(setListA); }));
    printRow(measureTime([&] { return setSetA->unionSet(setSetA); }));
    printRow(measureTime([&] { return setDequeA->unionSet(setDequeA); }));
    printRow(measureTime([&] { return setMapA->unionSet(setMapA); }));
    delim();
    printRowName(7);
    printRow(measureTime([&] { return intersectionSet(setNodeA, setNodeB); }));
    printRow(measureTime([&] { return setA->intersectionSet(setB); }));
    printRow(measureTime([&] { return setListA->intersectionSet(setListB); }));
    printRow(measureTime([&] { return setSetA->intersectionSet(setSetB); }));
    printRow(measureTime([&] { return setDequeA->intersectionSet(setDequeB); }));
    printRow(measureTime([&] { return setMapA->intersectionSet(setMapB); }));
    delim();
    printRowName(8);
    printRow(measureTime([&] { return differenceSet(setNodeA, setNodeB); }));
    printRow(measureTime([&] { return setA->differenceSet(setB); }));
    printRow(measureTime([&] { return setListA->differenceSet(setListB); }));
    printRow(measureTime([&] { return setSetA->differenceSet(setSetB); }));
    printRow(measureTime([&] { return setDequeA->differenceSet(setDequeB); }));
    printRow(measureTime([&] { return setMapA->differenceSet(setMapB); }));
    delim();
    printRowName(9);
    printRow(measureTime([&] { return differenceSet(setNodeB, setNodeA); }));
    printRow(measureTime([&] { return setB->differenceSet(setA); }));
    printRow(measureTime([&] { return setListB->differenceSet(setListA); }));
    printRow(measureTime([&] { return setSetB->differenceSet(setSetA); }));
    printRow(measureTime([&] { return setDequeB->differenceSet(setDequeA); }));
    printRow(measureTime([&] { return setMapB->differenceSet(setMapA); }));
    delim();
    printRowName(10);
    printRow(measureTime([&] { return symmetricDifferenceSet(setNodeA, setNodeB); }));
    printRow(measureTime([&] { return setA->symmetricDifferenceSet(setB); }));
    printRow(measureTime([&] { return setListA->symmetricDifferenceSet(setListB); }));
    printRow(measureTime([&] { return setSetA->symmetricDifferenceSet(setSetB); }));
    printRow(measureTime([&] { return setDequeA->symmetricDifferenceSet(setDequeB); }));
    printRow(measureTime([&] { return setMapA->symmetricDifferenceSet(setMapB); }));
    delim();
}

int validate() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    cout << "Для выхода введите exit" << endl;
    string str;
    regex reg("\\d{1,6}");
    do {
        cout << "Введите колличество элементов (целое неотрицательное число): ";
        cin >> str;
    } while (str != "exit" && (!regex_match(str, reg)));
    return stoi(str);
}

template <typename Func>
long measureTime(Func&& func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto result = chrono::high_resolution_clock::now();;
    return chrono::duration_cast<chrono::microseconds>(result - start).count();
}

void delim() {
    cout << endl << setfill(delimiter) << setw((col_width + 3) * 7) << "" << endl;
}

void printHeaders() {
    vector<string> headers = { " ","Односвязный список", "Класс список", "List", "Set",
        "Deque","Map" };

    delim();
    for (const auto& header : headers) {
        cout << left << setw(col_width) << setfill(' ') << header << row_delimiter;
    }
    delim();
};

void printRowName(int position) {
    vector<string> rows = { "Создание множества", "Мощность", "Подмножество A-A", "Подмножество B-A",
        "Равенство A-A", "Равенство B-A", "Объединение", "Пересечение",
        "Разность A-B","Разность B-A", "Симмметричная разность" };

    cout << left << setw(col_width) << setfill(' ') << rows[position] << row_delimiter;
}

void printRow(long row) {
    cout << left << setw(col_width) << setfill(' ') << row << row_delimiter;
}