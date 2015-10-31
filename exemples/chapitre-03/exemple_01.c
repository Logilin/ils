/************************************************************************\
  exemple_01 - Chapitre "Programmer avec les threads Posix"

  Creation de thread

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * fonction(void * inutile)
{
	for (;;) {
		fprintf(stderr, "fonction()\n");
		sleep(1);
	}
	return NULL;
}


int main(void)
{
	pthread_t  thr;

	if (pthread_create(& thr, NULL, fonction, NULL) != 0)
		exit(1);
	for (;;) {
		fprintf(stderr, "main()\n");
		sleep(1);
	}
	return 0;
}
