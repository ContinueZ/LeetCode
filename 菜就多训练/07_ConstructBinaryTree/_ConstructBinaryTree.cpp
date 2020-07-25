#include<iostream>
#include<exception>

struct BinaryTreeNode
{
	int                    m_nValue;
	BinaryTreeNode*        m_pLeft;
	BinaryTreeNode*        m_pRight;
	BinaryTreeNode*        m_pParent;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	//前序遍历第一个节点为根节点
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;


	if (startPreorder == endPreorder)
	{
		if (startPreorder == endPreorder && *startPreorder == *endPreorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	//从中序遍历中找到根节点
	int* rootInorder = startInorder;
	while (rootInorder != endInorder && *rootInorder != rootValue)
	{
		++rootInorder;
	}
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		//构建左子树
		ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		//构建右子树
		ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;

}

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
		{
			pRight = pRight->m_pLeft;
		}
		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != nullptr && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pCurrent;
	}
	return pNext;
}

int main()
{
	return 0;
}