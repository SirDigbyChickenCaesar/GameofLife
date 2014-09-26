#include "FileIO.h"
#include <stdio.h>
#include <stdlib.h>

FILE *openFile (char *input)
{
	FILE	*file;

	if ((file = fopen(input, "r")) == NULL)
	{
			if (input == NULL)
			{
				printf("Include file name as arguement");
				printf(" (e.g.) ./gameoflife <YourTextFile>\n");
			}
			else
			{
				printf("%s does not exist or", input);
				printf(" failed to open file for reading\n");
			}
			exit(1);	
	}
	else
	{
		return file;
	}
}

void closeFile (FILE *input)
{
	if (fclose(input) != 0)
	{
    	printf("Error closing the file!\n");
    }
}

void getGameHeight (FILE *input, int *height)
{
	if ((fscanf(input, "%d ", height)) == 0)
	{
		printf("Failed to get height of board");
	}
}

void getGameWidth (FILE *input, int *width)
{
	if ((fscanf(input, "%d", width)) == 0)
	{
		printf("Failed to get width of board");
	}
}

char **createBoard (int height, int width)
{
	char 	**gameBoard;
	int		i;

	gameBoard = malloc (height*sizeof(char*));
	{
		if (gameBoard == NULL)	//If memory allocation fails
		{
			printf("Memory Allocation failed!\n");
		}
	}
	for (i = 0; i < height; i++)
	{
		gameBoard[i] = malloc(width*sizeof(char));
		if (gameBoard[i] == NULL) //If memory allocation fails
		{
			printf("Memory Allocation failed!\n");
		}
	}
	return gameBoard;
}

void copyBoard (FILE *input, char **fileBoard, int height, int width)
{
	int 	i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			fscanf(input, "\n%c", &fileBoard[i][j]);
		}
	}

	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			printf("%c", fileBoard[i][j]);
		}
		printf("\n");
	}
}

int plays (int play)
{
	printf("How many times do you want to play the game of life?\n");
	scanf("%d", &play);
	return play;
}
