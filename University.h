#include "Educational_establishment.h"

class University : public Educational_establishment {
private:
	Type type = Type::university;
	vector <StudyGroup*> groups; // вектор указателей на группы университета
	map < WeekType,vector<pair < ScheduleStruct,size_t>>> count_audiences; // словарь для подсчета групп в аудитории
	map<string, AudienceType> audiences; // словарь, соотносящий аудиторию с ее типом
	map<string, vector<TeacherStruct>> TeacherSchedule; // расписание преподавателей
	void AddAudience(const AudienceType&, const string&); // добавить аудиторию и присвоить ей тип
public:
	map < WeekType, vector<pair < ScheduleStruct, size_t>>> GetCountAudiences() const; // для юнит-тестов
	map<string, vector<TeacherStruct>> GetTeacherSchedule() const; // для юнит-тестов
	void Add(StudyGroup*) override; // добавление указателя группы в вектор указателей групп
	vector <StudyGroup*> GetStudyGroups() const override; 
	Type GetType() const override;
	void AddToSchedule(StudyGroup*, const WeekType&, const Day&, const size_t&, const AudienceType&, const string&, const string&, const string&); // добавление занятия в расписание группы 
	void Delete(const size_t&); // удаление группы
	University(const string& name) :Educational_establishment(name) {};
};