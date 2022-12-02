// CSCI 1300 Fall 2022
// Author: Jenna Beagle & Sam Mankin
// Recitation: 102 – Ojasvi Bhalerao
// Project 3 code skeleton
#include "Monster.h"
#include "Player.h"
#include "Inventory.h"
#include "Map.h"
#include "Merchant.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <fstream>
using namespace std;
// these functions are still in progress but are a basic outline of what is meant to happen.
int Monster::split(string inputString, char separator, string arr[], int arrSize)
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
Monster::Monster()
{
    string monst = "monsters.txt";
    ifstream input;
    string line = "";
    int i = 0;
    input.open(monst);
    while (getline(input, line))
    {
        string temp[2];
        int size = 2;
        int yes = split(line, ',', temp, 2);

        monsterNames[i] = temp[0];
        monsterDifficulty[i] = stoi(temp[1]);
        alive[i] = true;
        line = "";
        i++;
    }
}
string Monster::getMonsterName(int index)
{
    return monsterNames[index];
}
int Monster::getDifficulty(int index)
{
    return monsterDifficulty[index];
}

// void Monster::setStatus(int index, bool what)
// {
//     alive[index]=what;

// }
bool Monster::getStatus(int index)
{
    return alive[index];
}
bool Monster::fight(Map &map, Inventory &invent, Player members[], int size)
{
    srand(time(0));
    int rooms = 5 - map.getRoomCount();
    int random;
    int numberof = 0;
    bool victory;
    if (rooms == 0)
    {
        if (alive[0] == false && alive[1] == false && alive[2] == false && alive[3] == false)
        {
            cout << "Pass the first room before fighting anymore monsters." << endl;
        }
        else
        {
            do
            {
                random = rand() % 3 + 0;

            } while (alive[random] == false);
        }
        //  random = rand() % 0+3;
    }
    else if (rooms == 1)
    {
        if (alive[4] == false && alive[5] == false && alive[6] == false && alive[7] == false)
        {
            cout << "Pass the second room before fighting anymore monsters." << endl;
        }
        else
        {
            do
            {
                srand(time(0));
                random = rand() % 7 + 4;
            } while (alive[random] == false);
        }
        // random = rand() % 4+7;
    }
    else if (rooms == 2)
    {
        if (alive[8] == false && alive[9] == false && alive[10] == false && alive[11] == false)
        {
            cout << "Pass the third room before fighting anymore monsters." << endl;
        }
        else
        {
            do
            {
                srand(time(0));
                random = rand() % 11 + 8;
            } while (alive[random] == false);
        }
        // random = rand() % 8+11;
    }
    else if (rooms == 3)
    {
        if (alive[12] == false && alive[13] == false && alive[14] == false && alive[15] == false)
        {
            cout << "Pass the fourth room before fighting anymore monsters." << endl;
        }
        else
        {
            do
            {
                srand(time(0));
                random = rand() % 15 + 12;
            } while (alive[random] == false);
        }
        // random = rand() % 12+15;
    }
    else if (rooms == 4)
    {
        if (alive[16] == false && alive[17] == false && alive[18] == false && alive[19] == false)
        {
            cout << "Pass the fifth room before fighting anymore monsters." << endl;
        }
        else
        {
            do
            {
                srand(time(0));
                random = rand() % 19 + 16;
            } while (alive[random] == false);
        }
        // random = rand() % 16+19;
    }
    else
    {
        random = 20;
    }
    cout << "You have encountered a Monster! Prepare your group to fight " << monsterNames[random] << " difficulty: " << monsterDifficulty[random] << endl;
    // for(int i=0;i<5;i++)
    // {
    //     if(members[i].getAliveStatus()==true)
    //     {
    //         numberof+=1;
    //     }
    // }
    if (invent.getWeapons(0) > 0 || invent.getWeapons(1) > 0 || invent.getWeapons(2) > 0 || invent.getWeapons(3) > 0 || invent.getWeapons(4) > 0) // this is not getting met
    {
        int de;
        // do
        // {
            cout << "Would you like to fight this monster or surrender?  (1 for fight, 2 for surrender)" << endl;
            cin >> de;
            if(de==1)
            {
                //cout << "Are you here?" << endl;
                int w = invent.getWeapons(0) + invent.getWeapons(1) + invent.getWeapons(2) + invent.getWeapons(3) + invent.getWeapons(4);
                // srand(time(0));
                int rone = rand() % 6 + 1;
                // srand(time(0));
                int rtwo = rand() % 6 + 1;
                int c = monsterDifficulty[random];
                //cout << c << endl;
                int a = invent.getArmor();
                //cout << a << endl;
                int d;
                // srand(time(0));
                int lostIngredients = rand() % 30 + 1;
                // bool victory;
                // srand(time(0));
                int key = rand() % 10 + 1;
                if (invent.getWeapons(0) <= 1 && invent.getWeapons(1) <= 1 && invent.getWeapons(2) <= 1 && invent.getWeapons(3) <= 1 && invent.getWeapons(4) <= 1)
                {
                    d = 4;
                }
                else
                {
                    d = 0;
                }
                //cout << "d" << endl;
                if ((rone * w) + d - ((rtwo * c) / (a + 1) > 0))
                {
                    victory == true;
                    invent.setGold((10 * c), true);
                    invent.setIngredients((5 * c), true);
                    if (key == 1)
                    {
                        invent.setKeys(1, true);
                        //cout << "invent.getKeys()" << endl;
                    }
                    alive[random] == false;
                }
                else
                {
                    // srand(time(0));
                    int play1 = rand() % 20 + 1;
                    // srand(time(0));
                    int play2 = rand() % 20 + 1;
                    // srand(time(0));
                    int play3 = rand() % 20 + 1;
                    // srand(time(0));
                    int play4 = rand() % 20 + 1;
                    victory = false;
                    invent.setGold((invent.getGold() / 4), false);
                    if (invent.getIngredients() < lostIngredients)
                    {
                        invent.setIngredients(invent.getIngredients(), false);
                        cout << "invent.getIngredients()" << endl;
                    }
                    else
                    {
                        invent.setIngredients(lostIngredients, false);
                    }
                    // as you go through mortality probability, remember to remove players from the array.
                    int sir = invent.getArmor();
                    for (int i = 1; i < size; i++)
                    {
                        if (members[i].getAliveStatus() == true)
                        {
                            if ((rand() % 20 + 1) > 10)
                            {
                                members[i].setFullness(1, false);
                                // srand(time(0));
                            }
                            cout << members[0].getFullness() << endl;
                            if (sir > 0) // five percent chance of being slain for this person
                            {
                                // srand(time(0));
                                if ((rand() % 20 + 1) == 1)
                                {
                                    members[i].setAliveStatus(false);
                                    cout << "You have lost a group member " << members[i].getPlayerName() << " has been slain as a result of the fight" << endl;
                                }
                                else
                                {
                                    cout << members[i].getPlayerName() << " has survived this monster." << endl;
                                }
                                sir--;
                                //cout << "sir" << endl;
                            }
                            else
                            {
                                // srand(time(0));
                                if ((rand() % 20 + 1) <= 2)
                                {
                                    members[i].setAliveStatus(false);
                                    cout << "You have lost a group member " << members[i].getPlayerName() << " has been slain as a result of the fight" << endl;
                                }
                                else
                                {
                                    cout << members[i].getPlayerName() << " has survived this monster." << endl;
                                }
                            }
                        }
                    }
                }
                //cout << "end" << endl;

            }
            else if(de==2) // surrendur
            {
                bool lostPlayer = false;
                for (int i = 1; i < size; i++)
                {
                    if (lostPlayer == false && members[i].getAliveStatus() == true)
                    {
                        members[i].setAliveStatus(false);
                        cout << "You have lost a group member " << members[i].getPlayerName() << " has been slain as a result of the fight" << endl;
                        lostPlayer = true;
                    }
                    int randomVar = rand() % 20 + 1;
                    if (randomVar > 10 && members[i].getAliveStatus() == true)
                    {
                        cout << members[i].getPlayerName() << " has lost a fullness point." << endl;
                        members[i].setFullness(1, false);
                    }
                }
            }
            else
            {
                cout << "Invalid input sir/ma'am/you" << endl;
            }
        // } while ((de != 1) || (de != 2));
    }
    else
    {
        victory = false;
        cout << "You can only surrender since you do not hold enough weapons." << endl;
        bool lostPlayer = false;
        for (int i = 1; i < size; i++)
        {
            if (lostPlayer == false && members[i].getAliveStatus() == true)
            {
                members[i].setAliveStatus(false);
                cout << "You have lost a group member " << members[i].getPlayerName() << " has been slain as a result of the fight" << endl;
                lostPlayer = true;
            }
            int randomVar = rand() % 20 + 1;
            if (randomVar > 10 && members[i].getAliveStatus() == true)
            {
                cout << members[i].getPlayerName() << " has lost a fullness point." << endl;
                members[i].setFullness(1, false);
            }
        }
    }
    return victory;
}
