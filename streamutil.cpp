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

void GetBooleanWrapper( string& input){
    stringstream converter;
    converter << input;
    int counter = 0;

    while( !converter.eof()){
        string temp;
        bool result;
        converter >> temp;
        counter++;
        
        if( temp != "true" && temp != "false"){
            cout << "Invalid input " << counter << endl;
            continue;
        }

        result = GetBoolean( temp);

        cout << "Input " << counter 
             << " is " << boolalpha << result << endl;
    }
}

    

bool GetBoolean( string& input){
    if( input == "true")
        return true;
    if( input == "false")
        return false;
}

bool ExcludeInteger( string& filename){
    ifstream input;
    input.open(filename.c_str());
    if( !input.is_open()){
        cerr << "Failed in reading file: " << filename << endl;
        return false;
    }

    while( true){
        int tmpInt;
        input >> tmpInt;

        if( input.eof() && input.fail()) // Important here!
            break;

        if( input.fail()){
            input.clear();
            string tmpStr;
            input >> tmpStr;
        }
        else
            cout << tmpInt << " ";
    }

    return true;
}

bool Exaggerate(char *source){
    char *start = source;
    if(start == NULL){
        cerr << "Wrong input!" << endl;
        return false;
    }
    char *findPtr = NULL; 
    
    while(*(start)!='\0'){
        findPtr = strpbrk(start, "012345678");
        if(findPtr != NULL){
            *findPtr += 1;
            start = findPtr + 1;
        }
        else
            break;
    }
}
        
