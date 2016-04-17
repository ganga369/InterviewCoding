
#ifndef SUBSEQUENCE_EXPORTS
#define SUBSEQUENCE __declspec(dllexport)
#else
#define SUBSEQUENCE __declspec(dllimport)
#endif

#include <vector>
#include <string>

using namespace std;


// LCS - Longest Common Subsequence
SUBSEQUENCE void FindLCS(const std::string& str1, const std::string& str2, std::string& lcs);

SUBSEQUENCE int numDistinct(const std::string&s, const std::string& t);