#pragma once

#include "kinematic_viscosity.h"
#include "saybolt_universal_viscosity.h"
#include "pnt.h"
#include "pnt_container.h"
#include "interpolation.h"

namespace nhill
{
namespace petreseng
{

template<typename T = double>
Saybolt_universal_viscosity<T> to_saybolt_universal_viscosity( const Kinematic_viscosity<T> & kv );

}
}



template<typename T>
auto nhill::petreseng::to_saybolt_universal_viscosity( const Kinematic_viscosity<T> & kv )->Saybolt_universal_viscosity<T>
{
	// x is the kinematic viscosity
	// y is the equivalent Saybolt Universal viscosity at 100°F
   static const Pnt_container<T> pnts
   {
      { 2.0f,  32.6f},
      { 2.5f,  34.4f},
      { 3.0f,  36.0f},
      { 3.5f,  37.6f},
      { 4.0f,  39.1f},
      { 4.5f,  40.7f},
      { 5.0f,  42.3f},
      { 6.0f,  45.5f},
      { 7.0f,  48.7f},
      { 8.0f,  52.0f},
      { 9.0f,  55.4f},
      {10.0f,  58.8f},
      {11.0f,  62.3f},
      {12.0f,  65.9f},
      {13.0f,  69.6f},
      {14.0f,  73.4f},
      {15.0f,  77.2f},
      {16.0f,  81.1f},
      {17.0f,  85.0f},
      {18.0f,  89.2f},
      {19.0f,  93.3f},
      {20.0f,  97.5f},
      {21.0f, 101.7f},
      {22.0f, 106.0f},
      {23.0f, 110.3f},
      {24.0f, 114.6f},
      {25.0f, 118.9f},
      {26.0f, 123.3f},
      {27.0f, 127.7f},
      {28.0f, 132.1f},
      {29.0f, 136.5f},
      {30.0f, 140.9f},
      {31.0f, 145.3f},
      {32.0f, 149.7f},
      {33.0f, 154.2f},
      {34.0f, 158.7f},
      {35.0f, 163.2f},
      {36.0f, 167.7f},
      {37.0f, 172.2f},
      {38.0f, 176.7f},
      {39.0f, 181.2f},
      {40.0f, 185.7f},
      {41.0f, 190.2f},
      {42.0f, 194.7f},
      {43.0f, 199.2f},
      {44.0f, 203.8f},
      {45.0f, 208.4f},
      {46.0f, 213.0f},
      {47.0f, 217.6f},
      {48.0f, 222.2f},
      {49.0f, 226.8f},
      {50.0f, 231.4f},
      {55.0f, 254.4f},
      {60.0f, 277.4f},
      {65.0f, 300.4f},
      {70.0f, 323.4f},
   };

   T suv{linear_interpolation<T,T>( pnts, kv )};

   return suv;
};
