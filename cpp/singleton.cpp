/*************************************************************************
    > File Name: singleton.cpp
    > Author: zguiq
    > Created Time: Thu 10 Nov 2016 07:13:20 PM CST
************************************************************************/
#include "singleton.h"
#include <stdio.h>

Singleton::Singleton()
{
}
Singleton::Singleton(const Singleton&)
{

}
Singleton &Singleton::operator = (const Singleton&){

}
Singleton *Singleton::instance = NULL;
int Singleton::mem = 0;
Singleton *Singleton::getInstance()
{
	if(instance == NULL)
	{
		if(instance == NULL)
			instance = new Singleton;
	}
	return instance;
}
void Singleton::freeSingleton()
{
	if(NULL != instance)
	{
		delete instance;
		instance = NULL;
	}
}



