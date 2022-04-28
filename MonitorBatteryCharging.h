#ifndef  MONITORBATTERYCHARGING_H
#define  MONITORBATTERYCHARGING_H

struct ranges{
	int lowerLim;
	int upperLim;
	int numberOfElements;
};

/* function declarations */
void sortInputReadings(int *InputReading, int numOfInputReading);
void absoluteArray(int* values, int numberOfValues);
struct ranges* findRanges(int* values, int numberOfValues);
void printRanges(struct ranges* finalRangesToPrint);

#endif /* MONITORBATTERYCHARGING_H */
