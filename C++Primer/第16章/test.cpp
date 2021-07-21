#include <vector>
#include <string>
#include <iostream>
#include <list>
#include "blobptr.h"
#include "Screen.h"
using namespace std;

//��ϰ16.4
template<typename Iterator,typename Value>
auto test01(Iterator first,Iterator last,Value const&value)
{
	for (; first != last && *first != value; ++first);
	return first;
}
//��ϰ16.5
template<typename Arr>
void print(Arr const&arr)
{
	for (auto const&elem : arr)
	{
		cout << elem << endl;
	}
}
//��ϰ16.6
template<typename T,unsigned size>
T* begin_def(T(&arr)[size])
{
	return arr;
}
template<typename T,unsigned size>
T*end_def(T(&arr)[size])
{
	return arr + size;
}
//��ϰ16.7
template<typename T, unsigned size>
constexpr unsigned getSize(const T(&b)[size])
{
	return size;
}
//��ϰ16.12
void test01()
{
	Screen<5, 5>scr('c');
	Screen<5, 5>scr2;
	cout << scr;
	cin >> scr2;
	cout << scr2;
}

int main()
{
	/*vector<int>v = { 1,2,3,4,5,6,7,8,9 };
	auto a = v.cend();
	auto is_in_vector = v.cend() != test01(v.cbegin(), v.cend(), 5);
	cout << (is_in_vector?"found\n":"not found\n");

	list<string> i = { "aa","bb","cc" };
	auto is_in_list = i.cend() != test01(i.cbegin(), i.cend(), "aa");
	cout << (is_in_list ? "found\n" : "not found\n");*/

	/*string s[] = { "sss","aaa","ssssss" };
	char c[] = { 'a','b','c','d' };
	int i[] = { 1 };
	print(s);
	print(c);
	print(i);*/

	/*string s[] = { "sssss","ss","sssssszzz" };
	cout << *(begin_def(s) + 1) << endl;
	cout << *(end_def(s) - 1) << endl;*/

	/*string s[] = { "sss" };
	cout << getSize(s) << endl;
	char c[] = "s";
	cout << getSize(c) << endl;*/

	test01();

	return 0;
}