#include "University.h"

bool operator==(const ScheduleStruct& a, const ScheduleStruct& b) {

	return a.atype == b.atype && a.audience == b.audience && a.day == b.day && a.number == b.number && a.subject == b.subject && a.teacher == b.teacher && a.wtype == b.wtype;
}

bool operator!= (const ScheduleStruct& a, const ScheduleStruct& b)
{
	return !(a == b);
}

void University::AddAudience(const AudienceType& type, const string& aud)
{
	if (audiences.count(aud) == 0) {
		audiences[aud] = type;
	}
	else {
		for (auto i : audiences) {
			if (audiences.at(aud) != type) {
				throw invalid_argument("Эта аудитория другого типа");
			}
		}
	}
}

map<WeekType, vector<pair<ScheduleStruct, size_t>>> University::GetCountAudiences() const
{
	return count_audiences;
}

map<string, vector<TeacherStruct>> University::GetTeacherSchedule() const
{
	return TeacherSchedule;
}

void University::Add(StudyGroup* group)
{
	for (auto i : groups) {
		if (i->GetName() == group->GetName()) {
			delete group;
			throw invalid_argument("Такая группа уже существует");
		}
	}
	groups.push_back(group);
}

vector<StudyGroup*> University::GetStudyGroups() const
{
	return groups;
}

Type University::GetType() const
{
	return type;
}

void University::AddToSchedule(StudyGroup* group, const WeekType& wtype, const Day& day, const size_t& number,const AudienceType& atype,const  string& cab, const string& subj, const string& teach)
{
    size_t n = 0;
	switch (atype) {
	case cabinet:
	{
		AddAudience(atype, cab);
		group->Add(university, groups, wtype, day, atype, number, cab, subj, teach);
		TeacherStruct t{ wtype,day,number,atype,cab,subj,{group->GetName()} };
		TeacherSchedule[teach].push_back(t);
		break;
	}
	case smallstream:
		for (auto& j : count_audiences[wtype]) {
			if (j.first.atype == atype && j.first.day == day && j.first.number == number && j.first.audience == cab) {
				if (j.first.subject != subj) {
					throw invalid_argument("За данной лекцией закреплен другой учебный предмет: " + j.first.subject);
				}
				if (j.first.teacher != teach) {
					throw invalid_argument("За данной лекцией закреплен другой преподаватель: " + j.first.teacher);
				}
				n = j.second;
				if (n == 5) {
					throw invalid_argument("Аудитория " + cab + " заполнена");
				}
				group->Add(university, groups, wtype, day, atype, number, cab, subj, teach);
				for (auto& i : TeacherSchedule[teach]) {
					if (i.wtype == wtype && i.day == day && i.number == number && i.atype == smallstream && i.audience == cab) {
						i.groups.push_back(group->GetName());
					}
				}
				++j.second;
			}
		}
		
		if (n == 0) {
		AddAudience(atype, cab);
		group->Add(university, groups, wtype, day, atype, number, cab, subj, teach);
		ScheduleStruct s = { wtype,atype,day,number,cab,teach,subj };
		count_audiences[wtype].push_back({ s,1 });
		TeacherStruct t{ wtype,day,number,atype,cab,subj,{group->GetName()} };
		TeacherSchedule[teach].push_back(t);

		}
		break;
	case bigstream:
		for (auto& j : count_audiences[wtype]) {
			if (j.first.atype == atype && j.first.day == day && j.first.number == number && j.first.audience == cab) {
				if (j.first.subject != subj) {
					throw invalid_argument("За данной лекцией закреплен другой учебный предмет: " + j.first.subject);
				}
				if (j.first.teacher != teach) {
					throw invalid_argument("За данной лекцией закреплен другой преподаватель: " + j.first.teacher);
				}
				n = j.second;
				if (n == 10) {
					throw invalid_argument("Аудитория " + cab + " заполнена");
				}
				group->Add(university, groups, wtype, day, atype, number, cab, subj, teach);
				for (auto& i : TeacherSchedule[teach]) {
					if (i.wtype == wtype && i.day == day && i.number == number && i.atype == bigstream && i.audience == cab) {
						i.groups.push_back(group->GetName());
					}
				}
				++j.second;
			}
		}

		if (n == 0) {
			AddAudience(atype, cab);
			group->Add(university, groups, wtype, day, atype, number, cab, subj, teach);
			ScheduleStruct s = { wtype,atype,day,number,cab,teach,subj };
			count_audiences[wtype].push_back({ s,1 });
			TeacherStruct t{ wtype,day,number,atype,cab,subj,{group->GetName()} };
			TeacherSchedule[teach].push_back(t);
		}
		break;
	}
}

void University::Delete(const size_t& id)
{
	for (auto i: groups[id]->GetSchedule()) {
		if (i.atype != cabinet) {
			for (auto& j : count_audiences) {
				for (auto& item : j.second) {
					if (i == item.first) {
						--item.second;
					}
				}
			}
		}
	}
	for (auto i : groups[id]->GetSchedule()) {
		for (auto& j : TeacherSchedule) {
			if (j.first == i.teacher) {
				for (size_t item = 0; item < j.second.size(); ++item) {
					if (j.second[item].wtype == i.wtype && j.second[item].audience == i.audience && j.second[item].day == i.day && j.second[item].number == i.number) {
						if (j.second[item].groups.size() != 1) {
							for (size_t index = 0;index < j.second[item].groups.size();++index) {
								if (j.second[item].groups[index] == groups[id]->GetName()) {
									j.second[item].groups.erase(j.second[item].groups.begin() + index);
									break;
								}
							}
						}
						else {
							j.second.erase(j.second.begin() + item);
							break;
						}
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

	delete groups[id];
	groups.erase(groups.begin() + id);

}

