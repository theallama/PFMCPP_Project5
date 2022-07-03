/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
#include<math.h>  

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
        
        void feed(bool isHungry);
        void pet(bool isAffectionate, float minutesToPet);
        void roamNeighborhood(bool rainyWeather, float avgCatTravels = 20.f);
        void roll(int numRolls, int happyIdxOutOfTen);
        void printInfoAboutKitten();
    };
            
    void scratchFurniture(bool isChair = false, int numberOfFurniture = 10);
    void makeNoise(bool foodBowlEmpty = true);
    bool sleep(bool isAsleep = true);
    void typicalCat(std::string, int, float);
    void gainWeight(int weight);
    void printInfoAboutCat();
    
    Kitten kittenJunior;
};

void Cat::printInfoAboutCat()
{
    std::cout << "Mittens has a " << this -> tailLength << " inch long " << this -> furColor << " tail!" << std::endl;
}

void Cat::Kitten::printInfoAboutKitten()
{
    std::cout << "Mittens Junior is " << (2022 - this -> birthYear) << " year old " << this -> catBreed << std::endl;
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
        
        void printDaysLeft(int warrantyBy);
        void informCurrentTime(bool timeUpdated);
        void indicateRepairDate(std::string date, bool needsRepair);
        bool selfCleans(bool heavyCleaning = true, std::string setting = "");
        void turnUpTemp(int ovenTemp);
        void printInfoAboutRangeControls();
    };
    
    void consumeFuel(std::string, int);
    void breaksDown(int ageOfHeatingElement);
    void heatsTheKitchen(int, int);
    void getBigger(int price);
    void printInfoAboutRange();
    
    RangeControls updatedSettings;
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
    
    void generateLift(bool, std::string);
    bool reduceDrag(float tailwind = 10.f);
    void lowersLandingSpeed(int drag, bool landed = false, float landingSpeed = 30.2f);
    void flex(int flex);
    void printInfoAboutPlaneWings();
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
    
    void designSpace(std::string addSlightVariation, int wallWidth);
    void safetyAlertViaWiFi(int currentOvenTemp, int setOvenTemp, int currentTime, std::string newModel);
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
    Cat mittens;
    
    mittens.makeNoise(true);
    mittens.scratchFurniture(false, 10);
    mittens.sleep(true);
    mittens.gainWeight(2);
    
    std::cout << "Mittens has a " << mittens.tailLength << " inch long " << mittens.furColor << " tail!" << std::endl;

    mittens.printInfoAboutCat();
   
    Cat::Kitten mittensJunior;
    
    mittensJunior.feed(true);
    mittensJunior.pet(true, 20);
    mittensJunior.roamNeighborhood(false, 30);
    mittensJunior.roll(8, 6);
    
    std::cout << "Mittens Junior is " << (2022 - mittensJunior.birthYear) << " year old " << mittensJunior.catBreed << std::endl;

    mittensJunior.printInfoAboutKitten();
    
    Range myRange;
    
    myRange.consumeFuel("electric", 65);
    myRange.breaksDown(70);
    myRange.heatsTheKitchen(7, 420);
    myRange.getBigger(1501);
    
    std::cout << "My range has a " << myRange.fuelType << " powered oven that reaches up to " << myRange.maxTempOven
              << " F in temp." << std::endl;

    myRange.printInfoAboutRange();
    
    Range::RangeControls specialFeature;
    specialFeature.printDaysLeft(20220630);
    
    Range::RangeControls backControls;
    
    backControls.informCurrentTime(false);
    backControls.indicateRepairDate("July 25th 2022", true);
    backControls.selfCleans(false, "light");
    backControls.turnUpTemp(350);
    
    std::cout << "The most popular model is " << backControls.controlPanelColor << " with its cotrol panel width of " << backControls.controlPanelWidth << "." << std::endl;

     backControls.printInfoAboutRangeControls();

    
    PlaneWings jjWings;
    
    jjWings.generateLift(true, "down");
    jjWings.reduceDrag(10.f);
    jjWings.lowersLandingSpeed(10, false, 50);
    jjWings.flex(26);
    
    std::cout << "The jumbo jet has a wingspan of " << jjWings.wingSpan << " ft and " << jjWings.numEngines << " engines are attached to the lower side of the wings." << std::endl;

    jjWings.printInfoAboutPlaneWings();


    Kitchen myKitchen;
    
    myKitchen.designSpace("darker", 80);
    myKitchen.safetyAlertViaWiFi(380, 390, 2397, "new");
    
    Concorde concorde;
    
    concorde.lengthDeIcingPanel(10);
    concorde.topSpeed(2);

    std::cout << "good to go!" << std::endl;
}
