#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <utility>
#include <set>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
//Á·Ï°11.3
void test01() {
	map<string, size_t>word_count;
	string word;
	while (cin >> word)
	{
		//++word_count[word];
		auto ret = word_count.insert({ word,1 });
		if (!ret.second) ++ret.first->second;
	}
	for (const auto& w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1 ? "times" : "time")) << endl;
}
//Á·Ï°11.4
void test02()
{
	map<string, size_t>word_count;
	fstream in("µ¥´Ê.txt");
	string word;
	while (in >> word)
	{
		string::iterator iter1;
		for (iter1 = word.begin(); iter1 != word.end(); iter1++)
		{
			*iter1 = tolower(*iter1);
		}
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		++word_count[word];
	}
	auto iter2 = word_count.begin();
	while (iter2 != word_count.end())
	{
		cout << iter2->first << " "  << iter2->second << endl;
		iter2++;
	}
}
//Á·Ï°11.7
void test03()
{
	map<string, vector<pair<string,string>>>family;
	string first_name, child_name,birthday;
	while ([&]()->bool {cout << "ÇëÊäÈë¼ÒÍ¥µÄÐÕ:"; return cin >> first_name && (first_name != "end"); }())
	{
		cout << "ÇëÊäÈëº¢×ÓµÄÃûºÍÉúÈÕ£º";
		while (cin >> child_name >> birthday&&child_name != "end")
		{
			family[first_name].push_back(make_pair(child_name,birthday));
		}
	}
	auto iter = family.begin();
	while (iter != family.end())
	{
		cout << iter->first << ":";
		auto iter2 = iter->second.begin();
		while (iter2 != iter->second.end())
		{
			cout << iter2->first << " " << iter2->second;
			iter2++;
		}
		iter++;
		cout << endl;
	}

}
//Á·Ï°11.9
void test04()
{
	unordered_map<string, list<int>>record;
	ifstream in("µ¥´Ê.txt");
	string lword, word;
	if (!in)cout << "°ó¶¨ÎÄ¼þÊ§°Ü" << endl;
	int line = 1;
	while (getline(in, lword))
	{
		istringstream read(lword);
		while (read >> word)
		{
			record[word].push_back(line);
		}
		line++;
	}
	for (auto iter = record.begin(); iter != record.end(); iter++)
	{
		cout << "µ¥´Ê£º" << iter->first << " ÐÐÊý£º" << *(iter->second).begin() << endl;

	}
}//Á·Ï°11.12
void test05()
{
	vector<pair<string, int>>vec;
	vector<string>vecstr = { "abj","nica","baiu","buab" ,"aaaaaak" };;
	vector<int>vecint = { 1,2,3,4,5 };
	auto iter1 = vecstr.begin();
	auto iter2 = vecint.begin();
	while (iter1 != vecstr.end() && iter2 != vecint.end())
	{
		//vec.push_back(make_pair(*iter1++, *iter2++));
		//vec.push_back({ *iter1++,*iter2++ });
		vec.push_back(pair<string,int>(*iter1++, *iter2++));
	}
	for (auto iter3 : vec)
	{
		cout << iter3.first << " " << iter3.second << endl;
	}
}
//Á·Ï°11.28
void test06()
{
	map<string, vector<int>>ma = { {"abc",{1,2,3}},{"VSD",{4,5,6}} };
	auto iter=ma.find("abc");
	cout << iter->first << endl;
	auto iter2 = iter->second.begin();
	while (iter2 != iter->second.end())
	{
		cout << *iter2<< endl;
		iter2++;
	}
}
//Á·Ï°11.31
void test07()
{
	string author = "Â³Ñ¸";
	string author1 = "ÕÅÃû";
	multimap<string, string>library;
	library.insert(make_pair(author, "ÄÅº°"));
	library.insert(make_pair(author, "áÝáå"));
	library.insert(make_pair(author, "¹ÊÊÂÐÂ±à"));
	library.insert(make_pair(author1, "Ò»"));
	string book = "ÄÅº°";
	if (library.find(author) != library.cend())
	{
		for (auto iter = library.equal_range(author); iter.first != iter.second;++iter.first)
		{
			if (iter.first->second == book)
			{
				library.erase(iter.first);
				break;
			}
		}
	}
	for (auto i : library)
	{
		cout << i.first << ":" << i.second << endl;
	}
}
//Á·Ï°11.32
void test08()
{
	multimap<string, string>authors{
		{"nais","ads"},
		{"nais","adffsf"},
		{"ads","afrsf"},
		{"au","aer"}
	};
	map<string, multiset<string>>order_authors;
	for (const auto& author : authors)
		order_authors[author.first].insert(author.second);
	for (const auto& author : order_authors) 
	{
		cout << author.first << ":";
		for (const auto& work : author.second)
			cout << work << " ";
		cout << endl;
	}

}
//Á·Ï°11.33
map<string,string> buildMap(ifstream&map_file)
{
	map<string, string>trans_map;
	string key;
	string value;
	while (map_file>>key&&getline(map_file,value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}
const string& transform(const string& s, const map<string, string>& m)
{
	auto map_it = m.find(s);
	return map_it == m.cend() ? s : map_it->second;
}
void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}
void test09()
{//µ¥´Ê×ª»»³ÌÐò
	ifstream ifs_map("word_map_file.txt"),ifs_content("input_word_file.txt");
	if (ifs_content && ifs_content)
		word_transform(ifs_map, ifs_content);
	else
		cerr << "can't find the documents." << endl;
}
int main() {
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	test09();
}