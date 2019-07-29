#include "pch.h"
#include "CppUnitTest.h"
#include "..\petreseng\viscosity.h"
#include "..\petreseng\kinematic_viscosity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;
using namespace nhill::petreseng;

namespace petresengtest
{


TEST_CLASS( Kin_visc_equiv_saybolt_test )
{
public:

   TEST_METHOD( container )
   {
      Kinematic_viscosity<float> kv{23.5f};
      kv.value( 3.5f );

      Saybolt_universal_viscosity<float> suv{to_saybolt_universal_viscosity( kv )};

   }

};
}
