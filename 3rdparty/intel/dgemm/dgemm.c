/*******************************************************************************
!   Copyright(C) 2010-2012 Intel Corporation. All Rights Reserved.
!   
!   The source code, information  and  material ("Material") contained herein is
!   owned  by Intel Corporation or its suppliers or licensors, and title to such
!   Material remains  with Intel Corporation  or its suppliers or licensors. The
!   Material  contains proprietary information  of  Intel or  its  suppliers and
!   licensors. The  Material is protected by worldwide copyright laws and treaty
!   provisions. No  part  of  the  Material  may  be  used,  copied, reproduced,
!   modified, published, uploaded, posted, transmitted, distributed or disclosed
!   in any way  without Intel's  prior  express written  permission. No  license
!   under  any patent, copyright  or  other intellectual property rights  in the
!   Material  is  granted  to  or  conferred  upon  you,  either  expressly,  by
!   implication, inducement,  estoppel or  otherwise.  Any  license  under  such
!   intellectual  property  rights must  be express  and  approved  by  Intel in
!   writing.
!   
!   *Third Party trademarks are the property of their respective owners.
!   
!   Unless otherwise  agreed  by Intel  in writing, you may not remove  or alter
!   this  notice or  any other notice embedded  in Materials by Intel or Intel's
!   suppliers or licensors in any way.
!
!*******************************************************************************
!  Content:
!      Performance Measurement Example Program ( dgemm )
!******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <mkl.h>

#define FLOAT_TYPE double

int main(int argc, char* argv[])
{
   	struct timeval stime, etime, diff;
    double timeinsec, perf;
	
	FLOAT_TYPE* A;
	FLOAT_TYPE* B;
	FLOAT_TYPE* C;
    FLOAT_TYPE  alpha = 1.0, beta = 1.0;

	int m = 1024;
	int n = 2048;
	int k = 512;
    int LOOP_COUNT = 10;
    int i;

	if (argc >= 2) m = atoi(argv[1]);
	if (argc >= 3) n = atoi(argv[2]);
	if (argc >= 4) k = atoi(argv[3]);
	if (argc >= 5) LOOP_COUNT = atoi(argv[4]);

	char transa='N';
	char transb='N';

	A = (FLOAT_TYPE*) malloc(sizeof(double)*m*k);
	B = (FLOAT_TYPE*) malloc(sizeof(double)*k*n);
	C = (FLOAT_TYPE*) malloc(sizeof(double)*m*n);

	printf("Size of Matrix A(mxk): %d x %d\n", m, k);
	printf("Size of Matrix B(kxn): %d x %d\n", k, n);
	printf("Size of Matrix C(mxn): %d x %d\n", m, n);
	printf("LOOP COUNT           : %d \n", LOOP_COUNT);

	for (i=0; i<m*k ; ++i)
	{
		A[i] = 1.0;
	}

	for (i=0; i<k*n ; ++i)
	{
		B[i] = 2.0;
	}

	for (i=0; i<m*n ; ++i)
	{
		C[i] = 1.0;
	}

    /* first call for thread/buffer initialization */
    dgemm(&transa, &transb, &m, &n, &k, &alpha, A, &m, B, &k, &beta, C, &m);
	
	gettimeofday(&stime, NULL);
	double time_st  = dsecnd();
    for (i=0; i<LOOP_COUNT; ++i)
    {
        dgemm(&transa, &transb, &m, &n, &k, &alpha, A, &m, B, &k, &beta, C, &m);
    }
	double time_end = dsecnd() ;
	gettimeofday(&etime,NULL);
	timersub(&etime, &stime, &diff);
    timeinsec  = (diff.tv_sec*1000+diff.tv_usec/1000)/1000.0/ LOOP_COUNT;
	printf("Average time:%f secs from gettiemeofday \n", timeinsec);
	
    double time_avg = (time_end - time_st)/LOOP_COUNT;

	double gflop = (2.0*m*n*k + 1.0*m*n)*1E-9;

	printf("Average time:%e secs \n", time_avg);
	printf("GFlop       :%.5f \n", gflop);
	printf("GFlop/sec   :%.5f \n", gflop/time_avg);

	return 0;
}
