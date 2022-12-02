#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
class Player
{
    private:
        string name;
        int fullness;/*
        We want to come back to misfortunes and things later*/
        bool alive;
        static const int maxFullness=50;
        int count;
    public:
        Player();

        void setPlayerName(string names);
        string getPlayerName();
        void setFullness(int full,bool what);
        int getFullness();
        void setAliveStatus(bool what);
        bool getAliveStatus();
        int getNumAlive(Player members[], int size);

};
#endif