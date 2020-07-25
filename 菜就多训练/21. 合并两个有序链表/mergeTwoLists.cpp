
 //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 || l2)
		{
			if (l1&&l2) {}
			else if (l1)
				return l1;
			else
				return l2;
		}
		ListNode* p1 = new ListNode(0);
		ListNode* p2 = new ListNode(0);
		p1->next = l1;
		p2->next = l2;
		ListNode* p3 = new ListNode(0);
		while (p1->next&&p2->next)
		{
			if (p1->next->val < p2->next->val)
			{
				p3->next = p1->next;
				p1->next = p1->next->next;
				continue;
			}
			if (p1->next->val == p2->next->val)
			{
				p3->next = p1->next;
				p1->next = p1->next->next;
			}
			ListNode* pt = new ListNode(0);
			pt->next = p2->next->next;
			p2->next->next = p1->next;
			if (p3->next)
			{
				p3->next->next = p2->next;
				p3->next = p2->next;
			}
			else
				l1 = p1->next = p2->next;
			p2 = pt;
		}
		if (p2->next)
			p3->next->next = p2->next;
		return l1;
	}
};

//¸ßÆ±½â·¨
class Solution1
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		if (l1 == nullptr)
			return l2;
		else
			return l1;

		if (l1->val <= l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

class Solution2
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode* result = new ListNode(-1);
		ListNode* workNode = result;
		while (l1&&l2)
		{
			if (l1->val <= l2->val)
			{
				workNode->next = l1;
				l1 = l1->next;
			}
			else
			{
				workNode->next = l2;
				l2 = l2->next;
			}
			workNode = workNode->next;
		}
		workNode = l1 != nullptr ? l1 : l2;

		return result->next;
		
	}
};