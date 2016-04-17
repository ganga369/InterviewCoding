#include "stdafx.h"
#include "Permutations.h"

PERMUTATION void PrintPermutations(std::string& inputString, vector<std::string>& permutations)
{
	if (inputString.length() == 0)
	{
		return;
	}

	vector<int> usedVec;
	
	char* pszString = (char *)malloc(sizeof(char) * (inputString.length() + 1));	
	pszString[inputString.length()] = '\0';

	for (int i = 0; i < inputString.length(); i++)
	{
		usedVec.push_back(0);
	}
	
	Dfs(inputString, pszString, permutations, usedVec, 0);
}

PERMUTATION void Dfs(std::string& inputString, 
	char* pszCurrentString, 
	vector<std::string>& permutations, 
	vector<int> usedVector,
	int currentLength)
{
	// Full string is formed
	if (currentLength == inputString.length())
	{
		permutations.push_back(pszCurrentString);		
		return;
	}

	for (unsigned int i = 0; i < inputString.length(); i++)
	{
		vector<int> currentUsedVec;

		currentUsedVec.insert(currentUsedVec.begin(), usedVector.begin(), usedVector.end());	

		int value = inputString.at(i) - 'a';
		if (currentUsedVec.at(value) == 1)
		{
			continue;
		}

		currentUsedVec.at(value) = 1;		
		pszCurrentString[currentLength] = inputString.at(i);

		Dfs(inputString, pszCurrentString, permutations, currentUsedVec, currentLength + 1);
	}
}