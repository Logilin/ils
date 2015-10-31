/************************************************************************\
  exemple_04 - Chapitre "Programmer avec les threads Posix"

  Valeur de retour d'un thread

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void * carre(void * arg)
{
	long num = (long) arg;
	return (void *) (num * num);
}



int main(int argc, char * argv[])
{
	long i, num;
	void * resultat;
	pthread_t thr;

	for (i = 1; i < argc; i ++) {
		fprintf(stderr, "%s: ", argv[i]);
		if(sscanf(argv[i], "%ld", & num) == 1) {
			pthread_create(& thr, NULL, carre, (void *) num);
			pthread_join(thr, & resultat);
			fprintf(stderr, "%ld", (long) resultat);
		}
		fprintf(stderr, "\n");
	}
	return 0;
}

