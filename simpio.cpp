/*
 * File: simpio.cpp
 * Last modified 
 * -------------------------------------------------------------
 *  This is a simple package of functions that simplify the reading
 *  of console input
 *  Mainly from Stanford course CS106L
 */

#include "genlib.h"
#include "simpio.h"

/*
 * Function: GetInteger
 * Usage: n = GetInteger();
 * ------------------------
 * GetInteger reads a line of text from standard input and scans
 * it as an integer.  The integer value is returned.  If an
 * integer cannot be scanned or if more characters follow the
 * number, the user is given a chance to retry.
 */

int GetInteger(){
    while(true) // Read input until obtain a valid integer
    {
        stringstream converter;
        converter << GetLine();
        
        /* TODO
         * some processing here
         */
        
        // Try reading an integer, continue if succeed
        int result;
        converter >> result;
        
        if( !converter.fail()){
            // Check whether there is any leftover data
            char remaining;
            converter >> remaining;
            if( converter.fail()){
                // This is no remaining data
                return result;
            }
            else{
                cout << "Unexpected character: " << remaining << endl;
            }
        }
        cout << "The input is not a legal integer" << endl;
        cout << "Retry:";
    }
}

/*
 * Function: GetLong
 * Usage: n = GetLong();
 * ---------------------
 * GetLong reads a line of text from standard input and scans
 * it into a long integer.  The long is returned.  If the
 * number cannot be scanned or if extra characters follow it,
 * the user is given a chance to retry.
 */

long GetLong(){
    while(true) // Read input until obtain a valid integer
    {
        stringstream converter;
        converter << GetLine();
        
        // Try reading an integer, continue if succeed
        long result;
        converter >> result;
        
        if( !converter.fail()){
            // Check whether there is any leftover data
            char remaining;
            converter >> remaining;
            if( converter.fail()){
                // This is no remaining data
                return result;
            }
            else{
                cout << "Unexpected character: " << remaining << endl;
            }
        }
        cout << "The input is not a legal long integer" << endl;
        cout << "Retry:";
    }
}



/*
 * Function: GetReal
 * Usage: x = GetReal();
 * ---------------------
 * GetReal reads a line of text from standard input and scans
 * it as a double.  If the number cannot be scanned or if extra
 * characters follow after the number ends, the user is given
 * a chance to reenter the value.
 */

double GetReal(){
    while(true) // Read input until obtain a valid integer
    {
        stringstream converter;
        converter << GetLine();
        
        // Try reading an integer, continue if succeed
        double result;
        converter >> result;
        
        if( !converter.fail()){
            // Check whether there is any leftover data
            char remaining;
            converter >> remaining;
            if( converter.fail()){
                // This is no remaining data
                return result;
            }
            else{
                cout << "Unexpected character: " << remaining << endl;
            }
        }
        cout << "The input is not a legal double" << endl;
        cout << "Retry:";
    }
}



/*
 * Function: GetLine
 * Usage: s = GetLine();
 * ---------------------
 * GetLine reads a line of text from standard input and returns
 * the line as a string.  The newline character that terminates
 * the input is not stored as part of the string that is returned.
 */

string GetLine(){
    // TODO
    // There should be a test about the state of cin stream
    // to ensure it is not in fail state

    string result;
    getline(cin, result);
    return result;
}
