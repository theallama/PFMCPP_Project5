#include <iostream>
#include <math.h>
#include "Concorde.h"

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

