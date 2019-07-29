#include "pch.h"
#include "CppUnitTest.h"
#include "interpolation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nicah::petreseng;

namespace petresengtest
{
TEST_CLASS( Interpolation_test )
{
public:

	TEST_METHOD( interpolate_test )
	{
	}

	TEST_METHOD( convert_to_api_test )
	{
		Specific_gravity<double> g{0.6690};
		Api_gravity<double> api{to_api( g )};
	}

	TEST_METHOD( convert_to_specific_test )
	{
		Api_gravity<double> api{80};
		Specific_gravity<double> g{to_specific( api )};
	}
};
}
