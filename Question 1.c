#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

pthread_t thread[2]; 
int counter; 
pthread_mutex_t lock; 

void* trythis(void* arg) 
{ 
	pthread_mutex_lock(&lock); 

	unsigned long b = 0; 
	counter += 1;
	 
	printf("\n Job %d has started\n", counter); 

	for(b = 0; b < (0xFFFFFFFF); b++); 

	printf("\n Job %d has finished\n", counter); 

	pthread_mutex_unlock(&lock); 

	return NULL; 
} 

int main(void) 
{ 
	int a = 0; 
	int error; 

	if (pthread_mutex_init(&lock, NULL) != 0)
	{ 
		printf("\n Mutex init has Failed\n"); 
		return 1; 
	} 

	while (a < 2)
	{ 
		error = pthread_create(&(thread[a]), NULL, &trythis, NULL); 
		if (error != 0)
		{
			printf("\nThread can't be created :[%s]", strerror(error));
		}
		a++; 
	} 

	pthread_join(thread[0], NULL); 
	pthread_join(thread[1], NULL); 
	
	pthread_mutex_destroy(&lock); 

	return 0; 
} 
