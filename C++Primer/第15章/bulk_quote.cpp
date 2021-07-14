#define _CRT_SECURE_NO_WARNINGS 1
#include "bulk_quote.h"
#include <iostream>
double Bulk_quote::net_price(size_t n)const
{
	return n * price * (n >= quantity ? 1 - discount : 1);
}
void Bulk_quote::debug()const
{
	Quote::debug();
	std::cout << "min_qty= " << this->quantity << " "
		<< "discount= " << this->discount << " ";
}