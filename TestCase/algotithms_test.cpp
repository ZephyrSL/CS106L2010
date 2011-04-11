#include "STL_algorithms.h"
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    vector<int> toPrint;
    for(int i=0;i<50;++i)
    {
        toPrint.push_back(i);
    }
    PrintVector(toPrint);

    string dummy_str="Today is April's fool!";
    vector<string> dummy_strs;
    for(string::size_type count=1;
        count<=dummy_str.size();
        ++count)
    {
        dummy_strs.push_back(dummy_str.substr(0,count));
    }
    RemoveShortWords(dummy_strs);
    copy(dummy_strs.begin(),dummy_strs.end(),ostream_iterator<string>(cout,"\n"));
    
    vector<double> toSquare;
    cout << "The square sum of " << endl;
    for(double elem=1.0;elem<5.0;elem+=1.0)
    {
        toSquare.push_back(elem);
        cout << elem << ", ";
    }
    cout << "The result: " << DistanceToOrigin(toSquare) << endl;

    vector<string> toSort;
    const int LineNum=500;
    toSort.resize(LineNum);
    ifstream rawdata("input_test.htm");
    string str_tmp=" ";
    while(!(rawdata.eof()&&rawdata.fail()))
    {
        getline(rawdata,str_tmp);
        toSort.push_back(str_tmp);
    }
    str_tmp="Me First";
    toSort.push_back(str_tmp);
    BiasedSort(toSort);
    copy(toSort.begin(),toSort.end(),ostream_iterator<string>(cout,"\n"));

    ifstream moviedata("movie_rate");
    string movie_name;
    double movie_rate;
    map<string,double> toPick;
    while(!(moviedata.eof()&&moviedata.fail()))
    {
        moviedata >> movie_name >> movie_rate;
        toPick.insert(make_pair(movie_name,movie_rate));
    }
    
    set<string> pickedMovie;
    pickedMovie=CriticsPick(toPick);
    copy(pickedMovie.begin(),pickedMovie.end(),ostream_iterator<string>(cout,"\n"));

    cout << CS106_count(toPrint.begin(),toPrint.end(),20) << endl;

    return 0;
}
