# A Simple Data Analysis Library for C
## Features added so far:
- Mean, median and mode support for results of ints, doubles and floats.

## How to use functions:
- getMean, getMeanFloat and getMeanDouble are used the way you would use any other function, with the only parameter is an array of values with the correct type (use getMean for integers)
- getMeanFloatRoundedToSigFig and getMeanDoubleRoundedToSigFig is the same as the regular mean functions with one additional parameter of how many significant figures do you want it rounded to.
- getMode, getModeFloat, and getModeDouble take in an argument of an array of the correct type (use getMode for integers)
- getMedia, getMedianFloat and getMedianDouble take in two arguments, one of an array of the correct type and a boolean of in the case of the median lying between two values, whether or not to return the value to the left or the value to the right of the "middle".
