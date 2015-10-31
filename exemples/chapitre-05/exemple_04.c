/************************************************************************\
  exemple_04 - Chapitre "Communication entre processus"

  Utilisation d'une memoire partagee

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>


int main(int argc, char * argv[])
{
	int fd;
	int * compteur;
	if (argc != 2) {
		fprintf(stderr, "usage: %s mem\n", argv[0]);
		exit(1);
	}
	fd = shm_open(argv[1], O_RDWR | O_CREAT, 0666);
	if (fd == -1) {
		perror(argv[1]);
		exit(2);
	}
	ftruncate(fd, sizeof(int));
	compteur = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
			MAP_SHARED, fd, 0);
	if (compteur == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
	while (1) {
		fprintf(stderr, "%d\n", *compteur);
		sleep(1);
		(*compteur) ++;
	}
	return 0;
}



