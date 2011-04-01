#include "STL_utils.h"
#include "simpio.h"
#include "genlib.h"
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> vect;
    for ( int i = 0; i < 10; i++ )
    {
        vect.push_back ( i );
    }

    stack<int> stk_1,stk_2;
    for ( vector<int>::iterator itr = vect.begin();
            itr != vect.end();
            ++itr )
    {
        stk_1.push ( *itr );
        stk_2.push ( *itr );
    }

    cout << endl << "Original Stack: " << endl;
    while ( !stk_1.empty() )
    {
        cout << stk_1.top() << ", ";
        stk_1.pop();
    }

    ReverseStack ( stk_2 );
    cout << endl << "Reverse Stack: " << endl;
    while ( !stk_2.empty() )   
    {
        cout << stk_2.top() << ", ";
        stk_2.pop();
    }

    // Test cast of Fibonacci
    vector<int> array;
    GenerateGeneralFibonacciNumbers(array, 1, 2);
    cout << endl << "The Fibonacci numbers: " << endl; 
    for(vector<int>::iterator itr=array.begin();
        itr!=array.end();
        ++itr)
    {
        cout << *itr << ", ";
    }
    
    // Test cast of CycleQueue
    queue<int> que;
    for(vector<int>::iterator itr=array.begin();
        itr!=array.end();
        ++itr)
    {
        que.push(*itr);
    }
    CycleQueue(que, 10);
    cout << endl << "The cycled queue: " << endl;
    while(!que.empty())
    {
        cout << que.front() << ", ";
        que.pop();
    }
    
    // Test case of CycleVector
    vector<int> cyvect(array);
    CycleVector(cyvect, 5);
    cout << endl << "The cycled vector: " << endl;
    for(vector<int>::iterator itr=cyvect.begin();
        itr!=cyvect.end();
        ++itr)
    {
        cout << *itr << ", ";
    }

    // Test case of CycleDeque
    deque<int> cydeq;
    for(vector<int>::iterator itr=array.begin();
        itr!=array.end();
        ++itr)
    {
        cydeq.push_back(*itr);
    }
    CycleDeque(cydeq,10);
    cout << endl << "The cycled deque: " << endl;
    for(deque<int>::iterator itr=cydeq.begin();
        itr!=cydeq.end();
        ++itr)
    {
        cout << *itr << ", ";
    }
    cout << endl;

    ClockVectorInsert();

    ifstream testsource("input_test.htm");
    map<char,int> table;
    CountLetters(testsource,table);
    
    vector<int> sortedvect;
    // sortedvect=SetSortVector(cyvect);
    sortedvect=ListSortVector(cyvect);
    for(vector<int>::iterator itr=sortedvect.begin();
        itr!=sortedvect.end();
        ++itr)
    {
        cout << *itr << ", ";
    }

    string toCount;
    toCount=GetLine();
    cout << endl << "The num of unique characters: "
         << NumUniqueCharacters(toCount) << endl;

    string filename;
    filename=GetLine();
    set<string> tokens;
    tokens=LoadAllTokens(filename);
    for(set<string>::iterator itr=tokens.begin();
        itr!=tokens.end();
        ++itr)
    {
        cout << *itr << endl;
    }
    return 0;
}

