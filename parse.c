/**
 * @file    parse.c
 * @Author  Danushka Ariyarathna
 * @brief   Parsing functions for the ppm reader
 *
 * @date    18 March 2020
 */
#include "transform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Reads the header information of the ppm image file
 *
 *
 * @param input         ppm file to read data from
 * @param rows          pointer to the number of pixel rows in the picture        
 * @param cols          pointer to the number of pixel columns in the picture
 * @return              none
 */
void parseHeader(FILE *input, int *cols, int *rows)
{
    char c; // Character pointer to grab each character
    int maxValue;

    /* Validate the Definition Number */
    fscanf(input, "P%c\n", &c);
    //printf("P%c\n", c);
    if (c != '6')
    {
        if (c != '3')
        {
            /* Definition Number is neither 6, nor 3 - return ERROR */
            // printf("Definition Number is not valid");
            return;
        }
    }

    c = getc(input);

    /* Skip Comments in the Header */
    while (c == '#')
    {
        do
        {
            c = getc(input);
            // printf("%c", c);
        } while (c != '\n');
        // printf("\n");
        c = getc(input);
    }

    /* Ensure next character is a digit, otherwise return ERROR */
    if (!isdigit(c))
    {
        printf("Error in the input file");
        return;
    }

    /* Return the digit so that it may be extracted wholly */
    ungetc(c, input);

    /* Scan for the maximum width, height, and maximum color spectrum */
    fscanf(input, "%d%d%d\n", cols, rows, &maxValue);

    if (maxValue > 255)
    {
        printf("\nMaximum color value supplied has exceeed"
               " supported range. Constraining to 255.");
        return;
    }
    // printf("header doene\n");
}

/**
 * Reads the content of the image and store in a linked list
 *
 *
 * @param input         ppm file to read data from
 * @param rows          pointer to the number of pixel rows in the picture        
 * @param cols          pointer to the number of pixel columns in the picture
 * @param theImage      pointer to the linked list to store the image data
 * @return              none
 */
void getImage(FILE *input, int rows, int cols, list_t *theImage)
{
    char c, r, g, b;
    int i = 0;
    int length = rows * cols;

    /*innitializing the linked List*/
    theImage->head = NULL;
    theImage->tail = NULL;

    /* For each pixel */
    while (i < length)
    {

        /* While the next character is not EOF  */
        if ((c = fgetc(input)) != EOF)
        {

            //Creating and innitializign a new pixel
            pixel_t *tempPixel;
            tempPixel = (pixel_t *)malloc(sizeof(pixel_t));
            /* Return the character */
            ungetc(c, input);
            /* Grab the next three integers and assign them to the pixel buffer */
            if (fscanf(input, "%c%c%c", &r, &g, &b) == 3)
            {
                //printf("%d getted\n",i);
                tempPixel->r = r;
                tempPixel->g = g;
                tempPixel->b = b;
                tempPixel->next = NULL;
                if (theImage->head == NULL)
                {
                    theImage->head = tempPixel;
                    theImage->tail = tempPixel;
                }
                else
                {
                    theImage->tail->next = tempPixel;
                    theImage->tail = theImage->tail->next;
                }
            }
            i++;
        }
    }
}