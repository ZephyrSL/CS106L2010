#include "genlib.h"
#include "cstr_utils.h"
#include "simpio.h"

int main(){
    string str1, str2;
    cout << "string1: " << endl;
    str1=GetLine();
    cout << "string2: " << endl;
    str2=GetLine();
    bool result=StrCaseEqual(str1.c_str(),str2.c_str());
    cout << result << endl;
    return 0;
}
