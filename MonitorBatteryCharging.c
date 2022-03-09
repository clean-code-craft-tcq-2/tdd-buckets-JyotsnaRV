#include <stdio.h>
#include "MonitorBatteryCharging.h"

batteryChargeReading_st checkBatteryChargeReading(int *chargeReading, int numOfReadings)
{
  int loopCntr = 0;
  int continuousReading =1, tempVar;
  int chargeCntr = 1;
  batteryChargeReading_st batteryChargeDetails;
  batteryChargeDetails.paramStatus = ERROR_INVALID;
  tempVar = chargeReading[loopCntr];
  for(;loopCntr<(numOfReadings-1);loopCntr++)
  {
    if((tempVar+1) == chargeReading[loopCntr+1])
    {
      continuousReading++; /* denotes continuous reading are present */
      /* these below mwntioned array stores the set of continuous values recorded */
      batteryChargeDetails.continuousChargReadValue[chargeCntr-1] =  tempVar;
      batteryChargeDetails.continuousChargReadValue[chargeCntr] =  tempVar+1;
      chargeCntr+=2;
    }
    tempVar = chargeReading[loopCntr+1];
    batteryChargeDetails.paramStatus = OK_VALID;
  }

  batteryChargeDetails.continuousReadingCnt = continuousReading;
  batteryChargeDetails.totalReadingsCnt = loopCntr;
  return batteryChargeDetails;
}
