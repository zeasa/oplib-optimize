#include <stdio.h>
#include <stdlib.h>

#define A( i, j )       a[ (j)*lda + (i) ]
#define B( i, j )       b[ (j)*ldb + (i) ]
#define abs( x )        ( (x) < 0.0 ? -(x) : (x) )

double compare_matrix( int m, int n, double *a, int lda, double *b, int ldb )
{
  int i, j;
  double max_diff = 0.0, diff;

  for ( j=0; j<n; j++ )
    for ( i=0; i<m; i++ ){
      diff = abs( A( i,j ) - B( i,j ) );
      max_diff = ( diff > max_diff ? diff : max_diff );
    }

  return max_diff;
}

void copy_matrix( int m, int n, double *a, int lda, double *b, int ldb )
{
  int i, j;

  for ( j=0; j<n; j++ )
    for ( i=0; i<m; i++ )
      B( i,j ) = A( i,j );
}

void print_matrix( int m, int n, double *a, int lda )
{
  int i, j;

  for ( j=0; j<n; j++ ){
    for ( i=0; i<m; i++ )
      printf("%le ", A( i,j ) );
    printf("\n");
  }
  printf("\n");
}

void random_matrix( int m, int n, double *a, int lda )
{
  double drand48();
  int i,j;

  for ( j=0; j<n; j++ )
    for ( i=0; i<m; i++ )
      A( i,j ) = 2.0 * drand48( ) - 1.0;
}

