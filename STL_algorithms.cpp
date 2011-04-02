#include "STL_algorithms.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

bool PrintVector(vector<int> toPrint)
{
    // ostream_iterator<int> outItr=(cout," ");
    // copy(toPrint.begin(),toPrint.end(),outItr);
    copy(toPrint.begin(),toPrint.end(),ostream_iterator<int>(cout," "));    

    return true;
}

static bool TooShort(string& toTest)
{
    const string::size_type THRESHOLD = 3;
    if(toTest.size()>=THRESHOLD)
        return false;
    else
        return true;
}

bool RemoveShortWords(vector<string> toRemove)
{
    remove_if(toRemove.begin(),toRemove.end(),TooShort);
    return true;
}

static double localSquare(double element)
{
    return element*element;
}

double DistanceToOrigin(vector<double> toSquare)
{
    vector<double> squared;
    squared.resize(toSquare.size());
    transform(toSquare.begin(),toSquare.end(),squared.begin(),localSquare);
    double sum=accumulate(squared.begin(),squared.end(),0.0);
    return sqrt(sum);
}

static bool localCompare(string str1, string str2)
{
    if(str1.compare("Me First")==0)
        return true;
    else if(str2.compare("Me First")==0)
        return false;
    else if(str1.compare(str2)<0)
        return true;
    else
        return false;
}

bool BiasedSort(vector<string>& toSort)
{
    sort(toSort.begin(),toSort.end(),localCompare);
    // sort(toSort.begin(),toSort.end());
    return true;
}

set<string> CriticsPick(map<string,double> toPick)
{
    map<double,string> Palmap;
    for(map<string,double>::iterator itr=toPick.begin();
        itr!=toPick.end();
        ++itr)
    {
        Palmap.insert(make_pair<double,string>(itr->second,itr->first));
    }

    set<string> topMovie;
    int count=0;
    for(map<double,string>::iterator itr=Palmap.begin();
        (itr!=Palmap.end())&&(count<10);
        ++itr,++count)
    {
        topMovie.insert(itr->second);
    }
    
    return topMovie;    
}

int CS106_count(vector<int>::iterator start, vector<int>::iterator end, int key)
{
    int cnt=0;
    for(vector<int>::iterator itr=start;
        itr!=end;
        ++itr)
    {
        if(*itr==key)
        {
            ++cnt;
        }
    }
    return cnt;
}
