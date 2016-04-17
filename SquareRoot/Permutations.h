
#ifndef PERMUTATION_EXPORTS
#define PERMUTATION __declspec(dllexport)
#else
#define PERMUTATION __declspec(dllimport)
#endif

#include <vector>
#include <string>

using namespace std;


PERMUTATION void PrintPermutations(std::string& inputString, vector<std::string>& permutations);

PERMUTATION void Dfs(std::string& inputString,
	char* currentString,
	vector<std::string>& permutations,
	vector<int> usedVector,
	int currentLength);
