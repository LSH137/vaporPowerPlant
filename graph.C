#include<stdio.h>
#include "Riostream.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TMultiGraph.h"

#define TRUE 1
#define FALSE 0
#define nSTEP 100
#define nData 501

char fileName[150];
char graphName[150];

void graph()
{
    FILE* fp_data = nullptr;
    double y;
    double tempReheat;
    double efficient;
    double workRatio;
    double p3;

    auto canvas2DEffiency = new TCanvas("efficiency_by_workRatio|reheatTemp","efficiency_by_workRatio|reheatTemp",800, 600);
    auto canvas2DWorkRatio = new TCanvas("efficiency_by_workRatio|reheatTemp","efficiency_by_workRatio|reheatTemp",800, 600);
    auto graph2DEffiency = new TGraph2D();
    auto graph2DWorkRatio = new TGraph2D();

    for(int i = 0; i <= nSTEP; i++)
    {
        // auto efficientCanvas = new TCanvas("efficiency:reheatTemp","efficiency:reheatTemp",800, 600);
        // auto workRatioCanvas = new TCanvas("workRatio:reheatTemp","workRatio:reheatTemp",800, 600);
        auto canvas = new TCanvas("ratio:reheatTemp","ratio:reheatTemp",800, 600);
        

        TGraph* efficientGraph = new TGraph();
        TGraph* workRatioGraph = new TGraph();


        auto mg = new TMultiGraph();

        y = (double)i/nSTEP;
        sprintf(fileName, "/home/lsh/Documents/program/vaporPowerPlant/result/water_parameter=reheat_temp_y=%.2lf.csv", y);
        printf("file name = %s\n", fileName);

        //open file
        fp_data = fopen64(fileName, "r");

        // read all
        if(fp_data != nullptr)
        {
            for(int j = 0; j < nData; j++)
            {
                fscanf(fp_data, "%lf, %lf, %lf, %lf", &tempReheat, &efficient, &workRatio, &p3);
                //printf("temp: %lf, effiency: %lf, work ratio: %lf\n", tempReheat, efficient, workRatio);
                efficientGraph -> SetPoint(efficientGraph->GetN(), tempReheat, efficient*100);
                workRatioGraph -> SetPoint(workRatioGraph->GetN(), tempReheat, workRatio*100);
                graph2DEffiency -> SetPoint(graph2DEffiency->GetN(), tempReheat, y*100, efficient*100);
                graph2DWorkRatio -> SetPoint(graph2DWorkRatio->GetN(), tempReheat, y*100, workRatio*100);
            }

            // draw efficiency graph
            //efficientCanvas -> cd();
            sprintf(graphName, "efficiency by T2 (y=%.2f)", y);
            efficientGraph -> SetTitle(graphName);
            efficientGraph -> SetMarkerColor(kBlue);
            efficientGraph -> SetMarkerSize(0.5);
            efficientGraph -> SetMarkerStyle(34);
            //efficientGraph -> GetXaxis()->SetTitle("temp[deg C]");
            //efficientGraph -> GetYaxis()->SetTitle("effciency[%]");

            //efficientGraph -> Draw("AP");

            sprintf(fileName, "/home/lsh/Documents/program/vaporPowerPlant/result/graph/water_parameter=reheat_temp_y=%.2lf_efficiency.png", y);
            //efficientCanvas -> SaveAs(fileName);

            // draw work ratio graph
            //workRatioCanvas -> cd();
            sprintf(graphName, "work ratio by T2 (y=%.2f)", y);
            workRatioGraph -> SetTitle(graphName);
            workRatioGraph -> SetMarkerColor(kOrange);
            workRatioGraph -> SetMarkerSize(0.5);
            workRatioGraph -> SetMarkerStyle(34);
            //workRatioGraph -> GetXaxis()->SetTitle("temp[deg C]");
            //workRatioGraph -> GetYaxis()->SetTitle("workRatio [W_t/(W_t+Q_load)*100, %]");

            //workRatioGraph -> Draw("AP");

            sprintf(fileName, "/home/lsh/Documents/program/vaporPowerPlant/result/graph/water_parameter=reheat_temp_y=%.2lfworkRatio.png", y);
            //workRatioCanvas -> SaveAs(fileName);

            // draw multigraph
            canvas->cd();
            sprintf(graphName, "work ratio and efficiency by T2 (y=%.2f)", y);
            mg -> SetTitle(graphName);
            mg->Add(efficientGraph, "PL");
            mg->Add(workRatioGraph, "PL");
            mg -> GetXaxis()->SetTitle("temp[deg C]");
            mg -> GetYaxis()->SetTitle("ratio[%]");
            mg->GetYaxis()->SetRangeUser(0, 100);
            mg->Draw("AP");

            canvas->BuildLegend();
            sprintf(fileName, "/home/lsh/Documents/program/vaporPowerPlant/result/graph/water_parameter=reheat_temp_y=%.2lf.png", y);
            canvas -> SaveAs(fileName);

            fclose(fp_data);

        }
    }
    canvas2DEffiency -> cd();
    //canvas2D -> SetLogz();
    graph2DEffiency->SetTitle("efficiency by T2 and y; ; y[%]; efficiency[%]");
    graph2DEffiency->Draw("surf1");
    canvas2DEffiency -> SaveAs("2DGraph_effiency.png");

    
    canvas2DWorkRatio -> cd();
    //canvas2D -> SetLogz();
    graph2DWorkRatio->SetTitle("workRatio by T2 and y; ; y[%]; workRatio[%]");
    graph2DWorkRatio->Draw("surf1");
    canvas2DWorkRatio -> SaveAs("2DGraph_workRatio.png");
}