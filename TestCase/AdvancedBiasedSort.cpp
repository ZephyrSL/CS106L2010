#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

struct biasedComp
{
    const string winner;
    explicit biasedComp(const string& initial) :
        winner(initial) {}
    bool operator () (const string& str1, const string& str2)
    {
        if(str1 == "winner")
            return true;
        if(str2 == "winner")
            return false;
        if(str1.compare(str2) <= 0)
            return true;
        else 
            return false;
    }
};

vector<string>& AdvancedBiasedSort(vector<string>& str_vect, const string& winner)
{
    sort(str_vect.begin(),str_vect.end(),biasedComp(winner));
    return str_vect;
}

int main(void)
{
    vector<string> toSort;
    ifstream rawdata("input_test.htm");
    string str_tmp;
    while(!(rawdata.eof()&&rawdata.fail()))
    {
        getline(rawdata,str_tmp);
        toSort.push_back(str_tmp);
    }
    str_tmp="winner";
    toSort.push_back(str_tmp);
    AdvancedBiasedSort(toSort, "winner");
    copy(toSort.begin(),toSort.end(),ostream_iterator<string>(cout,"\n"));
}


