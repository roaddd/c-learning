#define _CRT_SECURE_NO_WARNINGS 1
#include "strblob.h"
#include <iostream>
#include <vector>
#include <memory>
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
int main()
{
	//test01();
	//auto vec=test02_2(test02_1());
	//test02_3(vec) << endl;
	//destination dest("202.118.176.67", 3316);
	//f(dest);
	return 0;
}