#ifndef CDATA_H

#define CDATA_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

double getMeanDouble(double results[]);
double getMeanDoubleRoundedToSigFig(double results[], int sigFigs);

float getMeanFloat(float results[]);
float getMeanFloatRoundedToSigFig(float results[], int sigFigs);

int getMean(int results[]);

int *getMode(int results[]);
float *getModeFloat(float results[]);
double *getModeDouble(double results[]);

int getMedian(int results[], int getLeftValue);
float getMedianFloat(float results[], int getLeftValue);
double getMedianDouble(double results[], int getLeftValue);

#endif
