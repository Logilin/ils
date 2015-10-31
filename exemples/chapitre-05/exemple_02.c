/************************************************************************\
  exemple_02 - Chapitre "Communication entre processus"

  Emission dans une message queue

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char * argv[])
{
	mqd_t mqd;
	int prio;
	if ((argc < 4) 
	 || (sscanf(argv[2], "%d", & prio) != 1)) {
		fprintf(stderr, "usage: %s mq prio message\n", argv[0]);
		exit(1);
	}
	mqd = mq_open(argv[1], O_WRONLY | O_CREAT, 0666, NULL);
	if (mqd == -1) {
		perror(argv[1]);
		exit(2);
	}
	mq_send(mqd, argv[3], strlen(argv[3]), prio);
	return 0;
}



