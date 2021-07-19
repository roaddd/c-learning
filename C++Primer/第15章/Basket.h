#ifndef BASKET_H
#define BASKET_H
#include <set>
#include <memory>
#include "quote.h"
using namespace std;
class Basket
{
public:
	/*void add_item(const shared_ptr<Quote>& sale)
	{
		items.insert(sale);
	}*/
	double total_recepit(ostream&)const;
	void add_item(const Quote&sale);
	void add_item(Quote&&sale);
private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*>
		items{ compare };
};
#endif // !BASKET_H

