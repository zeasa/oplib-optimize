#ifndef _OPLIB_COMMON_H__
#define _OPLIB_COMMON_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>
//#include <mkl.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef  _DEBUG_
#define DEBUG_INFO(format, ...)		printf("[DEBUG]: " format, ##__VA_ARGS__)
#else
#define DEBUG_INFO(format, ...)
#endif

#define  FLOAT_T            float
#define  INT8_T             char
#if 0
typedef  char INT8VEC8_T    __attribute__ ((ext_vector_type(8)));        
typedef  char INT32VEC8_T   __attribute__ ((ext_vector_type(8)));
#endif

#define MEM_LAYOUT_NHWC     (0)
#define MEM_LAYOUT_NCHW     (1)
#define MEM_LAYOUT_NHWC8    (2)

#if 0
#define PROF_TMR_DECL()     struct timeval stime, etime, diff;double timeinsec, perf, time_st, time_end
#define PROF_TMR_START()    dtime = dclock()
#define PROF_TMR_END()      time_end = dsecnd();gettimeofday(&etime,NULL);timersub(&etime, &stime, &diff);timeinsec=(diff.tv_sec*1000+diff.tv_usec/1000)/1000.0;
#define PROF_TMR_VALSEC     (time_end - time_st)
#else
#define PROF_TMR_DECL()     double dtime
#define PROF_TMR_START()    dtime = dclock()
#define PROF_TMR_END()      dtime = dclock() - dtime
#define PROF_TMR_VALSEC     (dtime)
#endif

double compare_matrix(int m, int n, double *a, int lda, double *b, int ldb);
void copy_matrix(int m, int n, double *a, int lda, double *b, int ldb);
void print_matrix(int m, int n, double *a, int lda);
void random_matrix(int m, int n, double *a, int lda);

double dclock();

#ifdef __cplusplus
}
#endif
#endif /*_OPLIB_COMMON_H__*/
