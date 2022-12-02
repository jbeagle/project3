#include "Inventory.h"
#include "Merchant.h"
#include "Player.h"
#include "Monster.h"
#include <iomanip>
using namespace std;
/*
Algorithm
We want to create a class that stores and returns the resources that the group in the game has when the 
object from this class is called.
*/
Inventory::Inventory()//default constructor just sets everything to zero
{
    gold = 100;
    ingredients = 0;
    armor = 0;
    for(int i=0;i<3;i++)
    {
        Cookware[i]=0;
    }
    for(int j=0;j<5;j++)
    {
        Weapons[j]=0;
        treasures[j]=0;
    }
    numWeapons=0;
    numKeys=0;
}
bool Inventory::setGold(int golds,bool what)//adds or subtracts gold
{
    if(what==true)
    {
        gold+=golds;
    }
    else
    {
        if((gold-golds)<0)
        {
            gold=gold;
            return false;
        }
        else
        {
            gold = gold-golds;
        }
    }
    return true;
}
int Inventory::getGold()//returns the gold amount
{
    return gold;
}
bool Inventory::setIngredients(int ingr, bool what)//adds or subtract ingredients
{
    if(what==true)
    {
    ingredients+=ingr;
    }
    else
    {
        if((ingredients-ingr)<0)
        {
            ingredients = ingredients;
            return false;
        }
        else
        {
            ingredients = ingredients-ingr;
        }
    }
    return true;
}
int Inventory::getIngredients()//returns the number of ingredients
{
    return ingredients;
}
bool Inventory::setArmor(int arm,bool what)//sets number of armor
{
    if(what==true)
    {
        armor=armor+arm;
    }
    else
    {
        if((armor-arm)<0)
        {
            armor=armor;
            return false;
        }
        else
        {
            armor = armor-arm;
        }
    }
    return true;
}
int Inventory:: getArmor()//returns number of armor
{
    return armor;
}
bool Inventory::setCookware(int index,int cook, bool what)//takes in index for the cookware array
{  
    if(what==true)
    {
        Cookware[index] +=cook;
    }
    else
    {
        if((Cookware[index]- cook)<0)
        {
            Cookware[index]=Cookware[index];
            return false;
        }
        else
        {
            Cookware[index]= Cookware[index]-cook;
        }
    }
    return true;
}
int Inventory::getCookware(int index)//returns the number of a specific cookware at a given index
{
    return Cookware[index];
}
void Inventory:: setWeapons(int index, int weap,bool what)//sets the number of weapons in the weapons array
{
    if(what==true)
    {
        Weapons[index] +=weap;
        numWeapons+=weap;
    }
    else
    {
        if((Weapons[index]- weap)<0)
        {
            Weapons[index]=Weapons[index];
            // return false;
        }
        else
        {
            Weapons[index]= Weapons[index]-weap;
            numWeapons=numWeapons-weap;
        }
    }
    // return true;
}
int Inventory::getWeapons(int index)//gets number of specified weapons based off of a specified index
{

    return Weapons[index];
}
bool Inventory:: setTreasures(int index,int trea, bool what)//sets number of each treasure inside of the array
{
    if(what==true)
    {
        treasures[index] +=trea;
    }
    else
    {
        if((treasures[index]- trea)<0)
        {
            treasures[index]=treasures[index];
            return false;
        }
        else
        {
            treasures[index]= treasures[index]-trea;
        }
    }
    return true;
}
int Inventory::getTreasures(int index)//returns number of treasures at a specified index
{
    return treasures[index];
}
void Inventory::setNumWeapons(int num, bool what)//another way of setting the full number of weapons
{
    if(what==true)
    {
        numWeapons+=num;
    }
    else
    {
        numWeapons=numWeapons-num;
    }
}
int Inventory::getNumWeapons()//returns the number of all weapons the group has
{
    return numWeapons;
}
void Inventory:: setKeys(int amount,bool what)//sets number of keys
{
    if(what==true)
    {
        numKeys+=amount;
    }
    else
    {
        if((numKeys-amount)<0)
        {
            numKeys=numKeys;
        }
        else
        {
            numKeys = numKeys-amount;
        }
    }
}
int Inventory:: getKeys()//returns number of keys
{
    return numKeys;
}