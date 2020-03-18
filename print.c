/**
 * @file    print.c
 * @Author  Danushka Ariyarathna
 * @brief   printing the ppm file
 *
 * @date    18 March 2020
 */
#include "transform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Printing the header information of the ppm file
 *
 *
 * @param rows          number of pixel rows in the picture        
 * @param cols          number of pixel columns in the picture
 * @return              none
 */
void printHeader(int rows, int cols)
{
    FILE * outFile;
    outFile = fopen("output.ppm", "w+");
    fprintf(outFile,"P6 \n%d %d %d\n", cols, rows, 225);
    fclose(outFile);
}

/**
 * Printing image information to the image file
 *
 *
 * @param rows          number of pixel rows in the picture        
 * @param cols          number of pixel columns in the picture
 * @param theImage      pointer to the linkedlist containg image information
 * @return              none
 */
void printImage(int rows, int cols, list_t *theImage)
{
    FILE * outFile;
    outFile = fopen("output.ppm", "a");
    int i = 0;
    int length = rows * cols;

    pixel_t *node;
    if (theImage->head == NULL)
    {
        printf("\nEmpty List");
        return;
    }

    node = theImage->head;

    while (i < length)
    {

        fprintf(outFile,"%c", node->r);
        fprintf(outFile,"%c", node->g);
        fprintf(outFile,"%c", node->b);

        node = node->next;

        i++;
    }
    fclose(outFile);
}