#pragma once
#include "LeakedObjectDetector.h"

struct PlaneWings 
{
    PlaneWings();
    ~PlaneWings();
    
    int maxFlex = 28;
    int fuelCarried = 23;
    int numOfAilerons = 4;
    int numEngines = 4;
    double wingSpan;
    int maxSpeed = 656;
    
    void generateLift(const bool, const std::string); 
    bool reduceDrag(const float tailwind = 10.f); 
    void lowersLandingSpeed(const int drag, const bool landed = false, const float landingSpeed = 30.2f); 
    void flex(const int flex); 
    void printInfoAboutPlaneWings(); 

    JUCE_LEAK_DETECTOR(PlaneWings)
};
