#include "stdafx.h"
#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

DLL_EXPORTS_IMPORT void AddNode(BSTNode** ppRoot, int value)
{
    BSTNode* pNode = (BSTNode*)malloc(sizeof(BSTNode));
    
    if (pNode == nullptr)
    {
        return;
    }

    pNode->value = value;
    pNode->pLeft = nullptr;
    pNode->pRight = nullptr;
    
    // If first node to insert in the tree
    if (*ppRoot == nullptr)
    {
        *ppRoot = pNode;
        return;
    }
    
    BSTNode* pParentNode = nullptr;
    BSTNode* pCurrentNode = *ppRoot;

    while (pCurrentNode != nullptr)
    {
        pParentNode = pCurrentNode;

        if (value <= pCurrentNode->value)
        {
            if (pCurrentNode->pLeft == nullptr)
            {
                pCurrentNode->pLeft = pNode;
                break;
            }

            pCurrentNode = pCurrentNode->pLeft;
        }
        else
        {
            if (pCurrentNode->pRight == nullptr)
            {
                pCurrentNode->pRight = pNode;
                break;
            }

            pCurrentNode = pCurrentNode->pRight;
        }
    }
}

DLL_EXPORTS_IMPORT void PrintNodesInOrder(BSTNode* pRoot, vector<int>& vector)
{
    if (pRoot == nullptr)
    {
        return;
    }

    // Go left
    if (pRoot->pLeft != nullptr)
    {
        PrintNodesInOrder(pRoot->pLeft, vector);
    }

    // Print current node
    vector.push_back(pRoot->value);

    // Go right
    if (pRoot->pRight != nullptr)
    {
        PrintNodesInOrder(pRoot->pRight, vector);
    }
}