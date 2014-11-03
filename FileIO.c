#include "FileIO.h"
#include "printErr.h"
		

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

	gameBoard = malloc ((height+BORDER)*sizeof(char*));
	{
		if (gameBoard == NULL)
		{
			printError(MALLOCERROR);
		}
	}
	for (i = 0; i < (height+BORDER); i++)
	{
		gameBoard[i] = malloc((width+BORDER)*sizeof(char));
		if (gameBoard[i] == NULL)
		{
			printError(MALLOCERROR);
		}
	}
	return gameBoard;
}

void fileCopy (FILE* input, char **gameBoard, int height, int width)
{
	int		i, j;

	for (i = INSIDE; i < height + INSIDE; i++)
		for (j = INSIDE; j < width + INSIDE; j++) {
			fscanf(input, "\n%c", &gameBoard[i][j]);
		}
}
