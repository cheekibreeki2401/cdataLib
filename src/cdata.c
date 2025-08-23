#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>
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

int getStandardDeviation(int results[], size_t size){
	int *deviations = calloc(size, sizeof(int));
	int mean = getMean(results, size);
	for(size_t i = 0; i<size; i++){
		deviations[i] = (mean-results[i])*(mean-results[i]);
	}
	return sqrt(getMean(deviations, size));
}

float getStandardDeviationF(float results[], size_t size){
	float *deviations = calloc(size, sizeof(float));
	float mean = getMeanFloat(results, size);
	for(size_t i = 0; i < size; i++){
		deviations[i] = (mean-results[i])*(mean-results[i]);
	}
	return sqrt(getMeanFloat(deviations, size));
}

double getStandardDeviationD(double results[], size_t size){
	double *deviations = calloc(size, sizeof(double));
	double mean = getMeanDouble(results, size);
	for(size_t i = 0; i < size; i++){
		deviations[i] = (mean-results[i])*(mean-results[i]);
	}
	return sqrt(getMeanDouble(deviations, size));
}

int *getInterQuartiles(int results[], size_t size){
	int *quartiles = calloc(2, sizeof(int));
	int *lowerHalf = malloc(size*sizeof(int));
	int *upperHalf = malloc(size*sizeof(int));
	int lowerOffset = 0;
	int upperOffset = 0;
	int median = getMedian(results, size, 1);
	for(size_t i = 0; i<size; i++){
		if(results[i] <= median){
			lowerHalf[lowerOffset] = results[i];
			lowerOffset++;
		} else {
			upperHalf[upperOffset] = results[i];
			upperOffset++;
		}
	}
	int quartile1 = getMedian(lowerHalf, lowerOffset+1, 1);
	int quartile3 = getMedian(upperHalf, upperOffset+1, 1);
	free(lowerHalf);
	free(upperHalf);
	quartiles[0] = quartile1;
	quartiles[1] = quartile3;
	return quartiles;
}

float *getInterQuartilesF(float results[], size_t size){
	float *quartiles = calloc(2, sizeof(float));
	float *lowerHalf = malloc(size*sizeof(float));
	float *upperHalf = malloc(size*sizeof(float));
	int lowerOffset = 0;
	int upperOffset = 0;
	float median = getMedianFloat(results, size, 1);
	for(size_t i = 0; i<size; i++){
		if(results[i] <= median){
			lowerHalf[lowerOffset] = results[i];
			lowerOffset++;
		} else {
			upperHalf[upperOffset] = results[i];
			upperOffset++;
		}
	}
	float quartile1 = getMedianFloat(lowerHalf, lowerOffset+1, 1);
	float quartile3 = getMedianFloat(upperHalf, upperOffset+1, 1);
	free(lowerHalf);
	free(upperHalf);
	quartiles[0] = quartile1;
	quartiles[1] = quartile3;
	return quartiles;
}

