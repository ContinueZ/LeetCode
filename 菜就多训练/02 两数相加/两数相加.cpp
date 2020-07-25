/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *pScan = l1;
		int i = 0;
		int sum1 = 0;
		int sum2 = 0;
		ListNode* retList = new ListNode(-1);
		ListNode* p;
		ListNode* q;

		while (pScan->next != NULL)
		{
			for (int j = 0; j < i; j++)
			{
				pScan->next->val *= 10;
			}
			sum1 += pScan->next->val;
			pScan->next->val = 0;
			i++;
			pScan = pScan->next;
		}

		pScan = l2;
		i = 0;
		while (pScan->next != NULL)
		{
			for (int j = 0; j < i; j++)
			{
				pScan->next->val *= 10;
			}
			sum2 += pScan->next->val;
			pScan->next->val = 0;
			i++;
			pScan = pScan->next;
		}

		int sum = sum1 + sum2;
		cout << "�������:" << endl;
		cout<< sum1 << "+" << sum2 << "=" << sum << endl;
		
		q = retList;
		while (sum != 0)
		{
			int iTmp = sum % 10;
			sum = sum / 10;
			p = new ListNode(iTmp);
			q->next = p;
			q = p;
			p = NULL;

		}
		return retList->next;
	}
};

int main()
{
	int firstInput = -1;
	int secondInput = -1;
	ListNode *pL1 = NULL;
	ListNode *pL2 = NULL;
	ListNode *pTmpL = new ListNode(-1);
	ListNode *pHead1 = new ListNode(-1);
	ListNode *pHead2 = new ListNode(-1);
	Solution s;

	cout << "----------------�������----------------" << endl;
	cout << "�����������Ǹ�������������������㣺" << endl;

	cout << "�����һ�����֣��س���������" << endl;
	cin >> firstInput;
	cout << "����ڶ������֣��س���������" << endl;
	cin >> secondInput;

	if (firstInput == 0)
	{
		pL1 = new ListNode(0);
		//pL1->val = firstInput;
		pHead1->next = pL1;
		pL1->next = NULL;
	}
	else
	{
		pTmpL = pHead1;
		while (firstInput != 0)
		{
			int tmpNum = firstInput % 10;
			firstInput = firstInput / 10;
			pL1 = new ListNode(tmpNum);
			//pL1->val = tmpNum;
			pL1->next = NULL;
			pTmpL->next = pL1;
			pTmpL = pL1;
			pL1 = NULL;
		}
	}
	
	if (secondInput == 0)
	{
		pL1 = new ListNode(0);
		pL1->val = secondInput;
		pHead2->next = pL2;
		pL1->next = NULL;
	}
	else
	{
		pTmpL = pHead2;
		while (secondInput != 0)
		{
			int tmpNum = secondInput % 10;
			secondInput = secondInput / 10;
			pL2 = new ListNode(tmpNum);
			//pL2->val = tmpNum;
			pL2->next = NULL;
			pTmpL->next = pL2;
			pTmpL = pL2;
			pL2 = NULL;
		}
	}

	ListNode* pResult = s.addTwoNumbers(pHead1, pHead2);
	pTmpL = pResult;

	//�������
	cout << "���������" << endl;
	while (pTmpL != NULL)
	{
		cout << pTmpL->val;
		pResult = pTmpL->next;
		delete pTmpL;
		pTmpL = pResult;
	}

	cout << endl << endl;
	cout << "----------------�������----------------" << endl;
	cout << endl;

	while (pHead1->next != NULL)
	{
		pTmpL = pHead1->next;
		pHead1->next = pHead1->next->next;
		delete pTmpL;
		pTmpL = NULL;
	}
	delete pHead1;
	pHead1 = NULL;

	while (pHead2->next != NULL)
	{
		pTmpL = pHead2->next;
		pHead2->next = pHead2->next->next;
		delete pTmpL;
		pTmpL = NULL;
	}
	delete pHead2;
	pHead2 = NULL;

	return 0;
}

//
//�ⷨ1��
//����˼·��
//�����Ƚ϶̵�������ĩβ����ʹ��������������ȣ���һ��һ��Ԫ�ض�����ӣ����ǽ�λ��
//
//���岽�裺
//��ȡ������������Ӧ�ĳ���
//�ڽ϶̵�����ĩβ����
//������ӿ��ǽ�λ
//ʵ�ִ��룺
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//	class Solution {
//	public:
//		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//			int len1 = 1;//��¼l1�ĳ���
//			int len2 = 1;//��¼l2�ĳ���
//			ListNode* p = l1;
//			ListNode* q = l2;
//			while (p->next != NULL)//��ȡl1�ĳ���
//			{
//				len1++;
//				p = p->next;
//			}
//			while (q->next != NULL)//��ȡl2�ĳ���
//			{
//				len2++;
//				q = q->next;
//			}
//			if (len1 > len2)//l1�ϳ�����l2ĩβ����
//			{
//				for (int i = 1; i <= len1 - len2; i++)
//				{
//					q->next = new ListNode(0);
//					q = q->next;
//				}
//			}
//			else//l2�ϳ�����l1ĩβ����
//			{
//				for (int i = 1; i <= len2 - len1; i++)
//				{
//					p->next = new ListNode(0);
//					p = p->next;
//				}
//			}
//			p = l1;
//			q = l2;
//			bool count = false;//��¼��λ
//			ListNode* l3 = new ListNode(-1);//��Ž��������
//			ListNode* w = l3;//l3���ƶ�ָ��
//			int i = 0;//��¼��ӽ��
//			while (p != NULL && q != NULL)
//			{
//				i = count + p->val + q->val;
//				w->next = new ListNode(i % 10);
//				count = i >= 10 ? true : false;
//				w = w->next;
//				p = p->next;
//				q = q->next;
//			}
//			if (count)//������н�λ
//			{
//				w->next = new ListNode(1);
//				w = w->next;
//			}
//			return l3->next;
//		}
//};
//�ⷨ2��
//����˼·��
//�����벹�㣬������Ϊ������sum(����ÿ��λ�ĺ͵Ľ��)���ϣ����ǽ�λ��
//
//ʵ�ִ��룺
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* head = new ListNode(-1);//��Ž��������
//		ListNode* h = head;//�ƶ�ָ��
//		int sum = 0;//ÿ��λ�ļӺͽ��
//		bool carry = false;//��λ��־
//		while (l1 != NULL || l2 != NULL)
//		{
//			sum = 0;
//			if (l1 != NULL)
//			{
//				sum += l1->val;
//				l1 = l1->next;
//			}
//			if (l2 != NULL)
//			{
//				sum += l2->val;
//				l2 = l2->next;
//			}
//			if (carry)
//				sum++;
//			h->next = new ListNode(sum % 10);
//			h = h->next;
//			carry = sum >= 10 ? true : false;
//		}
//		if (carry)
//		{
//			h->next = new ListNode(1);
//		}
//		return head->next;
//};