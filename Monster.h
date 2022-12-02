// CSCI 1300 Fall 2022
// Author: Jenna Beagle & Sam Mankin
// Recitation: 102 – Ojasvi Bhalerao
// Project 3 code skeleton
#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include "Player.h"
#include "Inventory.h"
#include "Map.h"
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;
/*
Algorithm:
A class for monsters where we are able to use it to obtain the name and difficulty of each monster through the Monster functions.
This will be used to summon the monsters throughout the game. We will call this class and its functions in order to do so.
*/
class Monster
{
    public:
    Monster();
    string getMonsterName(int index);
    int getDifficulty(int index);
    int split(string inputString, char separator, string arr[], int arrSize);
    // void setStatus(int index,bool what);
    bool getStatus(int index);
    bool fight(Map& map,Inventory& invent,Player members[], int size);


    // void setStatus(string name)
    // bool status(string name);

    private:
    string filename;
    string monsterNames[21];
    int monsterDifficulty[21];
    bool alive[21];
    //Player members[5];
    

};
#endif
//private vector of monster objects
// setmonster itterates through text file adds name and difficulty 
//rand in driver
//