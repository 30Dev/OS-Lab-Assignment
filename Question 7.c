#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

static int s = 0;
  
void *printMessage(void)
{
	printf("WELCOME TO THE CALCULATOR\n");
	printf("Enter the numbers for addition: ");
}

void *printSum(void *data)
{
	int a = *((int*)data);
	
	s = s + a;
}

int main() 
{  
    pthread_t thread1;
    pthread_t thread2;
    
    int a[2];
    int i;
    
    pthread_create(&thread1, NULL, printMessage, NULL);
    
    for(i=0; i<2; i++)
    {
    	scanf("%d", &a[i]);
	}
  
    for(i=0; i<2; i++)
    {
		pthread_create(&thread2, NULL, printSum, &a[i]); 
	}
	
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("The sum of the two numbers: ");
	printf("%d", s);
	
    return 0; 
}
