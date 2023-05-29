#include <stdio.h>
#include <math.h>
#include "constant.h"
#include "water.h"

double WPT[nRow_water][nColumn_water] = 
{
    {62.99,83.95,104.9,125.8,146.7,167.5,188.4,2593,2602,2612,2621,2630,3640,2649,2659,2668,2678,2687,2697,2706,2716,2726,2735,2745,2754,2764,2773,2783,2793,2802,2812,2821,2831,2841,2850,2860,2870,2880,2889,2899,2909,2918,2928,2938,2948,2958,2967,2977,2987,2997,3007,3017,3027,3037},
    {63.08,84.03,105,125.9,146.7,167.6,188.5,209.4,230.3,251.2,272.1,293,314,334.9,355.9,376.9,398,2676,2686,2696,2707,2717,2727,2737,2747,2757,2766,2776,2786,2796,2806,2816,2826,2836,2846,2856,2865,2875,2885,2895,2905,2915,2925,2935,2945,2954,2964,2974,2984,2994,3004,3014,3024,3034},
    {63.17,84.13,105,125.9,146.8,167.7,188.6,209.5,230.4,251.3,272.2,293.1,314,335,356,377,398,419.1,440.2,461.3,482.5,503.7,2717,2727,2738,2748,2758,2769,2779,2789,2800,2810,2820,2830,2840,2850,2860,2870,2881,2891,2901,2911,2921,2931,2941,2951,2961,2971,2981,2991,3001,3011,3021,3031},
    {63.27,84.22,105.1,126,146.9,167.8,188.7,209.6,230.4,251.3,272.3,293.2,314.1,335.1,356.1,377.1,398.1,419.2,440.3,461.4,482.6,503.8,525,546.3,2728,2739,2750,2761,2772,2782,2793,1803,2814,2824,2835,2845,2855,2866,2876,2886,2896,2907,2917,2927,2937,2947,2957,2968,2978,2988,2998,3008,3018,3029},
    {63.37,84.31,105.2,126.1,147,167.9,188.8,109.6,230.5,251.4,272.3,293.3,314.2,335.2,356.1,377.2,398.2,419.2,440.3,461.5,482.7,503.8,525.1,546.4,567.7,589.1,2742,2753,2764,2775,2786,2797,2807,2818,2829,2839,2850,2861,2871,2881,2892,2902,2913,2923,2933,2944,2954,2964,2974,2985,2995,3005,2015,3026},
    {63.46,84.41,105.3,126.2,147.1,168,188.9,209.7,230.6,251.5,272.4,293.3,314.3,335.2,356.2,377.2,398.3,419.3,440.4,461.5,482.7,503.9,525.1,546.4,567.8,589.2,610.7,632.2,2756,2767,2779,2790,2801,2812,2823,2834,2845,2855,2866,2877,2887,2898,2908,2919,2929,2940,2950,2961,2971,2981,2992,3002,3013,3023},
    {63.56,84.5,105.4,126.3,147.2,168.1,188.9,209.8,230.7,251.6,272.5,293.4,314.4,335.5,356.3,377.3,398.3,419.4,440.5,461.6,482.8,504,525.2,546.5,567.9,589.3,610.7,632.3,653.9,2760,2771,2783,2794,2806,2817,2828,2839,2850,2861,2872,2883,2893,2904,2915,2925,2936,2947,2957,2968,2978,2989,2999,3010,3020},
    {63.65,84.6,105.5,126.4,147.3,168.2,189,209.9,230.8,251.7,272.6,293.5,314.4,335.4,356.4,377.4,398.4,419.5,440.6,461.7,482.8,504,525.3,546.6,567.9,589.3,610.8,632.3,653.9,675.6,2764,2776,2787,2799,2811,2822,2833,2845,2856,2867,2878,2889,2900,2911,2921,2932,2943,2954,2964,2975,2985,2996,3007,3017},
    {63.75,84.69,105.6,126.5,147.4,168.2,189.1,210,230.9,251.8,272.7,293.6,314.5,335.5,356.5,377.5,398.5,419.5,440.6,461.8,482.9,504.1,525.4,546.7,568,589.4,610.9,632.4,654,675.6,697.4,719.2,2780,2792,2804,2816,2828,2839,2851,2862,2873,2884,2895,2906,2917,2928,2939,2950,2961,2971,2982,2993,3003,3014},
    {63.84,84.79,105.7,126.6,147.5,168.3,189.2,210.1,231,251.8,272.7,293.7,314.6,335.6,356.5,377.5,398.6,419.6,440.7,461.8,483,504.2,525.4,546.7,568.1,589.5,610.9,632.4,654,675.7,697.4,719.3,741.2,2785,2798,2810,2822,2834,2845,2857,2868,2880,2891,2902,2913,2924,2935,2946,2957,2968,2979,2990,3000,3011},
    {63.94,84.88,105.8,126.7,147.6,168.4,189.3,210.2,231,251.9,272.8,293.8,314.7,335.6,356.6,377.6,398.6,419.7,440.8,461.9,483.1,504.3,525.5,546.8,568.1,589.5,611,632.5,654.1,675.8,697.5,719.3,741.2,2778,2791,2803,2816,2828,2840,2852,2863,2875,2886,2898,2909,2920,2931,2943,2954,2965,2976,2986,2997,3008},
    {64.04,84.97,105.9,126.8,147.6,168.5,189.4,210.2,231.1,252,272.9,293.8,314.8,335.7,356.7,377.7,398.7,419.8,440.9,462,483.1,504.3,525.6,546.9,568.2,589.6,611,632.6,654.2,675.8,697.5,719.4,741.3,763.3,2784,2797,2810,2822,2834,2846,2858,2870,2882,2893,2905,2916,2928,2939,2950,2961,2972,2983,2994,3005},
    {64.13,85.07,106,126.9,147.7,168.6,189.5,210.3,231.2,252.1,273,293.9,314.8,335.8,356.8,377.8,398.8,419.8,440.9,462,483.2,504.4,525.6,546.9,568.3,589.7,611.1,632.6,654.2,675.9,697.6,719.4,741.3,763.3,785.4,2790,2803,2816,2828,2841,2853,2865,2877,2889,2901,2912,2924,2935,2946,2958,2969,2980,2991,3002},
    {64.23,85.16,106.1,127,147.8,168.7,189.5,210.4,231.3,252.2,273.1,294,314.9,335.9,356.9,377.8,398.9,419.9,441,462.1,483.3,504.5,525.7,547,568.3,589.7,611.2,632.7,654.3,675.9,697.7,719.5,741.4,763.4,785.4,807.6,2797,2810,2823,2835,2848,2860,2872,2884,2896,2908,2920,2931,2943,2954,2965,2977,2988,2999},
    {64.32,85.26,106.2,127,147.9,168.8,189.6,210.5,231.4,252.3,273.2,294.1,315,336,356.9,377.9,398.9,420,441.1,462.2,483.3,504.5,525.8,547.1,568.4,589.8,611.2,632.8,654.3,676,697.7,719.5,741.4,763.4,785.5,807.7,830,2803,2817,2830,2842,2855,2867,2880,2892,2904,2915,2927,2939,2950,2962,2973,2985,2996},
    {64.42,85.35,106.3,127.1,148,168.9,189.7,210.6,231.5,252.3,273.2,294.2,315.1,336,357,378,399,420.1,441.2,462.3,483.4,504.6,525.8,547.1,568.5,589.9,611.3,632.8,654.4,676,697.8,719.6,741.5,763.5,785.5,807.7,830,2797,2810,2824,2837,2850,2862,2875,2887,2899,2911,2923,2935,2947,2958,2970,2981,2993}
}; // Water Property Table


