#include <iostream>
#include <string>
#include <vector>
#include "School.h"
#include "University.h"
#include <algorithm>


#pragma once;

using namespace std;

void Test_12_13_14() {
	University establish("����");
	establish.Add(new StudyGroup("1"));
	establish.Add(new StudyGroup("2"));
	establish.Add(new StudyGroup("3"));
	establish.Add(new StudyGroup("4"));
	establish.Add(new StudyGroup("5"));
	establish.Add(new StudyGroup("6"));

	establish.AddToSchedule(establish.GetStudyGroups()[0], even, monday, 1, smallstream, "2", "����������������", "������� �������������");
	establish.AddToSchedule(establish.GetStudyGroups()[1], even, monday, 1, smallstream, "2", "����������������", "������� �������������");
	establish.AddToSchedule(establish.GetStudyGroups()[2], even, monday, 1, smallstream, "2", "����������������", "������� �������������");
	establish.AddToSchedule(establish.GetStudyGroups()[3], even, monday, 1, smallstream, "2", "����������������", "������� �������������");

	establish.AddToSchedule(establish.GetStudyGroups()[0], odd, tuesday, 3, cabinet, "203", "���������", "����� ������������");

	establish.Delete(0);

	if (establish.GetTeacherSchedule().size() == 1) {
		cout << "���� 12 �������" << endl;
	}
	else {
		cout << "���� 12 �� �������" << endl;
	}

	for (auto i : establish.GetTeacherSchedule()) {
		if (i.first == "������� �������������") {
			for (auto j : i.second) {
				if (j.groups.size() == 3) {
					cout << "���� 13 �������" << endl;
				}
				else {
					cout << "���� 13 �� �������" << endl;
				}
			}
		}
	}

	for (auto i : establish.GetCountAudiences()) {
		if (i.first == even) {
			for (auto j : i.second) {
				if (j.first.day == monday && j.first.number == 1) {
					if (j.second == 3) {
						cout << "���� 14 �������" << endl;
						break;
					}
					else {
						cout << "���� 14  �� �������" << endl;
						break;
					}
				}
			}
		}
	}

	for (auto& i : establish.GetStudyGroups()) {
		delete i;
	}
}

void Test_7_8_9_10_11() {
	University establish("����");
	establish.Add(new StudyGroup("1"));
	establish.Add(new StudyGroup("2"));
	establish.Add(new StudyGroup("3"));
	establish.Add(new StudyGroup("4"));
	establish.Add(new StudyGroup("5"));
	establish.Add(new StudyGroup("6"));
	establish.AddToSchedule(establish.GetStudyGroups()[0], even, monday, 1, smallstream, "2", "����������������", "������� �������������");
	establish.AddToSchedule(establish.GetStudyGroups()[1], even, monday, 1, smallstream, "2", "����������������", "������� �������������");
	establish.AddToSchedule(establish.GetStudyGroups()[2], even, monday, 1, smallstream, "2", "����������������", "������� �������������");
	establish.AddToSchedule(establish.GetStudyGroups()[3], even, monday, 1, smallstream, "2", "����������������", "������� �������������");

	try {
		establish.AddToSchedule(establish.GetStudyGroups()[5], even, monday, 1, bigstream, "1", "����������������", "������� �������������");
	}
	catch (exception& e) {
		if ((string)e.what() == "� ������ ����� ������������� ������� ������������� ����� ������� � ������ ���������: 2") {
			cout << "���� 7 �������" << endl;
		}
		else {
			cout << "���� 7  �� �������" << endl;
		}
	}

	for (auto i : establish.GetCountAudiences()) {
		if (i.first == even) {
			for (auto j : i.second) {
				if (j.first.day == monday && j.first.number == 1) {
					if (j.second == 4) {
						cout << "���� 8 �������" << endl;
						break;
					}
					else {
						cout << "���� 8  �� �������" << endl;
						break;
					}
				}
			}
		}
	}


	try {
		establish.AddToSchedule(establish.GetStudyGroups()[4], even, monday, 1, smallstream, "2", "����������������", "������� �������������");

		establish.AddToSchedule(establish.GetStudyGroups()[5], even, monday, 1, smallstream, "2", "����������������", "������� �������������");
	}
	catch (exception& e) {
		if ((string)e.what() == "��������� 2 ���������") {
			cout << "���� 9 �������" << endl;
		}
		else {
			cout << "���� 9  �� �������" << endl;
		}
	}


	try {
		establish.AddToSchedule(establish.GetStudyGroups()[4], even, monday, 1, smallstream, "2", "������������ �������", "������� �������������");
	}
	catch (exception& e) {
		if ((string)e.what() == "�� ������ ������� ��������� ������ ������� �������: ����������������") {
			cout << "���� 10 �������" << endl;
		}
		else {
			cout << "���� 10  �� �������" << endl;
		}
	}

	try {
		establish.AddToSchedule(establish.GetStudyGroups()[4], even, monday, 1, smallstream, "2", "����������������", "������� ��������");
	}
	catch (exception& e) {
		if ((string)e.what() == "�� ������ ������� ��������� ������ �������������: ������� �������������") {
			cout << "���� 11 �������" << endl;
		}
		else {
			cout << "���� 11  �� �������" << endl;
		}
	}

	for (auto& i : establish.GetStudyGroups()) {
		delete i;
	}
}

