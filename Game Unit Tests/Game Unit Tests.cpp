#include "pch.h"
#include "CppUnitTest.h"
#include <SimpleMathExamples.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameUnitTests
{
	TEST_CLASS(GameUnitTests)
	{
	public:
		
		TEST_METHOD(AddTest)
		{
			Assert::AreEqual(4, SimpleMathExamples::Add(2, 2));
		}

		TEST_METHOD(SubstractTest)
		{
			Assert::AreEqual(0, SimpleMathExamples::Substract(2, 2));
		}

		TEST_METHOD(DivideTest)
		{
			Assert::AreEqual(1, SimpleMathExamples::Divide(2, 2));
		}
	};
}
