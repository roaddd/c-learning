#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
using namespace std;
class ConstStrBlobPtr;
class StrBlob {
public:
	using size_type = vector<string>::size_type;
	friend class ConstStrBlobPtr;
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
	StrBlob& operator=(const StrBlob&);
	ConstStrBlobPtr begin()const;
	ConstStrBlobPtr end() const;
	size_type size() const {
		return data->size();
	}
	bool empty() const {
		return data->empty();
	}

	void push_back(const string& t) {
		data->push_back(t);
	}
	void push_back(string&& t) && { data->push_back(move(t)); };
	void pop_back() {
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}


	string& front() {
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string& back() {
		check(0, "back on empty StrBlob");
		return data->back();
	}
	const string& front() const {
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const string& back() const {
		check(0, "back on empty StrBlob");
		return data->back();
	}
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& s) const {
		if (i >= data->size())
			throw out_of_range(s);
	};
};
class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
	const string& deref() const;
	ConstStrBlobPtr& incr();
private:
	shared_ptr<vector<string>> check(size_t, const string&)const;
	weak_ptr<vector<string>>wptr;
	size_t curr;
};


