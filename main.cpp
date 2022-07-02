/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
    you will learn how to take code from existing projects and migrate only what you need to new projects
    you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
    One for if you completed project 3
    One for if you skipped project 3.

 Destructors

===============================================================
 If you completed Project 3:

 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
     Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
	make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have:
	5 member variables
		the member variable names and types should be relevant to the work
the UDT will perform. 
        pick properties that can be represented with 'int float
double bool char std::string' 
    3 member functions with an arbitrary number of
parameters give some of those parameters default values. constructors that
initialize some of these member variables the remaining member variables should
be initialized in-class for() or while() loops that modify member variables 
 1) 2 of your 3 UDTs need to have a nested UDT. this nested UDT should fulfill the
same requirements as above: 5 member variables 3 member functions constructors
and loops.
 2) Define your implementations of all functions OUTSIDE of the class.
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
	make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new
UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.
		maybe print out the name of the class being destructed, or call a member
function of one of the members.  be creative

 7) copy over your main() from the end of Project3
		get it to compile with the types you copied over.
		remove any code in main() that uses types you didn't copy over.

 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
	   call their member functions.

 9) After you finish, click the [run] button.  Clear up any errors or warnings
as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list
of compiler arguments in the .replit file. all of the "-Wno" in that file are
compiler arguments. You can resolve any [-Wpadded] warnings by adding
-Wno-padded to the list of compiler arguments in the .replit file. all of the
"-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>

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
    };
    
    void scratchFurniture(bool isChair = false, int numberOfFurniture = 10);
    void makeNoise(bool foodBowlEmpty = true);
    bool sleep(bool isAsleep = true);
    void typicalCat(std::string, int, float);
    void gainWeight(int weight);
    
    Kitten kittenJunior;
};

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

struct Range {
	Range();
	~Range();
	int numOfRack;
	int maxTempOven = 450;
	std::string fuelType = "gas";
	int numOfTops;
	int width = 36;

	struct RangeControls 
    {
		int date_;
		RangeControls() : date_(20220628) {}
		~RangeControls() 
        {
			std::cout << "Range being destructed" << std::endl;
		}
		std::string clockSettingOption{"24hrs"};
		int daysLeft;
		std::string controlPanelColor = "chrome";
		int controlPanelWidth = 24;
		bool supportsWifi = true;
		bool isAnalog = false;
		int maxKnobTurned = 10;

		void printDaysLeft(int warrantyBy);
		void informCurrentTime(bool timeUpdated);
		void indicateRepairDate(std::string date, bool needsRepair);
		bool selfCleans(bool heavyCleaning = true, std::string setting = "");
		void turnUpTemp(int ovenTemp);
	};

	void consumeFuel(std::string, int);
	void breaksDown(int ageOfHeatingElement);
	void heatsTheKitchen(int, int);
	void getBigger(int price);

	RangeControls updatedSettings;
};

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

void Range::consumeFuel(
	std::string fuelSource = "electric",
	int energyEfficiency = 65) 
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
	std::cout << "Currently kitchen temp is " << kitchenTemp
			  << " due to oven use." << std::endl;
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
	int wingSpan;
	int maxSpeed = 656;

	void generateLift(bool, std::string);
	bool reduceDrag(float tailwind = 10.f);
	void lowersLandingSpeed(int drag, bool landed = false, float landingSpeed = 30.2f);
	void flex(int flex);
};

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
        return true;
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
	void safetyAlertViaWiFi(int currentOvenTemp, int setOvenTemp, int currentTime);
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
	std::string themeColor =
		addSlightVariation + rangeControls.controlPanelColor;
	int measureSpaceForFridge = wallWidth - range.width;

	std::cout << "Kitchen will be designed to go with " << themeColor
			  << std::endl;
	std::cout << "We still have enough space for a " << measureSpaceForFridge
			  << " wide fridge." << std::endl;
}

void Kitchen::safetyAlertViaWiFi(int currentOvenTemp, int setOvenTemp, int currentTime) 
{
	if (rangeControls.supportsWifi)
    {
		if (currentOvenTemp > 0) 
        {
			while (currentTime < 2400 && currentOvenTemp < setOvenTemp) 
            {
                currentOvenTemp += 10;
                int mins;                
				for (mins = 1; mins <= 10; ++mins) 
                {
					std::cout << "Alert to oven user : oven is on at "
								  << currentOvenTemp << std::endl;
				}
			}
			std::cout << "Auto turn off the oven ." << std::endl;
		}
		std::cout << "Oven is not on." << std::endl;
	}
	std::cout << "This model doesn't support WiFi feature." << std::endl;
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

	int lengthDeIcingPanel (int variation);
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

int Concorde::lengthDeIcingPanel (int variation)
{
    int n = 1;
	int hypotenuse;
	int cWingSpan = pw.wingSpan  / 2 - variation;
	return hypotenuse = cWingSpan / n;
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
int main() {
	Cat Mittens;

	Mittens.makeNoise(true);
	Mittens.scratchFurniture(false, 10);
	Mittens.sleep(true);
	Mittens.gainWeight(2);

	std::cout << "Mittens has a " << Mittens.tailLength << " inch long "
			  << Mittens.furColor << " tail!" << std::endl;

	Cat::Kitten MittensJunior;

	MittensJunior.feed(true);
	MittensJunior.pet(true, 20);
	MittensJunior.roamNeighborhood(false, 30);
	MittensJunior.roll(8, 6);

	std::cout << "Mittens Junior is " << (2022 - MittensJunior.birthYear)
			  << " year old " << MittensJunior.catBreed << std::endl;

	Range myRange;

	myRange.consumeFuel("electric", 65);
	myRange.breaksDown(70);
	myRange.heatsTheKitchen(7, 420);
	myRange.getBigger(1501);

	std::cout << "My range has a " << myRange.fuelType
			  << " powered oven that reaches up to " << myRange.maxTempOven
			  << " F in temp." << std::endl;

	Range::RangeControls specialFeature;
	specialFeature.printDaysLeft(20220630);

	Range::RangeControls backControls;

	backControls.informCurrentTime(false);
	backControls.indicateRepairDate("July 25th 2022", true);
	backControls.selfCleans(false, "light");
	backControls.turnUpTemp(350);

	std::cout << "The most popular model is " << backControls.controlPanelColor
			  << " with its cotrol panel width of "
			  << backControls.controlPanelWidth << "." << std::endl;

	PlaneWings jjWings;

	jjWings.generateLift(true, "down");
	jjWings.reduceDrag(10.f);
	jjWings.lowersLandingSpeed(10, false, 50);
	jjWings.flex(26);

	std::cout << "The jumbo jet has a wingspan of " << jjWings.wingSpan
			  << " ft and " << jjWings.numEngines
			  << " engines are attached to the lower side of the wings."
			  << std::endl;

	std::cout << "good to go!" << std::endl;

	Kitchen myKitchen;

	myKitchen.designSpace("darker", 80);
    myKitchen.safetyAlertViaWiFi(380, 390, 2397);

    Concorde concorde;

    concorde.lengthDeIcingPanel(10);
    concorde.topSpeed(2);
}
