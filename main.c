#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"
#include "arrayFunctions.h"

int main (int argc, char *argv[])
{
	FILE		*file;
	int			height, *pHeight = &height;
	int			width, *pWidth = &width;
	int			**ruleBoard;
	char		**gameBoard;

	/*------------Game Set-up-----------*/
	file = openFile (argv[1]);
	getGameHeight (file, pHeight);
	getGameWidth (file, pWidth);
	gameBoard = createBoard (file, height, width);
	printArray (gameBoard, height, width);
	ruleBoard = createRuleBoard (height, width);
	//printArray (ruleBoard, height, width);
	closeFile (file);
}
