/************************************************************************\
  exemple_01 - Chapitre "Deroulement des processus"

  Utilisation de l'appel-système fork()

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t valeur;

	fprintf(stderr, "Avant fork(), PID : %d, PPID : %d\n",
                        getpid(), getppid());

	valeur = fork();

	fprintf(stderr, "Après fork(), PID : %d, PPID : %d, fork()->%d\n",
                        getpid(), getppid(), valeur);
	return 0;
}
