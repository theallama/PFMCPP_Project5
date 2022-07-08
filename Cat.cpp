#include <iostream>
#include"Cat.h"

void Cat::printInfoAboutCat()
{
    std::cout << "Mittens has a " << this->tailLength << " inch long " << this->furColor << " tail!" << std::endl;
}

void Cat::Kitten::printInfoAboutKitten()
{
    std::cout << "Mittens Junior is " << (2022 - this->birthYear) << " year old " << this->catBreed << std::endl;
}

Cat::Cat() : type("domesticated"), numEars(2), dailyFoodIntake(5.1f) 
{
    std::cout << "A typical " << type << " cat  has " << numEars << " ears and eats one " << dailyFoodIntake << " oz can of cat food a day." << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Cat being destructed!" << std::endl;
}

Cat::Kitten::~Kitten() 
{
    std::cout << "Kitten being destructed!" << std::endl;
}

Cat::Kitten::Kitten() : disposition("nice"), numWhiskers(26) 
{
    std::cout << "A " << disposition << " kitten with " << numWhiskers
    << " whiskers being constructed!" << std::endl;
}

void Cat::Kitten::roll(int numRolls, int happyIdxOutOfTen = 0) 
{
    auto hi = happyIdxOutOfTen;
    while (numRolls < 30) 
    {
        for (hi = 1; hi <= 9; ++hi) 
        {
            numRolls += 10;
            std::cout << "Kitten rolls " << numRolls << " times on the floor."
            << std::endl;
        }
    }
    std::cout << "Kitten is feeling too dizzy to roll anymore." << std::endl;
}

void Cat::Kitten::feed(bool isHungry)
{
    float singlePortion = 0;
    if (isHungry) 
    {
        singlePortion = 6.f;
    }
    std::cout << "Kitty can have " << singlePortion << " oz of food." << std::endl;
}

void Cat::Kitten::pet(bool isAffectionate, float minutesToPet) 
{
    if (isAffectionate) 
    {
        minutesToPet = 20.f;
    }
}
void Cat::Kitten::roamNeighborhood(bool rainyWeather, float avgCatTravels)
{
    float milesTraveled;
    if (!rainyWeather) 
    {
        milesTraveled = avgCatTravels * 2;
    }
}

void Cat::gainWeight(int weight) 
{
    int overweightThreshold = 30;
    int week;
    while (weight < overweightThreshold) 
    {
        for (week = 1; week <= 4; week++) 
        {
            dailyFoodIntake += 3.f;
            std::cout << "Kitty eating more and more every day" << std::endl;
            weight += 5;
        }
    }
    std::cout << "Kitty on a diet." << weight << std::endl;
}

void Cat::scratchFurniture(bool isChair, int numFurnitureDestroyed) 
{
    if (!isChair) 
    {
        numFurnitureDestroyed += 1;
    }
}

void Cat::makeNoise(bool foodBowlEmpty) 
{
    std::string noise = "";
    if (foodBowlEmpty) 
    {
        noise = "meow";
    } 
    else 
    {
        noise = "purr";
    }
    std::cout << "Cat goes: " << noise << std::endl;
}

struct Time 
{
    int year = 2022, 
    month = 6, 
    day = 23, 
    hour = 7, 
    minute = 1, 
    second = 5;
    bool isPM = true;
};

bool Cat::sleep(bool isAsleep) 
{
    Time startTime, endTime;
    startTime.hour = 0;
    endTime.hour = 5;
    
    if (startTime.hour > 0 && startTime.isPM == false && endTime.hour < 5 && endTime.isPM == false) 
    {
        return isAsleep;
    }
    return !isAsleep;
}

