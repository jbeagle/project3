#include "Monster.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <iomanip>
#include <fstream>
using namespace std;
int split(string inputString, char separator, string arr[], int arrSize)
{
    // ex: "abc,c" separator: ","
    int numElementsInserted = 0;
    if(inputString.length() == 0) // inputString is empty
    {
        return 0;
    }

    string insertIntoArray;
    insertIntoArray.push_back(inputString.at(0)); // iia = "a"

    // inputString has 1 character
    if(inputString.length() == 1)
    {
        if (arrSize > numElementsInserted)
        {
            arr[numElementsInserted] = insertIntoArray;
            numElementsInserted++;
            return numElementsInserted;
        }
    }

    // inputString has 3 or more characters
    for (int i=1; i<inputString.length(); i++) // start at first char, which we know is not the delimeter
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
    if(arrSize == numElementsInserted)
    {
        return -1;
    }
    arr[numElementsInserted] = insertIntoArray;
    numElementsInserted++;
    
    return numElementsInserted;
    
}
int main()
{
    // Monster temp;
    // temp.setMonsterName("HERB");
    // cout<<temp.getMonsterName()<<endl;
    Monster monsters[21];  //{one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen,twenty,twentyone};
    ifstream input;
    string line="";
    int i=0;
    input.open("monsters.txt");
    while(getline(input,line))
    {
        
        string temp[2];
        int size=2;
        int yes=split(line,',',temp,2);
        
            monsters[i].setMonsterName(temp[0]);
            //cout<<"two"<<endl;
            monsters[i].setDifficulty(stoi(temp[1]));
            //cout<<"three"<<endl;
            line="";
            //cout<<"four"<<endl;
        i++;
       

    }
    cout<<monsters[6].getDifficulty()<<endl;
}