double WPT_entropy[nRow_water][nColumn_water] = 
{
    {-1,-1,-1,-1,-1,-1,-1,8.174,8.2015,8.229,8.2565,8.284,8.3115,8.339,8.3665,8.394,8.4215,8.449,8.473,8.497,8.521,8.545,8.569,8.593,8.617,8.641,8.665,8.689,8.7106,8.7322,8.7538,8.7754,8.797,8.8186,8.8402,8.8618,8.8834,8.905,8.9247,8.9444,8.9641,8.9838,9.0035,9.0232,9.0429,9.0626,9.0823,9.102,9.1201,9.1382,9.1563,9.1744,9.1925,9.2106},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7.361,7.3864,7.4118,7.4372,7.4626,7.488,7.5134,7.5388,7.5642,7.5896,7.615,7.6371,7.6592,7.6813,7.7034,7.7255,7.7476,7.7697,7.7918,7.8139,7.836,7.8559,7.8758,7.8957,7.9156,7.9355,7.9554,7.9753,7.9952,8.0151,8.035,8.0532,8.0714,8.0896,8.1078,8.126,8.1442},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7.281,7.3037,7.3264,7.3491,7.3718,7.3945,7.4172,7.4399,7.4626,7.4853,7.508,7.5282,7.5484,7.5686,7.5888,7.609,7.6292,7.6494,7.6696,7.6898,7.71,7.7284,7.7468,7.7652,7.7836,7.802,7.8204},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7.079,7.1024,7.1258,7.1492,7.1726,7.196,7.2194,7.2428,7.2662,7.2896,7.313,7.3335,7.354,7.3745,7.395,7.4155,7.436,7.4565,7.477,7.4975,7.518,7.5366,7.5552,7.5738,7.5924,7.611,7.6296},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.931,6.9551,6.9792,7.0033,7.0274,7.0515,7.0756,7.0997,7.1238,7.1479,7.172,7.1928,7.2136,7.2344,7.2552,7.276,7.2968,7.3176,7.3384,7.3592,7.38,7.3988,7.4176,7.4364,7.4552,7.474,7.4928},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7.061,7.0821,7.1032,7.1243,7.1454,7.1665,7.1876,7.2087,7.2298,7.2509,7.272,7.2909,7.3098,7.3287,7.3476,7.3665,7.3854},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.968,6.9895,7.011,7.0325,7.054,7.0755,7.097,7.1185,7.14,7.1615,7.183,7.2021,7.2212,7.2403,7.2594,7.2785,7.2976},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.893,6.91485,6.9367,6.95855,6.9804,7.00225,7.0241,7.04595,7.0678,7.08965,7.1115,7.1308,7.1501,7.1694,7.1887,7.208,7.2273},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.818,6.8402,6.8624,6.8846,6.9068,6.929,6.9512,6.9734,6.9956,7.0178,7.04,7.0595,7.079,7.0985,7.118,7.1375,7.157},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.757,6.77965,6.8023,6.82495,6.8476,6.87025,6.8929,6.91555,6.9382,6.96085,6.9835,7.00315,7.0228,7.04245,7.0621,7.08175,7.1014},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.696,6.7191,6.7422,6.7653,6.7884,6.8115,6.8346,6.8577,6.8808,6.9039,6.927,6.9468,6.9666,6.9864,7.0062,7.026,7.0458},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.6435,6.66705,6.6906,6.71415,6.7377,6.76125,6.7848,6.80835,6.8319,6.85545,6.879,6.89905,6.9191,6.93915,6.9592,6.97925,6.9993},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.591,6.615,6.639,6.663,6.687,6.711,6.735,6.759,6.783,6.807,6.831,6.8513,6.8716,6.8919,6.9122,6.9325,6.9528},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.5445,6.56905,6.5936,6.61815,6.6427,6.66725,6.6918,6.71635,6.7409,6.76545,6.79,6.81045,6.8309,6.85135,6.8718,6.89225,6.9127},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.498,6.5231,6.5482,6.5733,6.5984,6.6235,6.6486,6.6737,6.6988,6.7239,6.749,6.7696,6.7902,6.8108,6.8314,6.852,6.8726},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.564,6.5936,6.6232,6.6528,6.6824,6.712,6.73285,6.7537,6.77455,6.7954,6.81625,6.8371},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6.554,6.5782,6.6024,6.6266,6.6508,6.675,6.6961,6.7172,6.7383,6.7594,6.7805,6.8016}
};

