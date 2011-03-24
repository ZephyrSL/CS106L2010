/* The implementations of some cstrings manipulation functions
 * Arthor: Stephen Li
 */
#include "cstr_utils.h"
 
bool TruncateString(char *str_ptr, int index)
{
    *(str_ptr+index)='\0';

    return true;
}

char *StringDuplicate(char *orig)
{
    int length = strlen(orig);
    char *result = new char[length+1];
    strcpy(result,orig);
    return result;
}

int CountFrequency(const char *str, char key)
{
    int length = strlen(str);
    int count = 0;
    for(int i=0;i<length;i++)
    {
        if(str[i]==key)
            count++;
    }
    return count;
}

char *GetSubstring(const char* source, int start, int length)
{
    char *result = new char[length];
    for(int i=0; i<length; i++)
    {
        result[i]=source[start+i];
    }
    return result;
}

bool StrCaseEqual(const char* str1, const char* str2)
{
    int count = 0;
    while(str1[count]!='\0'&&str2[count]!='\0')
    {
        char temp1=str1[count];
        char temp2=str2[count];
        if(isalpha(temp1)&&isalpha(temp2))
        {
            temp1=tolower(temp1);
            temp2=tolower(temp2);
        }

        if(temp1<temp2)
            return true;
        else if(temp1>temp2)
            return false;
        else
            count++;
    }

    if(str1[count]=='\0')
        return true;
    else if(str2[count]=='\0')
        return false; }
