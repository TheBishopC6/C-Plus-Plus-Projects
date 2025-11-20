/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int transport, distance, passenger_age;
   int day, hour, baggage;
   char class_code, student, member;
   
   cout<<"Enter transport type (1=Bus, 2=Train, 3=Flight): ";
   cin>>transport;
   
   cout<<"Enter travel distance (km): ";
   cin>>distance;
   
   cout<<"Enter age: ";
   cin>>passenger_age;
   
   cout<<"Enter travel day (1=weekday, 2=weekend): ";
   cin>>day;
   
   cout<<"Enter travel hour (0...23): ";
   cin>>hour;
   
   cout<<"Enter class (S=Sleeper, A=AC, B=Business, N=Normal): ";
   cin>>class_code;
   
   cout<<"Enter baggage Weight (kg): ";
   cin>>baggage;
   
   cout<<"Is passenger a student? (Y/N): ";
   cin>>student;
   
   cout<<"Is passenger a member? (Y/N): ";
   cin>>member;
   
   double base_fare = 0, surcharge = 0, discount = 0;
   double baggage_fee = 0, total_fare = 0;
   
    switch(transport)
    {
        case 1:
        {
            if(class_code == 'S' || class_code == 's')
            {
                base_fare = base_fare * 1.2;
            }
            if(hour >= 18 && hour <= 22)
            {
                surcharge = base_fare * 1.15;
            }
            if(passenger_age <= 12 || passenger_age >= 60)
            {
                discount = discount +(base_fare * 0.5);
            }
            if(student == 'y' || student == 'Y')
            {
                discount = discount + (base_fare * 0.1);
            }
            if(member == 'y' || member == 'Y')
            {
                discount = discount + (base_fare * 0.05);
            }
            if(base_fare < 2)
            {
                base_fare = 2;
            }
            if(baggage > 10)
            {
                baggage_fee = (baggage - 10) * 1.0;
            }
        }
        break;
            default:
            {
                cout<<"invalid transport\n";
                return 0;
            }
    }
    
    total_fare = base_fare + surcharge - discount +baggage_fee;
    
    cout<<fixed<<setprecision(2);
    cout<<"final ticket price: $"<<total_fare<<endl;

    return 0;
}