/************************************************************************\
  exemple_07 - Chapitre "Programmer avec les threads Posix"

  Variables globales, automatiques, statiques

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globale = 0;

void * fonction(void * arg)
{
	long numero = (long) arg; /* automatique */
	static int statique = 0;
	for (;;) {
		statique ++;
		fprintf(stderr, "Thread %ld, globale = %d, statique = %d\n",
			numero, globale, statique);
		sleep(1);
	}
	return NULL;
}


int main(void)
{
	pthread_t  thr[3];
	long i;
	for (i = 0; i < 3; i ++)
		pthread_create(& (thr[i]), NULL, fonction, (void *) i);
	for (;;) {
		globale ++;
		fprintf(stderr, "main() : globale = %d\n",
				globale);
		sleep(1);
	}
	return 0;
}
