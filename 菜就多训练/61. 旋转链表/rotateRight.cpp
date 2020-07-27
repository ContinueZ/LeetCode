#include<iostream>
using namespace std;
 /* Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//ִ�н����
//ͨ��
//��ʾ����
//ִ����ʱ��8 ms, ������ C++ �ύ�л�����94.52%���û�
//�ڴ����ģ�7.1 MB, ������ C++ �ύ�л�����100.00%���û�
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 0)return head;
		ListNode* p1 = head;
		ListNode* p2 = head;
		ListNode* p3;
		int n = 1;
		int i = 0;
		while (p2->next != NULL && i < k) {
			p2 = p2->next;
			++n;
			++i;
		}
		if (k%n == 0)return head;
		if (k > n) {
			k %= n;
			i = 0;
			p2 = head;
			n = 1;
		}
		while (p2->next != NULL && i < k) {
			p2 = p2->next;
			++n;
			++i;
		}
		while (p2->next != NULL) {
			p1 = p1->next;
			p2 = p2->next;
		}
		p3 = p1->next;
		p1->next = p2->next;
		p2->next = head;
		head = p3;
		return head;
	}
};