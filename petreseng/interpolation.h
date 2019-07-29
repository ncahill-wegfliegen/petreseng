#pragma once

#include "pnt.h"
#include "pnt_container.h"
#include "compare.h"
#include <limits>
#include <stdexcept>
#include <array>

namespace nhill
{

template<typename T, typename FLT>
FLT linear_interpolation( const Pnt<T>& p1, const Pnt<T>& p2, T x )
{
	static_assert(std::is_floating_point_v<FLT>, "The return type must be floating point: float, double or long double.");

	if( equal<FLT>( p1.x, p2.x ) )
	{
		return std::numeric_limits<FLT>::max();
	}

	FLT x1{static_cast<FLT>(p1.x)};
	FLT y1{static_cast<FLT>(p1.y)};

	FLT x2{static_cast<FLT>(p2.x)};
	FLT y2{static_cast<FLT>(p2.y)};

	FLT y{y1 + (x - x1) * (y2 - y1) / (x2 - x1)};

	return y;
}

template<typename T>
std::array<typename Pnt<T>::cptr, 2> find_between( const Pnt_container<T>& pnts, T x )
{
	if( pnts.size() < 2 )
	{
		throw std::invalid_argument( "There are less than two points in the collection." );
	}

	if( less<T>( x, pnts.front().x ) || greater<T>( x, pnts.back().x ) )
	{
		throw std::invalid_argument( "The given x-value is outside of the collection." );
	}

	for( auto pnt1{pnts.begin()}; pnt1 < pnts.end() - 1; ++pnt1 )
	{
		auto pnt2{pnt1 + 1};

		if( greater_or_equal<T>( x, pnt1->x ) && less_or_equal<T>( x, pnt2->x ) )
		{
			return {&(*pnt1), &(*pnt2)};
		}
	}

	return {};
}

template<typename T, typename FLT>
FLT linear_interpolation( const Pnt_container<T>& pnts, T x )
{
	static_assert(std::is_floating_point_v<FLT>, "The return type must be floating point: float, double or long double.");

	FLT y{std::numeric_limits<FLT>::quiet_NaN()};
	std::array<typename Pnt<T>::cptr, 2> pair;

	try
	{
		pair = find_between( pnts, x );
	}
	catch( std::invalid_argument )
	{
		return y;
	}

	y = linear_interpolation<T,FLT>( *pair[0], *pair[1], x );

	return y;
}

}
