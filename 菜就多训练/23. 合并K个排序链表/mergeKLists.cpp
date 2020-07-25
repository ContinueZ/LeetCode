#include<vector>
#include<queue>
using namespace std;

 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

  class Solution {
  public:
	  ListNode* mergeKLists(vector<ListNode*>& lists) {
		  int size = int(lists.size());
		  if (size == 0)
			  return nullptr;
		  if (size == 1)
			  return lists[0];
		  //ListNode* p = lists[0];
		  //for (int i = 1; i < lists.size(); ++i)
		  //{
		  //	p = mergeTwoLists(p, lists[i]);
		  //}
		  //使用队列
		  queue<ListNode*> waiting(deque<ListNode*>(lists.begin(), lists.end()));
		  while (waiting.size() > 1)
		  {
			  ListNode* l1 = waiting.front();
			  waiting.pop();
			  ListNode* l2 = waiting.front();
			  waiting.pop();
			  waiting.push(mergeTwoLists(l1, l2));
		  }
		  return waiting.front();
	  }
	  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	  {
		  ListNode* result = new ListNode(0);
		  ListNode* workNode = result;
		  while (l1&&l2)
		  {
			  if (l1->val < l2->val)
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
		  workNode->next = l1 ? l1 : l2;

		  return result->next;

	  }
  };