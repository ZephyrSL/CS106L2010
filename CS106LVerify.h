#ifndef _CS106LVERIFY_H
#define _CS106LVERIFY_H
// #ifndef CS106LVERIFY_H
// #define CS106LVERIFY_H

void DoCS106LVerify(bool invariant, string statement, string file, int line)
{
    if(!invariant)
    {
        cerr << "CS106LVerify Failed!" << endl;
        cerr << "Expression: " << statement << endl;
        cerr << "File: " << file << endl;
        cerr << "Line: " << line << endl;
        #ifndef NO_CS106L_VERIFY
        abort();
        #else
        //cout << "Not abort!" << endl;
        #endif
    }
}

#define CS106LVerify(expr) DoCS106LVerify(expr, #expr, __FILE__, __LINE__)

// #endif
#endif // for #ifndef _CS106LVERIFY_H
