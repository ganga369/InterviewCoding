
#ifndef ADD_SINGLELINKEDLIST_EXPORTS
#define ADD_SINGLELINKEDLIST_API __declspec(dllexport)
#else
#define ADD_SINGLELINKEDLIST_API __declspec(dllimport)
#endif

#include "SinglyLinkedList.h"

ADD_SINGLELINKEDLIST_API void AddTwoLinkedLists(SinglyLinkedList* pList1, SinglyLinkedList* pList2, SinglyLinkedList** ppTotalList);

ADD_SINGLELINKEDLIST_API void SwapElementsPairWise(SinglyLinkedList** ppList);

ADD_SINGLELINKEDLIST_API void MergedLinkedListsWithAlternateNodes(SinglyLinkedList* pList1, SinglyLinkedList** ppList2);