#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int f1(int limite);

int f2(int limite)
{
	int i;
	for (i = 1; i < limite; i ++)
		f1(i);
}

int f1(int limite)
{
	int i;
	for (i = 1; i < limite; i ++)
		f2(i);
}

int  main(void)
{
	f1(25);
}

