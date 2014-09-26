#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"
#include "arrayFunctions.h"

int main (int argc, char *argv[])
{
	FILE		*file;
	int			height, *pHeight = &height;
	int			width, *pWidth = &width;
	char		**gameBoard;

	/*------------Game Set-up-----------*/
	file = openFile (argv[1]);
	getGameHeight (file, pHeight);
	getGameWidth (file, pWidth);
	gameBoard = createBoard (height, width);
	copyBoard (file, gameBoard, height, width);
	printArray (gameBoard, height, width);
	closeFile (file);
}
