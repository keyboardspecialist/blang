#pragma once

#include <stdint.h>

#ifdef BLANG_BUILD_64BIT
#   if !defined(__x86_64__) && !defined(_WIN64) && !defined(__amd64__)
#       pragma message "System is not 64-bit, ignoring BLANG_BUILD_64BIT"
#   else
#       if defined(__LP64__) && __LP64__
#           pragma message "Building for __LP64__; SizeType long"
            
#           define BLANG_SIZE long
#       elif defined(_WIN64)
#           pragma message "Building for _WIN64; SizeType long long"

#           define BLANG_SIZE long long

#       elif defined(__x86_64__)
#           pragma message "Targeting __x86_64__ instead. SizeType int64_t"

#           define BLANG_SIZE int64_t
#       endif


#       define BLANG_IS64       


#   endif
#else
#   pragma message "Building for 32-bit. SizeType int"
#   define BLANG_SIZE int
#endif



#define overrides virtual



namespace Blang
{
    typedef BLANG_SIZE SizeType;
}