# A set of simple Data Analysis Library for C
## Features added so far:
- Mean, median and mode support for results of ints, doubles and floats.
- A new data structure (A simple data frame) to be used for future implementations
- A function to get the Pearson correlation value between two columns.
- A function to process the k-means of the data-frame's numeric columns.

## How to use functions:
cdata library:
- getMean, getMeanFloat and getMeanDouble are used the way you would use any other function, with two parameters, the first being an array (or pointer) of the correct type, the other is the size of that array (use getMean for integers).
- getMeanFloatRoundedToSigFig and getMeanDoubleRoundedToSigFig is the same as the regular mean functions with one additional parameter of how many significant figures do you want it rounded to.
- getMode, getModeFloat, and getModeDouble takes in an argument of an array of the correct type and an argument for the size of the array (use getMode for integers).
- getMedian, getMedianFloat and getMedianDouble take in three arguments, one of an array of the correct type, one of the array size and a boolean of in the case of the median lying between two values, whether or not to return the value to the left or the value to the right of the "middle".
- getPearsonCorrelation takes in three arguments, one of a dataframe, and two size arguments to use the indecies of the columns being compared to each other. Returns a double.
- kmeans takes in three arguments, a one of a dataframe and two size arguments. One is k (number of data points) and the other is the max number of iterations.

cdataframe library:
- createDataFrame is used to create a dataframe pointer. Takes one argument of number of columns.
- setColumn is used to set the name and type of a new column. Takes four arguments of a dataframe pointer, the index of the column, the name of the column and the data type of the column.
- addRow is used to add a new row of values into the dataframe. Takes two arguments of a dataframe pointer and a pointer to the new row (Which is a series of DataEntries).
- getValue is used to get a pointer to the data entry at a particular row and column. Takes three arguments of a pointer to a dataframe, a column number and a row number for the entry.
- printDataFrame does what it says on the box, prints the contents of a dataframe. Takes in one argument of a dataframe pointer.
- freeDataFrame frees the memory of a specified dataframe. Takes in one argument of a dataframe pointer.
