/*************************************************************************
    > File Name: map.cpp
    > Author: zguiq
    > Created Time: Tuesday, November 15, 2016 PM07:32:50 CST
************************************************************************/
#include<iostream>
#include<map>

int main()
{
	std::map<char, int> mymap;
	char c;
	mymap['a']=101;
	mymap['b']=102;
	mymap['c']=103;
	mymap['d']=104;
	for(c = 'a'; c <'h'; c++)
	{
		if(mymap.count(c)>0)
			std::cout<<c<<" is a member of mymap"<<std::endl;
	}
	return 0;
}
