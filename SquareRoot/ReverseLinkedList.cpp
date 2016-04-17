#include "stdafx.h"
#include "ReverseLinkedList.h"

REVERSE_LINKEDLIST_API void ReverseLinkedList(SinglyLinkedList** ppList)
{
    SinglyLinkedList* pCurrentNode = *ppList;

    if (pCurrentNode == nullptr)
    {
        return;
    }

    SinglyLinkedList* pPrevNode = nullptr;
    SinglyLinkedList* pNextNode = nullptr;
    while (pCurrentNode != nullptr)
    {
        pNextNode = pCurrentNode->pNext;
        pCurrentNode->pNext = pPrevNode;

        pPrevNode = pCurrentNode;
        pCurrentNode = pNextNode;
    }

    // New Head of the node
    *ppList = pPrevNode;
}