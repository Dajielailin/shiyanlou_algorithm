/*
*@param : Given a sorted linked list
*@return : delete all nodes that have duplicate numbers, than return the remain list.
*@Example: Given 1->1->2->3->3, return 2.
*
*Definition of ListNode
*class ListNode{
*public:
*	int val;
*	ListNode *nest;
*	ListNode(int val){
*		this->val = val;
		this->next = NULL;	
	}	
}
*/
class Solution{
pubilc:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if(head == NULL)
			return head;
		ListNode start(0);
		start.next = head;
		ListNode *node = &start;
		while(node->next != NULL && node->next->next !=NULL)
		{
			if(node->next->val == node->next->next->val)
			{
				int val_pre = node->next->val;
				while(node->next != NULL && val_pre == node->next->val)
				{
					ListNode *tmp = node->next;
					node->next = node->next->next;
					delete(tmp);
				}
			}
			else
			{
				node = node->next;
			}
		}
		return start.next;
	}
}

