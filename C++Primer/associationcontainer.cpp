#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
//��ϰ11.3
void test01() {
	map<string, size_t>word_count;
	string word;
	while (cin >> word)
		++word_count[word];
	for (const auto& w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1 ? "times" : "time")) << endl;
}
//��ϰ11.4
void test02()
{
	map<string, size_t>word_count;
	fstream in("����.txt");
	string word;
	while (in >> word)
	{
		string::iterator iter1;
		for (iter1 = word.begin(); iter1 != word.end(); iter1++)
		{
			*iter1 = tolower(*iter1);
		}
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		++word_count[word];
	}
	auto iter2 = word_count.begin();
	while (iter2 != word_count.end())
	{
		cout << iter2->first << " "  << iter2->second << endl;
		iter2++;
	}
}
//��ϰ11.7
void test03()
{
	map<string, vector<string>>family;
	string first_name, child_name;
	while ([&]()->bool {cout << "�������ͥ����:"; return cin >> first_name && (first_name != "end"); }())
	{
		cout << "�����뺢�ӵ�����";
		while (cin >> child_name && (child_name != "end"))
		{
			family[first_name].push_back(child_name);
		}
	}

}
int main() {
	test02();
}