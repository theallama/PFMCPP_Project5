#include "Wrappers.h"
#include "Cat.h"
#include "Range.h"
#include "PlaneWings.h"
#include "Kitchen.h"
#include "Concorde.h"

CatWrapper::CatWrapper(Cat* catPtr) : pointerToCat(catPtr) {}
CatWrapper::~CatWrapper()
{
    delete pointerToCat;    
}

RangeWrapper::RangeWrapper(Range* rPtr) : pointerToRange(rPtr) {}
RangeWrapper::~RangeWrapper()
{
    delete pointerToRange;
}

PlaneWingsWrapper::PlaneWingsWrapper(PlaneWings* pwPtr) : pointerToPlaneWings(pwPtr) {}
PlaneWingsWrapper::~PlaneWingsWrapper()
{
    delete pointerToPlaneWings;    
}

KitchenWrapper::KitchenWrapper(Kitchen* kPtr) : pointerToKitchen(kPtr) {}
KitchenWrapper::~KitchenWrapper()
{
    delete pointerToKitchen;  
}

ConcordeWrapper::ConcordeWrapper(Concorde* concPtr) : pointerToConcorde(concPtr) {}
ConcordeWrapper::~ConcordeWrapper()
{
    delete pointerToConcorde;  
}

