/************************************************************************\
  exemple_06 - Chapitre "Communication entre processus"

  Reception de signaux

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int numero)
{
	fprintf(stderr, "(%d recu)", numero);
}

int main(void)
{
	struct sigaction action;

	action.sa_handler = handler;
	sigfillset(& action.sa_mask);
	action.sa_flags = 0;

	sigaction(SIGINT, & action, NULL);
	sigaction(SIGQUIT, & action, NULL);
	sigaction(SIGWINCH, & action, NULL);

	fprintf(stderr, "PID : %d\n", getpid());
	while (1) {
		fprintf(stderr, ".");
		sleep(1);
	}
	return 0;
}



