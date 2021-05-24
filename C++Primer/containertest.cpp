#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <list>
using namespace std;
vector<int>::iterator find(vector<int>::iterator begin, vector<int>::iterator end, int c) {
	for (begin; begin != end; begin++) {
		if (*begin == c) {
			return begin;
		}
	}
	return begin;
}
void test01() {
	int i = 0;
	vector<int>vec(10);
	for (i = 0; i < size(vec); i++) {
		vec[i] = i;
	}
	if (find(vec.begin(), vec.end(), 5)!=vec.end()) {
		cout << "We have found it!" << endl;
	}
	else
	{
		cout << "Sorry!" << endl;
	}

}

//从一个list<int>初始化一个vector<double>
void test03() {
	list<int>li = { 1,2,3,4,5 };
	vector<int>vec = { 1,2,3,4,5 };

	vector<double>vec1(li.begin(), li.end());
	vector<double>vec2(vec.begin(), vec.end());

	vector<double>::iterator it1 = vec1.begin();
	vector<double>::iterator it2 = vec2.begin();
	while (it1 != vec1.end()) {
		cout << *it1 << endl;
		it1++;
	}
}

//将一个list中的char*指针元素赋值给一个vector中的string
void test04() {
	list<const char*> chararr = { "a","an","the" };
	vector<string> new_chararr;
	new_chararr.assign(chararr.cbegin(), chararr.cend());
	vector<string>::iterator iter1 = new_chararr.begin();
	vector<string>::iterator iter2 = new_chararr.end();
	for (iter1; iter1 < iter2; iter1++) {
		cout << *iter1 << endl;
	}
}
int main(){
	//test01();
	//test03();
	test04();
	return 0;
}