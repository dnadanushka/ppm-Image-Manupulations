# ppm-Image-Manupulations
program that reads in a .ppm image and stores the pixels
from the image in a linked-list of pixels. Once the image is read in, a menu is presented to the
user with choices of printing out the original image or some other manipulation.
up to now only reading and writing functions are implemented not the manipulating functions

## Files
- **mainDriver.c**  : Main driver program of the PPM manipulation Program
- **menu.c**        : Helper menu of the Main driver
- **parse.c**       : Parsing functions for the ppm reader
- **print.c**       : printing the ppm file
- **transform.h**   : Function and struct prototypes of whole program
- **west_1.ppm**    : ppm image file for test
- **makefile**      : makefile of the program

## How to use

### Compiling

> make

### running 
  As a example 'west_1.ppm' file is used

> make run

### clean

> make clean

## Example of the running program

![Termian examlle](/images/term.png)


![output](/images/output.png)
