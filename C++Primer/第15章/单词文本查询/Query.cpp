#include "Query.h"
#include <set>
#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(const TextQuery&text)const
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<size_t>>();
	set_intersection(left.begin(), left.end(), right.begin(),
		right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery&text)const
{
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<size_t>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file().size();
	for (size_t n = 0; n != sz; ++n)
	{
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

QueryResult OrQuery::eval(const TextQuery&text)const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<size_t>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}