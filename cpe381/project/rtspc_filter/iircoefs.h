/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 *
 * Generated by MATLAB(R) 7.14 and the Signal Processing Toolbox 6.17.
 *
 * Generated on: 14-Apr-2015 11:44:48
 *
 */

/*
 * Discrete-Time IIR Filter (real)
 * -------------------------------
 * Filter Structure    : Direct-Form II
 * Numerator Length    : 32
 * Denominator Length  : 32
 * Stable              : Yes
 * Linear Phase        : No
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/*
 * Expected path to tmwtypes.h
 * /usr/local/MATLAB/R2012a_Student/extern/include/tmwtypes.h
 */
const int NL_22050 = 32;
const real64_T NUM_22050[32] = {
  9.116480031261e-11,2.826108809691e-09,4.239163214536e-08,4.097857774052e-07,
  2.868500441836e-06,1.548990238592e-05,6.712291033897e-05, 0.000239724679782,
  0.0007191740393461, 0.001837889211662, 0.004043356265657, 0.007719134688981,
    0.01286522448164,  0.01880302039624,  0.02417531193802,  0.02739868686309,
    0.02739868686309,  0.02417531193802,  0.01880302039624,  0.01286522448164,
   0.007719134688981, 0.004043356265657, 0.001837889211662,0.0007191740393461,
   0.000239724679782,6.712291033897e-05,1.548990238592e-05,2.868500441836e-06,
  4.097857774052e-07,4.239163214536e-08,2.826108809691e-09,9.116480031261e-11
};

const int DL_22050 = 32;
const real64_T DEN_22050[32] = {
                   1,    -5.77674552943,    20.07375973419,   -49.99916129228,
      98.43668245753,   -159.9166230172,    220.8665775504,   -264.0859156655,
      277.0460918208,   -257.3549707875,    213.1403163243,   -158.1404612019,
      105.4782450378,     -63.385088072,    34.36036800624,   -16.80813292249,
      7.415835240799,    -2.94717315485,    1.052728811538,  -0.3369394248642,
    0.09623261644576, -0.02439542117675, 0.005451864065472,-0.001064748414015,
  0.0001796998873738,-2.58280298351e-05,3.100035872566e-06,-3.023769700792e-07,
  2.302962136318e-08,-1.284999148755e-09,4.672726392105e-11,-8.311020649818e-13
};

const int NL_44100 = 11;
const real64_T NUM_44100[11] = {
  1.293671648767e-12,1.293671648767e-11,5.821522419451e-11, 1.55240597852e-10,
  2.716710462411e-10,3.260052554893e-10,2.716710462411e-10, 1.55240597852e-10,
  5.821522419451e-11,1.293671648767e-11,1.293671648767e-12
};

const int DL_44100 = 11;
const real64_T DEN_44100[11] = {
                   1,   -9.663272714187,    42.14796576941,   -109.2669279608,
      186.4503670639,   -218.8090049412,    178.8469666231,   -100.5338364328,
      37.19451781065,   -8.178346434819,    0.811571218292
};

