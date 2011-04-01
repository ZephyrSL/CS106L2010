#ifndef _CS106LNOTREACHED_H
#define _CS106LNOTREACHED_H
//#ifndef CS106LNOTREACHED_H
//#define CS106LNOTREACHED_H

#ifndef NO_CS106L_NOTREACHED

void DoCS106LNotReached(string errorlog, string file, int line)
{
    // For any call, abort from the run time
    cerr << "CS106LNotReached Failed!" << endl;
    cerr << "Statement: " << errorlog << endl;
    cerr << "File: " << file << endl;
    cerr << "Line: " << line << endl;
    abort();
}

#define CS106LNotReached(expr) DoCS106LNotReached(expr, __FILE__, __LINE__)

#else

#define CS106LNotReached(expr) 

#endif
//#endif
#endif // for #ifndef _CS106LNOTREACHED_H
