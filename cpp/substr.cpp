/*************************************************************************
    > File Name: substr.cpp
    > Author: zguiq
    > Created Time: 2016年11月21日 星期一 17时14分01秒
************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int findsubstr(string &s)
{
	if(s.empty())
		return 0;
	int result = 1;
	string tmp(1,s[0]);
	size_t found;
	string::iterator it = s.begin();
	for(it++ ;it != s.end();it++)
	{

		found = tmp.find(*it);
		if(string::npos == found)
		{
			tmp += *it;
			if(tmp.length()>result)
				result = tmp.length();
		}
		else
		{
			try
			{
				if(found < tmp.length()-1)
				{
					tmp = tmp.substr(found+1);
					tmp += *it;
				}
				else
					tmp = tmp.substr(found);
			}
			catch(int)
			{
				cout<<"catch error"<<found<<endl;
			}
		}
	}
	return result;
}

int main()
{
	string str;
	while(1)
	{
		cin>>str;
		cout<<findsubstr(str)<<endl;
		cout<<"+++++++++++++++++++"<<endl;
	}
	return 0;
}
