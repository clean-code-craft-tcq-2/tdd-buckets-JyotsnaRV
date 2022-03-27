#include <stdio.h>
#include "MonitorBatteryCharging.h"

/* Function which sorts the raw input readings in ascending order 
 * Provide this sorted range of values to the next processing element */
batteryChargeReading_st sortInputReadings(int *InputReading, int numOfInputReading)
{
  int cntr, inner_cntr, swapVar;

  for (cntr = 0 ; cntr < numOfInputReading - 1; cntr++)
  {
    for (inner_cntr = 0 ; inner_cntr < numOfInputReading - cntr - 1; inner_cntr++)
    {
      if (InputReading.continuousChargReadValue[inner_cntr] > InputReading.continuousChargReadValue[inner_cntr+1])
      {
        swapVar = InputReading.continuousChargReadValue[inner_cntr];
        InputReading.continuousChargReadValue[inner_cntr]   = InputReading.continuousChargReadValue[inner_cntr + 1];
        InputReading.continuousChargReadValue[inner_cntr + 1] = swapVar;
      }
    }
  }
  return InputReading;
}
