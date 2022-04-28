#include <stdio.h>
#include "MonitorBatteryCharging.h"

/* Function which sorts the raw input readings in ascending order 
 * Provide this sorted range of values to the next processing element */
void sortInputReadings(int *InputReading, int numOfInputReading)
{
  int cntr, inner_cntr, swapVar;

  for (cntr = 0 ; cntr < numOfInputReading - 1; cntr++)
  {
    for (inner_cntr = 0 ; inner_cntr < numOfInputReading - cntr - 1; inner_cntr++)
    {
      if (InputReading[inner_cntr] > InputReading[inner_cntr+1])
      {
        swapVar = InputReading[inner_cntr];
        InputReading[inner_cntr] = InputReading[inner_cntr + 1];
        InputReading[inner_cntr + 1] = swapVar;
      }
    }
  }

}

/* Function to return the absolute values in the array provided with both positive and negative elements */
void absoluteArray(int* values, int numberOfValues)
{
	for(int i =0; i<numberOfValues ; i++)
		((int*)values)[i] = abs(((int*)values)[i]);
}
