#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"

int main (int argc, char *argv[])
{
	FILE		*file;
	int			height, *pHeight = &height;
	int			width, *pWidth = &width;

	file = openFile (argv[1]);
	getGameHeight (file, pHeight);
	getGameWidth (file, pWidth);
	printf("Width: %d\n", width);
	printf("Height: %d\n", height);
	closeFile (file);
}