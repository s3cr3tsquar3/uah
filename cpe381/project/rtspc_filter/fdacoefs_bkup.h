/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 8.3 and the Signal Processing Toolbox 6.21.
 * Generated on: 10-Apr-2015 20:08:30
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 250
 * Stable            : Yes
 * Linear Phase      : Yes (Type 2)
 */

/* General type conversion for MATLAB generated C-code  */
//#include "tmwtypes.h"
/*
 * Expected path to tmwtypes.h
 * C:\Program Files\MATLAB\R2014a\extern\include\tmwtypes.h
 */
const int BL = 250;
const double B[250] = {
  -0.0007271679694203,-0.0003023152105387,-0.000319875212339,-0.0003000777803792,
  -0.000234458415504,-0.0001169954528582,5.445410687023e-05,0.0002778176893314,
  0.0005462488379991,0.0008483090447496, 0.001167587527484, 0.001483562896605,
   0.001773390740463, 0.002014388764894, 0.002184414522827, 0.002263184804372,
   0.002238993968035, 0.002103701933085, 0.001859334750795, 0.001515890314546,
   0.001092060225666,0.0006146564921474,0.0001161438219475,-0.0003670707706754,
  -0.0007979798151102,-0.001141479002898, -0.00136852054654,-0.001458300836122,
  -0.001400754462657,-0.001197841025523,-0.0008650702125334,-0.0004289881114324,
  7.241144022212e-05,0.0005944844289732, 0.001088170675033, 0.001505125774658,
   0.001801788029794, 0.001943992152904, 0.001910193513418, 0.001694488927888,
   0.001307809100902,0.0007779030937895,0.0001472346543854,-0.0005296994307616,
  -0.001191287139121,-0.001774132042074,-0.002218751619126,-0.002475798560818,
  -0.002510922842863,-0.002308951750953,-0.001876574021893,-0.001242514259135,
  -0.0004563552166291,0.0004154233489525, 0.001294356730322, 0.002097364077288,
   0.002743881226369, 0.003164028697888, 0.003305491654834, 0.003139811214499,
   0.002665885644424, 0.001912243034094,0.0009351391893204,-0.0001844915994283,
  -0.001347967471066,-0.002446811407378,-0.003372881372092,-0.004028301457497,
  -0.004335580878631,-0.004245896677752,-0.003745486780288,-0.002858721256466,
  -0.001648177900558,-0.0002106002432901, 0.001330035998085, 0.002832869399378,
    0.00415244824204, 0.005152156148277, 0.005717613966655, 0.005768845955096,
    0.00526969268844, 0.004234017720953,  0.00272717365226,0.0008632940209057,
  -0.001202736651335,-0.003286905322055,-0.005191783895039,-0.006723814794471,
  -0.007711840078703, -0.00802425818247,-0.007584160615535, -0.00637975659926,
  -0.004470310113921,-0.001985222659469,0.0008825718359344, 0.003889995712978,
   0.006762105531509, 0.009214858144717,  0.01097996601899,  0.01183032009796,
    0.01160350690832,  0.01022150495817, 0.007704481989213, 0.004177479938371,
  -0.000131348877325,-0.004900934076651,-0.009735737290735, -0.01419137767981,
   -0.01780565055511, -0.02013287552519, -0.02077894613229, -0.01943432817769,
   -0.01590255233245, -0.01012148448046,-0.002175949206747, 0.007700181880032,
    0.01913225957443,   0.0316238625554,  0.04458486787301,  0.05736720842533,
    0.06930547646014,  0.07975991772661,  0.08815826556568,  0.09403391144317,
    0.09705705875859,  0.09705705875859,  0.09403391144317,  0.08815826556568,
    0.07975991772661,  0.06930547646014,  0.05736720842533,  0.04458486787301,
     0.0316238625554,  0.01913225957443, 0.007700181880032,-0.002175949206747,
   -0.01012148448046, -0.01590255233245, -0.01943432817769, -0.02077894613229,
   -0.02013287552519, -0.01780565055511, -0.01419137767981,-0.009735737290735,
  -0.004900934076651,-0.000131348877325, 0.004177479938371, 0.007704481989213,
    0.01022150495817,  0.01160350690832,  0.01183032009796,  0.01097996601899,
   0.009214858144717, 0.006762105531509, 0.003889995712978,0.0008825718359344,
  -0.001985222659469,-0.004470310113921, -0.00637975659926,-0.007584160615535,
   -0.00802425818247,-0.007711840078703,-0.006723814794471,-0.005191783895039,
  -0.003286905322055,-0.001202736651335,0.0008632940209057,  0.00272717365226,
   0.004234017720953,  0.00526969268844, 0.005768845955096, 0.005717613966655,
   0.005152156148277,  0.00415244824204, 0.002832869399378, 0.001330035998085,
  -0.0002106002432901,-0.001648177900558,-0.002858721256466,-0.003745486780288,
  -0.004245896677752,-0.004335580878631,-0.004028301457497,-0.003372881372092,
  -0.002446811407378,-0.001347967471066,-0.0001844915994283,0.0009351391893204,
   0.001912243034094, 0.002665885644424, 0.003139811214499, 0.003305491654834,
   0.003164028697888, 0.002743881226369, 0.002097364077288, 0.001294356730322,
  0.0004154233489525,-0.0004563552166291,-0.001242514259135,-0.001876574021893,
  -0.002308951750953,-0.002510922842863,-0.002475798560818,-0.002218751619126,
  -0.001774132042074,-0.001191287139121,-0.0005296994307616,0.0001472346543854,
  0.0007779030937895, 0.001307809100902, 0.001694488927888, 0.001910193513418,
   0.001943992152904, 0.001801788029794, 0.001505125774658, 0.001088170675033,
  0.0005944844289732,7.241144022212e-05,-0.0004289881114324,-0.0008650702125334,
  -0.001197841025523,-0.001400754462657,-0.001458300836122, -0.00136852054654,
  -0.001141479002898,-0.0007979798151102,-0.0003670707706754,0.0001161438219475,
  0.0006146564921474, 0.001092060225666, 0.001515890314546, 0.001859334750795,
   0.002103701933085, 0.002238993968035, 0.002263184804372, 0.002184414522827,
   0.002014388764894, 0.001773390740463, 0.001483562896605, 0.001167587527484,
  0.0008483090447496,0.0005462488379991,0.0002778176893314,5.445410687023e-05,
  -0.0001169954528582,-0.000234458415504,-0.0003000777803792,-0.000319875212339,
  -0.0003023152105387,-0.0007271679694203
};