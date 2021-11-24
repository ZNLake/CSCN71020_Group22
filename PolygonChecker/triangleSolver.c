#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "triangleSolver.h"
#define PI 3.1415926

char* analyzeTriangle(int side1, int side2, int side3) 
{
 	char result1[300];
	double triAngles[3];
	double* triAngleStg;

	int temp1, temp2, temp3;

	temp1 = side1 + side2;
	temp2 = side1 + side3;
	temp3 = side3 + side2;

	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		strcpy(result1, "Not a triangle.");
		return result1;
	}
	else if (temp1 <= side3 || temp2 <= side2 || temp3 <= side1)
	{
		strcpy(result1, "Not a triangle.");
		return result1;
	}
	else if (side1 == side2 && side1 == side3) 
	{
		triAngleStg = analyzeAngles(triAngles, side1, side2, side3);
		sprintf(result1,"\nA Equilateral triangle. Angle A equals %.2lf degrees. Angle B equals %.2lf degrees. Angle C equals %.2lf degrees.\n", triAngleStg[0], triAngleStg[1], triAngleStg[2]);
		return result1;
	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2))
	{
		triAngleStg = analyzeAngles(triAngles, side1, side2, side3);
		sprintf(result1, "\nA Isosceles triangle. Angle A equals %.2lf degrees. Angle B equals %.2lf degrees. Angle C equals %.2lf degrees.\n", triAngleStg[0], triAngleStg[1], triAngleStg[2]);
		return result1;
	}
	else 
	{
			triAngleStg = analyzeAngles(triAngles, side1, side2, side3);
			sprintf(result1, "\nA Scalene triangle. Angle A equals %.2lf degrees. Angle B equals %.2lf degrees. Angle C equals %.2lf degrees.\n", triAngleStg[0], triAngleStg[1], triAngleStg[2]);
			return result1;
	}
}

double* analyzeAngles(double* triAngles, int side1, int side2, int side3)
{
	double angleA, angleB, angleC;
	int temp1, temp2;

	temp1 = pow(side2, 2) + pow(side3, 2);
	temp2 = 2 * side2 * side3;
	angleA = pow(side1, 2) - temp1;
	angleA = fabs(angleA) / temp2;
	angleA = acos(angleA);
	angleA = angleA * 180 / PI;//Converting the results from radians to degrees
	
	temp1 = pow(side1, 2) + pow(side3, 2);
	temp2 = 2 * side1 * side3;
	angleB = pow(side2, 2) - temp1;
	angleB = fabs(angleB) / temp2;
	angleB = acos(angleB);
	angleB = angleB * 180 / PI;//Converting the results from radians to degrees

	angleC = 180 - angleA - angleB;

	triAngles[0] = angleA;
	triAngles[1] = angleB;
	triAngles[2] = angleC;
	return triAngles;
} 