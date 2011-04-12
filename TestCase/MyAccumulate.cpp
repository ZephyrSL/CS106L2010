#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

struct intAddition
{
    int sum;
    const int threshold;
    explicit intAddition (int initial) : 
        sum(0), threshold(initial) {}
    
    void operator () (int operand)
    {
        if(operand>=threshold)
            sum+=operand;
    }
};

int MyAccumulate(vector<int>::iterator begin, vector<int>::iterator end, int initial)
{
    return (for_each(begin, end, intAddition(initial))).sum;
}

int main(void)
{
    vector<int> toSum(100);
    for(int i=1;i<=100;++i)
    {
        toSum.push_back(i);
    }
    
    cout << MyAccumulate(toSum.begin(),toSum.end(),0) << endl;

    return 0;
}
