#include "printErr.h"
#include <stdio.h>
#include <stdlib.h>

#define		BORDER			2
#define		CELL_BELOW		1
#define		CELL_ABOVE		1
#define		CELL_RIGHT		1
#define		CELL_LEFT		1
#define 	INSIDE			1 

void printArray (char **game, int height, int width);
//This function prints the game board;
int **createRuleBoard (int height, int width);
//Creates the board which determines if a cell lives or dies
void lifeDecider (char **gameBoard, int **cellDeath, int height, int width);

