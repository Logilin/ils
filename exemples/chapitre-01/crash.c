#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        char * ptr = NULL;
	fprintf(stderr, "Avant écriture\n");
        ptr[1] = 0;
	fprintf(stderr, "Après écriture\n");
        return 0;
}

