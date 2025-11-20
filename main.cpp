/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

float calculate_bill(int units)
{

float total;
    
    if(units <= 100)
    {
        total = units * 1.5;
    }
    else if(units <= 300)
    {
        total = (100 * 1.5) + (units - 100) * 2 ;
    }
    else if(units <= 500)
    {
        total = (100 * 1.5) + (200 * 2) + (units - 300) * 3;
    }
    else
    {
        total = (100 * 1.5) + (200 * 2) + (200 * 3) + (units - 500) * 5;
    }
    
    return total;
}

int main()
{
    int units;
    
    cout<<"Enter number of units used: ";
    cin>>units;
    
    float bill = calculate_bill(units);
    cout<<"Total Electricity bill = $"<<bill<<endl;
    
    return 0;
}