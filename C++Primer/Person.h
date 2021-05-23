#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
class Person {
public:
	Person();
	Person(string p_name, string p_address);
	void show_info();
	const string& getName() const;
	const string& getAddress() const;
private:
	string name;
	string address;

};

#endif // !PERSON_H


