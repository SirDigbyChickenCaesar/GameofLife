#include "printErr.h"
#include <stdio.h>
#include <stdlib.h>

#define		BORDER			2
#define		CELL_BELOW		1
#define		CELL_ABOVE		1
#define		CELL_RIGHT		1
#define		CELL_LEFT		1
#define 	INSIDE			1
#define		RESET			0 

void printArray (char **game, int height, int width);
//This function prints the game board;
int **createRuleBoard (int height, int width, char **initialBoard);
//Creates the board which determines if a cell lives or dies
int **lifeDecider (char **gameBoard, int **cellDeath, int height, int width);
//Decides with cells live or die
void lifeRules (char **gameBoard, int **cellDeath, int height, int width, int i, int j, int cnt);
//internal function which lifeDecider uses. You don't need to know what it does.
char **generateCharBoard (int height, int width); 
//Dynamically creates a 2D array of height+1 and width+1 and initiliases with '-'
char **successorGeneration (char **initialBoard, int **ruleBoard, int height, int width);