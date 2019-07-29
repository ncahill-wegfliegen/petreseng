#pragma once

#include "..\..\gemeinsam\utility\value.h"
#include "compare.h"
#include <type_traits>
#include <cstdint>
#include <stdexcept>



namespace nhill
{
namespace petreseng
{

template<typename T>
struct Kinematic_viscosity_validator : public nhill::utility::Value_validator<T>
{
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type (float, double or long double).");

   bool is_valid( T value ) const override;
   void invalid( T value ) const override;
   T adjust( T value ) const override;
};

template<typename T>
class Kinematic_viscosity : public nhill::utility::Value<T, Kinematic_viscosity_validator<T>>
{
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type (float, double or long double).");

public:
   using base = nhill::utility::Value<T, Kinematic_viscosity_validator<T>>;
   using base::base;
};

}
}

template<typename T>
inline bool nhill::petreseng::Kinematic_viscosity_validator<T>::is_valid( T value ) const
{
   return greater_or_equal<T,uint8_t>(value,0);
}

template<typename T>
inline void nhill::petreseng::Kinematic_viscosity_validator<T>::invalid( T value) const
{
   throw std::invalid_argument( "The value " + std::to_string( value ) + " is invalid.  The kinematic viscosity must be greater than or equal to zero." );
}

template<typename T>
inline T nhill::petreseng::Kinematic_viscosity_validator<T>::adjust( T value ) const
{
   return value;
}
