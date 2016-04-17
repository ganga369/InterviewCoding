
#ifndef DOUBLELINKEDLIST_EXPORTS
#define DOUBLELINKEDLIST __declspec(dllexport)
#else
#define DOUBLELINKEDLIST __declspec(dllimport)
#endif


struct DNode
{
	int value;
	struct DNode* pPrevious;
	struct DNode* pNext;
};

typedef struct DNode DNode;
