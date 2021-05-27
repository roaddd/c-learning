#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <forward_list>
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
	if (find(vec.begin(), vec.end(), 5) != vec.end()) {
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
//从标准输入读取string序列，存入一个deque中，用迭代器打印deque
void test05() {
	deque<string>deq;
	string word;
	while (cin >> word) {
		deq.push_back(word);
		if (word == "0") {
			break;
		}
	}
	deque<string>::iterator iter1 = deq.begin();
	for (iter1; iter1 != deq.end(); iter1++) {
		cout << *iter1 << endl;
	}
}
//从list<int>拷贝到两个deque中，一个装偶数一个装奇数
void test06() {
	list<int>lis = { 1,2,3,4,5,6,7,8,9,0 };
	deque<int>deq1;
	deque<int>deq2;
	list<int>::iterator iter1 = lis.begin();
	for (iter1; iter1 != lis.end(); iter1++) {
		if ((*iter1) % 2 == 0) {

			deq1.push_back(*iter1);
		}
		else {
			deq2.push_back(*iter1);
		}
	}
	deque<int>::iterator iter2 = deq1.begin();
	deque<int>::iterator iter3 = deq2.begin();
	for (iter2; iter2 != deq1.end(); iter2++) {
		cout << *iter2 << endl;
	}
	for (iter3; iter3 != deq2.end(); iter3++) {
		cout << *iter3 << endl;
	}
}

//9.22题
void test07() {
	int some_val = 3;
	vector<int>iv = { 3,2,3,4,5,6,7,8,9,0 };
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	while (iter != mid) {
		if (*mid == some_val) {
			mid = iv.insert(mid, 2 * some_val);
			//插入元素使迭代器失效，重新对迭代器赋值
			iter = iv.begin();
		}
		else {
			mid--;
		}
	}
	//判断首元素是否符合要求
	if (*iter == some_val) {
		iter = iv.insert(iter, 2 * some_val);
	}
	for (iter; iter != iv.end(); iter++) {
		cout << *iter << endl;
	}
}
//题9.24
void test08() {
	vector<int> vec = { 1 };
	auto a = vec.at(0);
	auto b = vec[0];
	auto c = vec.front();
	auto d = *vec.begin();
	cout << a << endl << b << endl << c << endl << d << endl;
}
//题9.26 
void test09() {
	int ia[] = { 0,1,2,3,5,8,13,21,55,89 };
	vector<int>vec(ia, ia + 9);
	list<int>lis(ia, ia + 9);
	vector<int>::iterator iter1 = vec.begin();
	list<int>::iterator iter2 = lis.begin();
	while (iter1 != vec.end()) {
		if ((*iter1) % 2 == 0) {
			iter1 = vec.erase(iter1);
		}
		else {
			iter1++;
		}
	}
	while (iter2 != lis.end()) {
		if ((*iter2) % 2 != 0) {
			iter2 = lis.erase(iter2);
		}
		else {
			iter2++;
		}
	}
	vector<int>::iterator iter3 = vec.begin();
	list<int>::iterator iter4 = lis.begin();
	while (iter3 != vec.end()) {
		cout << *iter3 << endl;
		iter3++;
	}
	while (iter4 != lis.end()) {
		cout << *iter4 << endl;
		iter4++;
	}
}
//查找并删除forward_list<int>中的奇数元素
void test10() {
	forward_list<int>flst = { 1,2,3,4,5,6,7,8,9,0 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if ((*curr) % 2 != 0) {
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;
			curr++;
		}
	}
	auto iter1 = flst.begin();
	while (iter1 != flst.end()) {
		cout << *iter1 << endl;
		iter1++;
	}
}
//接受一个forward_list<string>和两个string,在链表中查找第一个string，将第二个string插入到第一个string之后，若第一个string
//不存在，则将第二个插入到末尾
void test11(forward_list<string>& flst, string s1, string s2) {
	auto iter1 = flst.begin();
	auto iter2 = flst.before_begin();
	bool flag = true;
	for (iter1; iter1 != flst.end(); iter2 = iter1++) {
		if (*iter1 == s1) {//找到了
			flst.insert_after(iter1, s2);
			flag = false;
		}
	}
	if (flag) {//未找到
		flst.insert_after(iter2, s2);
	}
	auto iter3 = flst.begin();
	while (iter3 != flst.end()) {
		cout << *iter3 << endl;
		iter3++;
	}
}
int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	forward_list<string>list1 = { "cas","abc","jim","bub","vyv" };
	test11(list1, "jim", "nnn");
	return 0;
}