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
	int			**currentRuleBoard, **currentBoard, cnt = 0, plays;

	/*------------Game Set-up-----------*/
	file = openFile (argv[1]);
	printf("File loaded successfully\nHow many iterations?\n");
	scanf("%d", &plays);
	getGameHeight (file, pHeight);
	getGameWidth (file, pWidth);
	gameBoard = createBoard (height, width);
	fileCopy (file, gameBoard, height, width);
	closeFile (file);
	/*------------Game Play-------------*/
	printf("\nYour input Game Board is: \n");
	printArray (gameBoard, height, width);

	do {
		currentBoard = createRuleBoard (height, width, gameBoard);
		currentRuleBoard = lifeDecider (gameBoard, currentBoard, height, width);
		gameBoard = successorGeneration (gameBoard, currentRuleBoard, height, width);
		cnt++;
	} while (cnt < plays);

}
