#define _CRT_SECURE_NO_WARNINGS 1
#include "quote.h"
#include <iostream>
void Quote::debug()const
{
	cout << "data members of this class:\n" << "bookNo= " << this->bookNo << " "
		<< "price= " << this->price << " ";
}