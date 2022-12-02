#include "Merchant.h"
#include "Inventory.h"
#include "Player.h"
#include "Misfortunes.h"
#include "Monster.h"
#include <iostream>
#include <cmath>
using namespace std;
/*
We are implementing a class so that we can use this class to update the inventory of the players and 
display it to the user
*/
Merchant::Merchant()
{
    cout << "Between the 5 of you, you have 100 gold pieces." << endl;
    cout << "You will need to spend the some of your money on the following items: " << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;
}
void Merchant::displayMenu(Inventory& invent, Map obj, Player players[], int size)
{
    int choice;
    setPrices(obj);
    do
    {
        cout << "+-------------+" << endl;
        cout << "| INVENTORY   |" << endl;
        cout << "+-------------+" << endl;
        cout << "| Gold        | " << invent.getGold() << endl;
        cout << "| Ingredients | " << invent.getIngredients() << " kg" << endl;
        cout << "| Cookware    | P: " << invent.getCookware(0) << " | F: " << invent.getCookware(1) << " | C: " << invent.getCookware(2) << endl;
        cout << "| Weapons     | C: " << invent.getWeapons(0) << " | S: " << invent.getWeapons(1) << " | R: " << invent.getWeapons(2) << " | B: " << invent.getWeapons(3) << " | L: " << invent.getWeapons(4) << endl;
        cout << "| Armor       | " << invent.getArmor() << endl;
        cout << "| Treasures   | R: " << invent.getTreasures(0) << " | N: " << invent.getTreasures(1) << " | B: " << invent.getTreasures(2) << " | C: " << invent.getTreasures(3) << " | G: " << invent.getTreasures(4) << endl;
        cout << "+-------------+" << endl;
        cout << " " << endl;
        cout << "Choose one of the following:" << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        // cout<<invent.getNumWeapons()<<endl;
        // cout<<invent.getWeapons(1)<<endl;
        cout << " " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int amount = 0;
            string decision;
            cout << "How many kg of ingredients do you need [ " << ingredients << " Gold/kg]? (Enter a positive multiple of 5 or 0 to cancel)" << endl;
            cin >> amount;
            if (amount == 0)
            {
                cout << "What else can I get for you" << endl;
            }
            else if (amount % 5 != 0)
            {
                cout << "Invalid input" << endl;
            }
            else
            {
                cout << "You want to buy " << amount << " kg of ingredients for " << ingredients * amount << " Gold?(y/n)" << endl;
                cin >> decision;
                if (decision == "n")
                {
                    cout << "What else can I get for you?" << endl;
                }
                else if (decision == "y") // this is the corrected way to change gold values.
                {
                    if (invent.setGold(amount * ingredients, false) == true)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        invent.setIngredients(amount, true);
                    }
                    else
                    {
                        cout << "You unfortunately do not have enough gold for this decision" << endl;
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
            }
            break;
        }
        case 2:
        {
            int cookwareDecision;
            int dec;
            string number;
            cout << "I have a several types of cookware, which one would you like?" << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            cout << "Choose one of the following:" << endl;
            cout << "1. (25%) Ceramic Pot [" << pot << " Gold]" << endl;
            cout << "2. (10%) Frying Pan [" << pan << " Gold]" << endl;
            cout << "3. ( 2%) Cauldron [" << cauldron << " Gold]" << endl;
            cout << "4. Cancel" << endl;
            cin >> cookwareDecision;
            switch (cookwareDecision)
            {
            case 1:
            {
                cout << "How many Ceramic Pots would you like to purchase?" << endl;
                cin >> dec;
                if(dec==0)
                {
                    cout<<"Invalid Input"<<endl;
                }
                else{
                cout << "You want to purchase " << dec << " Ceramic Pot(s) for " << pot * dec << "Gold? (y/n)" << endl;
                cin >> number;
                if (number == "n")
                {
                    cout << "What else can I get for you?" << endl;
                }
                else if (number == "y")
                {
                    if (invent.setGold(dec * pot, false) == false)
                    {
                        cout << "You do not have enough gold for these items." << endl;
                    }
                    else
                    {
                        cout << "Thank you for your patronage, what else can I get for you?" << endl;
                        invent.setCookware(0, dec, true);
                        // invent.setGold((dec*pot),false);
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                }
                break;
                
            }
            case 2:
            {
                cout << "How many Frying Pans would you like to purchase?" << endl;
                cin >> dec;
                if(dec==0)
                {
                    cout<<"Invalid input"<<endl;
                }
                else{
                cout << "You want to purchase " << dec << " Frying Pan(s) for " << pan * dec << " Gold?(y/n)" << endl;
                cin >> number;
                if (number == "n")
                {
                    cout << "What else can I get for you?" << endl;
                }
                else if (number == "y")
                {
                    if (invent.setGold(dec * pan, false) == false)
                    {
                        cout << "You do not have enough gold for these items." << endl;
                    }
                    else
                    {
                        cout << "Thank you for your patronage, what else can I get for you?" << endl;
                        invent.setCookware(1, dec, true);
                        // invent.setGold((dec*pan),false);
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                }
                break;
            }
            case 3:
            {
                cout << "How many cauldrons would you like to purchase?" << endl;
                cin >> dec;
                if(dec<=0)
                {
                    cout<<"Invalid amount chosen"<<endl;
                }
                else
                {
                cout << "You want to purchase " << dec << " Cauldron(s) for " << cauldron * dec << " Gold?(y/n)" << endl;
                cin >> number;
                if (number == "n")
                {
                    cout << "What else can I get for you?" << endl;
                }
                else if (number == "y")
                {
                    if (invent.setGold(dec * cauldron, false) == false)
                    {
                        cout << "You do not have enough gold for these items." << endl;
                    }
                    else
                    {
                        cout << "Thank you for your patronage, what else can I get for you?" << endl;
                        invent.setCookware(2, dec, true);
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                }
                break;
            }
            case 4:
            {
                cout << "What else can I get for you?" << endl;
                break;
            }
            default:
            {
                cout << "Invalid Input" << endl;
                break;
            }
            }
            break;
        }
        case 3: // weapons
        {
            int coun = 0;
            for (int i = 0; i < size; i++)
            {
                if (players[i].getAliveStatus() == true)
                {
                    coun++;
                }
            }
            if (invent.getNumWeapons() >= coun)
            {
                cout << "You have reached the maximum number of weapons bought" << endl;
            }
            else
            {
                int decision;
                int dec;
                string name;
                cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
                cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
                cout << "Note that you can only carry one weapon per person and you cannot return the weapon once it is bought" << endl;

                cout << "Choose one of the following:" << endl;
                cout << "1. Stone Club [" << club << " Gold]" << endl;
                cout << "2. Iron Spear [" << spear << " Gold]" << endl;
                cout << "3. (+1) Mythril Rapier [" << rapier << " Gold]" << endl;
                cout << "4. (+2) Flaming Battle-Axe [" << axe << " Gold]" << endl;
                cout << "5. (+3) Vorpal Longsword [" << sword << " Gold]" << endl;
                cout << "6. Cancel" << endl;
                cout << " " << endl;
                cin >> decision;
                switch (decision)
                {
                case 1:
                {
                    cout << "How many Stone Clubs do you want to purchase?" << endl;
                    cin >> dec;
                    if(dec<=0)
                    {
                        cout<<"Invalid Input"<<endl;
                    }
                    else
                    {
                    cout << "You want to purchase " << dec << " Stone Clubs for " << dec * club << " Gold?(y/n)" << endl;
                    cin >> name;
                    if (name == "n")
                    {
                        cout << "What else can I get for you?" << endl;
                    }
                    else if (name == "y")
                    {
                        if (invent.setGold(dec * club, false) == false)
                        {
                            cout << "You do not have enough gold for these items." << endl;
                        }
                        else if (invent.getNumWeapons() + dec > coun)
                        {
                            cout << "You cannot carry this many weapons." << endl;
                        }
                        else
                        {
                            cout << "Thank you for your patronage, what else can I get for you?" << endl;
                            invent.setWeapons(0, dec, true);
                            invent.setNumWeapons(dec,true);
                        }
                    }
                    else
                    {
                        cout << "Invalid input" << endl;
                    }
                    }
                    break;
                }
                case 2:
                {
                    cout << "How many Iron Spears do you want to purchase?" << endl;
                    cin >> dec;
                    if(dec<=0)
                    {
                        cout<<"Invalid input"<<endl;
                    }
                    else
                    {
                    cout << "You want to purchase " << dec << " Iron Spears for " << dec * spear << " Gold?(y/n)" << endl;
                    cin >> name;
                    if (name == "n")
                    {
                        cout << "What else can I get for you?" << endl;
                    }
                    else if (name == "y")
                    {
                        if (invent.setGold(dec * spear, false) == false)
                        {
                            cout << "You do not have enough gold for these items." << endl;
                        }
                        else if (invent.getNumWeapons() + dec > coun)
                        {
                            cout << "You cannot carry this many weapons." << endl;
                        }
                        else
                        {
                            cout << "Thank you for your patronage, what else can I get for you?" << endl;
                            invent.setWeapons(1, dec, true);
                            invent.setNumWeapons(dec,true);
                        }
                    }
                    else
                    {
                        cout << "Invalid input" << endl;
                    }
                    }
                    break;
                }
                case 3:
                {
                    cout << "How many Mythril Rapiers do you want to purchase?" << endl;
                    cin >> dec;
                    if(dec<=0)
                    {
                        cout<<"Invalid Input"<<endl;
                    }
                    else
                    {
                    cout << "You want to purchase " << dec << " Mythril Rapiers for " << dec * rapier << " Gold?(y/n)" << endl;
                    cin >> name;
                    if (name == "n")
                    {
                        cout << "What else can I get for you?" << endl;
                    }
                    else if (name == "y")
                    {
                        if (invent.setGold(dec * rapier, false) == false)
                        {
                            cout << "You do not have enough gold for these items." << endl;
                        }
                        else if (invent.getNumWeapons() + dec > coun)
                        {
                            cout << "You cannot carry this many weapons." << endl;
                        }
                        else
                        {
                            cout << "Thank you for your patronage, what else can I get for you?" << endl;
                            invent.setWeapons(2, dec, true);
                            invent.setNumWeapons(dec,true);
                        }
                    }
                    else
                    {
                        cout << "Invalid input" << endl;
                    }
                    }
                    break;
                }
                case 4:
                {
                    cout << "How many Flaming Battle-Axes do you want to purchase?" << endl;
                    cin >> dec;
                    if(dec<=0)
                    {
                        cout<<"Invalid Input"<<endl;
                    }
                    else
                    { 
                    cout << "You want to purchase " << dec << " Flaming Battle-Axes for " << dec * axe << " Gold?(y/n)" << endl;
                    cin >> name;
                    if (name == "n")
                    {
                        cout << "What else can I get for you?" << endl;
                    }
                    else if (name == "y")
                    {
                        if (invent.setGold(dec * axe, false) == false)
                        {
                            cout << "You do not have enough gold for these items." << endl;
                        }
                        else if (invent.getNumWeapons() + dec > coun)
                        {
                            cout << "You cannot carry this many weapons." << endl;
                        }
                        else
                        {
                            cout << "Thank you for your patronage, what else can I get for you?" << endl;
                            invent.setWeapons(3, dec, true);
                            invent.setNumWeapons(dec,true);
                        }
                    }
                    else
                    {
                        cout << "Invalid input" << endl;
                    }
                    }
                    break;
                }
                case 5:
                {
                    int dec;
                    string na;
                    cout << "How many Vorpal Longswords do you want to purchase?" << endl;
                    cin >> dec;
                    if(dec<=0)
                    {
                        cout<<"Invalid Input"<<endl;
                    }
                    else
                    {
                    cout << "You want to purchase " << dec << " Vorpal Longswords for " << (dec * sword) << " Gold?(y/n)" << endl;
                    cin >> na;
                    if (na == "n")
                    {
                        cout << "What else can I get for you?" << endl;
                    }
                    else if (na == "y")
                    {
                        if (invent.setGold(dec * sword, false) == false)
                        {
                            cout << "You do not have enough gold for these items." << endl;
                        }
                        else if (invent.getNumWeapons() + dec > coun)
                        {
                            cout << "You cannot carry this many weapons." << endl;
                        }
                        else
                        {
                            cout << "Thank you for your patronage, what else can I get for you?" << endl;
                            invent.setWeapons(4, dec, true);
                            invent.setNumWeapons(dec,true);
                        }
                    }
                    else
                    {
                        cout << "Invalid input" << endl;
                    }
                    }
                    break;
                }
                case 6:
                {
                    cout << "What else can I get for you?" << endl;
                    break;
                }
                default:
                {
                    cout << "That's not a choice PEASANT" << endl;
                    break;
                }
                }
                break;
            }
            break;
        }

        case 4:
        {
            int count = 5;
            int amount = 0;
            string decision;
            cout << "How many sets of armor do you need [ " << armor << " Gold]?" << endl;
            cout << "Note that you can only carry one set of armor per person and you cannot return the armor once it is bought" << endl;
            cin >> amount;
            if (amount == 0)
            {
                cout << "What else can I get for you" << endl;
            }
            else
            {
                cout << "You want to buy " << amount << " set(s) of armor for " << amount * armor << " Gold?(y/n)" << endl;
                cin >> decision;
                if (decision == "n")
                {
                    cout << "What else can I get for you?" << endl;
                }
                else if (decision == "y")
                {
                    if (invent.setArmor(amount, true) == false)
                    {
                        cout << "You cannot carry this many sets of armor sir." << endl;
                    }
                    else if (invent.setGold(amount * armor, false) == true)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        // invent.setArmor(amount, true);
                    }
                    else
                    {
                        cout << "You unfortunately do not have enough gold for this decision" << endl;
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
            }
            break;
        }
        case 5:
        {
            int deci;
            cout << "I would love to provide some gold for any treasure you are able to provide! What are you able to sell to me today?" << endl;
            cout << "Choose one of the following" << endl;
            cout << "1. Silver ring (R) - 10 gold pieces each" << endl;
            cout << "2. Ruby necklace (N) - 20 gold pieces each" << endl;
            cout << "3. Emerald bracelet (B) - 30 gold pieces each" << endl;
            cout << "4. Diamond circlet (C) - 40 gold pieces each" << endl;
            cout << "5. Gem-encrusted goblet (G) - 50 gold pieces each" << endl;
            cin >> deci;
            switch (deci)
            {
            case 1:
            {
                if (invent.getTreasures(0) == 0)
                {
                    cout << "You do not have this treasure sugar bean....." << endl;
                }
                else
                {
                    cout << "I would love a Silver Ring! Here is 10 gold pieces for one!" << endl;
                    invent.setTreasures(0, 1, false);
                    invent.setGold(10, true);
                }

                break;
            }
            case 2:
            {
                if (invent.getTreasures(1) == 0)
                {
                    cout << "You do not have this treasure sugar bean....." << endl;
                }
                else
                {
                    cout << "A Ruby Necklace would be stupendus! Here is 20 gold pieces for one!" << endl;
                    invent.setTreasures(1, 1, false);
                    invent.setGold(20, true);
                }

                break;
            }
            case 3:
            {
                if (invent.getTreasures(2) == 0)
                {
                    cout << "You do not have this treasure sugar bean....." << endl;
                }
                else
                {
                    cout << "I wouldn't mind a Emerald bracelet! Here is 30 gold pieces for one!" << endl;
                    invent.setTreasures(2, 1, false);
                    invent.setGold(30, true);
                }

                break;
            }
            case 4:
            {
                if (invent.getTreasures(3) == 0)
                {
                    cout << "You do not have this treasure sugar bean....." << endl;
                }
                else
                {
                    cout << "I wouldn't mind a Diamond circlet! Here is 40 gold pieces for one!" << endl;
                    invent.setTreasures(3, 1, false);
                    invent.setGold(40, true);
                }
                break;
            }
            case 5:
            {
                if (invent.getTreasures(4) == 0)
                {
                    cout << "You do not have this treasure sugar bean....." << endl;
                }
                else
                {
                    cout << "I would be so excited to have a Gem-encrusted goblet! Here is 50 gold pieces for one!" << endl;
                    invent.setTreasures(4, 1, false);
                    invent.setGold(50, true);
                }
                break;
            }
            default:
            {
                cout << "THAT'S NOT AN OPTION PEASANT" << endl;
                break;
            }
            }
            break;
        }
        case 6:
        {
            string decis;
            cout << "Are you sure you're finished? You won't be able to buy anything else from me!(y/n)" << endl;
            cin >> decis;
            if (decis == "n")
            {
                cout << "Great! What else can I get for you?" << endl;
                choice = 7;
            }
            else if (decis == "y")
            {
                cout << "Stay Safe out there! Goodbye soldiers!" << endl;
            }
            else
            {
                choice = 7;
            }
            break;
        }
        // default:
        // {
        //     cout << "Invalid input" << endl;
        //     break;
        // }
        }
    } while (choice != 6);
}

// int Merchant:: roomsCleared(Map object)
// {

//     return count;
// }
void Merchant::setPrices(Map object)
{
    int room = object.getRoomCount();
    int count = 5 - room;
    double multiplier = count * 0.25;

    ingredients = 1 + (1 * multiplier);
    pot = 5 + (5 * multiplier);
    pan = 10 + (10 * multiplier);
    cauldron = 20 + (20 * multiplier);
    club = 2 + (2 * multiplier);
    spear = 2 + (2 * multiplier);
    rapier = 5 + (5 * multiplier);
    axe = 15 + (15 * multiplier);
    sword = 50 + (50 * multiplier);
    armor = 5 + (5 * multiplier);
}