#pragma once

#include <type_traits>

namespace nhill
{

template<typename T>
struct Pnt
{
	static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type: either integral or floating point.");

	using value_type = T;
	using ptr = Pnt<T>*;
	using cptr = const Pnt<T>*;
	using ref = Pnt<T> &;
	using cref = const Pnt<T> &;

	T x;
	T y;
};

}

