#include "genlib.h"
#include "simpio.h"
#include <iostream>
#include <string>

int main(){
    string str;
    int num;
    cout << "Input a string: " << endl;
    str = GetLine();
    cout << "Input an integer: " << endl;
    num = GetInteger();
    cout << str << "and " << num << endl;

    return 0;
}

