#include "arrayFunctions.h"
#include "FileIO.h"
#include "printErr.h"


void printArray (char **game, int height, int width)
{
	int		i, j;

	for (i = 0; i < (height+BORDER); i++){
		for (j = 0; j < (width+BORDER); j++){
			printf("%c", game[i][j]);
		}
		printf("\n");
	}
}

int **createRuleBoard (int height, int width, char **initialBoard)
{
	int 	**gameBoard;
	int		i;

	gameBoard = calloc ((height+BORDER), sizeof(int*));
	{
		if (gameBoard == NULL)
		{
			printError(MALLOCERROR);
		}
	}
	for (i = 0; i < (height+BORDER); i++)
	{
		gameBoard[i] = calloc((width+BORDER), sizeof(int*));
		if (gameBoard[i] == NULL)
		{
			printError(MALLOCERROR);
		}
	}
	return gameBoard;
}

int **lifeDecider (char **gameBoard, int **cellDeath, int height, int width)
{
	int 	i, j, cnt = 0;


	for (i = INSIDE; i < height + INSIDE % height; i++) //POSSIBLE SOURCE OF ERROR
		for (j = INSIDE; j < width + INSIDE % width; j++) {
			{
				lifeRules (gameBoard, cellDeath, height, width, i, j, cnt);
			}
		}
	//successorGeneration(gameBoard, cellDeath, height, width);
	return cellDeath;
}

void lifeRules (char **gameBoard, int **cellDeath, int height, int width, int i, int j, int cnt)
{

	if (gameBoard[i+CELL_BELOW][j] == '#') //CELL BELOW
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	if (gameBoard[i-CELL_ABOVE][j] == '#') //CELL ABOVE
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	if (gameBoard[i][j+CELL_RIGHT] == '#') //CELL TO THE RIGHT
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	if (gameBoard[i][j-CELL_LEFT] == '#') //CELL TO THE RIGHT
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	if (gameBoard[i-CELL_ABOVE][j-CELL_LEFT] == '#') //CELL TOP LEFT
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	if (gameBoard[i-CELL_ABOVE][j+CELL_RIGHT] == '#') //CELL TOP RIGHT
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	if (gameBoard[i+CELL_BELOW][j-CELL_LEFT] == '#') //CELL BOTTOM LEFT
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	if (gameBoard[i+CELL_BELOW][j+CELL_RIGHT] == '#') //CELL BOTTOM RIGHT
	{
		cnt++;
		cellDeath[i][j] = cnt;
	}
	cnt = RESET;

}

char **generateCharBoard (int height, int width)
{
	char	**newGeneration;
	int		i, j;

	newGeneration = createBoard(height, width);
	printf("\n");

 	for (i = 0; i < height+BORDER; i++)
 		for (j = 0; j < width+BORDER; j++)
 		{
 			newGeneration[i][j] = '-';
 		}
 	return newGeneration;
}

char **successorGeneration (char **initialBoard, int **ruleBoard, int height, int width)
{
	char	**sGeneration;
	int		i, j;

	sGeneration = generateCharBoard (height, width);
	for (i = 0; i < height+BORDER; i++)
		for (j = 0; j < width+BORDER; j++)
		{
			if (initialBoard[i][j] == '-')
			{
				if (ruleBoard[i][j] == 3)
				{
					sGeneration[i][j] = '#';
				}
			}
			if (initialBoard[i][j] == '#')
			{
				if (ruleBoard[i][j] == 2 || ruleBoard[i][j] == 3)
				{
					sGeneration[i][j] = '#';
				}
			}
		}
	printArray(sGeneration, height, width);
	return sGeneration;
}