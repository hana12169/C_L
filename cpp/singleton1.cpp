/*************************************************************************
    > File Name: singleton1.cpp
    > Author: zguiq
    > Created Time: 2016年11月16日 星期三 10时08分35秒
************************************************************************/
#include<stdio.h>

class Singleton
{
	private:
		static Singleton *instance;
		Singleton(){
		}
		Singleton(const Singleton&){
		}
		Singleton operator=(const Singleton&){
		}
	public:
		static Singleton* getInstance()
		{
			if(instance == NULL)
				instance = new Singleton();
			return instance;
		}
};
Singleton *Singleton::instance = NULL; 

int main()
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	if(s1 == s2)
	{
		printf("s1=s2\n");
	}
	return 0;
}
