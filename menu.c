/**
 * @file    menu.c
 * @Author  Danushka Ariyarathna
 * @brief	Helper menu of the Main driver of ppm file reader writer
 *
 * @date    18 March 2020
 */
#include "transform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * prints the menu of the program for the use of user
 *
 * 
 * @return              none
 */
int printMenu()
{

	int menuChoice = 0;

	printf("1. original image\n");
	printf("2. mirror image\n");
	printf("3. upside down image\n");
	printf("4. gray scale image\n");
	printf("5. rotate image to the right\n");
	printf("6. quit program\n");
	printf("\nMENU CHOICE:\t");

	if (scanf("%d", &menuChoice) == 0)
	{
		menuChoice = 0;
	}

	printf("\n");

	return menuChoice;
}
