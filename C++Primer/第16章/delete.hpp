#ifndef DELETE_HPP
#define DELETE_HPP

struct Delete
{
	template<typename T>
	auto operator()(T*p)const
	{
		delete p;
	}
};

#endif // !DELETE_HPP
