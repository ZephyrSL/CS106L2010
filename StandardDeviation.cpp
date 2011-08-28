#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iterator>

using namespace std;

double StandardDeviation(const vector<double>& rawdata)
{
    vector<double> temp=rawdata;
    double avg = accumulate(temp.begin(), temp.end(), 0) / temp.size();
    transform(temp.begin(), temp.end(), temp.begin(), bind2nd(minus<double>(), avg));
    copy(temp.begin(), temp.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    transform(temp.begin(), temp.end(), temp.begin(), bind2nd(ptr_fun<double, double, double>(pow), 2.0));
    copy(temp.begin(), temp.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    return sqrt(accumulate(temp.begin(), temp.end(), 0) / temp.size());
}


int main(void)
{
    vector<double> temp;
    for(double i=0; i<5; i+=1.0)
    {
        temp.push_back(i);
    }
    copy(temp.begin(), temp.end(), ostream_iterator<double>(cout, " "));
    cout << "The StandardDeviation: " << StandardDeviation(temp) << endl;
    
    return 0;
}
