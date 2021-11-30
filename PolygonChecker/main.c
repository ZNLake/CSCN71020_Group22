#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	char result[300];
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			strcpy(result, analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]));
			printf_s("%s\n", result);
			strcpy(result, "");
			break;
		case 2:
			printf_s("Rectangle selected. \n");
			int rectangleSidesX[4] = {0, 0, 0, 0};
			int rectangleSidesY[4] = {0, 0, 0, 0};
			getRectangleSidesX(rectangleSidesX, rectangleSidesY);
			//int* rectangleSidesPtr = getRectangleSidesY(rectangleSidesY);
			strcpy(result, analyzeRectangle(rectangleSidesX[0], rectangleSidesY[0], rectangleSidesX[1], rectangleSidesY[1], rectangleSidesX[2], rectangleSidesY[2], rectangleSidesX[3], rectangleSidesY[3]));
			printf_s("%s\n", result);
			strcpy(result, "");
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) 
{
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}


int* getRectangleSidesX(int* rectangleSidesX, int* rectangleSidesY)
{
	printf_s("\nEnter the four X points of the rectangle: ");
	for (int i = 0; i < 4; i++)
	{
		printf_s("\nEnter point %d of the rectangle: ", i + 1);
		scanf_s("%d%*c%d", &rectangleSidesX[i], &rectangleSidesY[i]);
	}
	return rectangleSidesX, rectangleSidesY;
} 