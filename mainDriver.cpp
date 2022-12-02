#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include "Map.h"
#include "Player.h"
#include "Merchant.h"
#include "Inventory.h"
#include "Monster.h"
#include "Misfortunes.h"

using namespace std;
int split(string inputString, char separator, string arr[], int arrSize)
{
    // ex: "abc,c" separator: ","
    int numElementsInserted = 0;
    if (inputString.length() == 0) // inputString is empty
    {
        return 0;
    }

    string insertIntoArray;
    insertIntoArray.push_back(inputString.at(0)); // iia = "a"

    // inputString has 1 character
    if (inputString.length() == 1)
    {
        if (arrSize > numElementsInserted)
        {
            arr[numElementsInserted] = insertIntoArray;
            numElementsInserted++;
            return numElementsInserted;
        }
    }

    // inputString has 3 or more characters
    for (int i = 1; i < inputString.length(); i++) // start at first char, which we know is not the delimeter
    {
        if (inputString.at(i) != separator) // character is not a separator
        {
            insertIntoArray.push_back(inputString.at(i));
        }
        else // character is a separator
        {
            if (arrSize > numElementsInserted)
            {
                arr[numElementsInserted] = insertIntoArray;
                numElementsInserted++;
                insertIntoArray = "";
            }
            else
            {
                return -1;
            }
        }
    }
    if (arrSize == numElementsInserted)
    {
        return -1;
    }
    arr[numElementsInserted] = insertIntoArray;
    numElementsInserted++;

    return numElementsInserted;
}

