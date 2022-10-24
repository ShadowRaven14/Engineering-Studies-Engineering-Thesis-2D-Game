#include "pch.h"
#include "CppUnitTest.h"
#include <BasicFunctions.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BasicFunctionsTests
{
	TEST_CLASS(GameUnitTests)
	{
	public:

		TEST_METHOD(Copy2DTableTest)
		{
			int tab1=0; int tab2=0;
			Assert::AreEqual(tab1, tab2);
		}
	};
}
