#include "pch.h"
#include "CppUnitTest.h"
#include "..\petreseng\interpolation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;
using namespace nhill::geometry;

namespace petresengtest
{
TEST_CLASS( Interpolation_test )
{
public:

	TEST_METHOD( linear_interpolation_test )
	{
		Pnt_container<float> pnts{{1,2}, {2,4}, {3,6}};
		float x{2.3f};

		float y{linear_interpolation<float,float>( pnts, x )};
		Assert::AreEqual( 4.6f, y );
	}

};
}