void Test_6() {
	Educational_establishment* establish;
	establish = new University("����");
	establish->Add(new StudyGroup("���-913"));
	establish->AddToSchedule(establish->GetStudyGroups()[0], even, monday, 1, cabinet, "102", "����������������", "������� �������������");
	try {
		establish->AddToSchedule(establish->GetStudyGroups()[0], odd, wednesday, 1, smallstream, "102", "�������������� ����������", "�������� ������������");
	}
	catch (exception& e) {
		if ((string)e.what() == "��� ��������� ������� ����") {
			cout << "���� 6 �������" << endl;
		}
		else {
			cout << "���� 6  �� �������" << endl;
		}
	}

	for (auto& i : establish->GetStudyGroups()) {
		delete i;
	}
	delete establish;
}

void Test_4_5(){
	Educational_establishment* establish;
	establish = new School("�������� �1");
	establish->Add(new StudyGroup("11A"));
	establish->Add(new StudyGroup("11�"));
	establish->GetStudyGroups()[0]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "102", "���������", "T������ ����������");
	try {
		establish->GetStudyGroups()[1]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "203", "���������", "T������ ����������");
	}
	catch (exception& e) {
		if ((string)e.what() == "� ������ ����� ������������� T������ ���������� ����� � ������� ������: 11A") {
			cout << "���� 4 �������" << endl;
		}
		else {
			cout << "���� 4  �� �������" << endl;
		}
	}

	try {
		establish->GetStudyGroups()[1]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "102", "��������", "��������� ����������");
	}
	catch (exception& e) {
		if ((string)e.what() == "� ������ ����� ������� 102 ����� ������� 11A") {
			cout << "���� 5 �������" << endl;
		}
		else {
			cout << "���� 5  �� �������" << endl;
		}
	}

	for (auto& i : establish->GetStudyGroups()) {
		delete i;
	}
	delete establish;

}

void Test_3() {
	Educational_establishment* establish;
	establish = new School("�������� �1");
	establish->Add(new StudyGroup("11A"));
	try {
		establish->GetStudyGroups()[0]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "102", "���������", "T������ ����������");
		establish->GetStudyGroups()[0]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "203", "��������", "��������� ����������");
	}
	catch (exception& e) {
		if ((string)e.what() == "������� � ��� ����� ��� ����") {
			cout << "���� 3 �������" << endl;
		}
		else {
			cout << "���� 3  �� �������" << endl;
		}
	};

	for (auto& i : establish->GetStudyGroups()) {
		delete i;
	}
	delete establish;

}

void Test_2() {
	Educational_establishment* establish;
	establish = new School("�������� �1");
	try {
		establish->Add(new StudyGroup("11A"));
		establish->Add(new StudyGroup("11�"));
		establish->Add(new StudyGroup("11A"));
	}
		catch (exception& e) {
			if ((string) e.what() == "����� ����� ��� ����������") {
				cout << "���� 2 �������" << endl;
			}
			else {
				cout << "���� 2  �� �������" << endl;
			}
		};

		for (auto& i : establish->GetStudyGroups()) {
			delete i;
		}
		delete establish;
}

void Test_1() {
	Educational_establishment* establish;
	establish = new School("�������� �1");
	establish->Add(new StudyGroup("11A"));
	establish->Add(new StudyGroup("11�"));
	if (establish->GetStudyGroups().size() == 2 && establish->GetStudyGroups()[establish->GetStudyGroups().size() - 2]->GetName() == "11A" && establish->GetStudyGroups()[establish->GetStudyGroups().size() - 1]->GetName() == "11�") {
		cout << "���� 1 �������" << endl;
	 }
	else {
		cout << "���� 1 �� �������" << endl;
	}

	for (auto& i : establish->GetStudyGroups()) {
		delete i;
	}
	delete establish;
}


void Unit_Tests() {
	Test_1();
	Test_2();
	Test_3();
	Test_4_5();
	Test_6();
	Test_7_8_9_10_11();
	Test_12_13_14();
}

int main() {
	setlocale(LC_ALL, "rus");

	Unit_Tests();

	return 0;
}