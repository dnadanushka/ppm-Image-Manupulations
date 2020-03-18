/**
 * @file    mainDriver.c
 * @Author  Danushka Ariyarathna
 * @brief   Main driver program of the PPM reader writer Program
 *
 * @date    18 March 2020
 */
#include "transform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Global Variables */
list_t *theImage;
int rows, cols, maxColorValue, version;

/*Main function*/
int main(int argc, char const *argv[])
{

	int menuChoice;
	/*Verify that correct number of arguments are supplied */
	if (argc != 2)
	{
		printf("Provide a PPM file for processing on the command line.");
		printf("For example:\n");
		printf("transform somefile.PPM\n");
		return 1;
	}

	/* Open input file and check that file is valid */
	FILE *inFile;
	//printf("Processing %s\n", argv[1]);
	inFile = fopen(argv[1], "rb");
	if (!inFile)
	{
		// We can't open the file and thus we can't proceed.
		printf("File %s cannot be opened.\n", argv[1]);
		return 1;
	}

	// When we get to here we have the file open and accessable through file
	//pointer pointerToFile.

	// Get row and column count
	theImage = (list_t *)malloc(sizeof(pixel_t) * cols * rows);
	parseHeader(inFile, &cols, &rows);
	getImage(inFile, rows, cols, theImage);

	menuChoice = 0;

	// D6. if menuChoice == 1, then call printHeader() and printImage
	while (menuChoice != 6)
	{

		// D5. call printMenu()
		menuChoice = printMenu();

		switch (menuChoice)
		{

		case 0: //~ maybe make this print the menu again??
			printf("This is not a valid option\n\n");
			break;
		case 1:
			printHeader(rows, cols);
			printImage(rows, cols, theImage);
			printf("output.ppm is generated\n\n");
			break;

		case 2:
			printf("mirror not implemented yet\n\n");
			break;

		case 3:
			printf("upside down image not implemented yet\n\n");
			break;

		case 4:
			printf("gray scale image not implemented yet\n\n");
			break;

		case 5:
			printf("rotate to the right not implemented yet\n\n");
			break;

		case 6:
			break;

		default: //~ maybe make this print the menu again??
			printf("This is not a valid option\n\n");
			break;
		} // end switch statement bracket
	}	  // end while statment bracket
}
