/*************************************************************************
    > File Name: main.cpp
    > Author: zguiq
    > Created Time: Thu 10 Nov 2016 07:41:06 PM CST
************************************************************************/
#include "singleton.h"
#include <stdio.h>
#include "time.h"

class ca
{
	public:
		static int mem;
};
int ca::mem ;


int fun()
{
	static int count = 10;
	return count --;
}

int main()
{
	//Singleton *singleton1 = Singleton::getInstance();
	//Singleton *singleton2 = Singleton::getInstance();
	//if(singleton1 == singleton2)
	//	printf("sing1 == sing2!\n");
	//else
	//	printf("sing1 not equal to sing2!\n");
	//printf("mem=%d\n",singleton1->mem);
	//singleton2->mem = 2;
	//printf("mem=%d\n",singleton1->mem);
	//ca *ca1 = new ca();
	//ca *ca2 = new ca();
	//printf ("ca1->mem=%d",ca1->mem);
	//printf ("ca2->mem=%d",ca2->mem);
	//ca1->mem = 3;
	//printf ("ca1->mem=%d",ca1->mem);
	//printf ("ca2->mem=%d",ca2->mem);
	//int count = 0;
	//for (int i =0;i<10;i++)
	//{
	//	printf("i=%d,count=%d\n",i,fun());
	//}
	//printf("\n");
	mTime time(14,95,93);
	mTime time1(time);
	mTime time2 = mTime(13,97,98);
	mTime time3 = time2;
	printf("time1 is %d:%d:%d\n",time1.hour,time1.min,time1.sec);
	printf("time2 is %d:%d:%d\n",time2.hour,time2.min,time2.sec);
	printf("time3 is %d:%d:%d\n",time3.hour,time3.min,time3.sec);
	mTime timesum;
	timesum = time1 + time2;
	printf("timesum is %d:%d:%d\n",timesum.hour,timesum.min,timesum.sec);
	mTime timemin = time1 - time2;
	printf("timemin is %d:%d:%d\n",timemin.hour,timemin.min,timemin.sec);
}
