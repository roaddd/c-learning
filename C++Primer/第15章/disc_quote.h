#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "quote.h"
class Disc_quote:public Quote
{
public:
	Disc_quote();
	Disc_quote(const string&b,double p,size_t q,double d):
		Quote(b,p),quantity(q),discount(d){}
	virtual double net_price(size_t n)const = 0;
protected:
	size_t quantity;
	double discount;
};
#endif // !DISC_QUOTE_H

