// This example prints the time elapsed since the program was invoked.
#include <time.h>
#include <stdio.h>

// use doubles to show small values
double timeValue, timeElapsed;

int main(void)
{
  // get initial time
  timeValue = (double)clock();
  // in seconds
  timeValue = timeValue / CLOCKS_PER_SEC;

  // call clock a second time
  timeElapsed = (((double)clock()) / CLOCKS_PER_SEC) - timeValue;
  printf("The elapsed time is %f seconds\n", timeElapsed);
}