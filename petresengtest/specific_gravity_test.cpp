#include "pch.h"
#include "CppUnitTest.h"
#include "..\petreseng\convert_gravity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::petreseng;

namespace petresengtest
{
	TEST_CLASS(petresengtest)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			Specific_gravity<double> g{5};
		}

		TEST_METHOD( convert_to_api_test )
		{
			Specific_gravity<double> g{0.6690};
			Api_gravity<double> api{to_api( g )};
		}

		TEST_METHOD( convert_to_specific_test )
		{
			Api_gravity<double> api{80};
			Specific_gravity<double> g{to_specific(api)};
		}
	};
}
