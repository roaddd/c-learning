#define _CRT_SECURE_NO_WARNINGS 1
#include "Person.h"
#include <stdio.h>
#include <iostream>
Person::Person() {};
Person::Person(string p_name, string p_address) {
	this->name = p_name;
	this->address = p_address;
}
void Person::show_info() {
	cout << "name:" << name << " address:" << address;
}
const string& Person::getName() const {
	return name;
}
const string& Person::getAddress() const {
	return address;
}