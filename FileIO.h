#include <stdio.h>

FILE *openFile (char *input);
//Function which opens the file for reading
void closeFile (FILE *input);
//Function which closes the file
void getGameHeight(FILE *input, int *height);
//Function which gets height of game board 
void getGameWidth(FILE *input, int *width);
//Function which gets width of game board 