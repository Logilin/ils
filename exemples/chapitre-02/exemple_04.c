/************************************************************************\
  exemple_04 - Chapitre "Deroulement des processus"

  Etat zombie

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	fprintf(stderr, "[PERE] Mon PID : %d\n", getpid());
	if (fork() == 0) { /* Processus FILS */
		fprintf(stderr, "[FILS] Mon PID : %d\n", getpid());
		sleep(10);
		fprintf(stderr, "[FILS] Je me termine...\n");
		exit(0);
	} else { /* Processus PERE */
		while(1) {
			sleep(1);
		}
	}
}
