#include "Misfortunes.h"
#include "Player.h"
#include "Inventory.h"
#include "Merchant.h"
#include <iostream>
#include <fstream>
using namespace std;
int Misfortunes::split(string inputString, char separator, string arr[], int arrSize)
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
Misfortunes::Misfortunes()
{
    int size = 2;
    victory = true;
    string temp[2];
    string line = "";
    ifstream input;
    input.open("riddles.txt");
    int i = 0;
    while (getline(input, line))
    {
        int yes = split(line, '~', temp, size);
        riddles[i] = temp[0];
        answers[i] = temp[1];
        line = "";
        i++;
    }
}
void Misfortunes::boulderParchmentSheers(string answer)
{
    // 1=boulder
    // 2=parchment
    // 3=sheers
    int weird = rand() % 3 + 1;
    if (weird == 1)
    {
        if (answer == "boulder")
        {
            victory = true;
        }
        else
        {
            victory = false;
        }
    }
    else if (weird == 2)
    {
        if (answer == "parchment")
        {
            victory = true;
        }
        else
        {
            victory = false;
        }
    }
    else
    {

        if (answer == "sheers")
        {
            victory = true;
        }

        else
        {
            victory = false;
        }
    }
}
string Misfortunes::getRiddles(int index)
{
    return riddles[index];
}
string Misfortunes::getAnswers(int index)
{
    return answers[index];
}
bool Misfortunes::getVictory()
{
    return victory;
}
void Misfortunes:: RoomMisfortunes(Inventory& invent, Player players[],int size)
{
    int ran = rand()% 100 + 1;
    int playerLostFullness = rand() % 5 + 1;
    int numpA=0;
    if(ran<=30)
    {
        cout<<"OH NO! Your team was robbed by dungeon bandits!"<<endl;
        invent.setGold(1,false);
    }
    else if(ran>30&&ran<=60)
    {
        cout<<players[playerLostFullness].getPlayerName()<<" has lost 10 fullness points"<<endl;
        players[playerLostFullness].setFullness(10,false);
        if(players[playerLostFullness].getFullness()==0)
        {
            cout<<"This team member could not handle that drop in fullness, you have lost "<< players[playerLostFullness].getPlayerName()<< " as a team member"<<endl;
            players[playerLostFullness].setAliveStatus(false);
            for(int i=0;i<size;i++)
            {
                if(players[i].getAliveStatus()==true)
                {
                    numpA+=1;
                }
            }
            if(numpA<2)
            {
                canContinue = false;
            }
        }
    }
    else if(ran>60&&ran<=90)
    {
        cout<<"OH No! Your team member "<<players[playerLostFullness].getPlayerName()<<"has been trapped in the previous room! You have lost a team member."<<endl;
        players[playerLostFullness].setAliveStatus(false);
                    for(int i=0;i<size;i++)
            {
                if(players[i].getAliveStatus()==true)
                {
                    numpA+=1;
                }
            }
            if(numpA<2)
            {
                canContinue = false;
            }
    }
}
bool Misfortunes::getCanContinue()
{
    return canContinue;
}