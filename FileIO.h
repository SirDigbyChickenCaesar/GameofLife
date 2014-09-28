#include <stdio.h>

FILE *openFile (char *input);
//Function which opens the file for reading
void closeFile (FILE *input);
//Function which closes the file
void getGameHeight(FILE *input, int *height);
//Function which gets height of game board 
void getGameWidth(FILE *input, int *width);
//Function which gets width of game board
char **createBoard (int height, int width);
//This function creates a dynamic 2D array using the user-defined size.
char createBorder (char **board, int height, int width);
//Creates a border around the user-defined gameboard so we can create a torroidal array
void copyBoard (FILE *input, char **fileBoard, int height, int width);
//This function copies the board from the file into the array
