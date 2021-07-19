#ifndef QUOTE_H
#define QUOTE_H
#include <string>
<<<<<<< HEAD
#include <iostream>
using namespace std;
class Quote
{
	friend bool operator!=(const Quote& lhs, const Quote& rhs);
=======
using namespace std;
class Quote
{
>>>>>>> ee7b8231da2ac9601ecd76991b576f910fad84ae
public:
	Quote() = default;
	Quote(const string&b,double p):bookNo(b),price(p){}

<<<<<<< HEAD
	Quote(const Quote& q) :bookNo(q.bookNo), price(q.price)
	{
		cout << "Quote:copy constructing\n";
	}
	Quote(Quote&& q)noexcept :bookNo(move(q.bookNo)), price(move(q.price))
	{
		cout << "Quote:move constructring\n";
	}
	Quote& operator=(const Quote& rhs)
	{
		if (*this != rhs)
		{
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		cout << "Quote:copy=()\n";
		return *this;
	}
	Quote& operator=(Quote&& rhs)noexcept
	{
		if (*this != rhs)
		{
			bookNo = move(rhs.bookNo);
			price = move(rhs.price);
		}
		cout << "Quote:move=!!!!!!!\n";
		return *this;
	}

	virtual Quote* clone() const &
	{
		return new Quote(*this);
	}
	virtual Quote* clone()const &&
	{
		return new Quote(move(*this));
	}

=======
>>>>>>> ee7b8231da2ac9601ecd76991b576f910fad84ae
	string isbn()const { return bookNo; }
	virtual double net_price(size_t n)const { return n * price; }
	virtual void debug()const;
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};
<<<<<<< HEAD

bool inline operator!=(const Quote& lhs, const Quote& rhs)
{
	return (lhs.bookNo != rhs.bookNo) && (lhs.price != rhs.price);
}
=======
>>>>>>> ee7b8231da2ac9601ecd76991b576f910fad84ae
#endif
