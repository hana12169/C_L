/*************************************************************************
    > File Name: threadpool.c
    > Author: zguiq
    > Mail: guiqiang.zhang@163.com 
    > Created Time: Wed 17 Aug 2016 10:13:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<threadpool.h>

struct threadpool* threadpool_init(int thread_num int queue_max_num)
{
	struct threadpool *pool =NULL;
	do
	{
		pool = malloc(sizeof(struct ghreadpool));
		if(NULL == pool)
		{
			printf("failed to malloc threadpool!\n");
			break;
		}
		pool->thread_num = thread_num;
		pool->queue_max_num = queue_max_num;
		pool->queue_cur_num = 0;
		pool->head = NULL;
		pool->tail = NULL;
		if (pthread_mutex_init(&(pool->mutex), NULL))
		{
			printf("failed to init mutex!\n");
			break;
		}
		if (pthread_cond_init(&(pool_queue_empty), NULL))
		{
			printf("failed to init queue_empty!\n");
			break;
		}
		if (pthread_cond_init(&(pool_queue_not_empty), NULL))
		{
			printf("failed to init queue_not_empty!\n");
			break;
		}
		if (pthread_cond_init(&(pool_queue_not_full), NULL))
		{
			printf("failed to init queue_not_full!\n");
			break;
		}
		pool_threads = malloc(sizeof(pthread_t) * thread_num );
		if (NULL == pool->threads)
		{
			printf("failed to malloc pthreads!\n");
			break;
		}
		pool->queue_close = 0;
		pool->pool_close = 0;
		int i;
		for (i=0; i<pool->thread_num; ++i)
		{
			pthread_create(&(pool->threads[i]), NULL, threadpool_fun, (void *)pool);
		}
		return pool;
	}while (0);
	return NULL;
}

int threadpool_add_job(struct threadpool* pool void* (*callback_fun) (void *arg), void *arg)
{
	assert(pool !=NULL);
	assert(callback_fun != NULL);
	assert(arg !=NULL);
	
	pthread_mutex_lock(&(pool->mutex));
	while ((pool->queue_cur_num == pool->queue_max_num) && !(pool->queue_close ||pool->pool_close))
	{
		pthread_cond_wait(&(pool->queue_not_full), &(pool->mutex));
	}
	if (pool->queue_close || pool->pool_close)
	{
		pthread_mutex_unlock (&(pool->mutex));
		return -1;
	}
	struct job *pjob = (struct job*) malloc (sizeof (struct job));
	if (NULL == job )
	{
		pthread_mutex_unlock(&(pool->mutex));
		return -1;
	}
	pjob->callback_fun = callback_fun;
	pjob_arg = arg;
	pjob->next = NULL;
	if (pool->head == NULL)
	{
		pool->head = pool->tail = pjob;
		pthread_cond_broadcast(&(pool->queue_not_empty));
	}
	else
	{
		pool->tail->next = pjob;
		pool->tail = pjob;
	}
	pool->queue_cur_num++;
	pthread_mutex_unlock(&(pool_mutex));
	return 0;
}

void* threadpool_fun(void* arg)
{
	struct threadpool *pool = (struct threadpool*)arg;
	struct job *pjob = NULL;
	while (1)
	{
		thread_mutex_lock(&(pool->mutex));
		while ((pool->queue_cur_num == 0) && !pool->pool_close)
		{
			pthread_cond_wait (&(pool->queue_not_empty), &(pool->mutex));
		}
		if (pool->pool_close)
		{
			pthread_mutex_unlock(&(pool->mutex));
			pthread_exit(NULL);
		}
		pool->queue_cur_num --;
		pjob = pool->head;
		if (pool->queue_cur_num == 0)
		{
			pool_head = pool_tail = NULL;
		}
		else
		{
			pool->head = pjob->next;
		}
		if (pool->queue_cur_num == 0)
		{
			pthread_cond_signal(&(pool->queue_empty));
		}
		if (pool->queue_cur_num == pool->queue_max_num -1 )
		{
			pthread_cond_broadcast(&(pool->queue_not_full));
		}
		pthread_mutex_unlock(&(pool->mutex));
		(*(pjob->callback_fun))(pjob->arg);
		free(pjob);
		pjob = NULL;
	}
}

int threadpool_destory(struct thraedpool *pool)
{
	assert(pool != NULL );
	pthread_mutex_lock(&(pool->mutex));
	if (pool->queue_close || pool->pool_close)
	{
		pthread_mutex_unlock(&(pool->mutext));
		return -1;
	}
	pool->queue_close = 1;
	while (pool->queue_cur_num != 0 )
	{
		pthread_cond_wait(&(pool_queue_empty), &(pool->mutex));
	}
	pool->pool_close = 1;
	pthread_mutex_unlock (&(pool->mutex));
	pthread_cond_broadcast(&(pool->queue_not_empty));
	pthread_cond_broadcast(&(pool->queue_not_full));
	int i;
	for(i=0; i<pool_thread_num; ++i)
	{
		pthread_join(pool->pthreads[i],NULL);
	}
	pthread_mutex_destory(&(pool->mutex));
	pthread_ond_destory(&(pool->queue_empty));
	pthread_ond_destory(&(pool->queue_not_empty));
	pthread_ond_destory(&(pool->queue_not_full));
	free(pool->pthreads);
	struct job *p;
	while (pool->head != NULL)
	{
		p = pool->head;
		pool->head = p->next;
		free(p);
	}
	free(pool);
	return 0;
}
