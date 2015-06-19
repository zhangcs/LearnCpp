/*******************************************
   File name: perf1a.c
   A simple example for performance
   By Chensong Zhang June/18/2015
********************************************/

#include <stdlib.h>

// main program here ...
int main()
{
  const int M = 10000000, N = 24;

  double *A, *x, *y;

  A = (double *)malloc(M*N*sizeof(double));
  x = (double *)malloc(N*sizeof(double));
  y = (double *)malloc(M*sizeof(double));
    
  for ( int j = 0; j < N; j++ ) {
    for ( int i = 0; i < M; i++ ) {
      y[i] += A[i*N+j] * x[j];
    }
  }

  free(A);
  free(x);
  free(y);
  
  return 0;
}
