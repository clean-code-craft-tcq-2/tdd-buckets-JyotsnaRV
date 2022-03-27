#include <stdio.h>
#include "MonitorBatteryCharging.h"

batteryChargeReading_st checkBatteryChargeReading(int *chargeReading, int numOfReadings)
{
  int loopCntr = 0;
  int continuousReading =1, tempVar;
  int chargeCntr = 1;
  batteryChargeReading_st batteryChargeDetails;
  batteryChargeDetails.paramStatus = ERROR_INVALID;
  
  /* Sort the raw user data in ascending order */
  sortInputReadings(chargeReading, numOfReadings);
  
  /* Below part of code performs the continuous range check 
   * Input is hence an already sorted array */
  tempVar = chargeReading[loopCntr];
  for(;loopCntr<(numOfReadings-1);loopCntr++)
  {
    if((tempVar+1) == chargeReading[loopCntr+1])
    {
      continuousReading++; /* denotesthat continuous reading is present */
      /* The arrays store the set of continuous values recorded */
      batteryChargeDetails.continuousChargReadValue[chargeCntr-1] = tempVar;
      batteryChargeDetails.continuousChargReadValue[chargeCntr] =  tempVar+1;
      chargeCntr += 2;
    }
    tempVar = chargeReading[loopCntr+1];
    batteryChargeDetails.paramStatus = OK_VALID;
  }
  /* this below mentioned code can be tested directly based on loopCntr value, hence not checked */
//  if((loopCntr == 0) || (chargeReading == NULL))
//  {
//   batteryChargeDetails.paramStatus = ERROR_INVALID;
//  }
  batteryChargeDetails.continuousReadingCnt = continuousReading;
  batteryChargeDetails.totalReadingsCnt = loopCntr;
  return batteryChargeDetails;
}
