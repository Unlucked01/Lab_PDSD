//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <stdio.h>
//#include <windows.h>
//#include <regex>
//
//using namespace std;
//
//const int col_width = 22;
//const char delimiter = '-';
//const string row_delimiter = " | ";
//
//void delim() {
//    cout << endl << setfill(delimiter) << setw((col_width + 3) * 7) << "" << endl;
//}
//
//int validate() {
//        SetConsoleOutputCP(1251);
//        SetConsoleCP(1251);
//        setlocale(LC_ALL, "ru");
//        cout << "��� ������ ������� exit" << endl;
//        string str;
//        regex reg("\\d{1,6}");
//        do {
//            cout << "������� ����������� ��������� (����� ��������������� �����): ";
//            cin >> str;
//        } while (str != "exit" && (!regex_match(str, reg)));
//        return stoi(str);
//    }
//
//void printHeaders() {
//    vector<string> headers = { " ","����������� ������", "����� ������", "List", "Set",
//        "Deque","Map" };
//
//    delim();
//    for (const auto& header : headers) {
//        cout << left << setw(col_width) << setfill(' ') << header << row_delimiter;
//    }
//    delim();
//};
//
//void printRowName(int position) {
//    vector<string> rows = { "�������� ���������", "��������", "������������ A-A", "������������ B-A",
//        "��������� A-A", "��������� B-A", "�����������", "�����������",
//        "�������� A-B","�������� B-A", "������������� ��������" };
//
//    cout << left << setw(col_width) << setfill(' ') << rows[position] << row_delimiter;
//}
//
//void printRow() {
//    cout << left << setw(col_width) << setfill(' ') << " " << row_delimiter;
//}
//
//void main() {
//    validate();
//    printHeaders();
//    printRowName(0);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(1);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(2);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(3);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(4);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(5);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(6);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(7);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(8);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(9);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//    printRowName(10);
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    printRow();
//    delim();
//}