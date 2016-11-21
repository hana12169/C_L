/*************************************************************************
    > File Name: sort.cpp
    > Author: zguiq
    > Created Time: Wednesday, November 16, 2016 PM08:59:16 CST
************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
int main1()
{
	vector<int> vi;
	int i;
	for (i =0 ;i<10;i++)
		vi.push_back(1+2*i);
	std::vector<int>::iterator it;
	for(it = vi.begin();it!= vi.end(); it++)
		std::cout<<*it<<" ";
	std::cout<<endl;
	int tar =6;
	std::cout<<tar<<endl;
	int start = 0;
	int end   = vi.size()-1;
	while(1)
	{
		if(start == end -1)
			return end;
		int tmp = (start+end)/2;
		if(vi[tmp] == tar)
			return tmp;
		if(vi[tmp]>tar)
			end = tmp;
		else
			start = tmp;
	}

}

int main()
{
	std::cout<<"index ="<<main1()<<std::endl;
	return 0;
}
