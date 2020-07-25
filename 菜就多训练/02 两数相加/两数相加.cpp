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
		cout << "两数相加:" << endl;
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

	cout << "----------------两数相加----------------" << endl;
	cout << "输入两个（非负）数字用来作相加运算：" << endl;

	cout << "输入第一个数字（回车结束）：" << endl;
	cin >> firstInput;
	cout << "输入第二个数字（回车结束）：" << endl;
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

	//逆序输出
	cout << "逆序输出：" << endl;
	while (pTmpL != NULL)
	{
		cout << pTmpL->val;
		pResult = pTmpL->next;
		delete pTmpL;
		pTmpL = pResult;
	}

	cout << endl << endl;
	cout << "----------------两数相加----------------" << endl;
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
//解法1：
//整体思路：
//将长度较短的链表在末尾补零使得两个连表长度相等，再一个一个元素对其相加（考虑进位）
//
//具体步骤：
//获取两个链表所对应的长度
//在较短的链表末尾补零
//对齐相加考虑进位
//实现代码：
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
//			int len1 = 1;//记录l1的长度
//			int len2 = 1;//记录l2的长度
//			ListNode* p = l1;
//			ListNode* q = l2;
//			while (p->next != NULL)//获取l1的长度
//			{
//				len1++;
//				p = p->next;
//			}
//			while (q->next != NULL)//获取l2的长度
//			{
//				len2++;
//				q = q->next;
//			}
//			if (len1 > len2)//l1较长，在l2末尾补零
//			{
//				for (int i = 1; i <= len1 - len2; i++)
//				{
//					q->next = new ListNode(0);
//					q = q->next;
//				}
//			}
//			else//l2较长，在l1末尾补零
//			{
//				for (int i = 1; i <= len2 - len1; i++)
//				{
//					p->next = new ListNode(0);
//					p = p->next;
//				}
//			}
//			p = l1;
//			q = l2;
//			bool count = false;//记录进位
//			ListNode* l3 = new ListNode(-1);//存放结果的链表
//			ListNode* w = l3;//l3的移动指针
//			int i = 0;//记录相加结果
//			while (p != NULL && q != NULL)
//			{
//				i = count + p->val + q->val;
//				w->next = new ListNode(i % 10);
//				count = i >= 10 ? true : false;
//				w = w->next;
//				p = p->next;
//				q = q->next;
//			}
//			if (count)//若最后还有进位
//			{
//				w->next = new ListNode(1);
//				w = w->next;
//			}
//			return l3->next;
//		}
//};
//解法2：
//整体思路：
//不对齐补零，若链表不为空则用sum(代表每个位的和的结果)加上，考虑进位。
//
//实现代码：
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* head = new ListNode(-1);//存放结果的链表
//		ListNode* h = head;//移动指针
//		int sum = 0;//每个位的加和结果
//		bool carry = false;//进位标志
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