#include "pch.h"
#include "CppUnitTest.h"
#include <limits.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
char* analyzeAngles(int side1, int side2, int side3, char* triangleType);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleSolvertests
{
	TEST_CLASS(triangleSolvertests)
	{
	public:
		
		TEST_METHOD(analyzeTriangle_UpperBounds)
		{
			char* result;
			result = analyzeTriangle(1, 0, 2147483648);

			Assert::AreEqual("Invalid Input.", result);
		}
		TEST_METHOD(analyzeTriangle_LowerBounds)
		{
			char* result;
			result = analyzeTriangle(1, INT_MIN, 2);

			Assert::AreEqual("Invalid Input.", result);
		}
		TEST_METHOD(analyzeTriangle_UpperAndLowerBounds)
		{
			char* result;
			result = analyzeTriangle(2147483648, 0, INT_MIN);

			Assert::AreEqual("Invalid Input.", result);
		}
		TEST_METHOD(analyzeTriangle_MixedInput)//mixed correct and incorrect input
		{
			char* result;
			result = analyzeTriangle('Egg', 0, 1);

			Assert::AreEqual("Invalid Input.", result);
		}
	};
}
