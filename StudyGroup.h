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
	bigstream, // ������� �������� ���������
	smallstream, // ��������� �������� ���������
	cabinet // �������
};


enum WeekType {
	even, //������ ������
	odd,  //�������� ������
	common //������� ��� ������(��� �����)
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
	WeekType wtype; //��� ������
	AudienceType atype; // ��� ���������
	Day day; // ����
	size_t number; // ����� �������
	string audience; // �������� ���������
	string teacher; // �������� �������������
	string subject; // ������� �������/����������
};

struct TeacherStruct {
	WeekType wtype;
	Day day;
	size_t number;
	AudienceType atype;
	string audience;
	string subject;
	vector<string>groups; // ������ ���������� �� ������� �����
};

class StudyGroup {
private:
	string name; // �������� ������/������
	vector<ScheduleStruct> schedule; // ����������
	void CheckAdd(const Type&, const vector<StudyGroup*>&, const WeekType&, const Day&, const AudienceType&, const size_t&, const string&, const string&, const string&); // �������� ������ ������� �� ������������
public:
	void Add(const Type& ,const vector<StudyGroup*>&, const WeekType&, const Day&, const AudienceType&, const size_t&, const string&, const string&, const string&); // ���������� ������ ������� � ����������
	string GetName() const ;
	vector<ScheduleStruct> GetSchedule() const ;
	StudyGroup(const string& name);

};
