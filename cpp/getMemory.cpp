/*************************************************************************
    > File Name: getMemory.cpp
    > Author: zguiq
    > Created Time: Wednesday, November 16, 2016 PM07:23:05 CST
************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

template <class Y>
void GetMemory(Y y)
{
	int b =100;
	y = &b;	
	//p = (char *)malloc(10);
}

void getmemory(char **p)
{
	*p = (char *)malloc(10);
}
char *getmemory(void)
{
	//char *p = (char *) malloc(10);
	char *p = "hello hehe";
	return p;
}
int main()
{
	int *ptr1 =0;
	char *str = getmemory();
	//int *x= new int(50);
	//GetMemory(x);
	char str1[30];
	printf("%s\n",str);
	str = str1;
	strcpy(str,"hello world");
	printf("%s\n",str);
	return 0;
}
