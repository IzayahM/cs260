/*
Izayah Marchand
1/17/2024
cs260

This program takes user input nad subtracts and adds marbles to a bag. 
in the future, I would like to add exception handling for entering chars
as well as a bag limit and marble colors.
*/
#include <iostream>

using std::cout;
using std::endl;

int main()
{

int ex = 0;
int marble = 0;

while (ex != 1)
{
    int num = 0;
    cout << "Current marbles in bag: " << marble << endl;

    cout << "\nEnter 1 to add marbles to bag, 2 to subtract marbles, and 3 to exit." << endl;
    std::cin >> num;

    //adds
    if(num == 1)
    {
        int x = 0;
        cout << "\nHow many marbles would you like to add?" << endl;
        std::cin >> x;
        marble += x;
    }

    //subtracts
    if(num == 2)
    {
        int x = 0;
        cout << "\nHow many marbles would you like to subtract?" << endl;
        std::cin >> x;
        marble -= x;
    }

    //exits program
    else if (num == 3)
    ex = 1;

    // else
    // continue;

}

printf("Have a fantastic day.");
return 0;

}