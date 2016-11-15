/*************************************************************************
    > File Name: vector.cpp
    > Author: zguiq
    > Created Time: Tuesday, November 15, 2016 PM07:18:42 CST
************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vi;
	int a;
	while(1)
	{
		cout<<"input a int and break at 0"<<endl;
		cin>>a;
		if(0 ==a )
			break;
		vi.push_back(a);
	}
	vector<int>::iterator iter;
	for(iter=vi.begin();iter!=vi.end();++iter)
		cout<<*iter;
	return 0;
}
