
#include "stdafx.h"
#include "SinglyLinkedList.h"
#include "AddTwoLinkedLists.h"
#include "ReverseLinkedList.h"

ADD_SINGLELINKEDLIST_API void AddTwoLinkedLists(SinglyLinkedList* pList1, SinglyLinkedList* pList2, SinglyLinkedList** ppTotalList)
{
    if (pList1 == nullptr && pList2 == nullptr)
    {
        return;
    }

    ReverseLinkedList(&pList1);
    ReverseLinkedList(&pList2);

    SinglyLinkedList* pNode1 = pList1;
    SinglyLinkedList* pNode2 = pList2;
    unsigned int carry = 0;

    while (pNode1 != nullptr && pNode2 != nullptr)
    {
        unsigned int newValue = (pNode1->value + pNode2->value + carry) % 10;
        carry = (pNode1->value + pNode2->value + carry) / 10;
        
        AddNodeAtStart(ppTotalList, newValue);

        pNode1 = pNode1->pNext;
        pNode2 = pNode2->pNext;
    }
    
    SinglyLinkedList* pRemainingList = nullptr;
    if (pNode1 != nullptr)
    {
        pRemainingList = pNode1;
    }
    else if (pNode2 != nullptr)
    {
        pRemainingList = pNode2;
    }

    while (pRemainingList != nullptr)
    {
        unsigned int newValue = (pRemainingList->value + carry) % 10;
        carry = (pRemainingList->value + carry) / 10;

        AddNodeAtStart(ppTotalList, newValue);

        pRemainingList = pRemainingList->pNext;
    }

    // Create a new node at the end if there is a carry remaining
    if (carry == 1)
    {
        AddNodeAtStart(ppTotalList, 1);
    }

    // Restore the original lists
    ReverseLinkedList(&pList1);
    ReverseLinkedList(&pList2);
}

ADD_SINGLELINKEDLIST_API void SwapElementsPairWise(SinglyLinkedList** ppList)
{
    if (*ppList == nullptr)
    {
        return;
    }

    SinglyLinkedList* pCurrentNode = *ppList;
    SinglyLinkedList* pNextNode = (*ppList)->pNext;
    SinglyLinkedList* pPrevNode = nullptr;

    bool headPtrChanged = false;

    while (pCurrentNode != nullptr && pNextNode != nullptr)
    {
        SinglyLinkedList* pNextToNextNode = pNextNode->pNext;

        pNextNode->pNext = pCurrentNode;
        pCurrentNode->pNext = pNextToNextNode;

        if (pPrevNode != nullptr)
        {
            pPrevNode->pNext = pNextNode;
        }

        if (!headPtrChanged)
        {
            headPtrChanged = true;
            *ppList = pNextNode;
        }

        // Set up the pointers for the next iteration
        pPrevNode = pCurrentNode;
        pCurrentNode = pNextToNextNode;
        if (pNextToNextNode != nullptr)
        {
            pNextNode = pNextToNextNode->pNext;
        }
    }
}

ADD_SINGLELINKEDLIST_API void MergedLinkedListsWithAlternateNodes(SinglyLinkedList* pList1, SinglyLinkedList** ppList2)
{
    SinglyLinkedList* pTempNode1 = nullptr;
    SinglyLinkedList* pTempNode2 = nullptr;

    SinglyLinkedList* pList2 = *ppList2;

    while (pList1 != nullptr && pList2 != nullptr)
    {
        pTempNode1 = pList1->pNext;
        pTempNode2 = pList2->pNext;

        pList1->pNext = pList2;
        pList2->pNext = pTempNode1;

        pList1 = pTempNode1;
        pList2 = pTempNode2;
    }

    *ppList2 = pList2;
}