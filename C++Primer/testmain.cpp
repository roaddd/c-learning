#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "Person.h"
using namespace std;
void testPerson() {
	Person p1("张三", "北京");
	p1.show_info();
}
int main() {
	testPerson();
	return 0;
}