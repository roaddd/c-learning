#include "TestQuery.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
TestQuery::TestQuery(ifstream &infile)
{
	string s;
	while (getline(infile, s))
	{
		input.push_back(s);//按行存储在vector中
		int n = input.size() - 1;//保存当前行号
		istringstream ss(s);
		for (string word, text; ss >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			auto& lines = mas[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
QueryResult TestQuery::query(const string &s)const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = mas.find(s);
	if (loc == mas.end())
		return QueryResult(s, nodata, input);
	else
		return QueryResult(s, loc->second, input);
}
ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.word << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times" : "time" )<< endl;
	for (auto i : *qr.lines)
	{
		ConstStrBlobPtr p(qr.input, i);
		os << "\t(line" << i + 1 << ")" << p.deref() << endl;
	}
	return os;
}