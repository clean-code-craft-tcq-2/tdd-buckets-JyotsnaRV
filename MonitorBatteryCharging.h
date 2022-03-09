#ifndef  MONITORBATTERYCHARGING_H
#define  MONITORBATTERYCHARGING_H
/* Macro Declaration */
#define ARRINDEXSIZE 30

/* Enum declarations */
typedef enum
{
  OK_VALID,
  ERROR_INVALID
}retChargeReadingStatus_en;
/* Structure declarations */
typedef struct
{
  int continuousReadingCnt;
  int totalReadingsCnt;
  retChargeReadingStatus_en paramStatus;
  int continuousChargReadValue[ARRINDEXSIZE];
  int continuousChargeReadValueCnt[ARRINDEXSIZE];
}batteryChargeReading_st;

/* function declarations */
batteryChargeReading_st checkBatteryChargeReading(int *chargeReading, int numOfReadings);
#endif /* MONITORBATTERYCHARGING_H */
