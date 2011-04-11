#include "genlib.h"
#include "simpio.h"
#include "streamutil.h"

int main(){
    
    // Test case of simpio
    //string str;
    //int num;
    // cout << "Input a string: " << endl;
    // str = GetLine();
    // cout << "Input an integer: " << endl;
    // num = GetInteger();
    // cout << str << " and " << num << endl;
    // cout << " Input a double: " << endl;
    // double num = GetReal();
    // cout << "The input is: " << num << endl;

    /* Test case of ExtractFirstToken
    stringstream input;
    string result;
    cout << "Please input a space-separated string: " << endl;
    input << GetLine();
    result = ExtractFirstToken( input);
    cout << "The first token is: " << result << endl;
    */

    /* Test case of HasHexLetters
    int num;
    bool result;
    cout << "Please input an integer" << endl;
    num = GetInteger();
    result = HasHexLetters( num);
    cout << "Is this integer has character in Hex? " << endl << boolalpha << result << endl;
    */

    /* Test case of Getboolean
    string inputstr;
    inputstr = GetLine();
    GetBooleanWrapper( inputstr);
    */

    /* Test case of ExtractFirstToken
    string filename;
    filename = GetLine();
    bool result;
    result = ExcludeInteger(filename);
    cout << endl << "The running result is: " << boolalpha << result
         << endl;
    */

    // Test case of Exaggerate
    string input;
    cout << "Please input a string: ";
    input = GetLine();
    char *input_cpy = new char[input.length()+1];
    strcpy(input_cpy, input.c_str());
    bool result = Exaggerate(input_cpy);
    cout << input_cpy << endl;


    return 0;
}
