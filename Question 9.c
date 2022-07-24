#include<stdio.h>
#include<pthread.h>

void *function1();
void *function2();
void *function3();

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;
pthread_mutex_t third_mutex;

//int res;
int main()
{
	pthread_mutex_init(&first_mutex,NULL);
	pthread_mutex_init(&second_mutex,NULL);
	pthread_mutex_init(&third_mutex,NULL);
	
	pthread_t one, two,three;
	
	pthread_create(&one, NULL, function1, NULL);
	pthread_create(&two, NULL, function2, NULL);
	pthread_create(&three, NULL, function3, NULL);
	
	pthread_join(one, NULL);
	pthread_join(two, NULL);
	pthread_join(three, NULL);
	
	printf("Thread joined\n");
}

void *function1()
{
	pthread_mutex_lock(&first_mutex);
	printf("Thread ONE acquired First_mutex\n");
	//sleep(1);
	pthread_mutex_lock(&second_mutex);	
    printf("Thread ONE acquired Second_mutex\n");
	//sleep(2);
	pthread_mutex_lock(&third_mutex);	
    printf("Thread ONE acquired Third_mutex\n");
    //sleep(3);
	pthread_mutex_unlock(&first_mutex);
	printf("Thread ONE released First_mutex\n");
	pthread_mutex_unlock(&second_mutex);
	printf("Thread ONE released Second_mutex\n");
	pthread_mutex_unlock(&third_mutex);
	printf("Thread ONE released Third_mutex\n");	
}

void *function2()
{
	pthread_mutex_lock(&second_mutex);
	printf("Thread TWO acquired Second_mutex\n");
	//sleep(1);
	pthread_mutex_lock(&third_mutex);
	printf("Thread TWO acquired Third_mutex\n");
	pthread_mutex_lock(&first_mutex);
	printf("Thread TWO acquired First_mutex\n");
	//sleep(2);
	pthread_mutex_unlock(&second_mutex);
	printf("Thread TWO released Second_mutex\n");
	pthread_mutex_unlock(&third_mutex);
	printf("Thread TWO released Third_mutex\n");
	pthread_mutex_unlock(&first_mutex);
	printf("Thread TWO released First_mutex\n");
}

void *function3()
{
	pthread_mutex_lock(&third_mutex);	
    printf("Thread THREE acquired Third_mutex\n");

	pthread_mutex_lock(&second_mutex);	
    printf("Thread THREE acquired Second_mutex\n");
        
	pthread_mutex_lock(&first_mutex);
	printf("Thread THREE acquired First_mutex\n");
	
	pthread_mutex_unlock(&third_mutex);
	printf("Thread THREE released Third_mutex\n");
	pthread_mutex_unlock(&second_mutex);
	printf("Thread THREE released Second_mutex\n");
	pthread_mutex_unlock(&first_mutex);
	printf("Thread THREE released First_mutex\n");
}
