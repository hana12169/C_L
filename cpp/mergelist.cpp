/*************************************************************************
    > File Name: mergelist.cpp
    > Author: zguiq
    > Created Time: Wednesday, November 16, 2016 PM10:51:52 CST
************************************************************************/
#include<vector>
#include<iostream>

using namespace std;

struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.empty())
		return NULL;
	ListNode *tmpre=NULL;
	ListNode *re=NULL;
	ListNode *tmp = lists[0];
	int t =0;
	vector<ListNode*>::iterator it1;
	vector<ListNode*>::iterator it;
	cout<<"hehe1"<<endl;
	for(it = lists.begin();it !=lists.end();)
	{

		if(NULL == *it)
		{

			cout<<"hehe2"<<endl;
			it = lists.erase(it);
			cout<<"hehe3"<<endl;
			continue;
		}

		if((tmp->val) >((*it)->val))
		{

			tmp = *it;
			it1 = it;
		}
		++it;
	}
	cout<<"hehe4"<<endl;
	tmpre = new ListNode(tmp->val);
	re = tmpre;
	tmpre->next =NULL;
	if(NULL != tmp->next)
		tmp=tmp->next;
	else
		lists.erase(it1);
	cout<<"hehe5"<<endl;
	while(lists.size()>0)
	{

		for(it = lists.begin();it !=lists.end();++it)
		{

			if(NULL == *it)
			{

				it = lists.erase(it);
				continue;
			}
			if((tmp->val) >((*it)->val))
			{

				tmp = *it;
				it1 = it;
			}
		}
		tmpre->next =new ListNode(tmp->val);
		tmpre =tmpre->next;
		tmpre->next =NULL;
		if(NULL != tmp->next)
			tmp=tmp->next;
		else
			lists.erase(it1);
	}
	return re;
}
int main()
{
	vector<ListNode*> lists;
	ListNode *tmp =NULL;
	lists.push_back(tmp);
	mergeKLists(lists);
	return 0;

}
