#pragma once

#include "value.h"
#include "compare.h"
#include <type_traits>
#include <cstdint>

namespace nicah
{
namespace petreseng
{

template<typename T>
class Saybolt_universal_viscosity : public nicah::utility::Value<T>
{
public:
   using base = nicah::utility::Value<T>;

   void value( T ) override;
};

}
}

template<typename T>
inline void nicah::petreseng::Saybolt_universal_viscosity<T>::value( T value )
{
   if( less<T, uint8_t>( value, 0 ) )
   {
      base::value( 0 );
   }
   else
   {
      base::value( value );
   }
}

