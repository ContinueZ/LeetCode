
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dumpNode = new ListNode(0);
		dumpNode->next = head;
		ListNode* firstNode = dumpNode;
		ListNode* secondNode = dumpNode;
		
		for (int i = 0; i < n; ++i)
		{
			secondNode = secondNode->next;
		}
		while (secondNode->next != nullptr)
		{
			secondNode = secondNode->next;
			firstNode = firstNode->next;
		}
		firstNode->next = firstNode->next->next;
		return dumpNode->next;
	}
};