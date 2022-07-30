#include <stdio.h>
#include <stdlib.h>
#include "oplib_common.h"
#include "oplib_interface.h"

/* 
In the test driver, there is a loop "for ( p=PFIRST; p<= PLAST; p+= PINC )"
The below parameters set this range of values that p takes on 
*/
#define PFIRST 40
#define PLAST  800
#define PINC   40

/* 
In the test driver, the m, n, and k dimensions are set to the below 
values.  If the value equals "-1" then that dimension is bound to the
index p, given above.
*/

#define M -1
#define N -1
#define K -1

/* 
In the test driver, each experiment is repeated NREPEATS times and
the best time from these repeats is used to compute the performance
*/

#define NREPEATS 2

/* 
Matrices A, B, and C are stored in two dimensional arrays with
row dimensions that are greater than or equal to the row dimension
of the matrix.  This row dimension of the array is known as the 
"leading dimension" and determines the stride (the number of 
double precision numbers) when one goes from one element in a row
to the next.  Having this number larger than the row dimension of
the matrix tends to adversely affect performance.  LDX equals the
leading dimension of the array that stores matrix X.  If LDX=-1 
then the leading dimension is set to the row dimension of matrix X.
*/

#define LDA 1000
#define LDB 1000
#define LDC 1000

int main()
{
	int
	    p,
	    m, n, k,
	    lda, ldb, ldc,
	    rep;

	double
	    dtime, dtime_best,
	    gflops,
	    diff;

	double
	    *a, *b, *c, *cref, *cold;

	printf("MY_MMult = [\n");

	for (p = PFIRST; p <= PLAST; p += PINC) {
		m = (M == -1 ? p : M);
		n = (N == -1 ? p : N);
		k = (K == -1 ? p : K);

		gflops = 2.0 * m * n * k * 1.0e-09;

		lda = (LDA == -1 ? m : LDA);
		ldb = (LDB == -1 ? k : LDB);
		ldc = (LDC == -1 ? m : LDC);

		/* Allocate space for the matrices */
		/* Note: I create an extra column in A to make sure that
		   prefetching beyond the matrix does not cause a segfault */
		a = (double *)malloc(lda * (k + 1) * sizeof(double));
		b = (double *)malloc(ldb * n * sizeof(double));
		c = (double *)malloc(ldc * n * sizeof(double));
		cold = (double *)malloc(ldc * n * sizeof(double));
		cref = (double *)malloc(ldc * n * sizeof(double));

		/* Generate random matrices A, B, Cold */
		random_matrix(m, k, a, lda);
		random_matrix(k, n, b, ldb);
		random_matrix(m, n, cold, ldc);

		copy_matrix(m, n, cold, ldc, cref, ldc);

		/* Run the reference implementation so the answers can be compared */

		REF_MMult(m, n, k, a, lda, b, ldb, cref, ldc);

		/* Time the "optimized" implementation */
		for (rep = 0; rep < NREPEATS; rep++) 
        {
			copy_matrix(m, n, cold, ldc, c, ldc);

			/* Time your implementation */
			dtime = dclock();

			MY_MMult(m, n, k, a, lda, b, ldb, c, ldc);

			dtime = dclock() - dtime;

			if (rep == 0)
				dtime_best = dtime;
			else
				dtime_best = (dtime < dtime_best ? dtime : dtime_best);
		}

		diff = compare_matrix(m, n, c, ldc, cref, ldc);

		printf("%d %le %le \n", p, gflops / dtime_best, diff);
		fflush(stdout);

		free(a);
		free(b);
		free(c);
		free(cold);
		free(cref);
	}

	printf("];\n");

	exit(0);
}
