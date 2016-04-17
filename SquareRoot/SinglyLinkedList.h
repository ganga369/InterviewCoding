
#ifndef SINGLELINKEDLIST_EXPORTS
#define SINGLELINKEDLIST_API __declspec(dllexport)
#else
#define SINGLELINKEDLIST_API __declspec(dllimport)
#endif

#ifndef __SINGLE_LINKED_LIST__
#define __SINGLE_LINKED_LIST__

#include <vector>
using namespace std;

struct SinglyLinkedList
{
    int value;
    struct SinglyLinkedList* pNext;
};

typedef struct SinglyLinkedList SinglyLinkedList;
typedef struct SinglyLinkedList SNode;

SINGLELINKEDLIST_API void AddNode(SinglyLinkedList** ppHead, int value);

SINGLELINKEDLIST_API void AddNodeAtStart(SinglyLinkedList** ppHead, int value);

SINGLELINKEDLIST_API void PrintNodesToVector(SinglyLinkedList* pHead, vector<int>& vec);

#endif