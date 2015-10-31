/************************************************************************\
  exemple_03 - Chapitre "Deroulement des processus"

  Terminaison forcee sur SIGSEGV

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char * ptr = NULL;
	fprintf(stderr, "Avant ecriture dans pointeur NULL\n");
	ptr[0] = 'A';
	fprintf(stderr, "Apres ecriture dans pointeur NULL\n");
	return 0;
}
