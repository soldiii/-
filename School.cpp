#include "School.h"


void School::AddToSchedule(StudyGroup* cl, const WeekType& wtype, const Day& day, const size_t& num, const AudienceType& atype, const string& cab, const string& subj, const string& teach)
{
	if (wtype != common) {
		throw invalid_argument("У школы тип недели - common");
	}
	if (atype != cabinet) {
		throw invalid_argument("У школы тип аудитории - кабинет");
	}

	cl->Add(school, this->classes, wtype, day, atype, num, cab, subj, teach);

	TeacherStruct t{ wtype,day,num,atype,cab,subj,{cl->GetName()} };
	TeacherSchedule[teach].push_back(t);
}

void School::Add(StudyGroup* cl)
{
	for (auto i : classes) {
		if (i->GetName() == cl->GetName()) {
			delete cl;
			throw invalid_argument("Такой класс уже существует");
		}
	}
	classes.push_back(cl);
}

vector<StudyGroup*> School::GetStudyGroups() const
{
	return classes;
}

Type School::GetType() const 
{
	return type;
}

void School::Delete(const size_t& id)
{
	for (auto i : classes[id]->GetSchedule()) {
		for (auto& j : TeacherSchedule) {
			if (j.first == i.teacher) {
				for (size_t item = 0; item < j.second.size(); ++item) {
					if (j.second[item].audience == i.audience && j.second[item].day == i.day && j.second[item].number == i.number) {
						j.second.erase(j.second.begin() + item);
						break;
					}
				}
			}
		}
	}

	for (auto& index : TeacherSchedule) {
		if (index.second.size() == 0) {
			TeacherSchedule.erase(index.first);
			break;
		}
	}

	delete classes[id];
	classes.erase(classes.begin() + id);
}
