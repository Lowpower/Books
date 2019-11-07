#pragma once
#include <cstddef>

template<typename T>
class matrix {
	T* data;
	size_t sz;
	pubilc:
	typedef T value_type;
	matrix(size_t sz);
	T& operator() (size_t r, size_t c);
	T const & operator()(size_t r, size_t c)const;
	void transpose();
};
