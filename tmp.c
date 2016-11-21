/*************************************************************************
    > File Name: tmp.c
    > Author: zguiq
    > Created Time: 2016年11月16日 星期三 11时04分20秒
************************************************************************/

#include<stdio.h>

int main()
{
	char str[5];
	int a=13;
	memcpy((void*)str,(const void *)&a,(size_t)4);
	printf("%s\n",str);
	//char chars[20]="aaaaaaaa";
	//printf("&char=%x\n",(int)&chars);
	//printf("char=%x\n",(int)chars);
	//printf("char=%x\n",(int)*chars);
	//char a;
	//char *p = &a;
	//char **pp = &p;
	//printf("p=%x\n",p);
	//printf("pp=%x\n",(int)pp);
	return 0;
}
