#pragma once

#include "..\..\gemeinsam\utility\value.h"
#include <type_traits>

namespace nhill
{
namespace petreseng
{

template<typename T>
class Api_gravity
{
	static_assert(std::is_floating_point_v<T>, "The template parameter must a floating point type (float, double of long double).");

public:
	using value_type = T;

	Api_gravity( T = 0 );
	Api_gravity& operator=( T );

	Api_gravity( const Api_gravity& );
	Api_gravity& operator=( const Api_gravity& );

	Api_gravity( Api_gravity&& );
	Api_gravity& operator=( Api_gravity&& );

	~Api_gravity();

	operator T() const;

	T value() const;
	void value( T );

private:
	T value_;
};

}
}

template<typename T>
inline nhill::petreseng::Api_gravity<T>::Api_gravity( T value )
	: value_{value}
{
}

template<typename T>
inline auto nhill::petreseng::Api_gravity<T>::operator=( T value )->Api_gravity &
{
	this->value( value );
	return *this;
}

template<typename T>
inline nhill::petreseng::Api_gravity<T>::Api_gravity( const Api_gravity& ) = default;

template<typename T>
inline auto nhill::petreseng::Api_gravity<T>::operator=( const Api_gravity& )->Api_gravity & = default;

template<typename T>
inline nhill::petreseng::Api_gravity<T>::Api_gravity( Api_gravity&& ) = default;

template<typename T>
inline auto nhill::petreseng::Api_gravity<T>::operator=( Api_gravity&& )->Api_gravity & = default;

template<typename T>
inline nhill::petreseng::Api_gravity<T>::~Api_gravity() = default;

template<typename T>
inline nhill::petreseng::Api_gravity<T>::operator T() const
{
	return value();
}

template<typename T>
inline T nhill::petreseng::Api_gravity<T>::value() const
{
	return value_;
}

template<typename T>
inline void nhill::petreseng::Api_gravity<T>::value( T value)
{
	value_ = value;
}

