#ifndef MISFORTUNES_H
#define MISFORTUNES_H
#include "Inventory.h"
#include "Merchant.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
using namespace std;
class Misfortunes
{
    private:
    bool victory;
    string riddles[20];
    string answers[20];
    bool canContinue=true;

    public:
    Misfortunes();
    void RoomMisfortunes(Inventory& invent, Player players[],int size);
    void boulderParchmentSheers(string answer);
    string getRiddles(int index);
    string getAnswers(int index);
    bool getVictory();
    bool getCanContinue();
    int split(string inputString, char separator, string arr[], int arrSize);

    //set riddle
    //set riddle answer
    //get riddle
    //get answer
    //get misfortune
    //set misfortune


};
#endif
