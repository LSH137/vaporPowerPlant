#include "water.h"
#include "R22.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#define nSTEP 1000
#define T1 280
#define P1 1.5

#define T2 120.2
#define P2 0.2


double mdot = 1; // 1 kg/s
double y = 0.15;

int main(void)
{
    double Wt1_dot;
    double Wt2_dot;
    double Wp_dot;
    double Qload_dot;
    double Qin_dot;

    double e;
    double workRatio;

    // stage 1
    water w1;
    printf("<< state 1 >>\n");
    w1.setPressure(P1);
    w1.setTemp(T1);
    double h1 = w1.getEnthalphy();
    w1.printProperty();

    // stage 2
    water w2;
    printf("<< state 2 >>\n");
    w2.setPressure(P2);
    w2.setTemp(T2);
    double h2 = 2625;
    w2.setEnthalphy(h2);
    w2.printProperty();

    // stage 3
    water w3;
    printf("<< state 3 >>\n");
    w3.setPressure(0.01);
    w3.setTemp(45.81);
    double h3 = 2280.4;
    w3.setEnthalphy(h3);
    w3.printProperty();

    // state 6
    water w6;
    printf("<< state 6 >>\n");
    w6.setPressure(0.1);
    w6.setTemp(60);
    double h6 = w6.getEnthalphy();
    w6.printProperty();

    // state 5
    water w5;
    printf("<< state 5 >>\n");
    w5.setPressure(1.5);
    w5.setTemp(45.87);
    double h5 = w5.getEnthalphy();
    w5.printProperty();

    // state 4
    water w4;
    printf("<< state 4 >>\n");
    w4.setPressure(0.01);
    w4.setTemp(45.81);
    double h4 = 191.83;
    w4.setEnthalphy(h4);
    w4.printProperty();


    // // parameter = y
    // std::ofstream dataFile;
    // dataFile.open("water_parameter=y.csv");

    // for(int i = 0; i <= nSTEP; i++)
    // {
    //     y = (double)i/nSTEP;
    //     printf("-------------------------------------------------------------------------------\n");
    //     printf("---------------------------------<< y = %lf >>---------------------------------\n", y);
    //     Wt1_dot = mdot*(h1 - h2);
    //     Wt2_dot = mdot*(1-y)*(h2 - h3);
    //     Wp_dot = mdot*(h5 - h4);

    //     Qload_dot = mdot*y*(h2 - h6);
    //     Qin_dot = mdot*(h1 - h5);

    //     printf("Wt1_dot = %lf, Wt_2_dot = %lf, Wp_dot = %lf, Qload_dot = %lf, Qin_dot = %lf\n", Wt1_dot, Wt2_dot, Wp_dot, Qload_dot, Qin_dot);

    //     e = (Wt1_dot + Wt2_dot + Qload_dot - Wp_dot)/Qin_dot;
    //     workRatio = (Wt1_dot + Wt2_dot) / (Wt1_dot + Wt2_dot + Qload_dot);
    //     printf("efficiency = %lf, workRatio = %lf\n", e, workRatio);

    //     dataFile << y << "," << e << "," << workRatio << "\n";
    // }
    // dataFile << std::endl;
    // dataFile.close();


    // parameter = reheat temp
    
    char dataFileName[250];
    for(int j = 0; j <= nSTEP; j++)
    {
        y = (double)j/nSTEP;

        if(y==0.4) printf("====================================== y = %.2f ===============================\n", y);
        sprintf(dataFileName, "/home/lsh/Documents/program/vaporPowerPlant/result/water_parameter=reheat_temp_y=%.2lf.csv", y);
        std::ofstream reheatDataFile;
        reheatDataFile.open(dataFileName);

        double reheatTemp;
        water w8;
        double h8;
        double Qreheat_dot;
        for(int i = nSTEP/2; i <= nSTEP; i++)
        {
            reheatTemp = (T1 - T2) * ((double)i/nSTEP) + T2;
            w8.setTemp(reheatTemp);
            w8.setPressure(P2);
            h8 = w8.getEnthalphy();

            w3.setTemp(reheatTemp);
            w3.setPressure(P2);
            w3.getEntropy();
            h3 = w3.findSaturatedGasProperty(); 

            Wt1_dot = mdot*(h1 - h2);
            Wt2_dot = mdot*(1 - y)*(h8 - h3);
            Wp_dot = mdot*(h5 - h4);

            if(y==0.4)printf("-- turbine 1: %lf KW\n", Wt1_dot);
            if(y==0.4)printf("-- turbine 2: %lf KW\n", Wt2_dot);


            Qload_dot = mdot*y*(h2 - h6);
            Qin_dot = mdot*(h1 - h5);
            Qreheat_dot = mdot*(1-y)*(h8 - h2);

            e = (Wt1_dot + Wt2_dot + Qload_dot - Wp_dot)/(Qin_dot + Qreheat_dot);
            workRatio = (Wt1_dot + Wt2_dot) / (Wt1_dot + Wt2_dot + Qload_dot);
            if(y==0.4)printf("efficiency = %lf, workRatio = %lf, pressure_3 = %lf, work_dot = %lf, h8 = %lf, h3 = %lf, Qreheat_dot= %lf\n", e, workRatio, w3.pressure, Wt1_dot+Wt2_dot, h8, h3, Qreheat_dot);

            reheatDataFile << reheatTemp << "," << e << "," << workRatio << "," << w3.pressure << "\n";
        }   
        reheatDataFile << std::endl;
        reheatDataFile.close();
    }
    


    return 0;
}
