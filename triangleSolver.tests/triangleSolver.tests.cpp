#include "pch.h"
#include "CppUnitTest.h"
#include <limits.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" double* analyzeAngles(double* triAngles, int side1, int side2, int side3);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleSolvertests
{
	TEST_CLASS(triangleSolvertests)
	{
	public:
		TEST_METHOD(analyzeTriangle_WrongInput)//checks if a numbers that dont create a triangle are given
		{
			char* result;
			result = analyzeTriangle(1, 2, 3);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeTriangle_NegativeInput)//checks if a single negative number is given
		{
			char* result;
			result = analyzeTriangle(-17, 15, 19);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeTriangle_AllNegativeInput)//checks if all negative numbers are given
		{
			char* result;
			result = analyzeTriangle(-17, -15, -19);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeTriangle_UpperBounds)// checks if only the upper bounds is exceeded
		{
			char* result;
			result = analyzeTriangle(1, 0, 2147483648);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeTriangle_LowerBounds)//checks if only the lower bounds is exceeded
		{
			char* result;
			result = analyzeTriangle(1, INT_MIN, 2);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeTriangle_UpperAndLowerBounds)//checks if both upper and lower bounds are exceeded
		{
			char* result;
			result = analyzeTriangle(2147483648, 0, INT_MIN);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeTriangle_MixedInput)//checks mixed correct and incorrect input with normal letters
		{
			char* result;
			result = analyzeTriangle('Egg', 0, 1);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeTriangle_MixedInput2)//checks mixed correct and incorrect input with special characters
		{
			char* result;
			result = analyzeTriangle('$#!^', 0, 1);

			Assert::AreEqual("Not a triangle.", result);
		}
		TEST_METHOD(analyzeAngles_AngleAFunctionality)// Checks if the angle A ouput is correct
		{
			double temp[3];
			double* result;
			result = analyzeAngles(temp, 19, 15, 17);
			
			//Rounding to two decimal places
			result[0] = round(result[0] * 100) / 100;

			Assert::AreEqual(72.54, result[0]);//Checking angle A
		}
		TEST_METHOD(analyzeAngles_AngleFBunctionality)// Checks if the angle B ouput is correct
		{
			double temp[3];
			double* result;
			result = analyzeAngles(temp, 19, 15, 17);

			//Rounding to two decimal places
			result[1] = round(result[1] * 100) / 100;

			Assert::AreEqual(48.86, result[1]);//Checking angle B
		}
		TEST_METHOD(analyzeAngles_AngleCFunctionality)// Checks if the angle C ouput is correct
		{
			double temp[3];
			double* result;
			result = analyzeAngles(temp, 19, 15, 17);

			//Rounding to two decimal places
			result[2] = round(result[2] * 100) / 100;
			
			Assert::AreEqual(58.6, result[2]);//Checking angle C
		}
	};
}
