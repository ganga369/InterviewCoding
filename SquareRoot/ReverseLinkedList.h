
#include "SinglyLinkedList.h"

#ifndef REVERSE_LINKEDLIST_EXPORTS
#define REVERSE_LINKEDLIST_API __declspec(dllexport)
#else
#define REVERSE_LINKEDLIST_API __declspec(dllimport)
#endif

REVERSE_LINKEDLIST_API void ReverseLinkedList(SinglyLinkedList** ppList);