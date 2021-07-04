#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <memory>
#include "StrBlobPtr.h"
#include <fstream>
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
//练习12.7
auto test02_1() {
	return make_shared<vector<int>>();
}
auto test02_2(shared_ptr<vector<int>> vec) {
	for (int i; cout << "Pls Enter:\n", cin >> i; vec->push_back(i));
	return vec;
}
auto test02_3(shared_ptr<vector<int>> vec) ->ostream&{
	for (auto i : *vec)
		cout << i << " ";
	return cout;
}
//练习12.14
struct connection {
	string ip;
	int port;
	connection(string ip_,int port_):ip(ip_),port(port_){}
};
struct destination {
	string ip;
	int port;
	destination(string ip_,int port_):ip(ip_),port(port_){}
};
connection connect(destination* pDest)
{
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	return *pConn;
}
void disconnect(connection pConn)
{
	cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}
void end_connection(connection* pConn)
{
	disconnect(*pConn);
}
void f(destination& d)
{
	connection conn = connect(&d);
	shared_ptr<connection>p(&conn, [](connection* pConn) {disconnect(*pConn); });
	cout << "connecting now(" << p.use_count() << ")" << std::endl;
}
//练习12.16
void test03()
{
	unique_ptr<string>p1(new string("abc"));

}
//练习12.20
void test04()
{
	ifstream ifs("单词.txt");
	StrBlob blob;
	for (string str; getline(ifs, str);)
		blob.push_back(str);
	for (ConstStrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
		cout << pbeg.deref() << endl;
}
//练习12.23
void test05()
{
	char* concatenate_string = new char[strlen("hello""world") + 1]();
	strcat(concatenate_string, "hello");
	strcat(concatenate_string, "world");
	cout << concatenate_string << endl;
	delete[]concatenate_string;

	string str1{ "hello" }, str2{ "world" };
	cout << str1 + str2 << endl;;
}
//练习12.24
void test06()
{
	int size{ 0 };
	cin >> size;
	char* input = new char[size + 1]();
	cin.ignore();
	cout << "input the string: ";
	cin.get(input,size+1);
	cout << endl<<input;
	delete[] input;
}
//练习12.26
void test07()
{
	int n = 5;
	allocator<string>alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p;
	while (q != p + n && cin >> s)
		alloc.construct(q++, s);
	while (q != p)
	{
		cout << *--q << " ";
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
}
//练习12.27
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
void test08()
{
	ifstream file("单词.txt");
	vector<string>input;
	map<string, set<decltype(input.size())>>dictionary;
	decltype(input.size()) line_no{ 0 };
	for (string line; getline(file, line); ++line_no)
	{
		input.push_back(line);
		istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			dictionary[word].insert(line_no);
		}
	}
	while (true)
	{
		cout << "enter word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		auto found = dictionary.find(s);
		if (found != dictionary.end())
		{
			cout << s << " occurs " << found->second.size() << (found->second.size() > 1 ? "times" : "time") << endl;
			for (auto i : found->second)
				cout << "\t(line" << i + 1 << ")" << input.at(i) << endl;

		}
		else
			cout << s << " occurs 0 time" <<endl;
	}
}
int main()
{
	//test01();
	//auto vec=test02_2(test02_1());
	//test02_3(vec) << endl;
	//destination dest("202.118.176.67", 3316);
	//f(dest);
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}