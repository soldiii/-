#include "Educational_establishment.h"

class School : public Educational_establishment {
private: 
	Type type = Type::school;
	vector <StudyGroup*> classes; // ������ ���������� �� ������ �����
	map<string, vector<TeacherStruct>> TeacherSchedule; //���������� ��������
public:
	void AddToSchedule(StudyGroup*, const WeekType&, const Day&, const size_t&, const AudienceType&, const string&, const string&, const string&); // ���������� ������� � ���������� ������ 
	void Add(StudyGroup*);//���������� ��������� ������ � ������ ���������� �������
	vector <StudyGroup*> GetStudyGroups() const override;
    Type GetType() const override;
	void Delete(const size_t&); // �������� ������
	School(const string& name) :Educational_establishment(name) {};
};