#include "printErr.h"
#include <stdio.h>
#include <stdlib.h>

void printError (int error)
{
	switch(error)
	{
		case 1:
			printf("Include file name as argument\n");
			break;
		case 2:
			printf("does not exist or failed to read for opening\n");
			break;
		case 3:
			printf("Error closing file\n");
			break;
		case 4:
			printf("Failed to get height of board!\n");
			break;
		case 5:
			printf("Failed to get width of board!\n");
			break;
		case 6:
			printf("Memory allocation failed!\n");
			break;
		default:
			printf("An unknown error has occured\n");
	}
	exit(1);
}
