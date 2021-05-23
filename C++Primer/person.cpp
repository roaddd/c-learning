#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;
class Person {
public:
	Person();
	Person(string p_name, string p_address) {
		this->name = p_name;
		this->address = p_address;
	}
	void show_info() {
		cout << "name:" << name << " address:" << address;
	}
	const string& getName() const{
		return name;
	}
	const string& getAddress() const {
		return address;
	}
private:
	string name;
	string address;
};
void test01() {
	Person p1("张三", "北京");
	p1.show_info();
}
int main() {
	test01();
	return 0;
}