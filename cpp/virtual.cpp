/*************************************************************************
    > File Name: virtual.cpp
    > Author: zguiq
    > Created Time: 2016年11月15日 星期二 14时10分46秒
************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Base
{
	protected:
		std::string A;
	public:
		Base(string a)
		{
			A = a;
			cout<<"base constructor"<<endl;
		}
		virtual void showstr() = 0;
		virtual ~Base();
};
Base::~Base()
{
	cout<<"Base destructor"<<endl;
}
void Base::showstr()
{
	cout<<"char A ="<<A<<endl;
}
class X:public Base
{
	public:
		X(string x):Base(x){
			cout<<"X constructor"<<endl;
		}
		void showstr();
		~X();
};
X::~X()
{
	cout<<"X destructor"<<endl;
}
void X::showstr()
{
	cout<<"char B ="<<A<<endl;
}
void fun(Base &base)
{
	base.showstr();
}

int main()
{
	//Base base("A");
	//base.showstr();
	//X x("B");
	//x.showstr();
	//base = x;
	//base.showstr();
	//Base &base1 = x;
	//base1.showstr();
	//Base *base2 = &x;
	//base2->showstr();
	//fun(x);
	//Base *base3 = new X("C");
	//base3->showstr();
	//delete base3;
	//base3 = NULL;
	X *x1= new X("D");
	x1->showstr();
	delete x1;
	x1 = NULL;
	return 0;
}
