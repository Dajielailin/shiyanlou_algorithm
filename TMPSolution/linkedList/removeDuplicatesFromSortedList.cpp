/*
*Definition for ListNode
*class ListNode{
*public:
*	int val;
*	ListNode *next;
*	ListNode(int val)
*	{
*		this->val = val;
*		this->next = NULL;
*	}
*}
*/
#include<iostream>
#include<list>

ListNode * removeDuplicates(ListNode *head)
{
	if(head == NULL)
		return head;
	ListNode * cur = head;
	while(cur != NULL)
	{
		while(cur->next != NULL && cur->val == cur->next->val)
		{
			ListNode * tmp = cur->next;
			cur->next = cur->next->next;
			delete(tmp);
			tmp = NULL;
		}
		cur = cur->next;
	}
	return head;
}

int main()
{
	return 0;
}
