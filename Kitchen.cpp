#include "Kitchen.h"

Kitchen::Kitchen() 
{
    std::cout << "Kitchen being constructed." << std::endl;
}

Kitchen::~Kitchen() 
{
    std::cout << "Kitchen being destructed." << std::endl;
}

#include <iostream>
#include "Kitchen.h"

void Kitchen::designSpace(std::string addSlightVariation, int wallWidth) 
{
    std::string themeColor = addSlightVariation + rangeControls.controlPanelColor;
    int measureSpaceForFridge = wallWidth - range.width;
    
    std::cout << "Kitchen will be designed to go with " << themeColor
    << std::endl;
    std::cout << "We still have enough space for a " << measureSpaceForFridge
    << " wide fridge." << std::endl;
}

void Kitchen::safetyAlertViaWiFi(int currentOvenTemp, int setOvenTemp, int currentTime, std::string newModel) 
{
    bool supportsWifi = (newModel == "new")? true : false; 
    
    if (supportsWifi)
    {
        if (currentOvenTemp > 0) 
        {
            while (currentTime < 2400 && currentOvenTemp < setOvenTemp) 
            {
                std::cout << "Alert to oven user : oven is on at " << currentOvenTemp << std::endl;
                currentOvenTemp += 2;
            }
            std::cout << "Auto turn off the oven ." << std::endl;
        }
        else
        {
            std::cout << "Oven is not on." << std::endl;
        }
    }
    else
    {
        std::cout << "This model doesn't support WiFi feature." << std::endl; 
    }
}

