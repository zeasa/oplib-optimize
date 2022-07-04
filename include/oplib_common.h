#ifndef _OPLIB_COMMON_H__
#define _OPLIB_COMMON_H__

#include <sys/time.h>
#include <mkl.h>

#ifdef  _DEBUG_
#define DEBUG_INFO(format, ...)		printf("[DEBUG]: " format, ##__VA_ARGS__)
#else
#define DEBUG_INFO(format, ...)
#endif

#define  FLOAT_T            float

#define MEM_LAYOUT_NHWC     (0)
#define MEM_LAYOUT_NCHW     (1)
#define MEM_LAYOUT_NHWC8    (2)

#define PROF_TMR_DECL()     struct timeval stime, etime, diff;double timeinsec, perf, time_st, time_end
#define PROF_TMR_START()    gettimeofday(&stime, NULL);time_st  = dsecnd()
#define PROF_TMR_END()      time_end = dsecnd();gettimeofday(&etime,NULL);timersub(&etime, &stime, &diff);timeinsec=(diff.tv_sec*1000+diff.tv_usec/1000)/1000.0;
#define PROF_TMR_VALSEC     (time_end - time_st)


#endif /*_OPLIB_COMMON_H__*/
