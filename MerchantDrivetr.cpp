#include "Merchant.h"
#include "Inventory.h"
#include "Player.h"
#include "Map.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    Merchant merchant;
    Inventory invent;
    Map map;
    merchant.displayMenu(invent,map);
}