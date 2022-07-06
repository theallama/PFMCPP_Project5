/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */

#include <iostream>
#include <math.h>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */
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
        
        void feed(bool isHungry); FIXME: check if you can use 'const'
        void pet(bool isAffectionate, float minutesToPet); FIXME: check if you can use 'const'
        void roamNeighborhood(bool rainyWeather, float avgCatTravels = 20.f); FIXME: check if you can use 'const'
        void roll(int numRolls, int happyIdxOutOfTen); FIXME: check if you can use 'const'
        void printInfoAboutKitten(); FIXME: check if you can use 'const'
    };
            
    void scratchFurniture(bool isChair = false, int numberOfFurniture = 10); FIXME: check if you can use 'const'
    void makeNoise(bool foodBowlEmpty = true); FIXME: check if you can use 'const'
    bool sleep(bool isAsleep = true); FIXME: check if you can use 'const'
    void typicalCat(std::string, int, float); FIXME: check if you can use 'const'
    void gainWeight(int weight); FIXME: check if you can use 'const'
    void printInfoAboutCat(); FIXME: check if you can use 'const'
    
    Kitten kittenJunior;

    JUCE_LEAK_DETECTOR(Cat)
};

struct CatWrapper
{
    CatWrapper(Cat* catPtr) : pointerToCat(catPtr) {}
    ~CatWrapper()
    {
        delete pointerToCat;
    }
    Cat* pointerToCat = nullptr;
};

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

/*
 copied UDT 2:
 */

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
        
        void printDaysLeft(int warrantyBy); FIXME: check if you can use 'const'
        void informCurrentTime(bool timeUpdated); FIXME: check if you can use 'const'
        void indicateRepairDate(std::string date, bool needsRepair); FIXME: check if you can use 'const'
        bool selfCleans(bool heavyCleaning = true, std::string setting = ""); FIXME: check if you can use 'const'
        void turnUpTemp(int ovenTemp); FIXME: check if you can use 'const'
        void printInfoAboutRangeControls(); FIXME: check if you can use 'const'
    };
    
    void consumeFuel(std::string, int); FIXME: check if you can use 'const'
    void breaksDown(int ageOfHeatingElement); FIXME: check if you can use 'const'
    void heatsTheKitchen(int, int); FIXME: check if you can use 'const'
    void getBigger(int price); FIXME: check if you can use 'const'
    void printInfoAboutRange(); FIXME: check if you can use 'const'
    
    RangeControls updatedSettings;

    JUCE_LEAK_DETECTOR(Range)
};

struct RangeWrapper
{
    RangeWrapper(Range* rPtr) : pointerToRange(rPtr) {}
    ~RangeWrapper()
    {
        delete pointerToRange;
    }
    Range* pointerToRange = nullptr;
};

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
void Range::RangeControls::indicateRepairDate(std::string date, bool needsRepair) 
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

/*
copied UDT 3:
*/
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
    
    void generateLift(bool, std::string); FIXME: check if you can use 'const'
    bool reduceDrag(float tailwind = 10.f); FIXME: check if you can use 'const'
    void lowersLandingSpeed(int drag, bool landed = false, float landingSpeed = 30.2f); FIXME: check if you can use 'const'
    void flex(int flex); FIXME: check if you can use 'const'
    void printInfoAboutPlaneWings(); FIXME: check if you can use 'const'

    JUCE_LEAK_DETECTOR(PlaneWings)
};

struct PlaneWingsWrapper
{
    PlaneWingsWrapper( PlaneWings* pwPtr) : pointerToPlaneWings(pwPtr) {}
    ~PlaneWingsWrapper()
    {
        delete pointerToPlaneWings;
    }
    PlaneWings* pointerToPlaneWings = nullptr;
};

void PlaneWings::printInfoAboutPlaneWings()
{
    std::cout << "'The jumbo jet has a wingspan of " << this->wingSpan << " ft and " << this->numEngines << " engines are attached to the lower side of the wings." << std::endl;
}

PlaneWings::PlaneWings()
: numEngines(4), wingSpan(200)
{
    std::cout << "Jumbo jet wings span " << wingSpan << " feet and have "<< numEngines << " engines attached to them." << std::endl;
}

PlaneWings::~PlaneWings()
{
    std::cout << "Jumbo jet wings span " << wingSpan << " feet and have "<< numEngines << " engines attached to them." << std::endl;
}

void PlaneWings::flex(int flex) 
{
    while (flex < maxFlex) 
    {
        auto ws = wingSpan;
        for (ws = 200; ws <= 202; ++ws) 
        {
            flex += 1;
            std::cout << "Longer the wing, more it can flex." << std::endl;
        }
    }
    std::cout << "Wing broken when flexed over 28ft." << std::endl;
}

void PlaneWings::generateLift (bool upwardForce, std::string airDirection)
{   
    std::string planeStatus = "stays on the ground";
    if (airDirection == "down" && upwardForce)
    {
        planeStatus = "goes up";
    }
    std::cout << "When the air goes " << airDirection << " the upward force creates lift and the plane " << planeStatus << std::endl;
}

bool PlaneWings::reduceDrag (float tailwind)
{
    if(tailwind < 10.f) 
    {
        return true;
    }
    return false;
}
void PlaneWings::lowersLandingSpeed (int drag, bool landed, float landingSpeed )
{
    if(!landed)
    {
        landingSpeed -= drag;
    }
}

/*
new UDT 4:
with 2 member functions
*/
struct Kitchen 
{
    Range range;
    Range::RangeControls rangeControls;
    
    Kitchen();
    ~Kitchen();
    
