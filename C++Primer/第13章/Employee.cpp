#define _CRT_SECURE_NO_WARNINGS 1
#include "Employee.h"
int Employee::s_increment = 0;
Employee::Employee()
{
	id_ = s_increment++;
}
Employee::Employee(const string& name)
{
	name_ = name;
	id_=s_increment++;
}
const int Employee::id()const
{
	return id_;
}