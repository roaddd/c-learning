#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <forward_list>
#include <fstream>
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
//题9.31
void test12() {
	//对于list
	list<int> lis = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = lis.begin();
	while (iter != lis.end()) {
		if (*iter % 2) {
			lis.insert(iter, *iter);
			(iter++)++;
		}
		else {
			iter = lis.erase(iter);
		}
	}
	auto iter1 = lis.begin();
	while (iter1 != lis.end()) {
		cout << *iter1 << endl;
		iter1++;
	}
	cout << "----------分割线---------" << endl;
	//对于forward_list
	forward_list<int>fls = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = fls.before_begin();
	auto curr = fls.begin();
	while (curr != fls.end()) {
		if (*curr % 2) {
			fls.insert_after(prev, *curr);
			prev = curr;
			curr++;
		}
		else {
			curr = fls.erase_after(prev);
		}
	}
	auto iter2 = fls.begin();
	while (iter2 != fls.end()) {
		cout << *iter2 << endl;
		iter2++;
	}
}
//题9.33(程序崩溃)
void test13() {
	vector<int>vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		++iter;
		vi.insert(iter, 42);
		++iter;
	}
	auto iter2 = vi.begin();
	while (iter2 != vi.end()) {
		cout << *iter2 << endl;
	}
}
//题9.34
void test14() {
	vector<int>vec = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter1 = vec.begin();
	while (iter1 != vec.end()) {
		if (*iter1 % 2) {
			iter1 = vec.insert(iter1, *iter1);
			iter1 += 2;
		}
		else {
			iter1++;
		}
	}
	auto iter2 = vec.begin();
	while (iter2 != vec.end()) {
		cout << *iter2 << endl;
		iter2++;
	}
}
//题9.41
void test15() {
	vector<char>vec = { 'a','b','c','d' };
	string s(vec.begin(), vec.end());
	cout << s << endl;
}
//题9.43
void test16(string& s, const string& oldVal, const string& newVal) {
	auto iter1 = s.begin();
	for (iter1; iter1 != s.end(); iter1++) {
		auto iter3 = iter1;
		auto iter2 = oldVal.begin();
		for (iter2; iter2 != oldVal.end(); iter2++) {
			if (*iter2 != *iter1) {
				break;
			}
			iter1++;
		}
		if (iter2 == oldVal.end()) {//判断是否存在与oldVal相等值
			iter1 = s.erase(iter3, iter1);
			iter1 = s.insert(iter1, newVal.begin(), newVal.end());
			iter1 += (newVal.size() - 1);
		}
	}
	cout << s << endl;
}
//重写9.43，使用一个下标和replace
void test17(string& s, const string& oldVal, const string& newVal) {
	for (string::size_type i = 0; i < s.size(); i++) {
		if (s.substr(i, oldVal.size()) == oldVal) {
			s.replace(i, oldVal.size(), newVal);
			i += (newVal.size() - 1);
		}
	}
	cout << s << endl;
}
//题9.45
void test18(string& name, const string& s1, const string& s2) {
	auto iter1 = name.begin();
	name.append(s2);
	name.insert(iter1, s1.begin(), s1.end());
	cout << name << endl;
}
//重写题9.45只使用insert
void test19(string& name, const string& s1, const string& s2) {
	auto iter1 = name.begin();
	name.insert(iter1, s1.begin(), s1.end());
	name.insert(name.size(), s2);
	cout << name << endl;
}
//题9.47
void test20() {
	string s = "ab2c3d7R4E6";
	string numbers("0123456789");
	string::size_type pos = 0;
	while ((pos = s.find_first_of(numbers, pos))
		!= string::npos) {
		cout << "found number at index:" << pos << " element is " << s[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = s.find_first_not_of(numbers, pos))
		!= string::npos) {
		cout << "found character at index:" << pos << " element is " << s[pos] << endl;
		++pos;
	}
}
//题9.49
void test21() {
	string s("bdfghijklpqty");//包含上出头和下出头字母
	vector<string>vec;
	string s1;
	string ifile = "单词.txt";
	ifstream in(ifile);

	while (in >> s1) {
		int i = 0;
		string::size_type pos = 0;
		while ((pos = s1.find_first_not_of(s, pos))
			!= string::npos) {
			++i;
			++pos;
		}
		if (i == s1.size()) {
			vec.push_back(s1);
		}
	}
	//冒泡排序，找出不包含上下头的最长的单词
	if (!vec.empty()) {
		for (int i = 0; i < vec.size() - 1; i++) {
			for (int j = 0; j < vec.size() - 1 - i; j++) {
				if (vec[j].size() < vec[j + 1].size()) {
					swap(vec[j], vec[j + 1]);
				}
			}
		}

		cout << vec[0] << endl;
	}
	else {
		cout << "没有符合要求的单词" << endl;
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
	//test11(list1, "jim", "nnn");
	//test12();
	//test13();
	//test14();
	//test15();
	string s1 = "autiguhauthght";
	//test17(s1,"au","hh");
	string name = "Tom";
	//test19(name,"Mr.","Jr.");
	//test20();
	test21();
	return 0;
}