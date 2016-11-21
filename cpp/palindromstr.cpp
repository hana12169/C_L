/*************************************************************************
    > File Name: palindromstr.cpp
    > Author: zguiq
    > Created Time: Monday, November 21, 2016 PM09:34:25 CST
************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

string longestPalindrome(string s) {

	if(s.empty())
		return NULL;
	string news;
	news.reserve(s.length()*2);
	for(int i=0;i<s.length();i++)
	{
		news+='#';
		news+= s[i];
	}
	news+='#';
	vector<int> nums;
	cout<<news.length()<<endl;
	cout<<news<<endl;
	for(int i=0; i<news.length(); i++)
	{

		int j =1;
		while(i -j>=0 && i+j<news.length())
		{

			if(news[i-j] == news[i+j])
				j++;
			else break;
		}
		nums.push_back(j);
	}
	int tmp = 0;
	int index =0;
	for(int i=0; i<nums.size(); i++)
	{

		if(tmp < nums[i])
		{

			tmp = nums[i];
			index =i;
		}
	}
	news = news.substr(index- tmp+1, 2*tmp-1);
	string result;
	for(int i=0; i<news.length();i++)
	{
		if(news[i]!='#')
		result += news[i];
	}
	cout<<"result="<<result<<endl;
	return result;
	//news = news.substr(index)
	//cout<<"nums.size()="<<nums.size()<<endl;
	//cout<<"tmp:"<<tmp<<"index:"<<index<<endl;
	//if(tmp%2 ==0)
	//	return s.substr((index-1)/2 -tmp/2+1,tmp );
	//else
	//	return s.substr(index/2 -tmp/2, tmp);
}
int main()
{
	string str;
	while(1)
	{
		cin>>str;
		cout<<longestPalindrome(str)<<endl;
		cout<<"finish"<<endl;
	}
	return 0;
}
