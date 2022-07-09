#include <iostream>
#include"Range.h"

void Range::printInfoAboutRange()
{
    std::cout << "My range has a " << this->fuelType << " powered oven that reaches up to " << this->maxTempOven
              << " F in temp." << std::endl;
}
void Range::RangeControls::printInfoAboutRangeControls()
{
    std::cout << "The most popular model is " << this->controlPanelColor << " with its cotrol panel width of " << this->controlPanelWidth << "." << std::endl;
}

Range::RangeControls::RangeControls() : date_(20220628)
{
    std::cout << "RangeControls being constructed" << std::endl;
}

Range::RangeControls::~RangeControls() 
{
    std::cout << "Range being destructed" << std::endl;
}

Range::Range() : numOfRack(3), numOfTops(6) 
{
    std::cout << "Range with " << numOfRack << " oven racks and " << numOfTops
    << " cooktops being constructed" << std::endl;
}

Range::~Range() 
{
    std::cout << "Range being destructed" << std::endl;
}

void Range::getBigger(int price) 
{
    while (numOfTops < 10) 
    {
        for (price = 1500; price <= 1505; ++price) 
        {
            numOfTops += 1;
            std::cout << "Pricier ovens have more cooktops." << std::endl;
        }
    }
    std::cout << "Ovens do not come in a bigger size." << std::endl;
}

void Range::consumeFuel(std::string fuelSource = "electric", int energyEfficiency = 65) 
{
    std::cout << "On average," << fuelSource << " convection oven has "
    << energyEfficiency << " percent cooking energy efficiency."
    << std::endl;
}

void Range::breaksDown(int ageOfHeatingElement) 
{
    if (ageOfHeatingElement >= 50) 
    {
        std::cout << "It'll break down within a year." << std::endl;
    } 
    else if (ageOfHeatingElement > 10 && ageOfHeatingElement < 50) 
    {
        std::cout << "Range can be used for a few more years." << std::endl;
    }
}

void Range::heatsTheKitchen(int durationOperated, int ovenTemp) 
{
    int kitchenTemp = 70;
    if (durationOperated > 0 && ovenTemp > 0) 
    {
        kitchenTemp = kitchenTemp + (ovenTemp / 100) * (durationOperated / 4);
    }
    std::cout << "Currently kitchen temp is " << kitchenTemp << " due to oven use." << std::endl;
}

void Range::RangeControls::turnUpTemp(int ovenTemp = 350) 
{
    while (ovenTemp <= 355) 
    {
        int degreeKnobTurned;
        for (degreeKnobTurned = 0; degreeKnobTurned <= maxKnobTurned;
        ++degreeKnobTurned) 
        {
            ovenTemp += 1;
            std::cout << "Increasing the oven temperature." << std::endl;
        }
    }
    std::cout << "Warning. Oven too hot." << std::endl;
}

void Range::RangeControls::printDaysLeft(int warrantyBy = 20220630) 
{
    daysLeft = warrantyBy - date_;
    std::cout << "You have: " << daysLeft
    << " days left until your warrnty expires." << std::endl;
}

void Range::RangeControls::informCurrentTime(bool timeUpdated) 
{
    std::string updatedTime = "17:00:00", currentTime = "12:00:00";
    if (timeUpdated) 
    {
        std::cout << "Time updated to: " << updatedTime << std::endl;
    }
    std::cout << "Current time is: " << currentTime << std::endl;
}
void Range::RangeControls::indicateRepairDate(std::string const date, bool needsRepair) 
{
    if (needsRepair) 
    {
        std::cout << "Range needs repair by " << date << std::endl;
    } 
    else 
    {
        std::cout << "Range In Good Shape" << std::endl;
    }
}

bool Range::RangeControls::selfCleans(bool heavyCleaning, std::string setting) 
{
    if (setting == "heavy") 
    {
        return heavyCleaning;
    }
    return !heavyCleaning;
}

