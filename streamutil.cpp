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
    //stringstream input;
    //input << GetLine();
    input >> result;
    return result;
}
