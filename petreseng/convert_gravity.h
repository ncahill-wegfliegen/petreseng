#pragma once

#include "specific_gravity.h"
#include "api_gravity.h"

namespace nhill
{
namespace petreseng
{

template<typename T>
Specific_gravity<T> to_specific( const Api_gravity<T>& api )
{
	T a{static_cast<T>(141.5)};
	T b{static_cast<T>(131.5)};
	return a/(b + api);
}

template<typename T>
Api_gravity<T> to_api( const Specific_gravity<T>& g )
{
	T a{static_cast<T>(141.5)};
	T b{static_cast<T>(131.5)};
	return (a / g) - b;
}

}
}
