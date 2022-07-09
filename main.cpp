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
// #if false
//a function where the argument is passed by const-ref.
// void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
// void Axe::aConstMemberFunction() const { }
// #endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */

// #pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wexit-time-destructors"
#include <iostream>

#include "LeakedObjectDetector.h"

#include "Wrappers.h"

#include "Cat.h"
#include "Range.h"
#include "PlaneWings.h"
#include "Kitchen.h"
#include "Concorde.h"


/*
 copied UDT 1:
 */
/*
 copied UDT 2:
 */
/*
copied UDT 3:
*/
/*
new UDT 4:
with 2 member functions
*/
/*
new UDT 5:
with 2 member functions
*/

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
              << " F in temp." << std::endl;

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
