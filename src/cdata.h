#include "cdataframe.h"
#ifndef CDATA_H

#define CDATA_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

typedef struct linearRegressionResult{
	double slope;
	double intercept;
	double r;
	double r2;
}linearRegressionResult;

double getMeanDouble(double results[], size_t resultsSize);
double getMeanDoubleRoundedToSigFig(double results[], size_t resultsSize, int sigFigs);

float getMeanFloat(float results[], size_t resultsSize);
float getMeanFloatRoundedToSigFig(float results[], size_t resultsSize, int sigFigs);

int getMean(int results[], size_t resultsSize);

int *getMode(int results[], size_t resultsSize);
float *getModeFloat(float results[], size_t resultsSize);
double *getModeDouble(double results[], size_t resultsSize);

int getStandardDeviation(int results[], size_t size);
float getStandardDeviationF(float results[], size_t size);
double getStandardDeviationD(double results[], size_t size);

int *getInterQuartiles(int results[], size_t size);
float *getInterQuartilesF(float results[], size_t size);
double *getInterQuartilesD(double results[], size_t size);

int getMedian(int results[], size_t resultsSize, int getLeftValue);
float getMedianFloat(float results[],size_t resultsSize, int getLeftValue);
double getMedianDouble(double results[], size_t resultsSize, int getLeftValue);

double getPearsonCorrelation(DataFrame *df, size_t col_x, size_t col_y);

int *kmeans(DataFrame *df, size_t k, size_t max_iters);

#endif