    void designSpace(std::string addSlightVariation, int wallWidth); FIXME: check if you can use 'const'
    void safetyAlertViaWiFi(int currentOvenTemp, int setOvenTemp, int currentTime, std::string newModel); FIXME: check if you can use 'const'

    JUCE_LEAK_DETECTOR(Kitchen)
};

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* kPtr) : pointerToKitchen(kPtr) {}
    ~KitchenWrapper()
    {
        delete pointerToKitchen;
    }
    Kitchen* pointerToKitchen = nullptr;
};

Kitchen::Kitchen() 
{
    std::cout << "Kitchen being constructed." << std::endl;
}

Kitchen::~Kitchen() 
{
    std::cout << "Kitchen being destructed." << std::endl;
}

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

/*
new UDT 5:
with 2 member functions
*/
struct Concorde 
{
    PlaneWings pw;
    
    Concorde();
    ~Concorde();
    
    double lengthDeIcingPanel (double variation);
    int topSpeed(int cNumEngines);

    JUCE_LEAK_DETECTOR(Concorde)
};

struct ConcordeWrapper
{
    ConcordeWrapper(Concorde* concPtr) : pointerToConcorde(concPtr) {}
    ~ConcordeWrapper()
    {
        delete pointerToConcorde;
    }
    Concorde* pointerToConcorde = nullptr;
};

Concorde::Concorde() 
{
    std::cout << "Concorde being constructed." << std::endl;
}

Concorde::~Concorde() 
{
    std::cout << "Concorde being destructed." << std::endl;
}

double Concorde::lengthDeIcingPanel (double variation)
{
    double d = 60*3.14/180; 
    double hypotenuse = 0;
    double cWingSpan = pw.wingSpan  / 2 - variation;
    hypotenuse = cWingSpan / cos(d);
    return hypotenuse;
}

int Concorde::topSpeed(int cNumEngines) 
{
    int cSpeed;
    while (cNumEngines <= 4) 
    {
        if (cNumEngines == pw.numEngines) 
        {
            cSpeed = pw.maxSpeed * 2;
        }
        cNumEngines += 1;
    }
    return cNumEngines;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left,
 entering a message, and click [Commit and push].

 If you didn't already:
	Make a pull request after you make your first commit
	pin the pull request link and this repl.it link to our DM thread in a single
 message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main() 
{  
    CatWrapper mittensW( new Cat() );
    
    mittensW.pointerToCat->makeNoise(true);
    mittensW.pointerToCat->scratchFurniture(false, 10);
    mittensW.pointerToCat->sleep(true);
    mittensW.pointerToCat->gainWeight(2);
    
    std::cout << "Mittens has a " << mittensW.pointerToCat->tailLength << " inch long " << mittensW.pointerToCat->furColor << " tail!" << std::endl;

    mittensW.pointerToCat->printInfoAboutCat();

    Cat::Kitten mittensJunior;
    
    mittensJunior.feed(true);
    mittensJunior.pet(true, 20);
    mittensJunior.roamNeighborhood(false, 30);
    mittensJunior.roll(8, 6);
    
    std::cout << "Mittens Junior is " << (2022 - mittensJunior.birthYear) << " year old " << mittensJunior.catBreed << std::endl;

    mittensJunior.printInfoAboutKitten();

    RangeWrapper myRangeW( new Range() );
    
    myRangeW.pointerToRange->consumeFuel("electric", 65);
    myRangeW.pointerToRange->breaksDown(70);
    myRangeW.pointerToRange->heatsTheKitchen(7, 420);
    myRangeW.pointerToRange->getBigger(1501);
    
    std::cout << "My range has a " << myRangeW.pointerToRange->fuelType << " powered oven that reaches up to " << myRangeW.pointerToRange->maxTempOven
              << " F in teWmp." << std::endl;

    myRangeW.pointerToRange->printInfoAboutRange();
    
    Range::RangeControls specialFeature;
    specialFeature.printDaysLeft(20220630);
    
    Range::RangeControls backControls;
    
    backControls.informCurrentTime(false);
    backControls.indicateRepairDate("July 25th 2022", true);
    backControls.selfCleans(false, "light");
    backControls.turnUpTemp(350);
    
    std::cout << "The most popular model is " << backControls.controlPanelColor << " with its cotrol panel width of " << backControls.controlPanelWidth << "." << std::endl;

     backControls.printInfoAboutRangeControls();

    PlaneWingsWrapper jjWingsW( new PlaneWings() );
    
    jjWingsW.pointerToPlaneWings->generateLift(true, "down");
    jjWingsW.pointerToPlaneWings->reduceDrag(10.f);
    jjWingsW.pointerToPlaneWings->lowersLandingSpeed(10, false, 50);
    jjWingsW.pointerToPlaneWings->flex(26);
    
    std::cout << "The jumbo jet has a wingspan of " << jjWingsW.pointerToPlaneWings->wingSpan << " ft and " << jjWingsW.pointerToPlaneWings->numEngines << " engines are attached to the lower side of the wings." << std::endl;

    jjWingsW.pointerToPlaneWings->printInfoAboutPlaneWings();

    KitchenWrapper myKitchenW( new Kitchen() );
    
    myKitchenW.pointerToKitchen->designSpace("darker", 80);
    myKitchenW.pointerToKitchen->safetyAlertViaWiFi(380, 390, 2397, "new");
    
    ConcordeWrapper concordeW( new Concorde() );
    
    concordeW.pointerToConcorde->lengthDeIcingPanel(10);
    concordeW.pointerToConcorde->topSpeed(2);

    std::cout << "good to go!" << std::endl;
}
