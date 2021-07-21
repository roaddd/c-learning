#ifndef BLOB_H
#define BLOB_H
#include <memory>
#include <vector>
#include <initializer_list>
using namespace std;

template <typename T> class Blob
{
public:
	typedef typename vector<T>::size_type size_type;

	Blob();
	Blob(initializer_list<T>i1);

	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }

	void push_back(const T&t) { data->push_back(t); }
	void push_back(T&&t) { data->push_back(move(t)); }
	void pop_back();

	T& back();
	T& operator[](size_type i);

	const T& back()const;
	const T& operator[](size_type i)const;
private:
	shared_ptr<vector<T>>data;
	void check(size_type i, const string &msg)const;
};

template<typename T>
Blob<T>::Blob() :data(make_shared<vector<T>>())
{}

template<typename T>
Blob<T>::Blob(initializer_list<T>i1):
	data(make_shared<vector<T>>(i1)) { }

template<typename T>
void Blob<T>::check(size_type i, const string &msg)const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
const T& Blob<T>::operator[](size_type i)const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>	
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
#endif // !BLOB_H

