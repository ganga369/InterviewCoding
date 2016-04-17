#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\SquareRoot\AddTwoLinkedLists.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AddSinglyLinkedLists
{
    TEST_CLASS(AddSinglyLinkedListsClass)
    {
    private:
        void AssertTwoLinkedListsAdd(unsigned int value1, unsigned int value2, unsigned int expectedTotalVal)
        {
            SinglyLinkedList* pList1 = nullptr;
            while (value1 != 0)
            {
                AddNodeAtStart(&pList1, value1 % 10);
                value1 = value1 / 10;
            }

            SinglyLinkedList* pList2 = nullptr;
            while (value2 != 0)
            {
                AddNodeAtStart(&pList2, value2 % 10);
                value2 = value2 / 10;
            }

            SinglyLinkedList* pTotalList = nullptr;
            AddTwoLinkedLists(pList1, pList2, &pTotalList);

            vector<int>  tempVector;
            
            while (expectedTotalVal != 0)
            {
                tempVector.push_back(expectedTotalVal % 10);
                expectedTotalVal = expectedTotalVal / 10;
            }

            vector<int> expectedOutVector;
            vector<int> actualOutVector;
            for (vector<int>::reverse_iterator rItr = tempVector.rbegin(); rItr != tempVector.rend(); rItr++)
            {                
                expectedOutVector.push_back(*rItr);
            }

            PrintNodesToVector(pTotalList, actualOutVector);
            for (unsigned int i = 0; i < expectedOutVector.size(); i++)
            {
                Assert::AreEqual(expectedOutVector.at(i), actualOutVector.at(i));
            }
        }

    public:

        TEST_METHOD(TestAddOfTwoSameNumbers)
        {
            AssertTwoLinkedListsAdd(123, 123, 246);
        }

        TEST_METHOD(TestAddOfTwoNumbersWithSameSize)
        {
            AssertTwoLinkedListsAdd(123, 456, 579);
        }

        TEST_METHOD(TestAddWithFirstNumberZero)
        {
            AssertTwoLinkedListsAdd(0, 456, 456);
        }

        TEST_METHOD(TestAddWithSecondNumberZero)
        {
            AssertTwoLinkedListsAdd(456, 0, 456);
        }

        TEST_METHOD(TestAddWithDifferentSizes)
        {
            AssertTwoLinkedListsAdd(1111, 11, 1122);
        }

        TEST_METHOD(TestAddWithCarryTillTheEnd)
        {
            AssertTwoLinkedListsAdd(999, 99, 1098);
        }

        TEST_METHOD(TestAddWithCarryTillTheEndWithEqualNumbers)
        {
            AssertTwoLinkedListsAdd(9999, 9999, 19998);
        }
    };
}