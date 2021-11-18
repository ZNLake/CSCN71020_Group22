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
	double* rectPropStg;
	
	//if each point is eaqual, it forms a triangle
	if (x1 == y2 && y1 == x2 && x3 == y4 && y3 == x4)
	{
		double length, width;
		//Calculates length of rectangle
		length = x1 - x2;
		length = fabs(length);

		//Calculates width of rectangle
		width = y1 - y2;
		width = fabs(width);

		rectPropStg = rectCalc(rectProp, length, width);
		sprintf(result1, "This rectangle has a perimeter of %.2lf m, and an area of %.2lf m.", rectPropStg[0], rectPropStg[1]);
		return result1;
	}
	else
	{
		strcpy(result1, "This is not a rectangle");
		return result1;
	}
}

double* rectCalc(double* rectProp, double width, double length)
{
	rectProp[0] = 2*(width + length);// calculates the perimeter
	rectProp[1] = width * length;//calculates the area

	return rectProp;
}
