#define _CRT_SECURE_NO_WARNINGS 1
#include "HasPtr.h"
HasPtr& HasPtr::operator=(const HasPtr& rhs_hp)
{
	auto new_p = new string(*rhs_hp.ps);
	delete ps;
	ps = new_p;
	i = rhs_hp.i;
	return *this;
}
void HasPtr::show()const
{
	cout << *ps << "  " << i << endl;
}