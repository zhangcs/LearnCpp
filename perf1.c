/*******************************************
   File name: perf1.c
   A simple example for performance
   By Chensong Zhang June/18/2015
********************************************/

// main program here ...
int main()
{
  const int M = 50000, N = 16;

  double A[M][N], x[N], y[M];

  for ( int j = 0; j < N; j++ ) {
    for ( int i = 0; i < M; i++ ) {
      y[i] += A[i][j] * x[j];
    }
  }
  
  return 0;
}

/* Note:

   gcc perf1.c -std=c99 -o perf.ex

   1. static allocation of arrays
   2. un-initialized arrays
   3. order of loops
   4. requires c99 standard
   5. lack of comments

 */
