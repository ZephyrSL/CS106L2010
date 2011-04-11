#include "genlib.h"
#include "cstr_utils.h"
#include "simpio.h"

int main(){
    char raw[]="What the hell is that!!!!"; 
    TruncateString(raw, strlen(raw));
    cout << string(raw) << endl;
    return 0;
}
