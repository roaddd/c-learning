#include "Query.h"
#include <fstream>
void test01()
{
	ifstream file("test.txt");
	TextQuery tQuery(file);
	Query q = Query("fieryzzz") | Query("wind");
	cout << q.eval(tQuery) << endl;
}
int main()
{
	test01();
	return 0;
}