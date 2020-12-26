#include "StudyGroup.h"

string StudyGroup::GetName() const
{
	return name;
}

vector<ScheduleStruct> StudyGroup::GetSchedule() const
{
	return schedule;
}

StudyGroup::StudyGroup(const string& name)
{
	this->name = name;
}

void StudyGroup::Add(const Type& etype, const vector<StudyGroup*>& v, const WeekType& wtype, const Day& day, const AudienceType& atype, const size_t& number, const string& audience, const string& subject, const string& teacher)
{
	CheckAdd(etype, v, wtype, day, atype, number, audience, subject, teacher);
	ScheduleStruct s = { wtype,atype,day,number,audience,teacher,subject };
	schedule.push_back(s);
}

void StudyGroup::CheckAdd(const Type& etype, const vector<StudyGroup*>& v, const WeekType& wtype, const Day& day, const AudienceType& atype, const size_t& number, const string& audience, const string& subject, const string& teacher)
{
	for (auto i : schedule) {
		if (i.wtype == wtype && i.day == day && i.number == number) {
			throw invalid_argument("Занятие в это время уже есть");
		}
	}

	switch (etype) {
	case school:
		for (auto i : v) {
			if (i->GetName() != name) {
				for (auto j : i->schedule) {
					if (j.day == day) {
						if (j.number == number && j.audience == audience) {
							throw invalid_argument("В данное время кабинет " + audience + " занят классом " + i->GetName());
						}
						if (j.number == number && j.teacher == teacher) {
							throw invalid_argument("В данное время преподаватель " + teacher + " ведет у другого класса: " + i->GetName());
						}
					}
				}
			}
		}
		break;

	case university:

		for (auto i : v) {
			if (i->GetName() != name) {
				for (auto j : i->schedule) {
					if (j.wtype == wtype && j.day == day ) {
						if (j.atype == cabinet) {
							if (j.number == number && j.audience == audience) {
								throw invalid_argument("В данное время аудитория " + audience + " занята группой " + i->GetName());
							}
							if (j.number == number && j.teacher == teacher) {
								throw invalid_argument("В данное время преподаватель " + teacher + " ведет у другой группы: " + i->GetName());
							}
						}
						else {
							if (j.number == number && j.audience != audience && j.teacher == teacher) {
								throw invalid_argument("В данное время преподаватель " + teacher + " ведет занятие в другой аудитории: " + j.audience);
							}
						}
					}
				}
			}
		}
		break;
	}
}
