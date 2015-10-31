/************************************************************************\
  exemple_09 - Chapitre "Programmer avec les threads Posix"

  Acces incontrole aux donnees partagees

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long int compteur = 0;

void * fonction(void * arg)
{
	long nb_iterations = (long) arg;
	long i;
	for (i = 0; i < nb_iterations; i ++)
		compteur = compteur + 1;
	return NULL;
}


int main(int argc, char * argv[])
{
	pthread_t  * thr;
	int i;
	int nb_threads;
	long nb_iterations;
	if ((argc != 3) || (sscanf(argv[1], "%d", &nb_threads) != 1)
	 || (sscanf(argv[2], "%ld", & nb_iterations) != 1)) {
		fprintf(stderr, "usage: %s nb_threads nb_iterations\n", argv[0]);
		exit(1);
	}
	thr = calloc(nb_threads, sizeof(pthread_t));
	for (i = 0; i < nb_threads; i ++)
		pthread_create(& (thr[i]), NULL, fonction, (void *)nb_iterations);
	for (i = 0; i < nb_threads; i ++)
		pthread_join(thr[i], NULL);
	fprintf(stderr, "Compteur = %lld\n",compteur);
	return 0;
}
