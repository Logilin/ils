/************************************************************************\
  exemple_05 - Chapitre "Programmer avec les threads Posix"

  Detachement des threads

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void * fonction(void * arg)
{
	return NULL;
}

int main(int argc, char * argv[])
{
	int i = 1;
	pthread_t thr;
	while (1) {
		if (pthread_create(& thr, NULL, fonction, NULL) != 0)
			break;
 		/* pthread_detach(thr); */
		fprintf(stderr, "%d ", (int) i);
		i ++;
	}
	fprintf(stderr, "\n");
	return 0;
}

