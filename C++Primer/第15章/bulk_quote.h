#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "disc_quote.h"
class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	/*Bulk_quote(const string&b,double p,size_t q,double disc):
		Disc_quote(b,p,q,disc){}*/
	using Disc_quote::Disc_quote;

	Bulk_quote(const Bulk_quote& b) :Disc_quote(b)
	{
		cout << "Bulk_quote:copy constructor\n";
	}
	Bulk_quote(Bulk_quote&& b)noexcept :Disc_quote(move(b))
	{
		cout << "Bulk_quote:move constructor\n";
	}
	Bulk_quote& operator=(const Bulk_quote& rhs)
	{
		Disc_quote::operator=(rhs);
		cout << "Bulk_quote:copy=()\n";
		return *this;
	}
	Bulk_quote& operator=(const Bulk_quote&& rhs)
	{
		Disc_quote::operator=(move(rhs));
		cout << "Bulk_quote:move=()\n";
		return *this;
	}

	Bulk_quote* clone()const&
	{
		return new Bulk_quote(*this);
	}
	Bulk_quote* clone()const &&
	{
		return new Bulk_quote(move(*this));
	}

	double net_price(size_t n)const override;
	void debug()const override;

	~Bulk_quote()override
	{
		cout << "destructoing Bulk_quote\n";
	}
};
#endif // !BULK_QUOTE_H

