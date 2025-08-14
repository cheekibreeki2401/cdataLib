#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cdata.h"

double getMeanDouble(double results[]){
	int resultsSize = (int)sizeof(results)/sizeof(double);
	double resultsTotal = 0.0;
	for(int i = 0; i < resultsSize; i++){
		resultsTotal += results[i];
	}
	return resultsTotal/resultsSize;
}

double getMeanDoubleRoundedToSigFig(double results[], int sigFigs){
	double rawMean = getMeanDouble(results);
	if(rawMean == 0.0){
		return 0.0;
	}
	double scale = pow(10, floor(log10(fabs(rawMean))) + 1 - sigFigs);
	return round(rawMean/scale) * scale;
}

float getMeanFloat(float results[]){
	int resultsSize = (int)sizeof(results)/sizeof(float);
	float resultsTotal = 0.0;
	for(int i = 0; i < resultsSize; i++){
		resultsTotal += results[i];
	}
	return resultsTotal/resultsSize;
}

float getMeanFloatRoundedToSigFig(float results[], int sigFigs){
	float rawMean = getMeanFloat(results);
	if(rawMean == 0.0){
		return 0.0;
	}
	float scale = pow(10, floor(log10(fabs(rawMean))) + 1 - sigFigs);
	return round(rawMean/scale)*scale;
}

int getMean(int results[]){
	int resultsSize = sizeof(results)/sizeof(int);
	int resultsTotal = 0.0;
	for(int i = 0; i < resultsSize; i++){
		resultsTotal += results[i];
	}
	return resultsTotal/resultsSize;
}

int getMaxInt(int list[]){
	int max = list[0];
	int listSize = sizeof(list)/sizeof(int);
	for(int i = 0; i < listSize; i++){
		if(list[i] > max){
			max = list[i];
		}
	}
	return max;
}

int compareInt(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int *getMode(int results[]){
	int resultsSize = sizeof(results)/sizeof(int);
	qsort(results, sizeof(results), sizeof(int), compareInt);
	int possibleModes[resultsSize];
	int mode_ctr[resultsSize] = {};
	int curr_number = 0;
	for(int i = 0; i < resultsSize; i++){
		int addedToList = 0;
		for(int j = 0; j < resultsSize; j++){
			if(results[i] == possibleModes[j]){
				mode_ctr[j]++;
				addedToList = 1;
				break;
			}
		}
		if(!addedToList){
			possibleModes[curr_number] = results[i];
			mode_ctr[curr_number]++;
			curr_number++;
		}
	}
	int mode_num = getMaxInt(mode_ctr);
	int *modes = (int*)malloc(resultsSize * sizeof(int));
	for(int i = 0; i < resultsSize; i++){
		if(mode_ctr[i] == mode_num){
			modes[i] = possibleModes[i];
		}
	}
	return modes;
}

float getMaxFloat(float list[]){
	float max = list[0];
	int listSize = sizeof(list)/sizeof(float);
	for(int i = 0; i < listSize; i++){
		if(list[i] > max){
			max = list[i];
		}
	}
	return max;
}

int compareFloat(const void *a, const void *b){
	const float *fa = (const float*) a;
	const float *fb = (const float*) b;

	if(fa<fb){
		return -1;
	} else if(fa>fb){
		return 1;
	} else {
		return 0;
	}
}

float *getModeFloat(float results[]){
	int resultsSize = sizeof(results)/sizeof(float);
	qsort(results, sizeof(results), sizeof(float), compareFloat);
	float possibleModes[resultsSize];
	int mode_ctr[resultsSize] = {};
	int curr_number = 0;
	for(int i = 0; i < resultsSize; i++){
		int addedToList = 0;
		for(int j = 0; j < resultsSize; j++){
			if(results[i] == possibleModes[j]){
				mode_ctr[j]++;
				addedToList = 1;
				break;
			}
		}
		if(!addedToList){
			possibleModes[curr_number] = results[i];
			mode_ctr[curr_number]++;
			curr_number++;
		}
	}
	int mode_num = getMaxInt(mode_ctr);
	float *modes = (float*)malloc(resultsSize * sizeof(float));
	for(int i = 0; i < resultsSize; i++){
		if(mode_ctr[i] == mode_num){
			modes[i] = possibleModes[i];
		}
	}
	return modes;
}

int compareDouble(const void *a, const void *b){
	const double *da = (const double*) a;
	const double *db = (const double*) b;

	if(da<db){
		return -1;
	} else if(da>db){
		return 1;
	} else {
		return 0;
	}
}

double *getModeDouble(double results[]){
	int resultsSize = sizeof(results)/sizeof(double);
	qsort(results, sizeof(results), sizeof(double), compareDouble);
	double possibleModes[resultsSize];
	int mode_ctr[resultsSize] = {};
	int curr_number = 0;
	for(int i = 0; i < resultsSize; i++){
		int addedToList = 0;
		for(int j = 0; j < resultsSize; j++){
			if(results[i] == possibleModes[j]){
				mode_ctr[j]++;
				addedToList = 1;
				break;
			}
		}
		if(!addedToList){
			possibleModes[curr_number] = results[i];
			mode_ctr[curr_number]++;
			curr_number++;
		}
	}
	int mode_num = getMaxInt(mode_ctr);
	double *modes = (double*)malloc(resultsSize * sizeof(double));
	for(int i = 0; i < resultsSize; i++){
		if(mode_ctr[i] == mode_num){
			modes[i] = possibleModes[i];
		}
	}
	return modes;
}

int getMedian(int results[], int getLeftValue){
	int resultsSize = sizeof(results)/sizeof(int);
	qsort(results, sizeof(results), sizeof(int), compareInt);
	if(!(resultsSize-1)%2){
		return results[(resultsSize-1)/2];
	} else {
		if(getLeftValue){
			return results[resultsSize/2];
		} else {
			return results[(resultsSize/2)+1];
		}
	}
}

float getMedianFloat(float results[], int getLeftValue){
	int resultsSize = sizeof(results)/sizeof(float);
	qsort(results, sizeof(results), sizeof(float), compareFloat);
	if(!(resultsSize-1)%2){
		return results[(resultsSize-1)/2];
	} else {
		if(getLeftValue){
			return results[resultsSize/2];
		} else {
			return results[(resultsSize/2)+1];
		}
	}
}

double getMedianDouble(double results[], int getLeftValue){
	int resultsSize = sizeof(results)/sizeof(double);
	qsort(results, sizeof(results), sizeof(double), compareDouble);
	if(!(resultsSize-1)%2){
		return results[(resultsSize-1)/2];
	} else {
		if(getLeftValue){
			return results[resultsSize/2];
		} else {
			return results[(resultsSize/2)+1];
		}
	}
}
