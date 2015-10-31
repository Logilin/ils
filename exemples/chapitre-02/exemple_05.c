/************************************************************************\
  exemple_05 - Chapitre "Deroulement des processus"

  Lecture de code de terminaison

  Exemples de la formation "Developpement Systeme sous Linux"

  (c) 2001-2009 Christophe Blaess - http://www.logilin.fr/
\************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[])
{
	pid_t pid;
	int ret, code;
	if ((pid = fork()) == 0) {
		fprintf(stderr, "[FILS] Mon PID : %d\n", getpid());
		if ((argc == 1) || (sscanf(argv[1], "%d", & ret) != 1))
			pause();
		exit(ret);
	} else {
		waitpid(-1, & code, 0);
		if (WIFEXITED(code)) {
			fprintf(stderr,
			        "[PERE] Mon fils %d termine avec code %d\n",
				pid, WEXITSTATUS(code));
		} else if (WIFSIGNALED(code)) {
			fprintf(stderr,
			        "[PERE] Mon fils %d tue par signal %d ",
				pid, WTERMSIG(code));
			if (WCOREDUMP(code))
				fprintf(stderr, "(core dump)");
			fprintf(stderr, "\n");
		}
	}
	return 0;
}
