#include "Basket.h"
void Basket::add_item(const Quote&sale)
{
	items.insert(shared_ptr<Quote>(sale.clone()));
}
void Basket::add_item(Quote&&sale)
{
	items.insert(shared_ptr<Quote>(move(sale).clone()));
}
double print_total(ostream&os, const Quote&item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " sold: " << n << " total due: " << ret << endl;
	return ret;
}
double Basket::total_recepit(ostream&os)const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
}
