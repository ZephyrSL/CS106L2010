#include "X_Macro.h"

int main(){
    for(int count = 0; count<=8; count++){
        cout << GetColorName(Color(count)) << endl;
    }

    return 0;
}
