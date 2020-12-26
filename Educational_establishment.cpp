#include "Educational_establishment.h"

string Educational_establishment::GetName() const
{
	return name;
}

Educational_establishment::Educational_establishment(string name)
{
	this->name = name;
}

