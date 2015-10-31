/**************************************************************************\
** Développeur système sous Linux - Programmation réseau sous Linux       **
**                                                                        **
** Christophe Blaess 2001-2004 - Tous droits réservés                     **
\**************************************************************************/

	#include <pthread.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>

	#include <arpa/inet.h>
	#include <netdb.h>
	#include <netinet/in.h>

	#include <sys/types.h>
	#include <sys/socket.h>

	void * thread_serveur (void * arg);
	void * thread_cnx (void * arg);

	int
main (int argc, char * argv [])
{
	pthread_t thr;
	long port;
	if ((argc != 2)
	 || (sscanf(argv[1], "%ld", & port) != 1)) {
		fprintf (stderr, "usage: %s port_tcp\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	pthread_create(& thr, NULL, thread_serveur, (void *) port);
	pthread_exit(NULL);
}


	void *
thread_serveur (void * void_port)
{
	long port = (long) void_port;
	int sock_contact;
	long sock_connectee;
	struct sockaddr_in adresse;
	pthread_t thr;
	if ((sock_contact = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	memset (& adresse, 0, sizeof (struct sockaddr_in));
	adresse.sin_family = AF_INET;
	adresse.sin_port = htons(port);
	adresse.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sock_contact, (struct sockaddr *) & adresse, sizeof(struct sockaddr_in)) < 0) {
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
		pthread_create(& thr, NULL, thread_cnx, (void *) sock_connectee);
		pthread_detach(thr);
	}
}

	void *
thread_cnx (void * void_sock)
{
	long sock = (long) void_sock;
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
	pthread_exit(NULL);
}
