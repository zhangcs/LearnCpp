#include <stdio.h>
#include <stdlib.h>

void main()
{
    const int N = 100000000;
    
    double *ap = malloc(N*sizeof(double)), *bp = malloc(N*sizeof(double));

    int i;

#if 1 // Optimized code: not necessary if -O2 flag is used

    double sum1 = 0, sum2 = 0, sum = 0, temp1 = 0, temp2 = 0;

    for ( i = 0; i < N/2-1; i++ ) {

        sum1 += temp1; temp1 = *(ap)   * *(bp);
        
        sum2 += temp2; temp2 = *(ap+1) * *(bp+1);

        ap += 2; bp += 2;

    }

    sum = sum1 + sum2;

#else // Better code: easy to understand 

    double sum; 
    for ( i = 0; i < N; i++ ) sum += ap[i] * bp[i];

#endif
}
