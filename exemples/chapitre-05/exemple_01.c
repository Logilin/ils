/************************************************************************\
  exemple_01 - Chapitre "Communication entre processus"

  Les semaphores Posix

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	sem_t * sem;
	int i;
	sem = sem_open("/essai", O_RDWR | O_CREAT, 0666, 1);
	if (sem == SEM_FAILED) {
		perror("sem_open");
		exit(1);
	}
	for (i = 0; i < 3; i ++) {
		fprintf(stderr, "[%d] attente\n", getpid());
		sem_wait(sem);
		fprintf(stderr, "      [%d] tient le semapore\n", getpid());
		sleep(2);
		fprintf(stderr, "   [%d] lache le semaphore\n", getpid());
		sem_post(sem);
		sleep(1);
	}
	return 0;
}



