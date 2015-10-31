/************************************************************************\
  exemple_01 - Chapitre "Gestion de la memoire"

  Classe d'allocation et emplacement en memoire virtuelle

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

	static int var_globale;
	static int var_globale_initialisee = 12345;


int main (void)
{
	int var_automatique;
	static int var_statique;
	char * petite_dynamique = malloc(128);
	char * grosse_dynamique = malloc(8000000L);
	fprintf(stderr, "Code main() : %p\n", main);
	fprintf(stderr, "var_globale : %p\n", & var_globale);
	fprintf(stderr, "var_globale_initialisee : %p\n", & var_globale_initialisee);
	fprintf(stderr, "var_automatique : %p\n", & var_automatique);
	fprintf(stderr, "var_statique : %p\n", & var_statique);
	fprintf(stderr, "petite_dynamique : %p\n", petite_dynamique);
	fprintf(stderr, "grosse_dynamique : %p\n", grosse_dynamique);
	return 0;
}
