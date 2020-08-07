#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* pFlag = new ListNode(0);
		pFlag->next = head;
		ListNode* pPre = pFlag;
		while (pFlag->next) {
			pFlag = pFlag->next;
			if (pFlag->val >= x)
			break;
			pPre = pFlag;
		}
		if (pPre == pFlag)return head;
		ListNode* p1 = pFlag;
		ListNode* p2 = pPre;
		while (p1->next) {
			p2 = p1;
			p1 = p1->next;
			if (p1->val < x) {

				p2->next = p1->next;
				p1->next = pPre->next;
				pPre->next = p1;
				
				pPre = p1;
				p1 = p2;
			}
		}
		return head;
	}
};

int main()
{
	ListNode* p=nullptr;
	ListNode* head = new ListNode(0);
	ListNode* l = head;
	int i;
	while (cin >> i) {
		if (i == 0)break;
		p = new ListNode(i);
		l->next = p;
		l = p;
	}
	int x = 3;
	Solution s;
	s.partition(head->next, x);
}