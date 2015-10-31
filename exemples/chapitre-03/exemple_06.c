/************************************************************************\
  exemple_06 - Chapitre "Programmer avec les threads Posix"

  Attribut de détachement

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
	pthread_attr_t attr;
	pthread_attr_init (& attr);
	pthread_attr_setdetachstate(& attr, PTHREAD_CREATE_DETACHED);
	while (1) {
		if (pthread_create(& thr, & attr, fonction, NULL) != 0)
			break;
		fprintf(stderr, "%d ", (int) i);
		i ++;
	}
	fprintf(stderr, "\n");
	return 0;
}

