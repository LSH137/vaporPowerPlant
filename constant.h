#ifndef CONSTANT_H
#define CONSTANT_H


#define FALSE 0
#define TRUE 1
#define epsilon 1E-5

#define WPT_startTemp 15
#define WPT_endTemp 280
#define WPT_tempInterver 5
#define WPT_startPressure 0
#define WPT_endPressure 1.5
#define WPT_pressureInterver 0.1
#define WPT_sat_nData 33

const int nRow_water = (WPT_endPressure - WPT_startPressure)/WPT_pressureInterver + 2;
const int nColumn_water = (WPT_endTemp - WPT_startTemp)/WPT_tempInterver + 1;


#define R22_startTemp 15
#define R22_endTemp 280
#define R22_tempInterver 5
#define R22_startPressure 0
#define R22_endPressure 1.5
#define R22_pressureInterver 0.1

const int nRow_R22 = (R22_endPressure - R22_startPressure)/R22_pressureInterver + 2;
const int nColumn_R22 = (R22_endTemp - R22_startTemp)/R22_tempInterver + 1;



#endif