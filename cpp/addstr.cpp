/*************************************************************************
    > File Name: addstr.cpp
    > Author: zguiq
    > Created Time: 2016年11月21日 星期一 14时26分41秒
************************************************************************/
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

void swapchar(char &char1, char &char2)
{
	//char tmp = *char1;
	//*char1 = *char2;
	//*char2 = *tmp;
	char tmp = char1;
	char1 = char2;
	char2 = tmp;
}
string addstr(string &str1, string &str2)
{
	if(str1.size()<1)
		return str2;
	if(str2.size()<1)
		return str1;
	int tmp = 0;
	string result;
	string::reverse_iterator it1 = str1.rbegin();
	string::reverse_iterator it2 = str2.rbegin();
	while(it1 != str1.rend() && it2 != str2.rend())
	{
		int tmp1 = (*it1 - '0')+(*it2 - '0') + tmp;
		if (tmp1 > 9)
		{
			tmp = 1;
			tmp1 = (tmp1 - 10);
		}
		else
		{
			tmp = 0;
		}
		result += (tmp1 + '0');
		it1 ++;
		it2 ++;
	}
	if (it1 != str1.rend())
	{
		while(it1 != str1.rend())
		{
			int tmp1 = (*it1 - '0') + tmp;
			if (tmp1 > 9)
			{
				tmp = 1;
				tmp1 = (tmp1 - 10);
			}
			else
			{
				tmp = 0;
			}
			result += (tmp1 + '0');
			it1 ++;
		}
	}
	if (it2 != str2.rend())
	{
		while(it2 != str2.rend())
		{
			int tmp1 = (*it2 - '0') + tmp;
			if (tmp1 > 9)
			{
				tmp = 1;
				tmp1 = (tmp1 - 10);
			}
			else
			{
				tmp = 0;
			}
			result += (tmp1 + '0');
			it2 ++;
		}
	}
	if(tmp)
		result +=(tmp+'0');
	//cout<<result<<endl;
	for(int i =0; i< result.length()/2; i++)
	{
		swapchar(result[i], result[result.length()-1-i]);
	}
	return result;

}
int main()
{
	
	string str1("1234");
	string str2("1234");
	cout<<addstr(str1,str2)<<endl;
	while(1)
	{
		cin>>str1;
		cin>>str2;
		cout<<addstr(str1,str2)<<endl;
	}
	return 0;
}
