#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void 
setup(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect problem_setup, N=%lld \n", N);
   for (int64_t i = 0; i < N; i++)
   {
      A[i] = i;
   }
   uint64_t temp;
   srand ( time(NULL) );
   for (int i = N-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}


int64_t
sum(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   int64_t count = 0;
   int64_t x = 0;
   for (int64_t i = 0; i < N; i++)
   {
      count += A[x];
      x = A[x];
   }

   return count;
}

