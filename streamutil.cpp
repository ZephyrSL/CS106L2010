/* Practises of Stanford CS106L
 * Chapter 3 - streams
 * This interface provides some kinda utilities to deal with streams
 * -----------------------------------------------------------------
 *  Author : Stephen Li
 */

#include "simpio.h"
#include "streamutil.h"

string ExtractFirstToken( stringstream& input){
    string result;
    input >> result;
    return result;
}

bool HasHexLetters( int input){
    stringstream hexstr;
    cout << "Input in Hex string: " << hex << input << endl;
    hexstr << hex << input << endl;

    while(!hexstr.eof()){
        char temp;
        hexstr >> dec >> temp;
        if( !(temp >= '0' && temp <= '9')){
            // The temp char is not Dec form
            return true;
        }
    }

    return false;
}
