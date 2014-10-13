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

void lifeDecider (char **gameBoard, int **cellDeath, int height, int width)
{
	int 	i, j, cnt = 0;


	for (i = INSIDE; i < height + INSIDE; i++)
		for (j = INSIDE; j < width + INSIDE; j++) {
			if (gameBoard[i][j] == '#')
			{
				if (gameBoard[i+CELL_BELOW][j] == '#')
				{
					cnt++;
					cellDeath[i][j] == cnt;
				}
				if (gameBoard[i-CELL_ABOVE][j] == '#')
				{
					cnt++;
					cellDeath[i][j] == cnt;
				}
				if (gameBoard[i][j+CELL_RIGHT] == '#')
				{
					cnt++;
					cellDeath[i][j] == cnt;
				}
				if (gameBoard[i][j-CELL_LEFT] == '#')
				{
					cnt++;
					cellDeath[i][j] == cnt;
				}
			}
		}
	for (i = 0; i < (height+BORDER); i++){
		for (j = 0; j < (width+BORDER); j++){
 			printf("%d", gameBoard[i][j]);
 		}
 		printf("\n");
	}

}
