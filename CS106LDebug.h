#ifndef _CS106LDEBUG_H
#define _CS106LDEBUG_H
#ifdef DISABLE_ALL_CS106L_DEBUG
#define NO_CS106L_ASSERT
#define NO_CS106L_VERIFY
#define NO_CS106L_NOTREACHED
#endif

#include <cstdlib>
#include "genlib.h"
#include "CS106LAssert.h"
#include "CS106LVerify.h"
#include "CS106LNotReached.h"

#endif // for #ifndef _CS106LDEBUG_H
