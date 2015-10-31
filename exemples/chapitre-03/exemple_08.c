/************************************************************************\
  exemple_08 - Chapitre "Programmer avec les threads Posix"

  Modification de la taille de la pile

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



int main(void)
{
	pthread_t  thr;
	pthread_attr_t attr;
	int i = 0;
	pthread_attr_init(& attr);
	/* pthread_attr_setstacksize(& attr, 32768); */
	while (pthread_create(& thr, &attr, fonction, NULL) == 0)
		i++;
	fprintf(stderr, "%d threads crees\n", i);
	return 0;
}
