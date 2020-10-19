//
//  Easing.hpp
//  CPP_Ease
//
//  Created by Chaos_F-Rog on 2020/10/16.
//

#pragma once
#include <stdio.h>
#include <cmath>

#define _USE_MATH_DEFINES

class Easing {
    private:
    public:
        /* イージング Sine */
        static double Ease_In_Sine(double, double, double);
        static double Ease_Out_Sine(double, double, double);
        static double Ease_InOut_Sine(double, double, double);
    
        /* イージング Quad */
        static double Ease_In_Quad(double, double, double);
        static double Ease_Out_Quad(double, double, double);
        static double Ease_InOut_Quad(double, double, double);
        
        /* イージング Cubic */
        static double Ease_In_Cubic(double, double, double);
        static double Ease_Out_Cubic(double, double, double);
        static double Ease_InOut_Cubic(double, double, double);
        
        /* イージング Quart */
        static double Ease_In_Quart(double, double, double);
        static double Ease_Out_Quart(double, double, double);
        static double Ease_InOut_Quart(double, double, double);
};
