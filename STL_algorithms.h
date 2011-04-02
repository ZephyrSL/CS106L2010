#ifndef _STL_ALGORITHMS_H
#define _STL_ALGORITHMS_H

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

bool PrintVector(vector<int>);

bool RemoveShortWords(vector<string>);

double DistanceToOrigin(vector<double>);

bool BiasedSort(vector<string>&);

set<string> CriticsPick(map<string,double> );

int CS106_count(vector<int>::iterator start, vector<int>::iterator end, int key);

#endif // for #ifndef _STL_ALGORITHMS_H
