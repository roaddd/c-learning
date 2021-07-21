#ifndef BLOBPTR_H
#define BLOBPTR_H
#include <memory>
#include <vector>
#include "Blob.h"

template <typename> class BlobPtr;

template <typename T>
bool operator ==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
bool operator < (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template<typename T> class BlobPtr
{
	friend bool operator==<T>
		(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs);
	friend bool operator < <T>
		(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs);
public:
	BlobPtr():curr(0){ }
	BlobPtr(Blob<T>&a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }

	T* operator*()const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	BlobPtr& operator++();
	BlobPtr& operator--();

	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	shared_ptr<vector<T>>
		check(size_t, const string&)const;

	weak_ptr<vector<T>>wptr;
	size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlob");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlob");
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;

}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template<typename T>bool operator==(const BlobPtr<T>&lhs, const BlobPtr<T>&rhs)
{
	if (lhs.wptr.lock() != rhs.wptr.lock())
	{
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.curr == rhs.curr;
}
template<typename T> bool operator < (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.curr < rhs.curr;
}
#endif // !BLOBPTR_H

