/*******************************************
   File name: perf2.c
   A simple example for performance
   By Chensong Zhang June/18/2015
********************************************/

// main program here ...
int main()
{
  const int M = 50000, N = 16;

  double A[M][N], x[N], y[M];

  for ( int i = 0; i < M; i++ ) {
    for ( int j = 0; j < N; j++ ) {
      y[i] += A[i][j] * x[j];
    }
  }
  
  return 0;
}
