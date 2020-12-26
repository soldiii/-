#include <iostream>
#include <string>
#include <vector>
#include "School.h"
#include "University.h"
#include <algorithm>


#pragma once;

using namespace std;

void Test_12_13_14() {
	University establish("НГТУ");
	establish.Add(new StudyGroup("1"));
	establish.Add(new StudyGroup("2"));
	establish.Add(new StudyGroup("3"));
	establish.Add(new StudyGroup("4"));
	establish.Add(new StudyGroup("5"));
	establish.Add(new StudyGroup("6"));

	establish.AddToSchedule(establish.GetStudyGroups()[0], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");
	establish.AddToSchedule(establish.GetStudyGroups()[1], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");
	establish.AddToSchedule(establish.GetStudyGroups()[2], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");
	establish.AddToSchedule(establish.GetStudyGroups()[3], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");

	establish.AddToSchedule(establish.GetStudyGroups()[0], odd, tuesday, 3, cabinet, "203", "Философия", "Игорь Владимирович");

	establish.Delete(0);

	if (establish.GetTeacherSchedule().size() == 1) {
		cout << "Тест 12 пройден" << endl;
	}
	else {
		cout << "Тест 12 не пройден" << endl;
	}

	for (auto i : establish.GetTeacherSchedule()) {
		if (i.first == "Евгений Александрович") {
			for (auto j : i.second) {
				if (j.groups.size() == 3) {
					cout << "Тест 13 пройден" << endl;
				}
				else {
					cout << "Тест 13 не пройден" << endl;
				}
			}
		}
	}

	for (auto i : establish.GetCountAudiences()) {
		if (i.first == even) {
			for (auto j : i.second) {
				if (j.first.day == monday && j.first.number == 1) {
					if (j.second == 3) {
						cout << "Тест 14 пройден" << endl;
						break;
					}
					else {
						cout << "Тест 14  не пройден" << endl;
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
	University establish("НГТУ");
	establish.Add(new StudyGroup("1"));
	establish.Add(new StudyGroup("2"));
	establish.Add(new StudyGroup("3"));
	establish.Add(new StudyGroup("4"));
	establish.Add(new StudyGroup("5"));
	establish.Add(new StudyGroup("6"));
	establish.AddToSchedule(establish.GetStudyGroups()[0], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");
	establish.AddToSchedule(establish.GetStudyGroups()[1], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");
	establish.AddToSchedule(establish.GetStudyGroups()[2], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");
	establish.AddToSchedule(establish.GetStudyGroups()[3], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");

	try {
		establish.AddToSchedule(establish.GetStudyGroups()[5], even, monday, 1, bigstream, "1", "Программирование", "Евгений Александрович");
	}
	catch (exception& e) {
		if ((string)e.what() == "В данное время преподаватель Евгений Александрович ведет занятие в другой аудитории: 2") {
			cout << "Тест 7 пройден" << endl;
		}
		else {
			cout << "Тест 7  не пройден" << endl;
		}
	}

	for (auto i : establish.GetCountAudiences()) {
		if (i.first == even) {
			for (auto j : i.second) {
				if (j.first.day == monday && j.first.number == 1) {
					if (j.second == 4) {
						cout << "Тест 8 пройден" << endl;
						break;
					}
					else {
						cout << "Тест 8  не пройден" << endl;
						break;
					}
				}
			}
		}
	}


	try {
		establish.AddToSchedule(establish.GetStudyGroups()[4], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");

		establish.AddToSchedule(establish.GetStudyGroups()[5], even, monday, 1, smallstream, "2", "Программирование", "Евгений Александрович");
	}
	catch (exception& e) {
		if ((string)e.what() == "Аудитория 2 заполнена") {
			cout << "Тест 9 пройден" << endl;
		}
		else {
			cout << "Тест 9  не пройден" << endl;
		}
	}


	try {
		establish.AddToSchedule(establish.GetStudyGroups()[4], even, monday, 1, smallstream, "2", "Компьютерная графика", "Евгений Александрович");
	}
	catch (exception& e) {
		if ((string)e.what() == "За данной лекцией закреплен другой учебный предмет: Программирование") {
			cout << "Тест 10 пройден" << endl;
		}
		else {
			cout << "Тест 10  не пройден" << endl;
		}
	}

	try {
		establish.AddToSchedule(establish.GetStudyGroups()[4], even, monday, 1, smallstream, "2", "Программирование", "Василий Игоревич");
	}
	catch (exception& e) {
		if ((string)e.what() == "За данной лекцией закреплен другой преподаватель: Евгений Александрович") {
			cout << "Тест 11 пройден" << endl;
		}
		else {
			cout << "Тест 11  не пройден" << endl;
		}
	}

	for (auto& i : establish.GetStudyGroups()) {
		delete i;
	}
}

void Test_6() {
	Educational_establishment* establish;
	establish = new University("НГТУ");
	establish->Add(new StudyGroup("АВТ-913"));
	establish->AddToSchedule(establish->GetStudyGroups()[0], even, monday, 1, cabinet, "102", "Программирование", "Евгений Александрович");
	try {
		establish->AddToSchedule(establish->GetStudyGroups()[0], odd, wednesday, 1, smallstream, "102", "Вычислительная математика", "Владимир Владимирович");
	}
	catch (exception& e) {
		if ((string)e.what() == "Эта аудитория другого типа") {
			cout << "Тест 6 пройден" << endl;
		}
		else {
			cout << "Тест 6  не пройден" << endl;
		}
	}

	for (auto& i : establish->GetStudyGroups()) {
		delete i;
	}
	delete establish;
}

void Test_4_5(){
	Educational_establishment* establish;
	establish = new School("Гимназия №1");
	establish->Add(new StudyGroup("11A"));
	establish->Add(new StudyGroup("11Б"));
	establish->GetStudyGroups()[0]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "102", "География", "Tатьяна Леонидовна");
	try {
		establish->GetStudyGroups()[1]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "203", "География", "Tатьяна Леонидовна");
	}
	catch (exception& e) {
		if ((string)e.what() == "В данное время преподаватель Tатьяна Леонидовна ведет у другого класса: 11A") {
			cout << "Тест 4 пройден" << endl;
		}
		else {
			cout << "Тест 4  не пройден" << endl;
		}
	}

	try {
		establish->GetStudyGroups()[1]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "102", "Биология", "Валентина Дмитриевна");
	}
	catch (exception& e) {
		if ((string)e.what() == "В данное время кабинет 102 занят классом 11A") {
			cout << "Тест 5 пройден" << endl;
		}
		else {
			cout << "Тест 5  не пройден" << endl;
		}
	}

	for (auto& i : establish->GetStudyGroups()) {
		delete i;
	}
	delete establish;

}

void Test_3() {
	Educational_establishment* establish;
	establish = new School("Гимназия №1");
	establish->Add(new StudyGroup("11A"));
	try {
		establish->GetStudyGroups()[0]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "102", "География", "Tатьяна Леонидовна");
		establish->GetStudyGroups()[0]->Add(school, establish->GetStudyGroups(), common, monday, cabinet, 1, "203", "Биология", "Валентина Дмитриевна");
	}
	catch (exception& e) {
		if ((string)e.what() == "Занятие в это время уже есть") {
			cout << "Тест 3 пройден" << endl;
		}
		else {
			cout << "Тест 3  не пройден" << endl;
		}
	};

	for (auto& i : establish->GetStudyGroups()) {
		delete i;
	}
	delete establish;

}

void Test_2() {
	Educational_establishment* establish;
	establish = new School("Гимназия №1");
	try {
		establish->Add(new StudyGroup("11A"));
		establish->Add(new StudyGroup("11Б"));
		establish->Add(new StudyGroup("11A"));
	}
		catch (exception& e) {
			if ((string) e.what() == "Такой класс уже существует") {
				cout << "Тест 2 пройден" << endl;
			}
			else {
				cout << "Тест 2  не пройден" << endl;
			}
		};

		for (auto& i : establish->GetStudyGroups()) {
			delete i;
		}
		delete establish;
}

void Test_1() {
	Educational_establishment* establish;
	establish = new School("Гимназия №1");
	establish->Add(new StudyGroup("11A"));
	establish->Add(new StudyGroup("11Б"));
	if (establish->GetStudyGroups().size() == 2 && establish->GetStudyGroups()[establish->GetStudyGroups().size() - 2]->GetName() == "11A" && establish->GetStudyGroups()[establish->GetStudyGroups().size() - 1]->GetName() == "11Б") {
		cout << "Тест 1 пройден" << endl;
	 }
	else {
		cout << "Тест 1 не пройден" << endl;
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