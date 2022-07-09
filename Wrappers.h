#pragma once
struct Cat;
struct Range;
struct PlaneWings;
struct Kitchen;
struct Concorde;

struct CatWrapper
{
    CatWrapper(Cat* catPtr);
    ~CatWrapper();
    Cat* pointerToCat = nullptr;
};

struct RangeWrapper
{
    RangeWrapper(Range* rPtr);
    ~RangeWrapper();
    Range* pointerToRange = nullptr;
};

struct PlaneWingsWrapper
{
    PlaneWingsWrapper(PlaneWings* pwPtr);
    ~PlaneWingsWrapper();
    PlaneWings* pointerToPlaneWings = nullptr;
};

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* kPtr);
    ~KitchenWrapper();
    Kitchen* pointerToKitchen = nullptr;
};

struct ConcordeWrapper
{
    ConcordeWrapper(Concorde* concPtr);
    ~ConcordeWrapper();
     Concorde* pointerToConcorde = nullptr;
};

