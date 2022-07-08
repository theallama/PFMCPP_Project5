#pragma once
#include "LeakedObjectDetector.h"

struct Range 
{
    Range();
    ~Range();
    int numOfRack;
    int maxTempOven = 450;
    std::string fuelType = "gas";
    int numOfTops;
    int width = 36;
    std::string newModel;
    
    struct RangeControls 
    {
        int date_;
        RangeControls();
        ~RangeControls();
        std::string clockSettingOption{"24hrs"};
        int daysLeft;
        std::string controlPanelColor = "chrome";
        int controlPanelWidth = 24;
        bool isAnalog = false;
        int maxKnobTurned = 10;
        
        void printDaysLeft(const int warrantyBy); 
        void informCurrentTime(const bool timeUpdated); 
        void indicateRepairDate(const std::string date, const bool needsRepair); 
        bool selfCleans(const bool heavyCleaning = true, const std::string setting = ""); 
        void turnUpTemp(const int ovenTemp); 
        void printInfoAboutRangeControls();
    };
    
    void consumeFuel(const std::string, const int); 
    void breaksDown(const int ageOfHeatingElement); 
    void heatsTheKitchen(const int, const int); 
    void getBigger(const int price); 
    void printInfoAboutRange(); 
    
    RangeControls updatedSettings;

    JUCE_LEAK_DETECTOR(Range)
};

