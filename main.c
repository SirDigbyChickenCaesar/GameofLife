#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"

int main (int argc, char *argv[])
{
	FILE		*file;

	file = openFile (argv[1]);
	closeFile (file);
}