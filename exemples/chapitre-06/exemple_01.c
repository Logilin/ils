/**************************************************************************\
** D�veloppeur syst�me sous Linux - Programmation r�seau sous Linux       **
**                                                                        **
** Christophe Blaess 2001-2004 - Tous droits r�serv�s                     **
\**************************************************************************/

	#include <netdb.h>
	#include <arpa/inet.h>
	#include <sys/socket.h>
	#include <stdio.h>
	#include <stdlib.h>

	int recherche_adresse(char * chaine);


	int
main (int argc, char * argv[])
{
	int i;
	for (i = 1; i < argc; i ++)
		recherche_adresse(argv[i]);
	return EXIT_SUCCESS;
}


	int
recherche_adresse (char * chaine)
{
	struct hostent * host;
	struct in_addr   addr;
	struct in_addr * result;

	if (inet_aton(chaine, & addr) != 0) {
		/* Il s'agit d'une adresse en notation point�e */
		host = gethostbyaddr((char *) & addr, sizeof(addr), AF_INET);
	} else {
		/* On peut penser qu'il s'agit d'un nom d'h�te */
		host = gethostbyname(chaine);
	}
	if (host == NULL)
		return -1;
	/* Afficher le r�sultat */
	result = (struct in_addr *) host->h_addr;
	fprintf(stdout, "%s : %s\n", host->h_name, inet_ntoa(*result));
	return 0;
}

