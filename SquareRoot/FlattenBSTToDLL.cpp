#include "stdafx.h"
#include "FlattednBSTToDLL.h"

FLATTEN_BST_TO_DLL void FlattenBSTToDLL(BSTNode* pNode, BSTNode** ppHead, BSTNode** ppTail)
{
	*ppHead = nullptr;
	*ppTail = nullptr;

	if (pNode == nullptr)
	{
		return;
	}

	BSTNode* pLeftHead = nullptr;
	BSTNode* pLeftTail = nullptr;
	BSTNode* pRightHead = nullptr;
	BSTNode* pRightTail = nullptr;

	// Flatten left
	if (pNode->pLeft != nullptr)
	{
		FlattenBSTToDLL(pNode->pLeft, &pLeftHead, &pLeftTail);
	}

	// Flatten right
	if (pNode->pRight != nullptr)
	{
		FlattenBSTToDLL(pNode->pRight, &pRightHead, &pRightTail);
	}

	// Merge left DLL and right DLL with the current node to create a big DLL
	if (pLeftHead != nullptr)
	{
		*ppHead = pLeftHead;
		
		pNode->pLeft = pLeftTail;
		pLeftTail->pRight = pNode;
	}
	else
	{
		*ppHead = pNode;
	}

	if (pRightTail != nullptr)
	{
		*ppTail = pRightTail;

		pNode->pRight = pRightHead;
		pRightHead->pLeft = pNode;
	}
	else
	{
		*ppTail = pNode;
	}
} 