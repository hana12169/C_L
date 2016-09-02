/*************************************************************************
    > File Name: cond_wait.c
    > Author: zguiq
    > Mail: guiqiang.zhang@163.com 
    > Created Time: Thu 18 Aug 2016 08:26:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *thread1(void*);
void *thread2(void*);

int i = 1;

int main()
{
	pthread_t t_a;
	pthread_t t_b;
	
	pthread_create(&t_a, NULL, thread2, (void*)NULL);
	usleep(3000);
	pthread_create(&t_b, NULL, thread1, (void*)NULL);
	
	pthread_join(t_b, NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	exit(0);
}

void *thread1 (void* junk)
{
	for (i = 1; i<=4; i++)
	{
		pthread_mutex_lock(&mutex);
		printf("call thread1 \n");
		if (i%3 == 0)
		{
			pthread_cond_signal(&cond);
			i++;
		}
		else
			printf("thread1:%d\n",i);
		pthread_mutex_unlock(&mutex);
		usleep(300000);
	}
}

void *thread2 (void *junk)
{
	while(i<5)
	{
		pthread_mutex_lock(&mutex);
		printf("call thread2\n");
		if(i%3 != 0)
			pthread_cond_wait(&cond, &mutex);
		sleep(1);
		printf("thread2:%d\n",i);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
