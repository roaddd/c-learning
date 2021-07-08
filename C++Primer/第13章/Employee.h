#pragma once
#include <string>
using namespace std;
class Employee
{
public:
	Employee();
	Employee(const string&);
	Employee(const Employee&)=delete;
	Employee& operator=(const Employee&)=delete;
	const int id() const;
private:
	string name_;
	int id_;
	static int s_increment;
};