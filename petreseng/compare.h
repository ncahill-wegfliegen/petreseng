#pragma once

namespace nhill
{

enum class Compare{ less = -1, equal = 0, greater = 1 };

template<typename T, typename U>
Compare compare( T a, U b )
{
	if( a < b )
	{
		return Compare::less;
	}
	else if( a > b )
	{
		return Compare::greater;
	}
	else
	{
		return Compare::equal;
	}
}

template<typename T, typename U>
bool less( T a, U b )
{
	return compare<T,U>( a, b ) == Compare::less;
}

template<typename T, typename U>
bool equal( T a, U b )
{
	return compare<T, U>( a, b ) == Compare::equal;
}

template<typename T, typename U>
bool greater( T a, U b )
{
	return compare<T, U>( a, b ) == Compare::greater;
}

template<typename T, typename U>
bool less_or_equal( T a, U b )
{
	return less<T, U>( a, b ) || equal<T, U>( a, b );
}

template<typename T, typename U>
bool greater_or_equal( T a, U b )
{
	return greater<T, U>( a, b ) || equal<T, U>( a, b );
}

}
