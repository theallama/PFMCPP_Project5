#pragma once
#include "LeakedObjectDetector.h"
#include "PlaneWings.h"

struct Concorde 
{
    PlaneWings pw;
    
    Concorde();
    ~Concorde();
    
    double lengthDeIcingPanel (double variation);
    int topSpeed(int cNumEngines);

    JUCE_LEAK_DETECTOR(Concorde)
};
