#include "arrayFunctions.h"
#include <stdio.h>
#include <stdlib.h>

void printArray (char **game, int height, int width)
{
	int		i, j;

	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			printf("%c", game[i][j]);
		}
		printf("\n");
	}
}
