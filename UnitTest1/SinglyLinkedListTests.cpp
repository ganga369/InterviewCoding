#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

#include "..\SquareRoot\ReverseLinkedList.h"
#include "..\SquareRoot\AddTwoLinkedLists.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
    void CreateLinkedList(SinglyLinkedList** ppList, vector<int>& vec, bool insertAtStart)
    {
        for (unsigned int i = 0; i < vec.size(); i++)
        {
            if (insertAtStart)
            {
                AddNodeAtStart(ppList, vec.at(i));
            }
            else
            {
                AddNode(ppList, vec.at(i));
            }
        }
    }

    void VertifyNodes(SinglyLinkedList* pList, vector<int>& expectedOutputVec)
    {
        vector<int> actualOutputVec;
        PrintNodesToVector(pList, actualOutputVec);

        // verify both vectors are same

        Assert::AreEqual(expectedOutputVec.size(), actualOutputVec.size());

        for (unsigned int i = 0; i < expectedOutputVec.size(); i++)
        {
            Assert::AreEqual(expectedOutputVec.at(i), actualOutputVec.at(i));
        }
    }

    TEST_CLASS(SinglyLinkedListClass)
    {
    public:

        TEST_METHOD(TestInsertionAtEndIsCorrect)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(4);

            CreateLinkedList(&pList, vec, false);

            VertifyNodes(pList, vec);
        }

        TEST_METHOD(TestInsertionAtBeginningIsCorrect)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;
            vec.push_back(4);
            vec.push_back(3);
            vec.push_back(2);
            vec.push_back(1);

            CreateLinkedList(&pList, vec, true);

            vector<int> reverseVec;
            
            for (vector<int>::reverse_iterator rItr = vec.rbegin(); rItr != vec.rend(); rItr++)
            {
                reverseVec.push_back(*rItr);
            }

            VertifyNodes(pList, reverseVec);
        }

    };

    TEST_CLASS(ReverseLinkedListClass)
    {

    public:

        TEST_METHOD(TestReverseLinkedList)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(4);

            vector<int> reverseVec;

            for (vector<int>::reverse_iterator rItr = vec.rbegin(); rItr != vec.rend(); rItr++)
            {
                reverseVec.push_back(*rItr);
            }

            CreateLinkedList(&pList, vec, false);

            ReverseLinkedList(&pList);

            VertifyNodes(pList, reverseVec);
        }

        TEST_METHOD(TestReverseWithNoElements)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;

            CreateLinkedList(&pList, vec, false);
            Assert::IsNull(pList);

            ReverseLinkedList(&pList);
            Assert::IsNull(pList);

        }
    };

    TEST_CLASS(AddSinglyLinkedListsClass)
    {
    public:
        TEST_METHOD(TestSwapPairWithEvenElements)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(4);
            vec.push_back(5);
            vec.push_back(6);

            vector<int> swapVec;
            swapVec.push_back(2);
            swapVec.push_back(1);
            swapVec.push_back(4);
            swapVec.push_back(3);
            swapVec.push_back(6);
            swapVec.push_back(5);

            CreateLinkedList(&pList, vec, false);

            SwapElementsPairWise(&pList);

            VertifyNodes(pList, swapVec);
        }

        TEST_METHOD(TestSwapPairWithOddElements)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(4);
            vec.push_back(5);

            vector<int> swapVec;
            swapVec.push_back(2);
            swapVec.push_back(1);
            swapVec.push_back(4);
            swapVec.push_back(3);
            swapVec.push_back(5);            

            CreateLinkedList(&pList, vec, false);

            SwapElementsPairWise(&pList);

            VertifyNodes(pList, swapVec);
        }

        TEST_METHOD(TestSwapPairWithNoElements)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;

            CreateLinkedList(&pList, vec, false);

            SwapElementsPairWise(&pList);

            VertifyNodes(pList, vec);
        }

        TEST_METHOD(TestSwapPairWithSingleElement)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;
            vec.push_back(1);

            CreateLinkedList(&pList, vec, false);

            SwapElementsPairWise(&pList);

            VertifyNodes(pList, vec);
        }

        TEST_METHOD(TestSwapPairWithTwoElements)
        {
            SinglyLinkedList* pList = nullptr;
            vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);

            vector<int> swapVec;
            swapVec.push_back(2);
            swapVec.push_back(1);

            CreateLinkedList(&pList, vec, false);

            SwapElementsPairWise(&pList);

            VertifyNodes(pList, swapVec);
        }
    };

    TEST_CLASS(MergeAlternateNodes)
    {
    public:
        TEST_METHOD(TestMergeAlternateNodesWithEqualElements)
        {
            SinglyLinkedList* pList1 = nullptr;
            SinglyLinkedList* pList2 = nullptr;

            vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);
            vec1.push_back(3);
            vec1.push_back(4);

            vector<int> vec2;
            vec2.push_back(5);
            vec2.push_back(6);
            vec2.push_back(7);
            vec2.push_back(8);

            CreateLinkedList(&pList1, vec1, false);
            CreateLinkedList(&pList2, vec2, false);

            MergedLinkedListsWithAlternateNodes(pList1, &pList2);

            vector<int> outputVec1;
            outputVec1.push_back(1);
            outputVec1.push_back(5);
            outputVec1.push_back(2);
            outputVec1.push_back(6);
            outputVec1.push_back(3);
            outputVec1.push_back(7);
            outputVec1.push_back(4);
            outputVec1.push_back(8);

            vector<int> outputVec2;

            VertifyNodes(pList1, outputVec1);
            VertifyNodes(pList2, outputVec2);
        }

        TEST_METHOD(TestMergeAlternateNodesWithMoreElementsInFirstList)
        {
            SinglyLinkedList* pList1 = nullptr;
            SinglyLinkedList* pList2 = nullptr;

            vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);
            vec1.push_back(3);
            vec1.push_back(4);
            vec1.push_back(9);
            vec1.push_back(10);


            vector<int> vec2;
            vec2.push_back(5);
            vec2.push_back(6);
            vec2.push_back(7);
            vec2.push_back(8);

            CreateLinkedList(&pList1, vec1, false);
            CreateLinkedList(&pList2, vec2, false);

            MergedLinkedListsWithAlternateNodes(pList1, &pList2);

            vector<int> outputVec1;
            outputVec1.push_back(1);
            outputVec1.push_back(5);
            outputVec1.push_back(2);
            outputVec1.push_back(6);
            outputVec1.push_back(3);
            outputVec1.push_back(7);
            outputVec1.push_back(4);
            outputVec1.push_back(8);
            outputVec1.push_back(9);
            outputVec1.push_back(10);

            vector<int> outputVec2;

            VertifyNodes(pList1, outputVec1);
            VertifyNodes(pList2, outputVec2);
        }

        TEST_METHOD(TestMergeAlternateNodesWithMoreElementsInSecondList)
        {
            SinglyLinkedList* pList1 = nullptr;
            SinglyLinkedList* pList2 = nullptr;

            vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);
            vec1.push_back(3);
            vec1.push_back(4);

            vector<int> vec2;
            vec2.push_back(5);
            vec2.push_back(6);
            vec2.push_back(7);
            vec2.push_back(8);
            vec2.push_back(9);
            vec2.push_back(10);


            CreateLinkedList(&pList1, vec1, false);
            CreateLinkedList(&pList2, vec2, false);

            MergedLinkedListsWithAlternateNodes(pList1, &pList2);

            vector<int> outputVec1;
            outputVec1.push_back(1);
            outputVec1.push_back(5);
            outputVec1.push_back(2);
            outputVec1.push_back(6);
            outputVec1.push_back(3);
            outputVec1.push_back(7);
            outputVec1.push_back(4);
            outputVec1.push_back(8);

            vector<int> outputVec2;
            outputVec2.push_back(9);
            outputVec2.push_back(10);

            VertifyNodes(pList1, outputVec1);
            VertifyNodes(pList2, outputVec2);
        }

        TEST_METHOD(TestMergeAlternateNodesWithNullElements)
        {
            SinglyLinkedList* pList1 = nullptr;
            SinglyLinkedList* pList2 = nullptr;

            vector<int> vec1;
            vector<int> vec2;

            CreateLinkedList(&pList1, vec1, false);
            CreateLinkedList(&pList2, vec2, false);

            MergedLinkedListsWithAlternateNodes(pList1, &pList2);

            vector<int> outputVec1;
            vector<int> outputVec2;

            VertifyNodes(pList1, outputVec1);
            VertifyNodes(pList2, outputVec2);
        }

        TEST_METHOD(TestMergeAlternateNodesWithFirstListNullElements)
        {
            SinglyLinkedList* pList1 = nullptr;
            SinglyLinkedList* pList2 = nullptr;
           
            vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);
            vec1.push_back(3);
            
            vector<int> vec2;

            CreateLinkedList(&pList1, vec1, false);
            CreateLinkedList(&pList2, vec2, false);

            MergedLinkedListsWithAlternateNodes(pList1, &pList2);

            VertifyNodes(pList1, vec1);
            VertifyNodes(pList2, vec2);
        }

        TEST_METHOD(TestMergeAlternateNodesWithSecondListNullElements)
        {
            SinglyLinkedList* pList1 = nullptr;
            SinglyLinkedList* pList2 = nullptr;

            vector<int> vec1;

            vector<int> vec2;
            vec2.push_back(1);
            vec2.push_back(2);
            vec2.push_back(3);

            CreateLinkedList(&pList1, vec1, false);
            CreateLinkedList(&pList2, vec2, false);

            MergedLinkedListsWithAlternateNodes(pList1, &pList2);

            VertifyNodes(pList1, vec1);
            VertifyNodes(pList2, vec2);
        }
    };
}