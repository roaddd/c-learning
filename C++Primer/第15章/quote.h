#ifndef QUOTE_H
#define QUOTE_H
#include <string>
using namespace std;
class Quote
{
public:
	Quote() = default;
	Quote(const string&b,double p):bookNo(b),price(p){}

	string isbn()const { return bookNo; }
	virtual double net_price(size_t n)const { return n * price; }
	virtual void debug()const;
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};
#endif
