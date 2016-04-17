
#ifndef _DECLSPEC_
#define DLL_EXPORTS_IMPORT __declspec(dllexport)
#else
#define DLL_EXPORTS_IMPORT __declspec(dllimport)
#endif

#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <vector>

using namespace std;

struct BInarySearchTreeNode
{
    int value;
    struct BInarySearchTreeNode* pLeft;
    struct BInarySearchTreeNode* pRight;
};

typedef struct BInarySearchTreeNode BSTNode;

DLL_EXPORTS_IMPORT void AddNode(BSTNode** ppRoot, int value);

DLL_EXPORTS_IMPORT void PrintNodesInOrder(BSTNode* pRoot, vector<int>& vector);

#endif