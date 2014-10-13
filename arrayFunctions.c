#include "arrayFunctions.h"


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

int **createRuleBoard (int height, int width)
{
	int 	**gameBoard;
	int		i, j;

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
	for (i = 0; i < (height+BORDER); i++){
		for (j = 0; j < (width+BORDER); j++){
			printf("%d", gameBoard[i][j]);
		}
		printf("\n");
	}

	return gameBoard;
}