double *getInterQuartilesD(double results[], size_t size){
	double *quartiles = calloc(2, sizeof(double));
	double *lowerHalf = malloc(size*sizeof(double));
	double *upperHalf = malloc(size*sizeof(double));
	int lowerOffset = 0;
	int upperOffset = 0;
	double median = getMedianDouble(results, size, 1);
	for(size_t i = 0; i<size; i++){
		if(results[i]<=median){
			lowerHalf[lowerOffset] = results[i];
			lowerOffset++;
		} else {
			upperHalf[upperOffset] = results[i];
			upperOffset++;
		}
	}
	double quartile1 = getMedianDouble(lowerHalf, lowerOffset+1, 1);
	double quartile3 = getMedianDouble(upperHalf, upperOffset+1, 1);
	free(lowerHalf);
	free(upperHalf);
	quartiles[0] = quartile1;
	quartiles[1] = quartile3;
	return quartiles;
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

double euclidianDistance(double *a, double *b, size_t n){
	double sum = 0.0;
	for(size_t i = 0; i < n; i++){
		double d = a[i] - b[i];
		sum+= d*d;
	}
	return sqrt(sum);
}

int *kmeans(DataFrame *df, size_t k, size_t max_iters){
	size_t num_features;
	double **data = extractNumericMatrix(df, &num_features);
	size_t n = df->num_rows;
	if(n == 0 || num_features == 0 || k == 0){
		return NULL;
	}
	int *labels = calloc(n, sizeof(int));
	double **centroids = malloc(k*sizeof(double*));
	for(size_t i=0; i<k;i++){
		centroids[i] = malloc(num_features * sizeof(double));
	}
	srand((unsigned)time(NULL));
	for(size_t i = 0; i < k; i++){
		int r = rand() % n;
		for(size_t j = 0; j < num_features; j++){
			centroids[i][j] = data[r][j];
		}
	}
	for(size_t i = 0; i < max_iters; i++){
		int changed = 0;
		for(size_t j = 0; j < n; j++){
			double bestDist = DBL_MAX;
			int bestCluster = 0;
			for(size_t c = 0; c < k; c++){
				double dist = euclidianDistance(data[j], centroids[c], num_features);
				if(dist<bestDist){
					bestDist = dist;
					bestCluster = c;
				}
			}
			if(labels[j] != bestCluster){
				labels[j] = bestCluster;
				changed = 1;
			}
		}
		if(!changed){
			break;
		}
		double **new_centroids = calloc(k, sizeof(double*));
		size_t *counts = calloc(k, sizeof(size_t));
		for(size_t c = 0; c < k; c++){
			new_centroids[c] = calloc(num_features, sizeof(double));
		}
		for(size_t j = 0; j < n; j++){
			int cluster = labels[j];
			for(size_t l = 0; l < num_features; l++){
				new_centroids[cluster][l] += data[j][l];
			}
			counts[cluster]++;
		}
		for(size_t c = 0; c < k; c++){
			if(counts[c] > 0){
				for(size_t j = 0; j < num_features; j++){
					centroids[c][j] = new_centroids[c][j]/counts[c];
				}
			}
			free(new_centroids[c]);
		}
		free(new_centroids);
		free(counts);
	}
	for(size_t i = 0; i < n; i++){
		free(data[i]);
	}
	free(data);
	for(size_t i = 0; i < k; i++){
		free(centroids[i]);
	}
	free(centroids);
	return labels;
}

linearRegressionResult LinearRegression(DataFrame *df, size_t col_x, size_t col_y){
	linearRegressionResult res = {0};
	if(!df || col_x >= df->num_cols || col_y >= df->num_cols){
		return res;
	}
	DataColumn *cx=&df->columns[col_x];
	DataColumn *cy=&df->columns[col_y];
	if(cx->type == TYPE_STRING || cx->type == TYPE_CHAR || cy->type == TYPE_STRING || cy->type == TYPE_CHAR){
		fprintf(stderr, "Regression only works on numeric columns\n");
		return res;
	}
	size_t n = df->num_rows;
	if(n<2){
		fprintf(stderr, "Not enough data points for regression\n");
		return res;
	}
	double *x = malloc(n*sizeof(double));
	double *y = malloc(n*sizeof(double));
	if(!x||!y){
		perror("Malloc error");
		exit(EXIT_FAILURE);
	}
	for(size_t i = 0; i < n; i++){
		x[i] = entry_to_double(cx->data[i]);
		y[i] = entry_to_double(cy->data[i]);
	}
	double meanX = getMeanDouble(x,n);
	double meanY = getMeanDouble(y,n);
	double num = 0.0;
	double den= 0.0;
	for(size_t i = 0; i<n; i++){
		double dx = x[i]-meanX;
		num+=dx*(y[i]-meanY);
		den+=dx*dx;
	}
	if(den == 0.0){
		fprintf(stderr, "Cannot compute regression, all \"x\" values are the same\n");
		free(x);
		free(y);
		return res;
	}
	res.slope=num/den;
	res.intercept=meanY-res.slope*meanX;
	double ssTot = 0.0;
	double ssRes = 0.0;
	for(size_t i = 0; i<n; i++){
		double yPred = res.intercept+res.slope*x[i];
		double dy = y[i]-meanY;
		double dyPred = y[i]-yPred;
		ssTot+=dy*dy;
		ssRes+=dyPred*dyPred;
	}
	if(ssTot==0.0){
		res.r2 = 1.0;
	} else {
		res.r2 = 1.0-(ssRes/ssTot);
	}
	res.r = sqrt(res.r2);
	free(x);
	free(y);
	return res;
}
