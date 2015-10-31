/************************************************************************\
  exemple_06 - Chapitre "Deroulement des processus"

  Execution d'un nouveau programme

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
	fprintf(stderr, "Avant appel de exec(%s)\n", argv[1]);
	execvp(argv[1], &argv[1]);
	perror(argv[1]);
	return 1;
}
