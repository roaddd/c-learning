#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <memory>
#include <iostream>
#include "TestQuery.h"
using namespace std;

class Query_base
{
	friend class Query;
protected:
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&)const = 0;
	virtual string rep()const = 0;
};


class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const string&s) :query_word(s)
	{
		cout << "WordQuery::WordQuery(" + s + ")\n";
	}
	QueryResult eval(const TextQuery&t)const override
	{
		return t.query(query_word);
	}
	string rep()const override
	{
		std::cout << "WodQuery::rep()\n";
		return query_word;
	}

	string query_word;
};


class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	friend ostream& operator<<(ostream&os, const Query &query);
public:
	Query(const std::string& s) : q(new WordQuery(s))
	{
		std::cout << "Query::Query(const std::string& s) where s=" + s + "\n";
	}
	//½Ó¿Úº¯Êý
	QueryResult eval(const TextQuery&t)const
	{
		return q->eval(t);
	}
	string rep() const
	{
		std::cout << "Query::rep() \n";
		return q->rep();
	}

private:
	Query(shared_ptr<Query_base>query) :q(query)
	{
		cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
	}
	shared_ptr<Query_base>q;
};
inline ostream& operator<<(ostream&os, const Query&query)
{
	return os << query.rep();
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query&l, const Query&r, string s) :
		lhs(l), rhs(r), opSym(s)
	{
		cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n";
	}
	string rep()const override
	{
		cout << "BinaryQuery::rep()\n";
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	string opSym;
};

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&lhs, const Query&rhs);
	AndQuery(const Query&left, const Query&right) :
		BinaryQuery(left, right, "&")
	{
		cout << "AndQuery::AndQuery()\n";
	}
	QueryResult eval(const TextQuery&)const override;
};
inline Query operator&(const Query&lhs, const Query&rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class NotQuery :public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query&q) :query(q)
	{
		cout << "NotQuery::NotQuery()\n";
	}
	string rep()const override
	{
		cout << "NotQuery::rep()\n";
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&)const override;
	Query query;
};
inline Query operator~(const Query&operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&lhs, const Query&rhs);
	OrQuery(const Query&left, const Query&right) :
		BinaryQuery(left, right, "|")
	{
		cout << "OrQuery::OrQuery\n";
	}
	QueryResult eval(const TextQuery&)const override;
};
inline Query operator|(const Query&lhs, const Query&rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif // !QUERY_H



