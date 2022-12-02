#ifndef MERCHANT_H
#define MERCHANT_H
#include "Inventory.h"
#include "Map.h"
#include "Player.h"
#include <iostream>
class Merchant
{
    private:
    int ingredients;
    int pot;
    int pan;
    int cauldron;
    int club;
    int spear;
    int rapier;
    int axe;
    int sword;
    int armor;
    static const int ring=10;
    static const int neck=20;
    static const int bracelet=30;
    static const int circlet=40;
    static const int goblet=50;
    //Player members[5];


    public:
    Inventory inventory;//inventory object
    Merchant();//displays instructions for merchant
    void displayMenu(Inventory& invent, Map obj, Player players[], int size);//takes in objects, some by reference that will help display the menu
    void setPrices(Map object);//This sets the prices based off of the number of rooms cleared
};
#endif