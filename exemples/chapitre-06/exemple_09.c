/**************************************************************************\
** Développeur système sous Linux - Programmation réseau sous Linux       **
**                                                                        **
** Christophe Blaess 2001-2004 - Tous droits réservés                     **
\**************************************************************************/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>

#define LG_BUF 1024

	int
recoit_messages (int mon_port)
{
	int sock;
	struct sockaddr_in mon_adresse;
	struct sockaddr_in adresse_emt;
	char buffer [LG_BUF];
	socklen_t lg;
	int broadcast;

  	memset(& mon_adresse, 0, sizeof(mon_adresse));
	mon_adresse.sin_family = AF_INET;
	mon_adresse.sin_port = htons(mon_port);
	mon_adresse.sin_addr.s_addr = htonl (INADDR_ANY);
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("impossible d'obtenir une socket UDP");
		return -1;
	}
	broadcast = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, & broadcast,
			sizeof (broadcast)) < 0) {
		perror("impossible d'utiliser le mode broadcast");
	}
	if (bind(sock, (struct sockaddr *) & mon_adresse, sizeof(mon_adresse)) < 0) {
		perror("impossible d'utiliser l'adresse");
		close(sock);
		return -1;
	}
	while (1) {
		lg = sizeof(adresse_emt);
		if (recvfrom(sock, buffer, LG_BUF, 0,
			(struct sockaddr *) & adresse_emt, & lg) < 0)
      			break;
		fprintf(stdout, "[%s] %s", inet_ntoa(adresse_emt.sin_addr),
			buffer);
	}
	return 0;
}

	int 
main (int argc, char * argv[])
{
	int port;
	if ((argc != 2)
	 || (sscanf(argv[1], "%d", & port) != 1)) {
		fprintf(stderr, "usage : %s port_udp\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	exit(recoit_messages(port));
}