int main()
{
    srand(time(0));
    Inventory invent;
    Map map;
    Monster monster;
    Misfortunes misfit;
    int sorcererAnger=0;
    char mapDecision;
    // display introduction and describe the game
    cout << "Welcome to Dungeon Escape!" << endl;
    cout << "You and your party members have been trapped in this curious and dangerous dungeon by an angry Sorcerer!" << endl;
    cout << "Here, you will need to use different strategies, your wit, and a bit of cleverness to escape this place." << endl;
    cout << "You have a map to help you find your way around and hopefully find your way out. HOWEVER!" << endl;
    cout << "You are going to encounter many different obstacles and people along the way that may benefit you or it may make it more difficult to find your way out of this cursed place." << endl;
    cout << "There will also be Monsters to fight and riddles to solve in order to progress in the game." << endl;
    cout << "You need to find keys throughout the map to get closer to your freedom and open more doors to progress." << endl;
    cout << "These keys can be found after fighting monsters and randomly throughout the map. Along with this, every time you move throughout the map there might be a misfortune you encounter" << endl;
    cout << "and the Sorcerer’s Anger level will rise by one point." << endl;
    cout << "Beware of this anger level, for if this monster’s anger level rises to 100, then you will be trapped in the dungeon forever." << endl;
    cout << "You and each of your team member’s each have a fullness level as well. This is set to 50. As you move along this map, these fullness levels may drop and risk death by hunger." << endl;
    cout << "Do not let this hunger level drop to zero or else that player will be terminated. Keep at least two members in your party and escape this dungeon in order to be successful in this journey!" << endl;
    cout << "Goodluck!" << endl;
    cout << " " << endl;
    string nam[5];
    cout << "Please enter your name" << endl;
    cin >> nam[0];
    cout << "Enter the name of your four traveling companions" << endl;
    cin >> nam[1];
    cin >> nam[2];
    cin >> nam[3];
    cin >> nam[4];

    cout << "Your team consists of five members: " << nam[0] << " " << nam[1] << " " << nam[2] << " " << nam[3] << " " << nam[4] << endl;
    cout << " " << endl;
    Player players[5];
    for (int i = 0; i < 5; i++)
    {
        players[i].setPlayerName(nam[i]);
    }
    cout << "In order to successfully make it through this dungeon, you will have to purchase different items from the merchant" << endl;
    cout << "such as ingredients for food and cookware to cook those ingredients" << endl;
    cout << "to keep your fullness level up. You will also need sets of armor and weapons, both of which you can only hold five of." << endl;
    cout << "You can also sell treasures here as well to gain more gold to buy more goods, but we can worry about that later...." << endl;
    cout << " " << endl;
    Merchant merchant;
    merchant.displayMenu(invent, map, players, 5);
    cout<<invent.getArmor()<<endl;
    cout<<invent.getIngredients()<<endl;
    cout << "Now we will move onto the map." << endl;
    cout << "In order to move you should use the 'A','S','D',and 'W' keys" << endl;
    cout << "A is for left, S is for down, D is for right, and W is for up" << endl;
    cout << "Each unexplored space is marked with a '-', Rooms are marked with a R and NPC's are not marked." << endl;
    cout << "Each time you hit a space that is explored and marked as ' ' then the sorcerer's anger rises by one." << endl;
    cout << "To start the game, move throughout the map looking for keys to open doors, open all five doors and reach the end with at least two members left to be victorious." << endl;
    cout << " " << endl;
    // map.displayMap();
    // cout << "What is your first move" << endl;
    // cout << "1. Move" << endl;
    map.displayMap();
    do
    {
        int wea=0;
        for(int j=0;j<5;j++)
        {
            wea+=invent.getWeapons(j);
        }
        cout<<"Rooms cleared: "<<(5-map.getRoomCount())<<endl;
        cout<<"Number of Keys found: "<<invent.getKeys()<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<players[i].getPlayerName()<<" Fullness: "<<players[i].getFullness()<<endl;
        }
        cout<<"Ingredients: "<<invent.getIngredients()<<endl;
        cout<<"Pots: "<<invent.getCookware(0)<<" Pans: "<<invent.getCookware(1)<<" Cauldrons: "<<invent.getCookware(2)<<endl;
        cout<<"Armor: "<<invent.getArmor()<<endl;
        cout<<"Weapons: "<<wea<<endl;
        cout<<"Gold: "<<invent.getGold()<<endl;
        cout<<"R: "<<invent.getTreasures(0)<< " N: "<<invent.getTreasures(1)<<" B: "<<invent.getTreasures(2)<<endl;
        cout<<"C: "<<invent.getTreasures(3)<<" g: "<<invent.getTreasures(4)<<endl;
        cout<<"Sorcerer's Anger: "<<sorcererAnger<<endl;
        cout << "Which way do you want to move?" << endl;
        cin >> mapDecision;

        if (mapDecision != 'm')
        {

            if (mapDecision == 'w' || mapDecision == 's' || mapDecision == 'a' || mapDecision == 'd')
            {
                map.move(mapDecision);
                map.displayMap();
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    sorcererAnger += 1;
                    if (sorcererAnger == 100)
                    {
                        cout << "You have made the sorcerer too angry! Prepare to spend eternity in this terrible dungeon!" << endl;
                        mapDecision = 'm';
                    }
                    int choose = 0;
                    string ans1;
                    do
                    {
                        cout << "You have encountered an NPC! What is your next move?" << endl;
                        cout << "1. Move" << endl;
                        cout << "2. Speak to NPC" << endl;
                        cout << "3. Give up" << endl;
                        cin >> choose;
                        switch (choose)
                        {
                        case 1:
                        {
                            cout << "Which direction would you like to move?" << endl;
                            choose = 3;
                            break;
                        }
                        case 2:
                        {
                            int hello = rand() % 20 + 1;
                            cout << "Hello Strangers! I see you have been trapped in this dungeon alongside myself!" << endl;
                            cout << "I would be more than happy to help you gain some more supplies, if you can solve this tricky riddle!" << endl;
                            cout << misfit.getRiddles(hello) << endl;
                            cin >> ans1;
                            if (ans1 == misfit.getAnswers(hello))
                            {
                                cout << "Very wise of you! Here is what I can offer you at this moment" << endl;
                                merchant.displayMenu(invent, map, players, 5);
                                choose = 3;
                            }
                            else
                            {
                                cout << "You fools! I have decided you are not wise enough to gain the help from me, time for you to fight a monster." << endl;
                                monster.fight(map, invent, players, 5);
                                choose = 3;
                            }

                            break;
                        }
                        case 3:
                        {
                            cout << "You had a sturdy effort warrior, better luck next time!" << endl;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Input." << endl;
                            break;
                        }
                        }
                    } while (choose != 3);
                    cout << "Goodluck explorers, be cautious of the many more obstacles and puzzles you will encounter along the way." << endl;
                }
                else if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    sorcererAnger += 1;
                    if (sorcererAnger == 100)
                    {
                        cout << "You have made the sorcerer too angry! Prepare to spend eternity in this terrible dungeon!" << endl;
                        mapDecision = 'm';
                    }
                    int chose2;
                    do
                    {
                        cout << "You have encountered one of many rooms! What is your next move?" << endl;
                        cout << "1. Move" << endl;
                        cout << "2. Open the Door" << endl;
                        cout << "3. Give Up" << endl;
                        cin >> chose2;
                        switch (chose2)
                        {
                        case 1:
                        {
                            cout << "Which direction would you like to move?" << endl;
                            break;
                        }
                        case 2:
                        {
                            int word = rand() % 100 + 1;
                            if (invent.getKeys() > 0)
                            {
                                monster.fight(map, invent, players, 5);
                                if (word <= 40)
                                {
                                    misfit.RoomMisfortunes(invent, players, 5);
                                    if (misfit.getCanContinue() == false)
                                    {
                                        cout << "Unfortunately You do not have enough people to continue exploring the dungeon." << endl;
                                        mapDecision = 'm';
                                    }
                                    chose2 = 1;
                                }
                                else
                                {
                                    cout << "You have dodged a misfortune!" << endl;
                                    chose2 = 1;
                                }
                            }
                            else
                            {
                                string yump="";
                                cout << "You don't have a key to open this door." << endl;
                                cout<<"You have fallen into a trapped door instead!"<<endl;
                                cout<<"You have to play a game of boulder parchment sheers in order to get out! Don't lose!"<<endl;
                                cout<<"Would you like to play a boulder, parchment, or sheers?"<<endl;
                                cin>>yump;
                                misfit.boulderParchmentSheers(yump);
                                if(misfit.getVictory()==true)
                                {
                                    cout<<"You have won!"<<endl;
                                    monster.fight(map,invent,players,5);
                                }
                                else 
                                {
                                    cout<<"You have lost!"<<endl;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            cout << "You had a sturdy effort warrior, better luck next time!" << endl;
                            mapDecision = 'm';
                            chose2 = 1;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Input" << endl;
                            break;
                        }
                        }
                    } while (chose2 != 1);
                }
                else if (map.isFreeSpace(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    sorcererAnger += 1;
                    if (sorcererAnger == 100)
                    {
                        cout << "You have made the sorcerer too angry! Prepare to spend eternity in this terrible dungeon!" << endl;
                        mapDecision = 'm';
                    }
                    else
                    {
                        int cho3;
                        do
                        {

                            cout << "What is your next move?" << endl;
                            cout << "1. Move" << endl;
                            cout << "2. Investigate" << endl;
                            cout << "3. Pick a Fight" << endl;
                            cout << "4. Cook and Eat" << endl;
                            cout << "5. Give Up" << endl;
                            cin >> cho3;
                            switch (cho3)
                            {
                            case 1:
                            {
                                cout << "Where would you like to move?" << endl;
                                break;
                            }
                            case 2:
                            {
                                int word = rand() % 100 + 1;
                                int lit = 0;
                                if (word <= 10)
                                {
                                    cout << "You have found a key!" << endl;
                                    invent.setKeys(1, true);
                                    for (int i = 0; i < 5; i++)
                                    {
                                        lit = rand() % 10 + 1;
                                        if (lit <= 5)
                                        {
                                            players[i].setFullness(1, false);
                                            cout << players[i].getPlayerName() << " has lost a fullness point." << endl;
                                        }
                                    }
                                }
                                else if (word > 10 && word <= 30)
                                {
                                    cout << "You have found a treasure!" << endl;
                                    if ((5 - map.getRoomCount()) == 0)
                                    {
                                        cout << "Clear a room in order to gain a treasure " << endl;
                                    }
                                    else if ((5 - map.getRoomCount()) == 1)
                                    {
                                        cout << "You have found a Silver Ring!" << endl;
                                        invent.setTreasures(0, 1, true);
                                    }
                                    else if ((5 - map.getRoomCount()) == 2)
                                    {
                                        cout << "You have found a Ruby Necklace!" << endl;
                                        invent.setTreasures(1, 1, true);
                                    }
                                    else if ((5 - map.getRoomCount()) == 3)
                                    {
                                        cout << "You have found an Emerald bracelet!" << endl;
                                        invent.setTreasures(2, 1, true);
                                    }
                                    else if ((5 - map.getRoomCount()) == 4)
                                    {
                                        cout << "You have found a Diamond Circlet!" << endl;
                                        invent.setTreasures(3, 1, true);
                                    }
                                    else
                                    {
                                        cout << "You have found a Gem Encrusted goblet!" << endl;
                                        invent.setTreasures(4, 1, true);
                                    }
                                    for (int i = 0; i < 5; i++)
                                    {
                                        lit = rand() % 10 + 1;
                                        if (lit <= 5)
                                        {
                                            players[i].setFullness(1, false);
                                            cout << players[i].getPlayerName() << " has lost a fullness point." << endl;
                                        }
                                    }
                                }
                                else if (word > 30 && word <= 50)
                                {
                                    monster.fight(map, invent, players, 5);
                                    for (int i = 0; i < 5; i++)
                                    {
                                        lit = rand() % 10 + 1;
                                        if (lit <= 5)
                                        {
                                            players[i].setFullness(1, false);
                                            cout << players[i].getPlayerName() << " has lost a fullness point." << endl;
                                        }
                                    }

                                }
                                else
                                {
                                    cout << "There is nothing to investigate here!" << endl;
                                    for (int i = 0; i < 5; i++)
                                    {
                                        lit = rand() % 10 + 1;
                                        if (lit <= 5)
                                        {
                                            players[i].setFullness(1, false);
                                            cout << players[i].getPlayerName() << " has lost a fullness point." << endl;
                                        }
                                    }
                                }
                                map.exploreSpace(map.getPlayerRow(),map.getPlayerCol);
                                break;
                            }
                            case 3:
                            {
                                cout << "You have decided to pick a fight!" << endl;
                                if(monster.fight(map, invent, players, 5)==true)
                                {
                                    cout<<"You have won!"<<endl;

                                }
                                else
                                {
                                    cout<<"You have lost"<<endl;
                                }

                                break;
                            }
                            case 4:
                            {
                                int cookchoi = 0;
                                int numing = 0;
                                cout << "Which cookware would you like to use" << endl;
                                cout << "| Cookware    | P: " << invent.getCookware(0) << " | F: " << invent.getCookware(1) << " | C: " << invent.getCookware(2) << endl;
                                cout << "Pot = 0, Frying pan = 1, Caulron = 2" << endl;
                                cin >> cookchoi;
                                switch (cookchoi)
                                {
                                case 0:
                                {
                                    if (invent.getCookware(0) > 1)
                                    {
                                        int yes = 0;
                                        cout << "How many ingredients would you like to cook?(enter a number divisible by 5)" << endl;
                                        cin >> numing;
                                        if (numing % 5 == 0)
                                        {
                                            if (numing <= invent.getIngredients())
                                            {
                                                yes = rand() % 100 + 1;
                                                if (yes <= 25)
                                                {
                                                    cout << "OH NO! your Ceramic Pot has broken, there has been no food made and you have lost those ingredients!" << endl;
                                                    invent.setIngredients(numing, false);
                                                    invent.setCookware(0, 1, false);
                                                }
                                                else
                                                {
                                                    cout << "You have successfully cooked " << numing << " ingredients! Each player's fullness level has increased by " << (numing / 5) << endl;
                                                    for (int i = 0; i < 5; i++)
                                                    {
                                                        if (players[i].getAliveStatus() == true)
                                                        {
                                                            players[i].setFullness((numing / 5), true);
                                                        }
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                            }
                                        }
                                        else
                                        {
                                            cout << "You entered an invalid amount of ingredients, this is not divisible by 5." << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "You do not have any ceramic pots to use." << endl;
                                    }
                                    break;
                                }
                                case 1:
                                {
                                    if (invent.getCookware(1) > 0)
                                    {
                                        int yes = 0;
                                        cout << "How many ingredients would you like to cook?(enter a number divisible by 5)" << endl;
                                        cin >> numing;
                                        if (numing % 5 == 0)
                                        {
                                            if (numing <= invent.getIngredients())
                                            {
                                                if (yes <= 10)
                                                {
                                                    cout << "OH NO! your Frying Pan has broken, there has been no food made and you have lost those ingredients!" << endl;
                                                    invent.setIngredients(numing, false);
                                                }
                                                else
                                                {
                                                    cout << "You have successfully cooked " << numing << " ingredients! Each player's fullness level has increased by " << (numing / 5) << endl;
                                                    for (int i = 0; i < 5; i++)
                                                    {
                                                        if (players[i].getAliveStatus() == true)
                                                        {
                                                            players[i].setFullness((numing / 5), true);
                                                        }
                                                    }
                                                    invent.setIngredients(numing, false);
                                                }
                                            }
                                            else
                                            {
                                                cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                            }
                                        }
                                        else
                                        {
                                            cout << "You entered an invalid amount of ingredients, this is not divisible by 5." << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "You do not have any frying pans to use." << endl;
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    if (invent.getCookware(2) > 0)
                                    {
                                        int yes = 0;
                                        cout << "How many ingredients would you like to cook?(enter a number divisible by 5)" << endl;
                                        cin >> numing;
                                        if (numing % 5 == 0)
                                        {
                                            if (numing <= invent.getIngredients())
                                            {
                                                if (yes <= 2)
                                                {
                                                    if (yes <= 10)
                                                    {
                                                        cout << "OH NO! your Cauldron has broken, there has been no food made and you have lost those ingredients!" << endl;
                                                        invent.setIngredients(numing, false);
                                                    }
                                                    else
                                                    {
                                                        cout << "You have successfully cooked " << numing << " ingredients! Each player's fullness level has increased by " << (numing / 5) << endl;
                                                        for (int i = 0; i < 5; i++)
                                                        {
                                                            if (players[i].getAliveStatus() == true)
                                                            {
                                                                players[i].setFullness((numing / 5), true);
                                                            }
                                                        }
                                                        invent.setIngredients(numing, false);
                                                    }
                                                }
                                                else
                                                {
                                                    cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                                }
                                            }
                                            else
                                            {
                                                cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                            }
                                        }
                                        else
                                        {
                                            cout << "You entered an invalid amount of ingredients, this is not divisible by 5." << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "You do not have any Cauldrons to use." << endl;
                                    }

                                    break;
                                }
                                default:
                                {
                                    cout << "invalid input bro" << endl;
                                    break;
                                }
                                }
                                break;
                            }
                            case 5:
                            {
                                cout << "You had a sturdy effort warrior, better luck next time!" << endl;
                                cho3 = 1;
                                mapDecision = 'm';
                                break;
                            }
                            default:
                            {
                                cout << "Invalid input" << endl;
                                break;
                            }
                            }
                        } while (cho3 != 1);
                    }
                }
                else if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == true)
                {

                    int cho4 = 0;
                    do
                    {
                        cout << "What is your next move?" << endl;
                        cout << "1. Move" << endl;
                        cout << "2. Investigate" << endl;
                        cout << "3. Pick a Fight" << endl;
                        cout << "4. Cook and Eat" << endl;
                        cout << "5. Give Up" << endl;
                        cin >> cho4;
                        switch (cho4)
                        {
                        case 1:
                        {
                            cout << "Where would you like to move?" << endl;
                            break;
                        }
                        case 2:
                        {
                            int lit = 0;

                            cout << "There is nothing to investigate here!" << endl;
                            for (int i = 0; i < 5; i++)
                            {
                                lit = rand() % 10 + 1;
                                if (lit <= 5)
                                {
                                    players[i].setFullness(1, false);
                                    cout << players[i].getPlayerName() << " has lost a fullness point." << endl;
                                }
                            }
                            break;
                        }
                        case 3:
                        {

                            cout << "You have decided to pick up a fight!" << endl;
                            monster.fight(map, invent, players, 5);
                            break;
                        }
                        case 4:
                        {
                            int cookchoi = 0;
                            int numing = 0;
                            cout << "Which cookware would you like to use" << endl;
                            cout << "| Cookware    | P: " << invent.getCookware(0) << " | F: " << invent.getCookware(1) << " | C: " << invent.getCookware(2) << endl;
                            cout << "Pot = 0, Frying pan = 1, Caulron = 2" << endl;
                            cin >> cookchoi;
                            switch (cookchoi)
                            {
                            case 1:
                            {
                                if (invent.getCookware(0) > 1)
                                {
                                    int yes = 0;
                                    cout << "How many ingredients would you like to cook?(enter a number divisible by 5)" << endl;
                                    cin >> numing;
                                    if (numing % 5 == 0)
                                    {
                                        if (numing <= invent.getIngredients())
                                        {
                                            yes = rand() % 100 + 1;
                                            if (yes <= 25)
                                            {
                                                cout << "OH NO! your Ceramic Pot has broken, there has been no food made and you have lost those ingredients!" << endl;
                                                invent.setIngredients(numing, false);
                                                invent.setCookware(0, 1, false);
                                            }
                                            else
                                            {
                                                cout << "You have successfully cooked " << numing << " ingredients! Each player's fullness level has increased by " << (numing / 5) << endl;
                                                for (int i = 0; i < 5; i++)
                                                {
                                                    if (players[i].getAliveStatus() == true)
                                                    {
                                                        players[i].setFullness((numing / 5), true);
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "You entered an invalid amount of ingredients, this is not divisible by 5." << endl;
                                    }
                                }
                                else
                                {
                                    cout << "You do not have any ceramic pots to use." << endl;
                                }
                                break;
                            }
                            case 2:
                            {
                                if (invent.getCookware(1) > 0)
                                {
                                    int yes = 0;
                                    cout << "How many ingredients would you like to cook?(enter a number divisible by 5)" << endl;
                                    cin >> numing;
                                    if (numing % 5 == 0)
                                    {
                                        if (numing <= invent.getIngredients())
                                        {
                                            if (yes <= 10)
                                            {
                                                cout << "OH NO! your Frying Pan has broken, there has been no food made and you have lost those ingredients!" << endl;
                                                invent.setIngredients(numing, false);
                                            }
                                            else
                                            {
                                                cout << "You have successfully cooked " << numing << " ingredients! Each player's fullness level has increased by " << (numing / 5) << endl;
                                                for (int i = 0; i < 5; i++)
                                                {
                                                    if (players[i].getAliveStatus() == true)
                                                    {
                                                        players[i].setFullness((numing / 5), true);
                                                    }
                                                }
                                                invent.setIngredients(numing, false);
                                            }
                                        }
                                        else
                                        {
                                            cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "You entered an invalid amount of ingredients, this is not divisible by 5." << endl;
                                    }
                                }
                                else
                                {
                                    cout << "You do not have any frying pans to use." << endl;
                                }
                                break;
                            }
                            case 3:
                            {
                                if (invent.getCookware(2) > 0)
                                {
                                    int yes = 0;
                                    cout << "How many ingredients would you like to cook?(enter a number divisible by 5)" << endl;
                                    cin >> numing;
                                    if (numing % 5 == 0)
                                    {
                                        if (numing <= invent.getIngredients())
                                        {
                                            if (yes <= 2)
                                            {
                                                if (yes <= 10)
                                                {
                                                    cout << "OH NO! your Frying Pan has broken, there has been no food made and you have lost those ingredients!" << endl;
                                                    invent.setIngredients(numing, false);
                                                }
                                                else
                                                {
                                                    cout << "You have successfully cooked " << numing << " ingredients! Each player's fullness level has increased by " << (numing / 5) << endl;
                                                    for (int i = 0; i < 5; i++)
                                                    {
                                                        if (players[i].getAliveStatus() == true)
                                                        {
                                                            players[i].setFullness((numing / 5), true);
                                                        }
                                                    }
                                                    invent.setIngredients(numing, false);
                                                }
                                            }
                                            else
                                            {
                                                cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                            }
                                        }
                                        else
                                        {
                                            cout << "You entered a number of ingredients higher than what you have in your inventory!" << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "You entered an invalid amount of ingredients, this is not divisible by 5." << endl;
                                    }
                                }
                                else
                                {
                                    cout << "You do not have any Cauldrons to use." << endl;
                                }

                                break;
                            }
                            default:
                            {
                                cout << "invalid input bro" << endl;
                                break;
                            }
                            }
                            break;
                        }
                        case 5:
                        {
                            cout << "You had a sturdy effort warrior, better luck next time!" << endl;
                            mapDecision = 'm';
                            cho4 = 1;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Input Bruv" << endl;
                            break;
                        }
                        }
                    } while (cho4 != 1);
                }
                else if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int survive=0;
                    if ((5 - map.getRoomCount()) == 5)
                    {
                        for(int i=0;i<5;i++)
                        {
                            if(players[i].getAliveStatus()==true)
                            {
                                survive+=1;
                            }
                        }
                        if(survive>=2)
                        {
                            cout<<"Congrats! You have escaped the dungeon!"<<endl;
                            mapDecision=='m';
                        }
                        
                    }
                    else
                    {
                        cout<<"You have not cleared enough rooms to exit the dungeon."<<endl;
                    }
                }
            }
            else
            {
                cout<<"Invalid Input"<<endl;
            }
        }

    } while (mapDecision != 'm');
    cout<<players[0].getPlayerName()<<endl;
    cout<<invent.getNumGold<<endl;
    


    // return 0?

    // for movement on the map, create string variable and use cin and if else statements.
    //  merchant.displayMenu();//compiles up to here we have made the players array and it runs through and populates it with the names of the players

    // monster.fight(map, invent, players, 5);
}
