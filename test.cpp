#include "genlib.h"
#include "simpio.h"
#include "streamutil.h"

using namespace std;

int main(){
    
    /* Test case of simpio
    string str;
    int num;
    cout << "Input a string: " << endl;
    str = GetLine();
    cout << "Input an integer: " << endl;
    num = GetInteger();
    cout << str << " and " << num << endl;
    */

    /* Test case of ExtractFirstToken
    stringstream input;
    string result;
    cout << "Please input a space-separated string: " << endl;
    input << GetLine();
    result = ExtractFirstToken( input);
    cout << "The first token is: " << result << endl;
    */

    // Test case of HasHexLetters
    int num;
    bool result;
    cout << "Please input an integer" << endl;
    num = GetInteger();
    result = HasHexLetters( num);
    cout << "Is this integer has character in Hex? " << endl << boolalpha << result << endl;

    return 0;
}
