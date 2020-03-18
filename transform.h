#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Struct to store pixel values*/
typedef struct pixel {
	unsigned char r, g, b;
	struct pixel * next;
}pixel_t;

/*Struct for the linked list*/
typedef struct list {
	pixel_t * head;
	pixel_t * tail;
} list_t;

/* Function Prototypes */
void parseHeader( FILE *input, int *cols, int *rows );
void getImage( FILE *input, int rows, int cols, list_t * theImage );
int printMenu();
void printHeader( int rows, int cols);
void printImage( int rows, int cols, list_t * theImage );

/*these are to be implemented*/
// void mirror( int rows, int cols, list_t * theImage );
// void flipHoriz( int rows, int cols, list_t * theImage );
// void grayScale( int rows, int cols, list_t * theImage );
// void rotate( int rows, int cols, list_t * theImage );

