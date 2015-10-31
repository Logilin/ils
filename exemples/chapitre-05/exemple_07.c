/************************************************************************\
  exemple_07 - Chapitre "Communication entre processus"

  Emission de signal temps-reel

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int sig;
	int val;
	int pid;
	union sigval value;
	
	if ((argc != 4)
	 || (sscanf(argv[1], "%d", & sig) != 1)
	 || (sscanf(argv[2], "%d", & val) != 1)
	 || (sscanf(argv[3], "%d", & pid) != 1)) {
		fprintf(stderr, "usage: %s signal valeur pid\n", argv[0]);
		exit(1);
	}
	value.sival_int = val;
	sigqueue(pid, sig, value);
	return 0;
}



