#define _CRT_SECURE_NO_WARNINGS 1
#include "strblob.h"
#include <iostream>
#include <vector>
using namespace std;
//��ϰ12.2
void test01() {
	//push_back��pop_back������Ҫ��const��������const�������const��StrBlob
	//���Ե���const��push_back��pop_back�����������ᷢ���ı�(dataδ�ı�)�����������߼�
	const StrBlob csb{ "hello","world","time" };
	StrBlob sb{ "hello", "world", "people" };
	cout << csb.front() << " " << csb.back() << endl;
	sb.back() = "time";
	cout << sb.front() << " " << sb.back() << endl;
}
//��ϰ12.6
vector<int>&
int main()
{
	test01();
	return 0;
}