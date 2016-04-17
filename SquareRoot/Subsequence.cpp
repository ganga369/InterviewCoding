#include "stdafx.h"
#include "Subsequence.h"

SUBSEQUENCE void FindLCS(const std::string& str1, const std::string& str2, std::string& lcs)
{
	/*unsigned int length1 = str1.length();
	unsigned int length2 = str2..length();

	// For now create big array
	unsigned int arr[100][100] = { 0 };

	arr[0][0] = 0;
	for (unsigned int i = 1; i < length1; i++)
	{
		arr[0][i] = 0;
	}

	for (unsigned int i = 1; i < length2; i++)
	{
		arr[i][0] = 0;
	}

	for (unsigned i = 2; i < length1; i++)
	{
		for (unsigned j = 2; j < length2; j++)
		{
			// Set arr[i][j]
			if (str1.at(i) == str2.at(j))
			{

			}

		}
	}
	*/
}

SUBSEQUENCE int numDistinct(const std::string& s, const std::string& t) 
{

	int **dynamicArray;

	dynamicArray = new int *[s.length() + 1];

	for (unsigned int i = 0; i <= s.length(); i++)
	{
		dynamicArray[i] = new int[t.length() + 1];
	}

	for (unsigned int i = 0; i <= s.length(); i++)
	{
		dynamicArray[i][0] = 0;
	}

	for (unsigned int i = 0; i <= t.length(); i++)
	{
		dynamicArray[0][i] = 0;
	}

	unsigned int distinct = 0;

	for (unsigned int i = 1; i <= s.length(); i++)
	{
		for (unsigned int j = 1; j <= t.length(); j++)
		{
			if (s[i-1] == t[j-1])
			{
				dynamicArray[i][j] = dynamicArray[i - 1][j - 1] + 1;

				if (dynamicArray[i][j] == dynamicArray[i - 1][j] ||
					dynamicArray[i][j] == dynamicArray[i][j - 1]
					)
				{
					distinct += 1;
				}
			}
			else
			{
				dynamicArray[i][j] = max(dynamicArray[i][j - 1], dynamicArray[i - 1][j]);
			}
		}
	}

	if (dynamicArray[s.length()][t.length()] != 0)
	{
		distinct += 1;
	}

	return distinct;
}