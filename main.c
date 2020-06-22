/*Serboi Florea-Dan 315CB*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bmp_header.h"
#include "utils.h"

int main(int argc, char *argv[])
{
	if(strcmp(argv[argc-1],"1") == 0)
		task1();
	if(strcmp(argv[argc-1],"2") == 0)
		task2();
	if(strcmp(argv[argc-1],"3") == 0)
		task3();
	if(strcmp(argv[argc-1],"4") == 0)
		task4();
	if(strcmp(argv[argc-1],"bonus") == 0)
		bonus();
	return 0;
}
