//
//  Easing.cpp
//  CPP_Ease
//
//  Created by Chaos_F-Rog on 2020/10/16.
//

#include "Easing.hpp"

/* イージング Sine */
double Easing::Ease_In_Sine(double first, double end, double t) {
    double dif = end - first;
    return dif * (1 - cos((t * M_PI) / 2)) + first;
}

double Easing::Ease_Out_Sine(double first, double end, double t) {
    double dif = end - first;
    return dif * sin((t * M_PI) / 2) + first;
}

double Easing::Ease_InOut_Sine(double first, double end, double t) {
    double dif = end - first;
    return dif * (-(cos(t * M_PI) - 1) / 2) + first;
}


/* イージング Quad */
double Easing::Ease_In_Quad(double first, double end, double t) {
    double dif = end - first;
    return dif * pow(t, 2) + first;
}
double Easing::Ease_Out_Quad(double first, double end, double t) {
    double dif = end - first;
    return dif * (1 - pow(1 - t, 2)) + first;
}
double Easing::Ease_InOut_Quad(double first, double end, double t) {
    double dif = end - first;
    if(t < 0.5) {
        return dif * (2 * pow(t, 2)) + first;
    } else {
        return dif * (1 - pow(-2 * t + 2, 2) / 2) + first;
    }
}


/* イージング Cubic */
double Easing::Ease_In_Cubic(double first, double end, double t) {
    double dif = end - first;
    return dif * pow(t, 3) + first;
}

double Easing::Ease_Out_Cubic(double first, double end, double t) {
    double dif = end - first;
    return dif * (1 - pow(1 - t, 3)) + first;
}

double Easing::Ease_InOut_Cubic(double first, double end, double t) {
    double dif = end - first;
    if(t < 0.5) {
        return dif * (4 * pow(t, 3)) + first;
    } else {
        return dif * (1 - pow(-2 * t + 2, 3) / 2) + first;
    }
}


/* イージング Quart */
double Easing::Ease_In_Quart(double first, double end, double t) {
    double dif = end - first;
    return dif * pow(t, 4) + first;
}

double Easing::Ease_Out_Quart(double first, double end, double t) {
    double dif = end - first;
    return dif * (1 - pow(1 - t, 4)) + first;
}

double Easing::Ease_InOut_Quart(double first, double end, double t) {
    double dif = end - first;
    if(t < 0.5) {
        return dif * (8 * pow(t, 4)) + first;
    } else {
        return dif * (1 - pow(-2 * t + 2, 4) / 2) + first;
    }
}
