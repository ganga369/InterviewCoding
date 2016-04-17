#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

#include "..\SquareRoot\BinaryTree.h"
#include "..\SquareRoot\FlattednBSTToDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace BinaryTree
{
    TEST_CLASS(BinaryTreeTestClass)
    {
    private:

        void AddNodes(BSTNode** ppRoot, vector<int> nodeValuesToInsert)
        {
            for each (int i in nodeValuesToInsert)
            {
                AddNode(ppRoot, i);
            }
        }

        void VerifyOrderSame(BSTNode* pRoot, vector<int> expectedOrder)
        {
            vector<int> originalOrder;

            PrintNodesInOrder(pRoot, originalOrder);

            Assert::AreEqual(originalOrder.size(), expectedOrder.size());

            for (unsigned int i = 0; i < originalOrder.size(); i++)
            {
                Assert::AreEqual(originalOrder.at(i), expectedOrder.at(i));
            }			
        }

		void VerifyDLL(BSTNode* pHead, BSTNode* pTail, unsigned int totalValues)
		{
			int i = 1;

			while (pHead != nullptr)
			{
				Assert::AreEqual(pHead->value, i);
				
				pHead = pHead->pRight;
				i++;
			}
			Assert::AreEqual(totalValues+1, static_cast<unsigned int>(i));

			i = totalValues;
			while (pTail != nullptr)
			{
				Assert::AreEqual(pTail->value, i);

				pTail = pTail->pLeft;
				i--;
			}
			Assert::AreEqual(0, i);
		}

    public:

        TEST_METHOD(BinaryTree_TestConstructionOfBinaryTree)
        {
            BSTNode* pRoot = nullptr;
            vector<int> vec;

            vec.push_back(4);

            vec.push_back(2);
            vec.push_back(1);
            vec.push_back(3);

            vec.push_back(6);
            vec.push_back(5);
            vec.push_back(7);

            AddNodes(&pRoot, vec);

            vector<int> outputVec;
            for (int i = 1; i <= 7; i++)
            {
                outputVec.push_back(i);
            }

            VerifyOrderSame(pRoot, outputVec);
        }

        TEST_METHOD(BinaryTree_TestNodesInAscendingOrder)
        {
            BSTNode* pRoot = nullptr;
            vector<int> vec;

            for (int i = 1; i <= 7; i++)
            {
                vec.push_back(i);
            }

            AddNodes(&pRoot, vec);

            VerifyOrderSame(pRoot, vec);
        }

        TEST_METHOD(BinaryTree_TestNodesInDescendingOrder)
        {
            BSTNode* pRoot = nullptr;
            vector<int> vec;            

            for (int i = 7; i >= 1; i--)
            {
                vec.push_back(i);
            }

            AddNodes(&pRoot, vec);

            vector<int> expectedOrder;

            for (int i = 1; i <= 7; i++)
            {
                expectedOrder.push_back(i);
            }

            VerifyOrderSame(pRoot, expectedOrder);
        }

		// Flattening Tests
		TEST_METHOD(Flatten_CompleteBST)
		{
			BSTNode* pRoot = nullptr;

			vector<int> vec;

			vec.push_back(4);
			
			vec.push_back(2);
			vec.push_back(1);
			vec.push_back(3);

			vec.push_back(6);
			vec.push_back(5);
			vec.push_back(7);

			AddNodes(&pRoot, vec);

			BSTNode* pHead = nullptr;
			BSTNode* pTail = nullptr;

			FlattenBSTToDLL(pRoot, &pHead, &pTail);
			VerifyDLL(pHead, pTail, vec.size());
		}

		TEST_METHOD(Flatten_NullTree)
		{
			
			BSTNode* pHead = nullptr;
			BSTNode* pTail = nullptr;

			FlattenBSTToDLL(nullptr, &pHead, &pTail);

			Assert::IsNull(pHead);
			Assert::IsNull(pTail);
		}

		TEST_METHOD(Flatten_RightOnlyTree)
		{
			BSTNode* pRoot = nullptr;

			vector<int> vec;

			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);
			vec.push_back(6);
			vec.push_back(7);

			AddNodes(&pRoot, vec);

			BSTNode* pHead = nullptr;
			BSTNode* pTail = nullptr;

			FlattenBSTToDLL(pRoot, &pHead, &pTail);
			VerifyDLL(pHead, pTail, vec.size());
		}

		TEST_METHOD(Flatten_LeftOnlyTree)
		{
			BSTNode* pRoot = nullptr;

			vector<int> vec;

			vec.push_back(7);
			vec.push_back(6);
			vec.push_back(5);
			vec.push_back(4);
			vec.push_back(3);
			vec.push_back(2);
			vec.push_back(1);

			AddNodes(&pRoot, vec);

			BSTNode* pHead = nullptr;
			BSTNode* pTail = nullptr;

			FlattenBSTToDLL(pRoot, &pHead, &pTail);
			VerifyDLL(pHead, pTail, vec.size());
		}
    };
}