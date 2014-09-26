#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"

int main (int argc, char *argv[])
{
	FILE		*file;
	int			height, *pHeight = &height;
	int			width, *pWidth = &width;
	int			play = 0, run;
	char		**gameBoard;

	/*------------Game Set-up-----------*/
	run = plays (play);
	file = openFile (argv[1]);
	getGameHeight (file, pHeight);
	getGameWidth (file, pWidth);
	gameBoard = createBoard (height, width);
	copyBoard (file, gameBoard, height, width);
	closeFile (file);
}