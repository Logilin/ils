#define _POSIX_C_SOURCE  200112L

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NB_THREADS	10

pthread_spinlock_t  spl;

void * fonction(void * arg)
{
	int numero = (int) arg;
	while (1) {
		fprintf(stderr, "%d attend\n", numero);
		pthread_spin_lock(& spl);
		fprintf(stderr, "       %d tient le spinlock\n", numero);
		sleep(3);
		fprintf(stderr, "       %d libère le spinlock\n", numero);
		pthread_spin_unlock(& spl);
		sleep(1);
	}
}

int main(void)
{
	int i;
	pthread_t thr[NB_THREADS];

	pthread_spin_init(& spl, 0);
	for (i = 0; i < NB_THREADS; i ++)
		pthread_create(& thr[i], NULL, fonction, (void *) i);
	pthread_exit(NULL);	
}
