#define _CRT_SECURE_NO_WARNINGS 1
#include "bulk_quote.h"
#include "limit_quote.h"
#include "quote.h"
#include "disc_quote.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "teat_5_22/TestQuery.h"
#include "Query.h"
void print_debug(const Quote& q)
{
	q.debug();
}
double print_total(ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
void test01()
{
	ifstream file("test.txt");
	TestQuery tQuery(file);
	Query q=Query("fieryzzz") | Query("wind");
	cout << q.eval(tQuery) << endl;
}
int main()
{
	Quote q("aaa", 10.60);
	Bulk_quote bq("bbb", 111, 10, 0.3);
	Limit_quote lq("ccc", 222, 10, 0.3);

	/*Quote& r = q;
	r.debug();
	cout << "\n";
	r = bq;
	r.debug();
	cout << "\n";
	r = lq;
	r.debug();
	cout << "\n";
	cout << "====================\n";
	print_debug(q);
	cout << "\n";
	print_debug(lq);
	cout << "\n";
	print_debug(bq);
	cout << "\n";*/


	test01();

	return 0;
}