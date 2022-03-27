#include <stdio.h>
#include "MonitorBatteryCharging.h"

batteryChargeReading_st checkBatteryChargeReading(int *chargeReading, int numOfReadings)
{
  int loopCntr = 0;
  int loopCntr_1 = 0;
  int loopCntr_2 = 0;
  int tempVar;
  int chargeCntr = 1;
  batteryChargeReading_st batteryChargeDetails;
  batteryChargeDetails.paramStatus = ERROR_INVALID;
  
  /* Sort the raw user data in ascending order */
  sortInputReadings(chargeReading, numOfReadings);

  /* Below part of code performs the continuous range check 
   * Input is hence an already sorted array */
  tempVar = chargeReading[loopCntr];
  for(;loopCntr<(numOfReadings-1);)
  {

    for(;((tempVar == (chargeReading[loopCntr+1]-1))||(tempVar == (chargeReading[loopCntr+1])));)
    {
      /* The arrays store the set of continuous values recorded */

      batteryChargeDetails.continuousChargeReadValueCnt[loopCntr_1][loopCntr_2] = tempVar;
      batteryChargeDetails.continuousChargeReadValueCnt[loopCntr_1][loopCntr_2+1] = tempVar+1;
      
        batteryChargeDetails.continuousReadingCnt[loopCntr_1] += 1; /* denotes that continuous reading is present */

        loopCntr += 1;
        tempVar = chargeReading[loopCntr];

        loopCntr_2+=1;

        printf("\n");
    }

    printf("Count of the continuous range-%d: %d\n",loopCntr_1+1,batteryChargeDetails.continuousReadingCnt[loopCntr_1]+1);
    
    loopCntr += 1;
    tempVar = chargeReading[loopCntr];

    loopCntr_1 +=1;
    loopCntr_2 = 0;
    batteryChargeDetails.paramStatus = OK_VALID;
  }
 return batteryChargeDetails;  
}
