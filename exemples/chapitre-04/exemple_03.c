/************************************************************************\
  exemple_03 - Chapitre "Gestion de la memoire"

  Saturation de la memoire

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{

	char * ptr;
	int nb_blocs = 0;

	while (1) {
		ptr = malloc(1024 * 1024);
		if (ptr == NULL)
			break;
		nb_blocs ++;
	}
	fprintf(stderr, "Allocation de %d Mo... Ok\n", nb_blocs);
	pause();
	return 0;
}
