#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Span{
    int start, stop;
    Span(int begin, int end) : 
        start(begin), stop(end) {}
};

class CString
{
    public:
        CString();
        ~CString();
        CString(const string& other);
        CString(const char* other);
        CString(const CString& other);
        CString& operator =(const CString& other);

        char& operator [] (const int& index);
        const char& operator [] (const int& index) const;
        CString operator [] (const Span& range);

        void strPrint();

    private:
        void clear();
        void copyOther(const CString& other);

        char *theString;
        
};

CString :: CString()
{
    theString = NULL;
}

CString :: ~CString()
{
    clear();
}

CString :: CString(const char* other)
{
    theString = new char[strlen(other)+1];
    strcpy(theString, other);
}

CString :: CString(const string& other)
{
    theString = new char[other.size()+1];
    strcpy(theString,other.c_str());
}

CString :: CString(const CString& other)
{
    copyOther(other);
}

CString& CString :: operator =(const CString& other)
{
    if(this != &other)
    {
        clear();
        copyOther(other);
    }

    return *this;
}

void CString :: clear()
{
    delete [] theString;
    theString = NULL;
}

void CString :: copyOther(const CString& other)
{
    theString = new char[strlen(other.theString)+1];
    strcpy(theString, other.theString);
}

void CString :: strPrint()
{
    printf("%s\n",theString);
}

char& CString :: operator [] (const int& index)
{
    return *(theString+index);
}

const char& CString :: operator [] (const int& index) const
{
    return *(theString+index);
}

CString CString :: operator [] (const Span& range)
{
    int copyLenge = range.stop-range.start;
    char *subStr = new char [copyLenge+1];
    strncpy(subStr,theString+range.start,copyLenge);
    subStr[copyLenge]='\0';
    return CString(subStr);
}

int main(void)
{
    string cppstr("This is a string.");
    char *cstr="This is a C-string.";
    CString Cstr(cstr), Cppstr(cppstr);
    CString Copystr(Cstr);
    CString Assnstr;
    Assnstr=Cppstr;
    Cstr.strPrint();
    Cppstr.strPrint();
    Copystr.strPrint();
    Assnstr.strPrint();
    cout << Cstr[0] << Cppstr[10] << endl;
    Span range(5,15);
    Cppstr[range].strPrint();

    return 0;
}
