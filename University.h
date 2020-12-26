#include "Educational_establishment.h"

class University : public Educational_establishment {
private:
	Type type = Type::university;
	vector <StudyGroup*> groups; // ������ ���������� �� ������ ������������
	map < WeekType,vector<pair < ScheduleStruct,size_t>>> count_audiences; // ������� ��� �������� ����� � ���������
	map<string, AudienceType> audiences; // �������, ����������� ��������� � �� �����
	map<string, vector<TeacherStruct>> TeacherSchedule; // ���������� ��������������
	void AddAudience(const AudienceType&, const string&); // �������� ��������� � ��������� �� ���
public:
	map < WeekType, vector<pair < ScheduleStruct, size_t>>> GetCountAudiences() const; // ��� ����-������
	map<string, vector<TeacherStruct>> GetTeacherSchedule() const; // ��� ����-������
	void Add(StudyGroup*) override; // ���������� ��������� ������ � ������ ���������� �����
	vector <StudyGroup*> GetStudyGroups() const override; 
	Type GetType() const override;
	void AddToSchedule(StudyGroup*, const WeekType&, const Day&, const size_t&, const AudienceType&, const string&, const string&, const string&); // ���������� ������� � ���������� ������ 
	void Delete(const size_t&); // �������� ������
	University(const string& name) :Educational_establishment(name) {};
};