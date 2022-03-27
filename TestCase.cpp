#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "MonitorBatteryCharging.h"

TEST_CASE("To check Continous readings in given range - PASS") {
    int CurrentChargeRange[] = {1,2,5,4,6,8,7,9};
    batteryChargeReading_st batteryChargeDetails;
    int sizeOfArrayIndex = sizeof(CurrentChargeRange) / sizeof(CurrentChargeRange[0]); 
    batteryChargeDetails = checkBatteryChargeReading(&CurrentChargeRange[0],sizeOfArrayIndex);
  REQUIRE(batteryChargeDetails.continuousReadingCnt[0] == 1);
}

TEST_CASE("To check if Current reading range is empty - PASS") 
{
    int CurrentChargeRange[] = {};
    batteryChargeReading_st batteryChargeDetails;
    int sizeOfArrayIndex = sizeof(CurrentChargeRange) / sizeof(CurrentChargeRange[0]);
    batteryChargeDetails = checkBatteryChargeReading(&CurrentChargeRange[0],sizeOfArrayIndex);
  REQUIRE(batteryChargeDetails.paramStatus == ERROR_INVALID);
}

TEST_CASE("To check Continous readings in given range - PASS") {
    int CurrentChargeRange[] = {3,3,5,4,10,11,12};
    batteryChargeReading_st batteryChargeDetails;
    int sizeOfArrayIndex = sizeof(CurrentChargeRange) / sizeof(CurrentChargeRange[0]); 
    batteryChargeDetails = checkBatteryChargeReading(&CurrentChargeRange[0],sizeOfArrayIndex);
  REQUIRE(batteryChargeDetails.continuousReadingCnt[1] == 2);
}

/*
// Can be uncommented to check failure state of this test case
TEST_CASE("To check if Current reading range is empty - FAIL") 
{
    int CurrentChargeRange[] = {};
    batteryChargeReading_st batteryChargeDetails;
    int sizeOfArrayIndex = sizeof(CurrentChargeRange) / sizeof(CurrentChargeRange[0]);
  
  batteryChargeDetails = checkBatteryChargeReading(&CurrentChargeRange[0],sizeOfArrayIndex);
  REQUIRE(batteryChargeDetails.paramStatus == OK_VALID);
}
*/
