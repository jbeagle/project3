#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    fullness=50;
    alive=true;
    count=0;
}
void Player::setPlayerName(string names)
{
    name=names;
}

string Player::getPlayerName()
{
    return name;
}

void Player::setFullness(int full, bool what)
{
    if(what==true)
    {
        fullness+=full;
    }
    else
    {
        if(fullness-full<=0)
        {
            setAliveStatus(false);
        }
        fullness = fullness-full;
    }
}
int Player::getFullness()
{
    return fullness;
}
void Player::setAliveStatus(bool what)
{
    if(fullness<=0)
    {
        alive = false;
    }
    else if(what==false)
    {
        alive = false;
    }
    else if(what==true)
    {
        alive = true;
    }
}
bool Player::getAliveStatus()
{
    return alive;
}
int Player::getNumAlive(Player members[], int size)
{
    for(int i=0;i<size;i++)
    {
        if(members[i].getAliveStatus()==false)
        {
            count=count;
        }
        else
        {
            count+=1;
        }
    }
    return count;
}