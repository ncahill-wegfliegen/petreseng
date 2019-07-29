#include "pch.h"
#include "CppUnitTest.h"
#include "specific_gravity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nicah::petreseng;

namespace petresengtest
{
TEST_CLASS( Specific_gravity_type )
{
public:

	TEST_METHOD( ctor )
	{
		Specific_gravity<double> g;
		Specific_gravity<int> g1;

		g1.value( 5 );
	}
};
}
