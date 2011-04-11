#define DISABLE_ALL_CS106L_DEBUG
#include "CS106LDebug.h"

int main(){
    int *ptr = NULL;
    // CS106LAssert(ptr != NULL);
    CS106LVerify( ptr != NULL);
    
    
    cout << "Not Abort!" << endl;

    return 0;
}
