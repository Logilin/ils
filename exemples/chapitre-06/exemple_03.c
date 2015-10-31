/**************************************************************************\
** Développeur système sous Linux - Programmation réseau sous Linux       **
**                                                                        **
** Christophe Blaess 2001-2004 - Tous droits réservés                     **
\**************************************************************************/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	#include <unistd.h>

	#include <arpa/inet.h>
	#include <netdb.h>
	#include <netinet/in.h>

	#include <sys/types.h>
	#include <sys/socket.h>

	struct hostent * recherche_adresse (char * chaine);
	int numero_port (char * service, char * protocole);

	#define LG 1024

	int
main (int argc, char * argv [])
{
	struct sockaddr_in adresse;
	struct hostent * hostent;
	int 	port;
	int	sock;
	char buffer [LG];
	int	n;
	if (argc != 3) {
		fprintf(stderr, "usage : %s serveur port\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	hostent = recherche_adresse(argv[1]);
	if (hostent == NULL) {
		fprintf(stderr, "%s inconnu\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	port = numero_port(argv[2], "tcp");
	if (port < 0) {
		fprintf(stderr, "port %s invalide\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	memset(& adresse, 0, sizeof (struct sockaddr_in));	
	adresse.sin_family = AF_INET;
	adresse.sin_addr   = * (struct in_addr *)(hostent->h_addr);
	adresse.sin_port   = port;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	if (connect(sock, (struct sockaddr *) & adresse, sizeof(struct sockaddr_in)) < 0) {
		perror("connect");
		exit(EXIT_FAILURE);
	}
	sprintf(buffer, "GET http://%s HTTP/1.0\r\n\r\n", argv[1]);
	write(sock, buffer, strlen(buffer));
	while ((n = read(sock, buffer, LG)) >= 0)
		write(STDOUT_FILENO, buffer, n);
	return EXIT_SUCCESS;
}


	struct hostent *
recherche_adresse (char * chaine)
{
	struct hostent * host;
	struct in_addr   addr;

	if (inet_aton(chaine, & addr) != 0) {
		host = gethostbyaddr((char *) & addr, sizeof (addr), AF_INET);
	} else {
		host = gethostbyname(chaine);
	}
	return host;
}

	int
numero_port (char * service, char * protocole)
{
	int port;
	struct servent *servent;
	
	servent = getservbyname(service, protocole);
	if (servent != NULL)
		return servent->s_port;
	if (sscanf(service, "%d", & port) != 1)
		return -1;
	if ((port <= 0) || (port > 65535))
		return -1;
	return htons(port);
}
