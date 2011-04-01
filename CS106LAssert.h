#ifndef _CS106LASSERT_H
#define _CS106LASSERT_H

#ifndef NO_CS106L_ASSERT

#include <cstdlib>

void DoCS106LAssert(bool invariant, string statement, string file, int line)
{
    if(!invariant)
    {
        cerr << "CS106LAssert Failed!" << endl;
        cerr << "Expression: " << statement << endl;
        cerr << "File: " << file << endl;
        cerr << "Line: " << line << endl;
        abort();
    }
}

#define CS106LAssert(expr) DoCS106LAssert(expr, #expr, __FILE__, __LINE__)

#else //Disable assertions

#define CS106LAssert(expr) 

#endif
//#endif
#endif // for #ifndef _CS106LASSERT_H
