
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "StudyGroup.h"

#pragma once;

using namespace std;

class Educational_establishment {
private:
	string name; 
public:
	string GetName() const;
	virtual vector <StudyGroup*> GetStudyGroups() const = 0;
	virtual void Add(StudyGroup*) = 0;
	virtual Type GetType() const = 0;
	virtual void AddToSchedule(StudyGroup* , WeekType,Day,size_t,AudienceType,const string& ,const string&,const string&) = 0;
	virtual void Delete(size_t) = 0;
	Educational_establishment(string name);
};
