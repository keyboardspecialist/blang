#pragma once

#include <cstdio>

#if defined(BLANG_LOGGING)

#	if !defined(BLANG_LOG_LEVEL)
#		define BLANG_LOG_LEVEL 0
#		pragma message "BLANG_LOG_LEVEL not defined. Defaulting to error output only. -1 to disable all"
#	endif

#	if BLANG_LOG_LEVEL >= 0

#		define LOG(out, msg, ...) fprintf(out, msg, ##__VA_ARGS__);

#		define LOG_ERR(msg, ...) LOG(stderr, msg, ##__VA_ARGS__);

#	endif

#	if BLANG_LOG_LEVEL >= 1

#		define LOG_MSG(msg, ...) LOG(stdout, msg, ##__VA_ARGS__);

#	endif

#endif



#if !defined(LOG)
#	define LOG 0
#endif

#if !defined(LOG_MSG)
#	define LOG_MSG 0
#endif

#if !defined(LOG_ERR)
#	define LOG_ERR 0
#endif