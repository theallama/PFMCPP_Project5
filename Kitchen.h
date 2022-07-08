#pragma once
#include "LeakedObjectDetector.h"
#include "Range.h"

struct Kitchen 
{
    Range range;
    Range::RangeControls rangeControls;
    
    Kitchen();
    ~Kitchen();
    
    void designSpace(const std::string addSlightVariation, const int wallWidth); 
    void safetyAlertViaWiFi(const int currentOvenTemp, const int setOvenTemp, const int currentTime, std::string newModel);

    JUCE_LEAK_DETECTOR(Kitchen)
};
