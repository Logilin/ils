/**************************************************************************\
** Développeur système sous Linux - Programmation réseau sous Linux       **
**                                                                        **
** Christophe Blaess 2001-2004 - Tous droits réservés                     **
\**************************************************************************/

	#include <netdb.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>

	int numero_port (char * service, char * protocole);

	int
main (int argc, char * argv[])
{
	if (argc != 3) {
		fprintf(stderr, "syntaxe : %s service protocole\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%s/%s : %d\n", argv[1], argv[2], ntohs(numero_port(argv[1], argv[2])));
	return EXIT_SUCCESS;
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
