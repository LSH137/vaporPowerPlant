#ifndef WATER_H
#define WATER_H

#include <math.h>
#include <stdio.h>
#include "constant.h"
#include "interpolation.h"

#define DEBUG_WATER 0


extern double WPT[nRow_water][nColumn_water];
extern double WPT_entropy[nRow_water][nColumn_water];
extern double WPT_sat[WPT_sat_nData][3];

int WPTpressureToIndex(double pressure);

double WPTindexToPressure(int idx);

int WPTtempToIndex(double temp);

double WPTindexToTemp(int idx);




class water
{
public:
    water()
    {   
        temp = -1;
        pressure = -1;
        enthalphy = -1;
        entropy = -1;
    }
    ~water() = default;

    double temp; // celcius deg
    double pressure; // MPa
    double enthalphy; // KJ/Kg
    double entropy;

    
    void setTemp(double t)
    {
        this->temp = t;
    }

    void setPressure(double p)
    {
        if(p == 0.01)
            this->pressure = 0;
        else
            this->pressure = p;
    }

    void setEnthalphy(double h)
    {
        this->enthalphy = h;
    }

    double getEnthalphy()
    {
        int idxTempLow;
        int idxTempHigh;
        double tempLow;
        double tempHigh;

        int idxPressureLow;
        int idxPressureHigh;
        double pressureLow;
        double pressureHigh;


        // check temp and pressure is setted
        if(temp >= 0 && pressure >= 0)
        {
            //if(DEBUG_WATER) printf("temp > 0 and pressure > 0\n");

            // get index from temp
            int idxTemp = WPTtempToIndex(temp);

            // get index from pressure
            int idxPressure = WPTpressureToIndex(pressure);

            // check does index is correct
            bool idxTempCheck = fabs(WPTindexToTemp(idxTemp) - temp) < epsilon;
            bool idxPressureCheck = fabs(WPTindexToPressure(idxPressure) - pressure) < epsilon;

            if(DEBUG_WATER) printf("check property: idxTemp = %d, idxPressure = %d, temp = %lf, pressure = %lf, idxTempCheck = %d, idxPressureCheck = %d\n", idxTemp, idxPressure, temp, pressure, idxTempCheck, idxPressureCheck);


            // calculate near point
            if(idxTempCheck == FALSE)
            {
                idxTempLow = idxTemp;
                idxTempHigh = idxTemp + 1;
                tempLow = WPTindexToTemp(idxTempLow);
                tempHigh = WPTindexToTemp(idxTempHigh);
            }

            if(idxPressureCheck == FALSE)
            {
                idxPressureLow = idxPressure;
                idxPressureHigh = idxPressure + 1;
                pressureLow = WPTindexToPressure(idxPressureLow);
                pressureHigh = WPTindexToPressure(idxPressureHigh);
            }

            // calculate enthalpy
            if(idxTempCheck == FALSE && idxPressureCheck == FALSE)
            {
                // check which point to use (T_l, P_l, h_ll), (T_l, P_h, h_lh), (T_h, P_l, h_hl) or (T_l, P_h, h_lh), (T_h, P_l, h_hl), (T_h, P_h, h_hh)
                double h_hl = WPT[idxPressureLow][idxTempHigh];
                double p_hl[3] = {tempHigh, pressureLow, h_hl};

                double h_lh = WPT[idxPressureHigh][idxTempLow];
                double p_lh[3] = {tempLow, pressureHigh, h_lh};

                double p[3] = {temp, pressure, 0};

                if(temp + pressure > (tempHigh + pressureHigh)/2)
                {
                    double h_hh = WPT[idxPressureHigh][idxTempHigh];
                    double p_hh[3] = {tempHigh, pressureHigh, h_hh};   

                    enthalphy = linearInterpolation2D(p_hh, p_hl, p_lh, p);
                    return enthalphy;
                }
                else
                {
                    double h_ll = WPT[idxPressureLow][idxTempLow];
                    double p_ll[3] = {tempLow, pressureLow, h_ll};

                    enthalphy = linearInterpolation2D(p_ll, p_hl, p_lh, p);
                    return enthalphy;
                }
            }
            else if(idxTempCheck == TRUE && idxPressureCheck == FALSE)
            {
                double h_l = WPT[idxPressureLow][idxTemp];
                double h_h = WPT[idxPressureHigh][idxTemp];

                enthalphy = linearInterpolation1D(pressureLow, h_l, pressureHigh, h_h, pressure);
                return enthalphy;
            }
            else if(idxTempCheck == FALSE && idxPressureCheck == TRUE)
            {
                double h_l = WPT[idxPressure][idxTempLow];
                double h_h = WPT[idxPressure][idxTempHigh];

                enthalphy = linearInterpolation1D(tempLow, h_l, tempHigh, h_h, temp);
                return enthalphy;
            }
            else
            {
                enthalphy = WPT[idxPressure][idxTemp];
                return enthalphy;
            }
        }
        else
        {
            printf("set temperature and pressure first!\n");
            return -1;
        }
    }

