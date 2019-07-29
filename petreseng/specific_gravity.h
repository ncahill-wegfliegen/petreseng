#pragma once

#include <type_traits>

namespace nhill
{
namespace petreseng
{

template<typename T>
class Specific_gravity
{
	static_assert(std::is_floating_point_v<T>, "The template parameter must a floating point type (float, double of long double).");

public:
	using value_type = T;

	Specific_gravity( T = 0 );
	Specific_gravity& operator=( T );

	Specific_gravity( const Specific_gravity& );
	Specific_gravity& operator=( const Specific_gravity& );

	Specific_gravity( Specific_gravity&& );
	Specific_gravity& operator=( Specific_gravity&& );

	~Specific_gravity();

	operator T() const;

	T value() const;
	void value( T );

private:
	T value_;
};

}
}

template<typename T>
inline nhill::petreseng::Specific_gravity<T>::Specific_gravity( T value )
	: value_{value}
{
}

template<typename T>
inline auto nhill::petreseng::Specific_gravity<T>::operator=( T value)->Specific_gravity &
{
	this->value( value );
	return *this;
}

template<typename T>
inline nhill::petreseng::Specific_gravity<T>::Specific_gravity( const Specific_gravity& ) = default;

template<typename T>
inline auto nhill::petreseng::Specific_gravity<T>::operator=( const Specific_gravity& )->Specific_gravity & = default;

template<typename T>
inline nhill::petreseng::Specific_gravity<T>::Specific_gravity( Specific_gravity&& ) = default;

template<typename T>
inline auto nhill::petreseng::Specific_gravity<T>::operator=( Specific_gravity&& )->Specific_gravity & = default;

template<typename T>
inline nhill::petreseng::Specific_gravity<T>::~Specific_gravity() = default;

template<typename T>
inline nhill::petreseng::Specific_gravity<T>::operator T() const
{
	return value();
}

template<typename T>
inline T nhill::petreseng::Specific_gravity<T>::value() const
{
	return value_;
}

template<typename T>
inline void nhill::petreseng::Specific_gravity<T>::value( T value)
{
	value_ = value;
}

