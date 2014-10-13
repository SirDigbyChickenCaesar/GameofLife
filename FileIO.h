#include <stdio.h>
#include <stdlib.h>

#define 	BORDER		2
#define 	INSIDE		1 

FILE *openFile (char *input);
//Function which opens the file for reading
void closeFile (FILE *input);
//Function which closes the file
void getGameHeight(FILE *input, int *height);
//Function which gets height of game board 
void getGameWidth(FILE *input, int *width);
//Function which gets width of game board
char **createBoard (FILE* input, int height, int width);
//This function creates a dynamic 2D array using the user-defined size.
//and copies the board from the file
