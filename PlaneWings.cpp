#include<iostream>
#include "PlaneWings.h"

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

