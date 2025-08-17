#include "cdataframe.h"
#ifndef CDATA_H

#define CDATA_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

double getMeanDouble(double results[], size_t resultsSize);
double getMeanDoubleRoundedToSigFig(double results[], size_t resultsSize, int sigFigs);

float getMeanFloat(float results[], size_t resultsSize);
float getMeanFloatRoundedToSigFig(float results[], size_t resultsSize, int sigFigs);

int getMean(int results[], size_t resultsSize);

int *getMode(int results[], size_t resultsSize);
float *getModeFloat(float results[], size_t resultsSize);
double *getModeDouble(double results[], size_t resultsSize);

int getMedian(int results[], size_t resultsSize, int getLeftValue);
float getMedianFloat(float results[],size_t resultsSize, int getLeftValue);
double getMedianDouble(double results[], size_t resultsSize, int getLeftValue);

double getPearsonCorrelation(DataFrame *df, size_t col_x, size_t col_y);

#endif
