
#ifndef FLATTEN_BST_TO_DLL_EXPORTS
#define FLATTEN_BST_TO_DLL __declspec(dllexport)
#else
#define FLATTEN_BST_TO_DLL __declspec(dllimport)
#endif

#include "BinaryTree.h"

FLATTEN_BST_TO_DLL void FlattenBSTToDLL(BSTNode* pRoot, BSTNode** ppHead, BSTNode** ppTail);
