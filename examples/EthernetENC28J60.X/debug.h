#ifndef _debug_h__
#define _debug_h__

#ifdef __debug__
#include <stdio.h>
#define DEBUG_MACRO_PRINT_FUNTION printf("%s\n",__func__);
#else // __debug__
#define DEBUG_MACRO_PRINT_FUNTION
#endif // __debug__

#endif //_debug_h__