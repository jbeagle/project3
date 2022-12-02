#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
using namespace std;
class Inventory
{
    private:
    int gold;
    int ingredients;
    int Cookware[3];//the 0 index is p first is f and third is c
    int Weapons[5];//0 is club 1 is spear two is mythril three is axe four is longsword
    int armor;
    int treasures[5];// 0 is ring one is necklace to is bracelet three is circlet four is goblet
    int numWeapons;
    int numKeys;
    // int numArmor;


    public:
    Inventory();//default constructor
    bool setGold(int golds,bool what);//adds or subtracts from the number of gold the group has
    int getGold();//returns number of gold
    bool setIngredients(int ingr,bool what);//adds or subtracts ingredients
    int getIngredients();//returns number of ingredients
    bool setCookware(int index, int cook, bool what);//adds or subtracts cookware at a specified index
    int getCookware(int index);//returns cookware at a given index
    void setWeapons(int index, int weap,bool what);//sets number of weapons at a specified index
    int getWeapons(int index);//returns number of weapons at a specific index
    bool setArmor(int arm,bool what);//adds or subtracts the number of armor the group has
    int getArmor();//returns the number of armor the group has
    bool setTreasures(int index,int trea,bool what);//adds or subtracts the number of treasures at a specified index
    int getTreasures(int index);//returns treasures at a specified index
    int getNumWeapons();//returns the full amount of weapons
    void setKeys(int amount,bool what);//adds or subtracts number of keys
    int getKeys();//returns number of keys
    void setNumWeapons(int num, bool what);//sets full number of weapons
    // int getNumArmor();

};
#endif