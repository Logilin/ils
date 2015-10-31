/************************************************************************\
  exemple_03 - Chapitre "Programmer avec les threads Posix"

  Terminaison d'un thread

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NB_THREADS 10

void * fonction(void *);

int main(void)
{
	pthread_t  thr[NB_THREADS] ;
	long i;

	for (i = 0; i < NB_THREADS; i ++) {
		if (pthread_create(& (thr[i]), NULL, fonction, (void *) i) != 0)
			exit(1);
	}
	pthread_exit(NULL);
}

void * fonction(void * arg)
{
	long numero = (long) arg;
	while (1) {
		fprintf(stderr, "fonction(%ld)\n", numero);
		sleep(1);
		if (numero == 4)
			pthread_exit(NULL);
	}
	return NULL;
}

