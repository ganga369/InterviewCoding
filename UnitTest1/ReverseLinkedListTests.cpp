#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

#include "..\SquareRoot\ReverseLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(SinglyLinkedListClass)
    {
    private:

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

            VertifyNodes(pList, vec);
        }

    };
}