/**************************************************************************\
** Développeur système sous Linux - Programmation réseau sous Linux       **
**                                                                        **
** Christophe Blaess 2001-2004 - Tous droits réservés                     **
\**************************************************************************/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>

	#include <arpa/inet.h>
	#include <netdb.h>
	#include <netinet/in.h>

	#include <sys/types.h>
	#include <sys/socket.h>

	void	serveur_tcp (int port);
	void	traite_connexion (int sock);

	int
main (int argc, char * argv [])
{
	int port;
	if ((argc != 2)
	 || (sscanf(argv[1], "%d", & port) != 1)) {
		fprintf(stderr, "usage: %s port_tcp\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	serveur_tcp(port);
	exit(EXIT_SUCCESS);
}


	void
serveur_tcp (int port)
{
	int sock_contact;
	int sock_connectee;
	struct sockaddr_in adresse;
	
	if ((sock_contact = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror ("socket");
		exit (EXIT_FAILURE);
	}
	
	memset(& adresse, 0, sizeof (struct sockaddr_in));
	adresse.sin_family = AF_INET;
	adresse.sin_port = htons(port);
	adresse.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sock_contact, (struct sockaddr *) & adresse,
		 sizeof(struct sockaddr_in)) < 0) {
		close(sock_contact);
		perror("bind");
		exit(EXIT_FAILURE);
	}
	listen(sock_contact, 5);

	while (1) {
		sock_connectee = accept(sock_contact, NULL, 0);
		if (sock_connectee < 0) {
			perror("accept");
			exit(EXIT_FAILURE);
		}
		switch (fork()) {
			case -1 :
				perror("fork");
				exit(EXIT_FAILURE);
			case 0 : /* fils */
				close(sock_contact);
				traite_connexion(sock_connectee);
				exit(EXIT_SUCCESS);
			default : /* père */
				close(sock_connectee);
				break;
		}
	}
}

	void
traite_connexion (int sock)
{
	char buffer [256];
	int  longueur;
	int  i, tmp;
	while (1) {
		longueur = read(sock, buffer, 256);
		if (longueur <= 0)
			break;
		while ((longueur > 0)
		    && ((buffer[longueur - 1] == '\n')
		     || (buffer[longueur - 1] == '\r')))
			longueur --;
		if (longueur == 0)
			break;
		buffer[longueur] = '\0';
		for (i = 0; i < longueur / 2; i++) {
			tmp = buffer[longueur - 1 - i];
			buffer[longueur - 1 - i] = buffer[i];
			buffer[i] = tmp;
		}
		buffer[longueur] = '\n';
		write(sock, buffer, longueur+1);
	}
	close(sock);
}
