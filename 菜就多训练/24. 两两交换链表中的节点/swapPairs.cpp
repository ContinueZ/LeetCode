



//Definition for singly-linked list.
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		if (head->next == nullptr)
			return head;

		ListNode* phead = new ListNode(-1);
		phead->next = head;
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		ListNode* pt = phead;
		while (p2)
		{

			p1->next = p2->next;
			p2->next = p1;
			pt->next = p2;
			pt = p1;
			p1 = p1->next;
			if (p1&&p1->next)
				p2 = p1->next;
			else
				return phead->next;
		}
		return phead->next;
	}
};