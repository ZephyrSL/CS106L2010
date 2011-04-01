#include "STL_utils.h"
#include "simpio.h"
#include <cassert>

bool ReverseStack(stack<int>& stk)
{
    vector<int> vect_tmp;
    while(!stk.empty())
    {
      vect_tmp.push_back(stk.top());
      stk.pop();
    }
    
    for(vector<int>::iterator Itr = vect_tmp.begin();Itr != vect_tmp.end();++Itr)
    {
      stk.push(*Itr);
    }
    
    return true;
}

bool GenerateGeneralFibonacciNumbers(vector<int>& array, int init_1, int init_2)
{
    if(!array.size()==0)
    {
        cout << "The vector is not empty!" << endl;
        return false;
    }
    
    array.push_back(init_1);
    array.push_back(init_2);
    int tmp1, tmp2, sum;
    tmp1=init_1;
    tmp2=init_2;
    const int RUNTIME = 20;
    for(int i=2;i<=RUNTIME;i++)
    {
        sum=tmp1+tmp2;
        array.push_back(sum);
        tmp1 = tmp2;
        tmp2 = sum;
    }

    return true;
}

bool CycleQueue(queue<int>& que, int iteration)
{
    assert(iteration>=0);
    int count=iteration;
    while(count>0)
    {
        que.push(que.front());
        que.pop();
        count--;
    }
    return true;
}

bool CycleVector(vector<int>& vect, int iteration)
{
    assert(iteration>=0);
    vector<int>::size_type orig = vect.size();
    // Bug fixed:
    // the vector should be resize
    // before further manipulation
    vect.resize(orig+iteration);
    vector<int>::iterator itr=vect.begin();
    int count=iteration;
            
    while(count>0)
    {
       *(itr+orig)=*itr;
        ++itr;      
        count--;
    }
    vect.erase(vect.begin(), vect.begin()+iteration);
    return true;
}

bool CycleDeque(deque<int>& deq, int iteration)
{
    assert(iteration>=0);
    int count=iteration;
    while(count>0)
    {
        deq.push_back(deq.front());
        deq.pop_front();
        count--;
    }
    return true;
}

void ClockVectorInsert()
{
    // Input from file and generate a container
    // with string

    vector<string> strs;
    string str_tmp;
    // cout << "Please specify input file: ";
    // str_tmp=GetLine();
    // if(str_tmp=="\n")
    ifstream input("input_test.htm");
    // else
    //    ifstream input(str_tmp.c_str());
    
    if(!input.is_open())
    {
        cerr << "Failed in opening file: "
             << str_tmp << endl;
        return;
    }

    while(true)
    {
        str_tmp="";
        getline(input,str_tmp);
        if(input.eof()&&input.fail())
            break;
        strs.push_back(str_tmp);
    }
    
    vector<string>::size_type linenum=strs.size();
    
    // Clock with no reserve
    clock_t test_orig=clock();
    vector<string> vect;
    for(vector<string>::iterator itr=strs.begin();
        itr!=strs.end();
        ++itr)
    {
        vect.push_back(*itr);
    }
    test_orig=clock()-test_orig;


    clock_t test_rsv=clock();
    vector<string> vect_rsv;
    vect_rsv.resize(linenum);
    for(vector<string>::iterator itr=strs.begin();
        itr!=strs.end();
        ++itr)
    {
        vect_rsv.push_back(*itr);
    }
    test_rsv=clock()-test_rsv;
    
    cout << "Test without reserve: "
         << ((double)(test_orig)/CLOCKS_PER_SEC)
         << " seconds." << endl;
    cout << "Test with reserve: "
         << ((double)(test_rsv)/CLOCKS_PER_SEC)
         << " seconds." << endl;

}

bool CountLetters(ifstream& input, map<char,int>& table)
{
    char tmp;
    while(true)
    {
        input.get(tmp);
        if(input.eof()&&input.fail())
            break;
        table[tmp]+=1;
    }

    for(map<char,int>::iterator itr=table.begin();
        itr!=table.end();
        ++itr)
    {
        cout << itr->first <<" : " << itr->second << endl;
    }

    return true;
}

vector<int> SetSortVector(vector<int>& origin)
{
    multiset<int> bufset;
    for(vector<int>::iterator itr=origin.begin();
        itr!=origin.end();
        ++itr)
    {
        bufset.insert(*itr);
    }

    vector<int> sortedvect;
    sortedvect.reserve(origin.size());
    for(multiset<int>::iterator itr=bufset.begin();
        itr!=bufset.end();
        ++itr)
    {
        sortedvect.push_back(*itr);
    }

    return sortedvect;
}

vector<int> ListSortVector(vector<int>& origin)
{
    list<int> buflist;
    for(vector<int>::iterator itr=origin.begin();
        itr!=origin.end();
        ++itr)
    {
        buflist.push_back(*itr);
    }
    
    buflist.sort();
    vector<int> sortedvect;
    sortedvect.reserve(origin.size());
    for(list<int>::iterator itr=buflist.begin();
        itr!=buflist.end();
        ++itr)
    {
        sortedvect.push_back(*itr);
    }

    return sortedvect;
}

int NumUniqueCharacters(string& toCount)
{
    set<char> table(toCount.begin(),toCount.end());
    
    /*
    for(set<char>::iterator itr=table.begin();
        itr!=table.end();
        ++itr)
    {
        cout << *itr << endl;
    }
    */

    return table.size();

}

set<string> LoadAllTokens(string& filename)
{
    ifstream rawdata(filename.c_str());
    set<string> tokens;
    istream_iterator<string> rawitr(rawdata);
    istream_iterator<string> eos;
    insert_iterator<set<string> > tkitr(tokens,tokens.begin());
    while(rawitr!=eos)
    {
        *tkitr=*rawitr;
        ++tkitr;
        ++rawitr;
    }
    return tokens;
}