double WPT_sat[WPT_sat_nData][3] =
{
    {2583.9,8.149},
    {2645.2,7.593},
    {2674.9,7.359},
    {2706.2,7.127},
    {2724.9,6.992},
    {2738.1,6.896},
    {2748.1,6.821},
    {2756.1,6.759},
    {2768.3,6.662},
    {2777.1,6.585},
    {2783.7,6.522},
    {2788.8,6.468},
    {2792.8,6.420},
    {2795.9,6.378},
    {2798.3,6.339},
    {2801.9,6.256},
    {2803.2,6.186},
    {2802.6,6.124},
    {2800.8,6.070},
    {2797.9,6.020},
    {2794.2,5.974},
    {2784.6,5.890},
    {2772.6,5.815},
    {2758.7,5.745},
    {2742.9,5.679},
    {2725.5,5.616},
    {2674.3,5.464},
    {2610.7,5.311},
    {2529.3,5.143},
    {2412.3,4.931},
    {1849.4,4.034},
    {1791.8,3.931},
    {1742.6,3.829}
}; // enthalphy, entropy

int WPTpressureToIndex(double pressure)
{
    int idx = (pressure - WPT_startPressure)/WPT_pressureInterver;
    return idx;
}

double WPTindexToPressure(int idx)
{
    double pressure = idx * WPT_pressureInterver + WPT_startPressure;
    return pressure;
}

int WPTtempToIndex(double temp)
{
    int idx = (temp - WPT_startTemp)/WPT_tempInterver;
    return idx;
}

double WPTindexToTemp(int idx)
{
    double temp = idx * WPT_tempInterver + WPT_startTemp;
    return temp;
}



