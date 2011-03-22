/* Practises of Stanford CS106L
 * Lecture 3 - streams
 * Lecture 5 - Problem set 0
 * This interface provides some kinda utilities to deal with streams
 * -----------------------------------------------------------------
 *  Author : Stephen Li
 */

#ifndef _streamutil_h
#define _streamutil_h

#include "genlib.h"
#include <cstring>


string ExtractFirstToken( stringstream& );

bool HasHexLetters( int);

void GetBooleanWrapper( string&);
bool GetBoolean( string&);

bool ExcludeInteger( string&);

bool Exaggerate(char *source);

#endif
