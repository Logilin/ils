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

	int
envoie_message (char * ip_dest, int port_dest, char * message)
{
	struct sockaddr_in adresse_dest;
	int	sock;
	int	lg;

	memset(& adresse_dest, 0, sizeof(adresse_dest));
	adresse_dest.sin_family = AF_INET;
	adresse_dest.sin_port = htons(port_dest);
	if (inet_aton(ip_dest, & (adresse_dest.sin_addr)) < 0) {
		perror("adresse IP destinataire invalide");
		return -1;
	}
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("impossible d'obtenir une socket UDP");
		return -1;
	}
	lg = strlen(message) + 1;
	if (sendto(sock, message, lg, 0,
	  (struct sockaddr *) & adresse_dest, sizeof(adresse_dest)) != lg) {
		perror("erreur d'emission");
		close(sock);
		return -1;
	}
	close(sock);
	return 0;
}

#define LG_BUF 1024

	int
main (int argc, char * argv[])
{
	char	buffer [LG_BUF];
	int	port;
	
	if ((argc != 3) 
	 || (sscanf(argv[2], "%d", & port) != 1)) {
		fprintf(stderr, "usage: %s adr_ip_dest port_udp_dest\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, LG_BUF, stdin) != NULL)
		if (envoie_message(argv[1], port, buffer) != 0)
			break;
	exit(EXIT_SUCCESS);
}
