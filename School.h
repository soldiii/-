#include "Educational_establishment.h"

class School : public Educational_establishment {
private: 
	Type type = Type::school;
	vector <StudyGroup*> classes; // вектор указателей на классы школы
	map<string, vector<TeacherStruct>> TeacherSchedule; //расписание учителей
public:
	void AddToSchedule(StudyGroup*, const WeekType&, const Day&, const size_t&, const AudienceType&, const string&, const string&, const string&); // добавление занятия в расписание класса 
	void Add(StudyGroup*);//добавление указателя класса в вектор указателей классов
	vector <StudyGroup*> GetStudyGroups() const override;
    Type GetType() const override;
	void Delete(const size_t&); // удаление класса
	School(const string& name) :Educational_establishment(name) {};
};