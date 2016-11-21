/*************************************************************************
    > File Name: const.cpp
    > Author: zguiq
    > Created Time: Wednesday, November 16, 2016 PM07:11:43 CST
************************************************************************/
#include<stdio.h>


class A
{
	private:
		int mutable ma;
	public:
		A():ma(1){

		}
		int getA() const {
			printf("%d\n",ma);
			return ma;
		}
		int GetA() 
		{
			printf("%d\n",ma);
			return ma;
		}
		int setA(int a) const
		{
			ma = a;
			printf("%d\n",ma);
		}
		int SetA(int a)
		{
			ma = a;
			printf("%d\n",ma);
		}
};
int main()
{
	A a1;
	const A a2;
	int t;
	t = a1.getA();
	t = a1.GetA();
	t = a2.getA();
//	t = a2.GetA();
	return 0;
}

