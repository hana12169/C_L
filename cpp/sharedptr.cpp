/*************************************************************************
    > File Name: sharedptr.cpp
    > Author: zguiq
    > Created Time: Wednesday, November 16, 2016 PM06:52:19 CST
************************************************************************/
#include <tr1/memory>
#include <stdio.h>

using std::tr1::shared_ptr;

shared_ptr<int> ReturnPtr()
{
	shared_ptr<int> p(new int(100));
	return p;
}

int main()
{
	shared_ptr<int> p1 = ReturnPtr();
	printf("%d\n",*p1);
	return 0;
}
