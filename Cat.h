#pragma once
#include "LeakedObjectDetector.h"

struct Cat 
{
    Cat();
    ~Cat();
    std::string type;
    int numEars;
    float dailyFoodIntake{5.4f};
    std::string furColor = "brown";
    double tailLength = 5.3432;

    struct Kitten 
    {
        int birthYear{2020};
        Kitten();
        ~Kitten();
        std::string disposition;
        int numLegs = 4;
        int numWhiskers{24};
        std::string catBreed = "Tabby";
        
        void feed(const bool isHungry); 
        void pet(const bool isAffectionate, const float minutesToPet); 
        void roamNeighborhood(const bool rainyWeather, const float avgCatTravels = 20.f);
        void roll(const int numRolls, const int happyIdxOutOfTen); 
        void printInfoAboutKitten(); 
    };
            
    void scratchFurniture(const bool isChair = false, const int numberOfFurniture = 10);
    void makeNoise(const bool foodBowlEmpty = true); 
    bool sleep(const bool isAsleep = true); 
    void typicalCat(const std::string, const int, const float); 
    void gainWeight(const int weight); 
    void printInfoAboutCat();
    
    Kitten kittenJunior;

    JUCE_LEAK_DETECTOR(Cat)
};

