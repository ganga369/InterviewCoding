#include "stdafx.h"
#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

SINGLELINKEDLIST_API void AddNode(SinglyLinkedList** ppHead, int value)
{
    SinglyLinkedList* pNode = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));

    if (pNode == nullptr)
    {
        return;
    }
    pNode->value = value;
    pNode->pNext = nullptr;
    
    // If it's first node to insert
    if (*ppHead == nullptr)
    {
        *ppHead = pNode;       
    }
    else
    {
        SinglyLinkedList* pTempNode = *ppHead;

        while (pTempNode->pNext != nullptr)
        {
            pTempNode = pTempNode->pNext;
        }
        pTempNode->pNext = pNode;
    }

    return;
}

SINGLELINKEDLIST_API void AddNodeAtStart(SinglyLinkedList** ppHead, int value)
{
    SinglyLinkedList* pNode = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));

    if (pNode == nullptr)
    {
        return;
    }
    pNode->value = value;
    pNode->pNext = nullptr;

    // If it's first node to insert
    if (*ppHead == nullptr)
    {
        *ppHead = pNode;
    }
    else
    {
        pNode->pNext = *ppHead;
        *ppHead = pNode;
    }

    return;
}

SINGLELINKEDLIST_API void PrintNodesToVector(SinglyLinkedList* pHead, vector<int>& vec)
{
    while (pHead != nullptr)
    {
        vec.push_back(pHead->value);
        pHead = pHead->pNext;
    }
}