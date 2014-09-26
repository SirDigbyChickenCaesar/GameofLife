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

