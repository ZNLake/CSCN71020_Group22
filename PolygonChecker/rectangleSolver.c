#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "rectangleSolver.h"
#define PI 3.1415926

char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	char result1[300];
	double rectProp[2];
	double length, width;
	double* rectPropStg;
	
	//if each point is eaqual, it forms a rectamgle
	if (x1 == y2 && y1 == x2 && x3 == y4 && y3 == x4)
	{
		//Calculates length of rectangle
		length = x1 - x2;
		length = fabs(length);

		//Calculates width of rectangle
		width = y1 - y2;
		width = fabs(width);

		rectPropStg = rectCalc(rectProp, length, width);
		sprintf(result1, "This rectangle has a perimeter of %.2lf m, and an area of %.2lf m^2.", rectPropStg[0], rectPropStg[1]);
		return result1;
	}
	else if (y1 == y3 && y2 == y4 && x1 == x2 && x3 == x4)
	{
		//Calculates length of rectangle
		length = distance(x1, y1, x2, y2);
		length = fabs(length);

		//Calculates width of rectangle
		width = distance(x1, y1, x3, y3);
		width = fabs(width);

		rectPropStg = rectCalc(rectProp, length, width);
		sprintf(result1, "This rectangle has a perimeter of %.2lf m, and an area of %.2lf m^2.", rectPropStg[0], rectPropStg[1]);
		return result1;
	}
	else
	{
		return "This is not a rectangle.";
	}
}

double distance(x1, y1, x2, y2)
{
	double result = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return result;
}

double* rectCalc(double* rectProp, double width, double length)
{
	rectProp[0] = 2*(width + length);// calculates the perimeter
	rectProp[1] = width * length;//calculates the area

	return rectProp;
}

