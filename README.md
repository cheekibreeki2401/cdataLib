# A simple Data Analysis Library for C with a custom datatype.
## Features added so far:
- Mean, median and mode support for results of ints, doubles and floats.
- A new data structure (A simple data frame) to be used for future implementations
- A series of functions to get the standard deviation of a given numeric dataset.
- A series of functions to get the 1st and 3rd Quartiles of a given numeric dataset.
- A series of functions to remove outliers of a dataset either by using the interquartile method or standard deviation method.
- A function to get the Pearson correlation value between two columns.
- A function to process the k-means of the data-frame's numeric columns.
- A function to calculate linear regression (Comes with a new data type linearRegressionResult)

## How to use functions:
cdata library:
- getMean, getMeanFloat and getMeanDouble are used the way you would use any other function, with two parameters, the first being an array (or pointer) of the correct type, the other is the size of that array (use getMean for integers).
- getMeanFloatRoundedToSigFig and getMeanDoubleRoundedToSigFig is the same as the regular mean functions with one additional parameter of how many significant figures do you want it rounded to.
- getMode, getModeFloat, and getModeDouble takes in an argument of an array of the correct type and an argument for the size of the array (use getMode for integers).
- getMedian, getMedianFloat and getMedianDouble takes in three arguments, one of an array of the correct type, one of the array size and a boolean of in the case of the median lying between two values, whether or not to return the value to the left or the value to the right of the "middle".
- getStandardDeviation, getStandardDeviationF and getStandardDeviationD takes in two arguments, one of an array of the correct type, one of the array size. Returns a singular value of the type being used.
- getInterQuartile, getInterQuartileF and getInterQuartileD takes in two arguments, one of an array of the correct type, one of the array size. Returns a pointer to two values that represents the first and third quartiles.
- removeOutliersQ, removeOutliersQF and removeOutliersQD takes in two arguments, one of an array of the correct type and the size of the array. Returns a pointer to the results after removing outliers using the interquartile method.
- removeOutliersSD, removeOutliersSDF and removeOutliersSDD takes in three arguments, one of an array of the correct type, the size of the array and an integer of the number of standard deviations that outliers can fall from. Returns a pointer to the results after removing outliers using the standard deviation method.
- getPearsonCorrelation takes in three arguments, one of a dataframe, and two size arguments to use the indecies of the columns being compared to each other. Returns a double.
- kmeans takes in three arguments, one of a dataframe and two size arguments. One is k (number of data points) and the other is the max number of iterations.
- LinearRegression takes in three arguments, one dataframe and two indexes of columns to get the regression. Returns a linearRegressionResult struct type, which has the members slope, intercept, r and r2.

cdataframe library:
- createDataFrame is used to create a dataframe pointer. Takes one argument of number of columns.
- setColumn is used to set the name and type of a new column. Takes four arguments of a dataframe pointer, the index of the column, the name of the column and the data type of the column.
- addRow is used to add a new row of values into the dataframe. Takes two arguments of a dataframe pointer and a pointer to the new row (Which is a series of DataEntries).
- getValue is used to get a pointer to the data entry at a particular row and column. Takes three arguments of a pointer to a dataframe, a column number and a row number for the entry.
- printDataFrame does what it says on the box, prints the contents of a dataframe. Takes in one argument of a dataframe pointer.
- freeDataFrame frees the memory of a specified dataframe. Takes in one argument of a dataframe pointer.
