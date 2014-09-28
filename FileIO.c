#include "FileIO.h"
#include "printErr.c"
#include <stdio.h>
#include <stdlib.h>

#define 	NOARGUMENT		1
#define		NOFILE			2
#define		CLOSEERROR		3
#define		HEIGHTERROR		4
#define		WIDTHERROR		5
#define		MALLOCERROR		6		

FILE *openFile (char *input)
{
	FILE	*file;

	if ((file = fopen(input, "r")) == NULL)
	{
			if (input == NULL)
			{
				printError(NOARGUMENT);
			}
			else
			{
				printf("%s ", input);
				printError(NOFILE);
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
    	printError(CLOSEERROR);
    }
}

void getGameHeight (FILE *input, int *height)
{
	if ((fscanf(input, "%d ", height)) == 0)
	{
		printError(HEIGHTERROR);
	}
}

void getGameWidth (FILE *input, int *width)
{
	if ((fscanf(input, "%d", width)) == 0)
	{
		printError(WIDTHERROR);
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
			printError(MALLOCERROR);
		}
	}
	for (i = 0; i < height; i++)
	{
		gameBoard[i] = malloc(width*sizeof(char));
		if (gameBoard[i] == NULL) //If memory allocation fails
		{
			printError(MALLOCERROR);
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
}
