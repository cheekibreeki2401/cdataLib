#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"

DataFrame *createDataFrame(size_t num_cols){
	DataFrame *df = malloc(sizeof(DataFrame));
	if(!df){
		return NULL;
	}
	df->num_rows = 0;
	df->num_cols = num_cols;
	df->columns = calloc(num_cols, sizeof(DataColumn));
	if(!df->columns){
		free(df);
		return NULL;
	}
	return df;
}

void freeDataFrame(DataFrame *df){
	if(!df){
		return;
	}

	for(size_t i = 0; i < df->num_cols; i++){
		DataColumn *col = &df->columns[i];
		free(col->name);
		for(size_t j = 0; j < df->num_rows; j++){
			if(col->type == TYPE_STRING && col->data[j].value.s){
				free(col->data[j].value.s);
			}
		}
		free(col->data);
	}

	free(df->columns);
	free(df);
}

void setColumn(DataFrame *df, size_t col_index, const char *name, DataType type){
	if(!df || col_index >= df->num_cols){
		return;
	}
	DataColumn *col = &df->columns[col_index];
	col->name = strdup(name);
	col->type = type;
	col->data = NULL;
}

void addRow(DataFrame *df, DataEntry *entries){
	if(!df || !entries){
		return;
	}
	for(size_t i=0; i < df->num_cols; i++){
		DataColumn *col = &df->columns[i];
		col->data=realloc(col->data, sizeof(DataEntry)*(df->num_rows+1));
		if(!col->data){
			perror("Failed to allocate memory for row");
			exit(EXIT_FAILURE);
		}
		if(col->type == TYPE_STRING && entries[i].value.s){
			col->data[df->num_rows].type = TYPE_STRING;
			col->data[df->num_rows].value.s = strdup(entries[i].value.s);
		} else {
			col->data[df->num_rows] = entries[i];
		}
	}
	df->num_rows++;
}

DataEntry *getValue(DataFrame *df, size_t row, size_t col){
	if(!df || row >= df->num_rows || col >= df->num_cols){
		return NULL;
	}
	return &df->columns[col].data[row];
}

void printDataFrame(DataFrame *df){
	if(!df){
		return;
	}
	for(size_t i = 0; i < df->num_cols; i++){
		printf("%s\t", df->columns[i].name);
	}
	printf("\n");

	for(size_t i = 0; i < df->num_cols; i++){
		for(size_t j = 0; j < df->num_cols; j++){
			DataColumn *col = &df->columns[j];
			switch(col->type){
				case TYPE_INT:
					printf("%d\t", col->data[i].value.i);
					break;
				case TYPE_UINT:
					printf("%u\t", col->data[i].value.ui);
					break;
				case TYPE_LONG:
					printf("%ld\t", col->data[i].value.l);
					break;
				case TYPE_ULONG:
					printf("%lu\t", col->data[i].value.ul);
					break;
				case TYPE_FLOAT:
					printf("%f\t", col->data[i].value.f);
					break;
				case TYPE_DOUBLE:
					printf("%lf\t", col->data[i].value.d);
					break;
				case TYPE_CHAR:
					printf("%c\t", col->data[i].value.c);
					break;
				case TYPE_STRING:
					printf("%s\t", col->data[i].value.s ? col->data[i].value.s:"");
			}
		}
		printf("\n");
	}
}
