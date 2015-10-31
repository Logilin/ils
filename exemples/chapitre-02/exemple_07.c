/************************************************************************\
  exemple_07 - Chapitre "Deroulement des processus"

  Utilisation de la fonction system()

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s commande [args...]\n", argv[0]);
		exit(1);
	}
	fprintf(stderr, "Mon PID est %d\n", getpid());
	fprintf(stderr, "Avant appel de system(%s)\n", argv[1]);
	system(argv[1]);
	fprintf(stderr, "Après appel de system(%s)\n", argv[1]);
	return 1;
}
