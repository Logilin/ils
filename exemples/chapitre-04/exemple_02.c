/************************************************************************\
  exemple_02 - Chapitre "Gestion de la memoire"

  Utilisation de mmap()

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>


int main (void)
{
	int fd;
	struct stat status;
	char * ptr;
	
	fd = open("/etc/passwd", O_RDONLY);
	if (fd < 0)
		exit(1);
	if (fstat(fd, & status) != 0)
		exit(2);
	ptr = mmap(NULL, status.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED)
		exit(3);
	fprintf(stderr, "[%d] Projection Ok\n", getpid());
	pause();
	return 0;
}
