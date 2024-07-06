/*
*                                                      _____  _________________       
* ___________________ __________ ________________      __  / / /_  /___(_)__  /_______
* _  ___/  __ \_  __ `__ \_  __ `__ \  __ \_  __ \     _  / / /_  __/_  /__  /__  ___/
* / /__ / /_/ /  / / / / /  / / / / / /_/ /  / / /     / /_/ / / /_ _  / _  / _(__  ) 
* \___/ \____//_/ /_/ /_//_/ /_/ /_/\____//_/ /_/      \____/  \__/ /_/  /_/  /____/  
*                                                                                     
*/

#ifndef __TRACE_IF_H__
#define __TRACE_IF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

/* TPT = Trace-Point Tracking */

#define TRACE_INFO		1
#define TRACE_ERROR		2
#define TRACE_ABN		3
#define TRACE_DEBUG		4

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

void tracepoint(const char *provider, const char *file, int line, int level, const char *format, ...);
void tracepoint_cpp(const char *provider, const char *file, int line, int level, const char *str);

#ifdef __cplusplus
#define TPT_TRACE(level, str) tracepoint_cpp(TPT_PROVIDER, __FILENAME__, __LINE__, (level), (str))
#else
#define TPT_TRACE(level, format, ...) tracepoint(TPT_PROVIDER, __FILENAME__, __LINE__, (level), (format), ##__VA_ARGS__)
#endif

#ifdef __cplusplus
}
#endif

#endif // __TRACE_IF_H__