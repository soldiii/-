#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>


using namespace std;

#pragma once;

enum Type {
	school,
	university
};

enum AudienceType {
	bigstream, // большая поточная аудитория
	smallstream, // маленькая поточная аудитория
	cabinet // кабинет
};


enum WeekType {
	even, //четная неделя
	odd,  //нечетная неделя
	common //обычный тип недели(для школы)
};

enum Day {
	monday, 
	tuesday, 
	wednesday,
	thursday,
	friday,
	saturday
};

struct ScheduleStruct {
	WeekType wtype; //тип недели
	AudienceType atype; // тип аудитории
	Day day; // день
	size_t number; // номер занятия
	string audience; // название аудитории
	string teacher; // инициалы преподавателя
	string subject; // учебный предмет/дисциплина
};

struct TeacherStruct {
	WeekType wtype;
	Day day;
	size_t number;
	AudienceType atype;
	string audience;
	string subject;
	vector<string>groups; // вектор записанных на занятие групп
};

class StudyGroup {
private:
	string name; // название группы/класса
	vector<ScheduleStruct> schedule; // расписание
	void CheckAdd(const Type&, const vector<StudyGroup*>&, const WeekType&, const Day&, const AudienceType&, const size_t&, const string&, const string&, const string&) const; // проверка данных занятия на правильность
public:
	void Add(const Type& ,const vector<StudyGroup*>&, const WeekType&, const Day&, const AudienceType&, const size_t&, const string&, const string&, const string&); // добавление данных занятия в расписание
	string GetName() const ;
	vector<ScheduleStruct> GetSchedule() const ;
	StudyGroup(const string& name);

};
