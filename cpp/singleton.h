/*************************************************************************
    > File Name: singleton.h
    > Author: zguiq
    > Created Time: Thu 10 Nov 2016 07:09:07 PM CST
************************************************************************/
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton
{
	public:
		static Singleton *getInstance();
		static void freeSingleton();
		static int mem;
	private:
		Singleton();
		Singleton(const Singleton&);
		Singleton & operator = (const Singleton&);

		static Singleton *instance;
};

#endif

