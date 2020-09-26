#include "filter.h"
#include <math.h>

IIR_Filter::IIR_Filter(float weight) 
{

    alpha = weight; // 0.2 = 20% weight.  0 < alpha < 1
    // low alpha means good smoothing but slow response
    // high alpha means bad smoothing but fast response
    filteredData = 0; // before measuring, the data is set to zero; 
}

double IIR_Filter::mapping(double sourceNumber, double fromA, double fromB, double toA, double toB, int decimalPrecision ) 
{
    // https://stackoverflow.com/questions/5731863/mapping-a-numeric-range-onto-another
    // We needed to map analog sensor value to its true potential range of 0-255
    // to be able to then use it to affect the duty cycle.
    // This custom function, unlike the map() function from the arduino library, returns double values. 
    deltaA = fromB - fromA;
    deltaB = toB - toA;
    scale  = deltaB / deltaA;
    negA   = -1 * fromA;
    offset = (negA * scale) + toA;
    finalNumber = (sourceNumber * scale) + offset;
    calcScale = (int) pow(10, decimalPrecision);
    ratio = (double) round(finalNumber * calcScale) / calcScale;
    return ratio;
}

double IIR_Filter::exponentialFilter(float sensorPin) 
{
    //A recursive filter is just one that calculates a new, smoothed value (yn) 
    // by using the last smoothed value (yn – 1) and a new measurement (xn):
    // yn = w × xn + (1 – w) × yn – 1
    // The amount of smoothing is controlled by a weighting parameter (w). 
    // The weight is a value between 0% and 100%.
    raw = sensorPin; 
    filteredData = alpha * raw + (1 - alpha)*filteredData;
    return filteredData; 

}