/**************************************************************************\
** Développeur système sous Linux - Programmation réseau sous Linux       **
**                                                                        **
** Christophe Blaess 2001-2004 - Tous droits réservés                     **
\**************************************************************************/

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/socket.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <netinet/in.h>

	int
main (void)
{
	int		sock;
	socklen_t	longueur;
	int		valeur;
	struct sockaddr_in adresse;

	adresse.sin_family = AF_INET;
	adresse.sin_port   = htons(2003);
	if (inet_aton("127.0.0.1", & adresse.sin_addr) < 0) {
		perror("inet_aton()");
		exit(EXIT_FAILURE);
	}
	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket()");
		exit(EXIT_FAILURE);
	}
	
	longueur = sizeof(valeur);
	valeur = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
	                & valeur, longueur) < 0) {
		perror("setsockopt()");
		exit(EXIT_FAILURE);
	}
	if (bind(sock, (struct sockaddr *)& adresse,
		sizeof(struct sockaddr_in))< 0) {
		perror("bind()");
		exit(EXIT_FAILURE);
	}
	listen(sock, 5);
	while (1)
		close(accept(sock, NULL, 0));
	return 0;
}
