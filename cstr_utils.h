#ifndef _CSTR_UTILS_H
#define _CSTR_UTILS_H

#include <cstdlib>
#include <cstring>
#include <cctype>
#include "genlib.h"

bool TruncateString(char *, int);

char *StringDuplicate(char *);

int CountFrequency(const char*, char);

char *GetSubstring(const char*, int, int);

bool StrCaseEqual(const char*, const char*);

char *CreateRepetitiveString(char chr, int length);
#endif // for #ifndef _CSTR_UTILS_H

