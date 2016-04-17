#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>

#include "..\SquareRoot\SquareRoot.h"

#include "..\SquareRoot\Permutations.h"

#include "..\SquareRoot\Subsequence.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{		
	void combinationSum(int start, int currentSum, int totalSum, int k, vector<int> vec, vector<vector<int>>& outputVec)
	{
		if (currentSum == totalSum && vec.size() == k)
		{
			outputVec.push_back(vec);
			return;
		}

		if (currentSum > totalSum || vec.size() > k)
		{
			return;
		}

		for (int i = start; i <= 9; i++)
		{
			vector<int> currentVec;

			currentVec.insert(currentVec.begin(), vec.begin(), vec.end());
			currentVec.push_back(i);

			combinationSum(i + 1, currentSum + i, totalSum, k, currentVec, outputVec);
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {

		vector<vector<int>> outputVec;


		vector<int> vec;
		combinationSum(1, 0, n, k, vec, outputVec);

		return outputVec;
	}
	TEST_CLASS(UnitTest12)
	{		
        /*
        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(1, 0);
        }

        TEST_METHOD(TestMethod2)
        {
            CSquareRoot s;
            Assert::AreEqual(0.0, s.GetSquareRoot(25));
        }

        TEST_METHOD(TestMethod3)
        {
            CSquareRoot s;            
            Assert::AreEqual(1.0, s.GetSquareRoot(25));
        }

        TEST_METHOD(TestMethod4)
        {
            CSquareRoot s;
            Assert::AreEqual(1.0, (double)fnSquareRoot());
        }

        */

	public:

		TEST_METHOD(TestMethod1)
		{
			numDistinct("a", "b");
		}
	};
}