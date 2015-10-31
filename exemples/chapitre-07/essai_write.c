#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int i;
	int fd;
	int taille_bloc;
	int nb_blocs;
	char * buffer;
	

	if ((argc != 4) 
	 || ((fd = open(argv[1], O_WRONLY | O_CREAT, 0644)) < 0)
	 || (sscanf(argv[2], "%d", & taille_bloc) != 1)
	 || (sscanf(argv[3], "%d", & nb_blocs) != 1)) {
		fprintf(stderr, "usage: %s <fichier> <taille_bloc> <nb_blocs>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((buffer = malloc(taille_bloc)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < taille_bloc; i ++)
		buffer[i] = i % 255;
	for (i = 0; i < nb_blocs; i ++)
		if (write(fd, buffer, taille_bloc) != taille_bloc) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	close(fd);
	exit(EXIT_SUCCESS);
}

