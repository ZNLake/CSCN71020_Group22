#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char result[100];
			strcpy(result, analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]));		//strcpy
			printf_s("%s\n", result);
			break;
		/*case 2:
			printf_s("Rectangle selected. \n");
			int rectangleSides[4][2];
			int* rectangleSidesPtr = getRectangleSides(rectangleSides);
			char result[100];
			strcpy(result, analyzeRectangle(rectangleSidesPtr[0], rectangleSidesPtr[1], rectangleSidesPtr[2], rectangleSidesPtr[3]));
			printf_s("%s\n");
			break;*/
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

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

/*
int* getRectangleSides(int* rectangleSides) {
	int temp;
	int j;

	printf_s("Enter the four points of the rectangle: ");
	for (int i = 0; i < 4; i++)
	{
		printf_s("Enter point %dx of the rectangle: ");
		for(j = 0; j < 2; j++)
		{
			scanf_s("%d", &rectangleSides[i][j]);
		}
		
		printf_s("Enter point %dx of the rectangle: ");
		for (j = 0; j < 2; j++)
		{
			scanf_s("%d", &rectangleSides[i][j]);
		}
	}
	return rectangleSides;
} 
*/