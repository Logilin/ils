/************************************************************************\
  exemple_08 - Chapitre "Communication entre processus"

  Reception de signaux temps-reel

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int numero, siginfo_t * info, void * unused)
{
	fprintf(stderr, "(%d", numero);
	if ((info != NULL) && (info->si_code == SI_QUEUE)) {
		fprintf(stderr, " avec %d",
			info->si_value.sival_int);
	}
	fprintf(stderr,")");
}

int main(void)
{
	struct sigaction action;

	action.sa_sigaction= handler;
	sigfillset(& action.sa_mask);
	action.sa_flags = SA_SIGINFO;

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



