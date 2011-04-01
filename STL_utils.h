#ifndef _STL_UTILS_H 
#define _STL_UTILS_H

#include <stack> 
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iterator>
#include "genlib.h"

bool ReverseStack(stack<int>& stk);

bool GenerateGeneralFibonacciNumbers(vector<int>& array, int init_1, int init_2);

bool CycleQueue(queue<int>&, int iteration);

bool CycleVector(vector<int>&, int iteration);

bool CycleDeque(deque<int>&, int iteration);

void ClockVectorInsert();

bool CountLetters(ifstream& input, map<char,int>& table);

vector<int> SetSortVector(vector<int>& origin);

vector<int> ListSortVector(vector<int>& origin);

int NumUniqueCharacters(string&);

set<string> LoadAllTokens(string& filenam);
#endif // for #ifndef _STL_UTILS_H


