#define _CRT_SECURE_NO_WARNINGS 1
#include "strblob.h"
#include <iostream>
#include <vector>
using namespace std;
//练习12.2
void test01() {
	//push_back和pop_back函数不要加const，若加了const，则定义的const的StrBlob
	//可以调用const的push_back和pop_back函数，容器会发生改变(data未改变)，这样不合逻辑
	const StrBlob csb{ "hello","world","time" };
	StrBlob sb{ "hello", "world", "people" };
	cout << csb.front() << " " << csb.back() << endl;
	sb.back() = "time";
	cout << sb.front() << " " << sb.back() << endl;
}
//练习12.6
vector<int>&
int main()
{
	test01();
	return 0;
}