#include<string>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		int strSize = int(s.size());
		if (strSize % 2 == 1)
			return false;

		stack<char> stack;

		for (auto tmpChar:s)
		{
			char popChar = ' ';
			switch (tmpChar)
			{

			case '(':
			case '[':
			case '{':
				stack.push(tmpChar);
				break;
			case ')':
				if (stack.empty())
					return false;
				popChar = stack.top();
				stack.pop();
				if (popChar != '(')
					return false;
				break;
			case ']':
				if (stack.empty())
					return false;
				popChar = stack.top();
				stack.pop();
				if (popChar != '[')
					return false;
				break;
			case '}':
				if (stack.empty())
					return false;
				popChar = stack.top();
				stack.pop();
				if (popChar != '{')
					return false;
				break;
			}
		}
		if (stack.empty())
			return true;
		else
			return false;
	}
};

//��Ʊ�ⷨ
//class Solution {
//public:
//	bool isValid(string s) {
//		int strSize = int(s.size());
//		if (strSize % 2 != 0)
//			return false;
//
//		stack<char> store;
//
//		for (auto tmpChar : s)
//		{
//			char popChar = ' ';
//			switch (tmpChar)
//			{
//				//�����(,[,{,��ѹ��ջ��
//			case '(':
//			case '[':
//			case '{':
//				store.push(tmpChar);
//				break;
//			case ')':
//				//ע��ջΪ�յ����
//				if (store.empty())
//				{
//					return false;
//				}
//				popChar = store.top();
//				store.pop();
//				if (popChar != '(')
//				{
//					return false;
//				}
//				break;
//			case ']':
//				if (store.empty())
//				{
//					return false;
//				}
//				popChar = store.top();
//				store.pop();
//				if (popChar != '[')
//				{
//					return false;
//				}
//				break;
//			case '}':
//				if (store.empty())
//				{
//					return false;
//				}
//				popChar = store.top();
//				store.pop();
//				if (popChar != '{')
//				{
//					return false;
//				}
//				break;
//			}
//		}
//		if (store.empty())
//			return true;
//		else
//			return false;
//	}
//};