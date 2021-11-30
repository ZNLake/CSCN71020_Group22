#include "pch.h"
#include "CppUnitTest.h"
#include <limits.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" double* analyzeAngles(double* triAngles, int side1, int side2, int side3);
extern "C" char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
extern "C" double* rectCalc(double* rectProp, double width, double length);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleSolvertests
{
	TEST_CLASS(typeOfTriangletests)
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
	};
	TEST_CLASS(analyzeAngleTests)
	{
	public:
		TEST_METHOD(analyzeAngles_AngleAFunctionality)// Checks if the angle A ouput is correct
		{
			double temp[3];
		
			analyzeAngles(temp, 19, 15, 17);

			//Rounding to two decimal places
			temp[0] = round(temp[0] * 100) / 100;

			Assert::AreEqual(72.54, temp[0]);//Checking angle A
		}
		TEST_METHOD(analyzeAngles_AngleBFunctionality)// Checks if the angle B ouput is correct
		{
			double temp[3];

			analyzeAngles(temp, 19, 15, 17);

			//Rounding to two decimal places
			temp[1] = round(temp[1] * 100) / 100;

			Assert::AreEqual(48.86, temp[1]);//Checking angle B
		}
		TEST_METHOD(analyzeAngles_AngleCFunctionality)// Checks if the angle C ouput is correct
		{
			double temp[3];
			analyzeAngles(temp, 19, 15, 17);

			//Rounding to two decimal places
			temp[2] = round(temp[2] * 100) / 100;

			Assert::AreEqual(58.6, temp[2]);//Checking angle C
		}
	};
	TEST_CLASS(fourPointsTests)
	{
	public:
		TEST_METHOD(analyzeRectangleCorrectPosFunctionality)// Checks if given positive correct input if the output is correct
		{
			char* result = analyzeRectangle(2, 4, 4, 2, 5, 7, 7, 5);

			Assert::AreEqual("This rectangle has a perimeter of 8.00 m, and an area of 4.00 m^2.", result);
		}
		TEST_METHOD(analyzeRectangleCorrectNegFunctionality)// Checks if given negative correct input if the output is correct
		{
			char* result = analyzeRectangle(-2, -4, -4, -2, -5, -7, -7, -5);

			Assert::AreEqual("This rectangle has a perimeter of 8.00 m, and an area of 4.00 m^2.", result);
		}
		TEST_METHOD(analyzeRectangleCorrectNegPosFunctionality)// Checks if given both negative and positive correct input iin a different order, if the output is correct.
		{
			char* result = analyzeRectangle(-3, 2, -3, -3, 4, 2, 4, -3);

			Assert::AreEqual("This rectangle has a perimeter of 24.00 m, and an area of 35.00 m^2.", result);
		}
		TEST_METHOD(analyzeRectangleFunctionality)// Checks if given input that does not form a rectangle
		{
			char* result = analyzeRectangle(2, 8, 4, 2, 5, 7, 7, 5);
		
			Assert::AreEqual("This is not a rectangle.", result);
		}
		TEST_METHOD(analyzeRectangleIncorrectFunctionality)// Checks if given incorrect input if the output is correct
		{
			char* result = analyzeRectangle(2, 'c', 4, 2, 5, 7, 7, 5);

			Assert::AreEqual("This is not a rectangle.", result);
		}
		TEST_METHOD(recCalcPerimFunctionality)// Checks if the perimeter output is correct
		{
			double temp[2];
			double* result;
			result = rectCalc(temp, 2.0, 2.0);

			Assert::AreEqual(8.0, result[0]);
		}
		TEST_METHOD(rectCalcAreaFunctionality)// Checks if the area output is correct
		{
			double temp[2];
			double* result;
			result = rectCalc(temp, 2.0, 2.0);

			Assert::AreEqual(4.0, result[1]);
		}
	};
}
