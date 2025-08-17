#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cdata.h"

double getMeanDouble(double results[], size_t resultsSize){
	double resultsTotal = 0.0;
	for(size_t i = 0; i < resultsSize; i++){
		resultsTotal += results[i];
	}
	return resultsTotal/resultsSize;
}

double getMeanDoubleRoundedToSigFig(double results[], size_t resultsSize, int sigFigs){
	double rawMean = getMeanDouble(results, resultsSize);
	if(rawMean == 0.0){
		return 0.0;
	}
	double scale = pow(10, floor(log10(fabs(rawMean))) + 1 - sigFigs);
	return round(rawMean/scale) * scale;
}

float getMeanFloat(float results[], size_t resultsSize){
	float resultsTotal = 0.0;
	for(size_t i = 0; i < resultsSize; i++){
		resultsTotal += results[i];
	}
	return resultsTotal/resultsSize;
}

float getMeanFloatRoundedToSigFig(float results[], size_t resultsSize, int sigFigs){
	float rawMean = getMeanFloat(results, resultsSize);
	if(rawMean == 0.0){
		return 0.0;
	}
	float scale = pow(10, floor(log10(fabs(rawMean))) + 1 - sigFigs);
	return round(rawMean/scale)*scale;
}

int getMean(int results[], size_t resultsSize){
	int resultsTotal = 0.0;
	for(size_t i = 0; i < resultsSize; i++){
		resultsTotal += results[i];
	}
	return resultsTotal/resultsSize;
}

int getMaxInt(int list[], size_t listSize){
	int max = list[0];
	for(size_t i = 0; i < listSize; i++){
		if(list[i] > max){
			max = list[i];
		}
	}
	return max;
}

int compareInt(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int *getMode(int results[], size_t resultsSize){
	qsort(results, resultsSize, sizeof(int), compareInt);
	int possibleModes[resultsSize];
	int mode_ctr[resultsSize] = {};
	int curr_number = 0;
	for(size_t i = 0; i < resultsSize; i++){
		int addedToList = 0;
		for(size_t j = 0; j < resultsSize; j++){
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
	int mode_num = getMaxInt(mode_ctr, sizeof(mode_ctr)/sizeof(int));
	int *modes = (int*)malloc(resultsSize * sizeof(int));
	for(size_t i = 0; i < resultsSize; i++){
		if(mode_ctr[i] == mode_num){
			modes[i] = possibleModes[i];
		}
	}
	return modes;
}

float getMaxFloat(float list[], size_t listSize){
	float max = list[0];
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

float *getModeFloat(float results[], size_t resultsSize){
	qsort(results, resultsSize, sizeof(float), compareFloat);
	float possibleModes[resultsSize];
	int mode_ctr[resultsSize] = {};
	int curr_number = 0;
	for(size_t i = 0; i < resultsSize; i++){
		int addedToList = 0;
		for(size_t j = 0; j < resultsSize; j++){
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
	int mode_num = getMaxInt(mode_ctr, sizeof(mode_ctr)/sizeof(int));
	float *modes = (float*)malloc(resultsSize * sizeof(float));
	for(size_t i = 0; i < resultsSize; i++){
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

double *getModeDouble(double results[], size_t resultsSize){
	qsort(results, resultsSize, sizeof(double), compareDouble);
	double possibleModes[resultsSize];
	int mode_ctr[resultsSize] = {};
	int curr_number = 0;
	for(size_t i = 0; i < resultsSize; i++){
		int addedToList = 0;
		for(size_t j = 0; j < resultsSize; j++){
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
	int mode_num = getMaxInt(mode_ctr, sizeof(mode_ctr)/sizeof(int));
	double *modes = (double*)malloc(resultsSize * sizeof(double));
	for(size_t i = 0; i < resultsSize; i++){
		if(mode_ctr[i] == mode_num){
			modes[i] = possibleModes[i];
		}
	}
	return modes;
}

int getMedian(int results[], size_t resultsSize, int getLeftValue){
	qsort(results, resultsSize, sizeof(int), compareInt);
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

float getMedianFloat(float results[], size_t resultsSize, int getLeftValue){
	qsort(results, resultsSize, sizeof(float), compareFloat);
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

double getMedianDouble(double results[],size_t resultsSize, int getLeftValue){
	qsort(results, resultsSize, sizeof(double), compareDouble);
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

//The following functions can only be used with the correct data frames.

double getPearsonCorrelation(DataFrame *df, size_t col_x, size_t col_y){
	if(!df || col_x >= df->num_cols || col_y >= df->num_cols){
		fprintf(stderr, "Invalid Column index for corrleation\n");
		return 0.0;
	}
	DataColumn *cx = &df->columns[col_x];
	DataColumn *cy = &df->columns[col_y];

	if(cx->type == TYPE_STRING || cy->type == TYPE_STRING){
		fprintf(stderr, "Cannot compute correlation between strings\n");
		return 0.0;
	}
	if(cx->type == TYPE_CHAR || cy->type == TYPE_CHAR){
		fprintf(stderr, "Cannot compute correlation between chars\n");
		return 0.0;
	}
	size_t n = df->num_rows;
	if(!n){
		return 0.0;
	}
	double *x_vals = malloc(sizeof(double)*n);
	double *y_vals = malloc(sizeof(double)*n);
	if(!x_vals || !y_vals){
		perror("Malloc failure");
		exit(EXIT_FAILURE);
	}
	for(size_t i = 0; i < n; i++){
		x_vals[i] = entry_to_double(cx->data[i]);
		y_vals[i] = entry_to_double(cy->data[i]);
	}
	double mean_x = getMeanDouble(x_vals, n);
	double mean_y = getMeanDouble(y_vals, n);
	double numerator = 0.0;
	double denom_x = 0.0;
	double denom_y = 0.0;
	for(size_t i = 0; i < n; i++){
		double dx = x_vals[i] - mean_x;
		double dy = y_vals[i] - mean_y;
		numerator += dx*dy;
		denom_x += dx*dx;
		denom_y += dy*dy;
	}
	free(x_vals);
	free(y_vals);

	if(denom_x == 0.0 || denom_y == 0.0){
		return 0.0;
	}
	return numerator/(sqrt(denom_x)*sqrt(denom_y));
}
