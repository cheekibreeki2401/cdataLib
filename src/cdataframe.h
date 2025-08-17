#ifndef DATAFRAME_H
#define DATAFRAME_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

typedef enum DataType{
	TYPE_INT,
	TYPE_UINT,
	TYPE_LONG,
	TYPE_ULONG,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_CHAR,
	TYPE_STRING
}DataType;

typedef struct DataEntry{
	DataType type;
	union{
		int i;
		unsigned int ui;
		long l;
		unsigned long ul;
		float f;
		double d;
		char c;
		char *s;
	}value;
}DataEntry;

typedef struct DataColumn{
	char *name;
	DataType type;
	DataEntry *data;
}DataColumn;

typedef struct DataFrame{
	size_t num_rows;
	size_t num_cols;
	DataColumn *columns;
}DataFrame;

double entry_to_double(DataEntry entry);
DataFrame *createDataFrame(size_t num_cols);
void freeDataFrame(DataFrame *df);
void setColumn(DataFrame *df, size_t col_index, const char *name, DataType type);
void addRow(DataFrame *df, DataEntry *entries);
DataEntry *getValue(DataFrame *df, size_t row, size_t col);;
void printDataFrame(DataFrame *df);
#endif
