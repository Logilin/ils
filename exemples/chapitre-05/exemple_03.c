/************************************************************************\
  exemple_03 - Chapitre "Communication entre processus"

  Reception depuis une message queue

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
	char buffer[8192];
	int n;
	unsigned int prio;
	if (argc != 2) {
		fprintf(stderr, "usage: %s mq\n", argv[0]);
		exit(1);
	}
	mqd = mq_open(argv[1], O_RDONLY | O_CREAT, 0666, NULL);
	if (mqd == -1) {
		perror(argv[1]);
		exit(2);
	}
	n = mq_receive(mqd, buffer, 8192, & prio);
	if (n > 0) {
		buffer[n] = '\0';
		printf("[%d]%s\n", prio, buffer);
	}
	return 0;
}



