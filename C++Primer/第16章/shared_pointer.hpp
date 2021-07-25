#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include <functional>
#include "delete.hpp"
using namespace std;

namespace cp5 {

	template<typename T>
	class SharedPointer;

	template<typename T>
	void swap(SharedPointer<T>&lhs, SharedPointer<T>&rhs)
	{
		swap(lhs.ptr, rhs.ptr);
		swap(lhs.ref_count, rhs.ref_count);
		swap(lhs.deleter, rhs.deleter);
	}

	template<typename T>
	class SharedPointer
	{
	public:
		SharedPointer() 
			:ptr{ nullptr }, ref_count{ new size_t(1) }, deleter{ Delete{} }
		{}


		explicit SharedPointer(T*raw_ptr)
			:ptr{ raw_ptr }, ref_count{ new size_t(1) }, deleter{ Delete{} }
		{}

		SharedPointer(SharedPointer const&other)
			:ptr{ other.ptr }, ref_count{ other.ref_count }, deleter{ other.deleter }
		{
			++*ref_count;
		}

		SharedPointer(SharedPointer &&other)noexcept
			:ptr{ other.ptr }, ref_count{ other.ref_count }, deleter{ move(other.deleter) }
		{
			other.ptr = nullptr;
			other.ref_count = nullptr;
		}

		SharedPointer&operator=(SharedPointer const&rhs)
		{
			if (*this == rhs)
				++*rhs.ref_count;
			decrement_and_destroy();
			ptr = rhs.ptr;
			ref_count = rhs.ref_count;
			deleter = rhs.deleter;
			return *this;
		}

		SharedPointer&operator=(SharedPointer &&rhs) noexcept
		{
			cp5::swap(*this, rhs);
			rhs.decrement_and_destory();
			return *this;
		}

		operator bool() const
		{
			return ptr ? true : false;
		}

		T& operator*()const
		{
			return *ptr;
		}

		T*operator->()const
		{
			return &*ptr;
		}

		auto use_count()const
		{
			return *ref_count;
		}

		auto get()const
		{
			return *ptr;
		}

		auto unique()const
		{
			return 1 == *ref_count;
		}

		void swap(SharedPointer&rhs)
		{
			cp5::swap(*this, rhs);
		}

		auto reset()
		{
			decrement_and_destroy();
		}
		//用传入的指针进行重置
		auto reset(T*pointer)
		{
			if (ptr != pointer)
			{
				decrement_and_destroy();
				ptr = pointer;
				ref_count = new size_t(1);
			}
		}
		//用传入的指针和删除器进行重置
		auto reset(T*pointer, const function<void(T*)>&d)
		{
			reset(pointer);
			deleter = d;
		}

		~SharedPointer()
		{
			decrement_and_destroy();
		}
	private:
		T*ptr;
		size_t*ref_count;
		function<void(T*)>deleter;

		auto decrement_and_destroy()
		{
			if (ptr && 0 == --*ref_count)//当前指针不为空且只有一个指针指向此对象
			{
			delete ref_count;
			deleter(ptr);
			}
			else if (!ptr)//当前指针没有指向任何对象
			delete ref_count;
			ptr = nullptr;
			ref_count = nullptr;
		}
	};
}

#endif // !SHARED_POINTER_HPP
