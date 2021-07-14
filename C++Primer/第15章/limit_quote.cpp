#define _CRT_SECURE_NO_WARNINGS 1
#include "limit_quote.h"
#include <iostream>
void Limit_quote::debug()const
{
	Quote::debug();
	cout<< "max_qty= " << this->max_qty << " "
		<< "discount= " << this->discount << " ";
}