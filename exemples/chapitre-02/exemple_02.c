/************************************************************************\
  exemple_02 - Chapitre "Deroulement des processus"

  Code de retour d'un programme

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int ret = 0;

	if (argc > 1)
		sscanf(argv[1], "%d", &ret);

	return ret;
}