    double getEntropy()
    {
        int idxTempLow;
        int idxTempHigh;
        double tempLow;
        double tempHigh;

        int idxPressureLow;
        int idxPressureHigh;
        double pressureLow;
        double pressureHigh;


        // check temp and pressure is setted
        if(temp >= 0 && pressure >= 0)
        {
            //if(DEBUG_WATER) printf("temp > 0 and pressure > 0\n");

            // get index from temp
            int idxTemp = WPTtempToIndex(temp);

            // get index from pressure
            int idxPressure = WPTpressureToIndex(pressure);

            // check does index is correct
            bool idxTempCheck = fabs(WPTindexToTemp(idxTemp) - temp) < epsilon;
            bool idxPressureCheck = fabs(WPTindexToPressure(idxPressure) - pressure) < epsilon;

            if(DEBUG_WATER) printf("check property: idxTemp = %d, idxPressure = %d, temp = %lf, pressure = %lf, idxTempCheck = %d, idxPressureCheck = %d\n", idxTemp, idxPressure, temp, pressure, idxTempCheck, idxPressureCheck);


            // calculate near point
            if(idxTempCheck == FALSE)
            {
                idxTempLow = idxTemp;
                idxTempHigh = idxTemp + 1;
                tempLow = WPTindexToTemp(idxTempLow);
                tempHigh = WPTindexToTemp(idxTempHigh);
            }

            if(idxPressureCheck == FALSE)
            {
                idxPressureLow = idxPressure;
                idxPressureHigh = idxPressure + 1;
                pressureLow = WPTindexToPressure(idxPressureLow);
                pressureHigh = WPTindexToPressure(idxPressureHigh);
            }

            // calculate enthalpy
            if(idxTempCheck == FALSE && idxPressureCheck == FALSE)
            {
                // check which point to use (T_l, P_l, h_ll), (T_l, P_h, h_lh), (T_h, P_l, h_hl) or (T_l, P_h, h_lh), (T_h, P_l, h_hl), (T_h, P_h, h_hh)
                double h_hl = WPT_entropy[idxPressureLow][idxTempHigh];
                double p_hl[3] = {tempHigh, pressureLow, h_hl};

                double h_lh = WPT_entropy[idxPressureHigh][idxTempLow];
                double p_lh[3] = {tempLow, pressureHigh, h_lh};

                double p[3] = {temp, pressure, 0};

                if(temp + pressure > (tempHigh + pressureHigh)/2)
                {
                    double h_hh = WPT_entropy[idxPressureHigh][idxTempHigh];
                    double p_hh[3] = {tempHigh, pressureHigh, h_hh};   

                    entropy = linearInterpolation2D(p_hh, p_hl, p_lh, p);
                    return entropy;
                }
                else
                {
                    double h_ll = WPT_entropy[idxPressureLow][idxTempLow];
                    double p_ll[3] = {tempLow, pressureLow, h_ll};

                    entropy = linearInterpolation2D(p_ll, p_hl, p_lh, p);
                    return entropy;
                }
            }
            else if(idxTempCheck == TRUE && idxPressureCheck == FALSE)
            {
                double h_l = WPT_entropy[idxPressureLow][idxTemp];
                double h_h = WPT_entropy[idxPressureHigh][idxTemp];

                entropy = linearInterpolation1D(pressureLow, h_l, pressureHigh, h_h, pressure);
                return entropy;
            }
            else if(idxTempCheck == FALSE && idxPressureCheck == TRUE)
            {
                double h_l = WPT_entropy[idxPressure][idxTempLow];
                double h_h = WPT_entropy[idxPressure][idxTempHigh];

                entropy = linearInterpolation1D(tempLow, h_l, tempHigh, h_h, temp);
                return entropy;
            }
            else
            {
                entropy = WPT_entropy[idxPressure][idxTemp];
                return entropy;
            }
        }
        else
        {
            printf("set temperature and pressure first!\n");
            return -1;
        }
    }

    void printProperty()
    {
        //printf("-----------------------------------------------------------------------------------------------------\n");
        printf("Water\n");
        if(enthalphy > 0)
            printf("pressure: %lf[MPa], Temperature: %lf[*C], enthalphy: %lf[KJ/Kg]\n", pressure, temp, enthalphy);
        else
            printf("pressure: %lf[MPa], Temperature: %lf[*C], enthalphy: uncalculated\n", pressure, temp);
        printf("-----------------------------------------------------------------------------------------------------\n");
    }

    double findSaturatedGasProperty()
    {  
       if(entropy >= 0)
       {
            for(int i = 0; i < WPT_sat_nData-1; i++)
            {
                if(WPT_sat[i][1] > entropy && entropy >= WPT_sat[i+1][1])
                {
                    enthalphy = linearInterpolation1D(WPT_sat[i+1][1], WPT_sat[i+1][0], WPT_sat[i][1], WPT_sat[i][0], entropy);
                    return enthalphy;
                }
            }
            printf("can not find saturated gas property! \n");
            return -1;
       }
       else
       {
            printf("Set entropy first. \n");
            return -1;
       }
    }
};

#endif