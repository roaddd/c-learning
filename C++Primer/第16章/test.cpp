#include <vector>
#include <string>
#include <iostream>
#include <list>
#include "blobptr.h"
#include "Screen.h"
#include "vec.h"
#include "DebugDelete.h"
#include "shared_pointer.hpp"
using namespace std;

//Á·Ï°16.4
template<typename Iterator,typename Value>
auto test01(Iterator first,Iterator last,Value const&value)
{
	for (; first != last && *first != value; ++first);
	return first;
}
//Á·Ï°16.5
template<typename Arr>
void print(Arr const&arr)
{
	for (auto const&elem : arr)
	{
		cout << elem << endl;
	}
}
//Á·Ï°16.6
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
//Á·Ï°16.7
template<typename T, unsigned size>
constexpr unsigned getSize(const T(&b)[size])
{
	return size;
}
//Á·Ï°16.12
void test01()
{
	Screen<5, 5>scr('c');
	Screen<5, 5>scr2;
	cout << scr;
	cin >> scr2;
	cout << scr2;
}
//Á·Ï°16.16
void test02()
{
	Vec<int>v = { 1,2,3,4,5 };
	Vec<int>v2;
	v2 = v;
	cout << v2.capacity() << endl;
	v2.push_back(99);
	v2.resize(2, 2);
	for (auto i : v2)
		cout << i << endl;
	cout << v2.capacity() << endl;
}
//Á·Ï°16.19
template<typename T>
void test03(T&t)
{
	typedef T::size_type size_type;
	for (size_type i = 0; i != t.size(); ++i)
		cout << t[i] << endl;
}
//Á·Ï°16.20
template<typename T>
void test04(T&t)
{
	auto beg = t.begin();
	while (beg != t.end())
		cout << *beg++ << endl;
}
//Á·Ï°16.21
void test05()
{
	double *p = new double;
	DebugDelete d;
	d(p);

	//unique_ptr<int, DebugDelete>p(new int, DebugDelete());
}
//Á·Ï°16.28
void test06()
{
	auto foo = cp5::SharedPointer<int>{ new int(42) };
	auto bar(foo);
	cout << *foo << endl;
	cout << foo.use_count() << endl;


	
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

	//test01();
	//test02();
	vector<int>vec = { 1,2,3,4 };
	//test03(vec);
	//test04(vec);
	//test05();
	test06();
	return 0;
}