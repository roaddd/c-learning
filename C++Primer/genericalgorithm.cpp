#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>
//Á·Ï°10.1
void test01() {
	//vector<int>vec(10, 3);
	string s[3] = { "abcdefg" ,"aa","bbb"};
	vector<string>vec(s, s + 3);
	cout<<count(vec.begin(), vec.end(), "aa")<<endl;
}
//Á·Ï°10.6
void test02() {
	vector<int>vec(10,10);
	fill_n(vec.begin(), vec.size(), 0);
	auto iter1 = vec.begin();
	while (iter1 != vec.end()) {
		cout << *iter1 << endl;
		iter1++;
	}
}
//Á·Ï°10.9
bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}
void test03(vector<string> &words) {
	stable_sort(words.begin(), words.end(), isShorter);
	for (const auto& s : words) {
		cout << s << " ";
	}
	cout << endl;
	auto iter3 = words.begin();
	while (iter3!=words.end())
	{
		cout << *iter3 << endl;
		iter3++;
	}
	cout << "---------------" << endl;
	auto end_unique=unique(words.begin(), words.end());
	auto iter1 = words.begin();
	while (iter1 != words.end())
	{
		cout << *iter1 << endl;
		iter1++;
	}
	cout <<words.size()<< "---------------" << endl;
	words.erase(end_unique, words.end());
	auto iter2 = words.begin();
	while (iter2 != words.end())
	{
		cout << *iter2 << endl;
		iter2++;
	}
}
int main() {
	//test01();
	//test02();
	vector<string>vec = { "abc","abc","vfb","bgd" };
	test03(vec);
}