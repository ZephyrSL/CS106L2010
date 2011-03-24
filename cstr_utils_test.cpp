#include "genlib.h"
#include "cstr_utils.h"
#include "simpio.h"

int main(){
    int length=0;
    cout << "Please input an integer: " << endl;
    length=GetInteger();
    char *result=new char[length];
    result=CreateRepetitiveString('s',length);
    cout << string(result) << endl;
    return 0;
}
