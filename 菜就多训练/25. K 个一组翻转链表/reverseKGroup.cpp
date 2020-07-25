#include<iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		int length = 0;
		auto node = head;
		while (node != NULL) {
			if (++length >= k) break;
			node = node->next;
		}
		if (length < k) return head;
		ListNode* prev = NULL;
		ListNode* curr = head;
		for (int i = 0; i < k; ++i) {
			auto node = curr->next;
			curr->next = prev;
			prev = curr;
			curr = node;
		}
		head->next = reverseKGroup(curr, k);
		return prev;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	ListNode*p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	//p->next = new ListNode(5);
	//p = p->next;

	ListNode *pt = new ListNode(-1);
	pt->next = s.reverseKGroup(head, 2);
	while (pt->next) {
		cout << pt->next->val << endl;
		pt = pt->next;
	}

}