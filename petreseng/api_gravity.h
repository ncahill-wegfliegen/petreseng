#pragma once

#include "..\..\gemeinsam\utility\value.h"
#include "..\..\gemeinsam\math\compare.h"
#include <type_traits>

namespace nhill
{
namespace petreseng
{

template<typename T>
struct Api_gravity_validator : public nhill::utility::Value_validator<T>
{
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type (float, double or long double).");

   bool is_valid( T value ) const override;
   void invalid( T value ) const override;
   T adjust( T value ) const override;
};


template<typename T>
class Api_gravity : public nhill::utility::Value<T, Api_gravity_validator<T>>
{
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type (float, double or long double).");

public:
   using base = nhill::utility::Value<T, Api_gravity_validator<T>>;
   using base::base;
};


}
}

template<typename T>
inline bool nhill::petreseng::Api_gravity_validator<T>::is_valid( T value ) const
{
   return nhill::math::greater_or_equal<T, uint8_t>( value, 0 );
}

template<typename T>
inline void nhill::petreseng::Api_gravity_validator<T>::invalid( T value ) const
{
   throw std::invalid_argument( "The value " + std::to_string( value ) + " is invalid.  The API gravity must be greater than or equal to zero." );
}

template<typename T>
inline T nhill::petreseng::Api_gravity_validator<T>::adjust( T value ) const
{
   return value;
}
