/*************************************************************************
    > File Name: cond_signal.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年08月19日 星期五 15时10分12秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

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
	sleep(1);
	pthread_create(&t_b, NULL, thread1, (void*)NULL);

	pthread_join(t_a, NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	exit(0);
}

void *thread1 (void * arg)
{
	pthread_mutex_lock(&mutex);
	printf("call thread1 \n");
	pthread_cond_signal(&cond);
	printf("thread1 called\n");
	pthread_mutex_unlock(&mutex);
}

void *thread2 (void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("call thread2\n");
	pthread_cond_wait(&cond, &mutex);
	sleep(1);
	printf("thread2 called\n");
	pthread_mutex_unlock(&mutex);
}
