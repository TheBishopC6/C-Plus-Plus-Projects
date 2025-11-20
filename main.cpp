//tracks the movement of an elevator and moves from floor to floor
#include <iostream>
using namespace std;

int bulding_min = -2;
int building_max = 10;

int min_floor = 0;
int max_floor = 0;
int invalid_moves = 0;

int main()
{
    int current_floor = 0;
    char command;
    
    while(true)
    {
        cout<<"\nEnter command (u/d/s/q): ";
        cin>>command;
        
        if(command == 'q')
        {
            break;
        }
        
        switch(command)
        {
            case 'u':

                if(current_floor + 1 > building_max)
                {
                    cout<<"error! Already at top floor!"<<endl;
                    invalid_moves++;
                }
                else
                {
                    current_floor++;
                }
                break;
            case 'd':
                if(current_floor - 1 < bulding_min)
                {
                    cout<<"Error! Already at bottom floor!"<<endl;
                    invalid_moves++;
                }
                else
                {
                    current_floor--;
                }
                break;
            case 's':
                break;

            default:
                cout<<"Invalid command!Please choose correct command(u/d/s/q)";
                invalid_moves++;
                break;
        }
        
        if(current_floor < min_floor)
        {
            min_floor = current_floor;
        }
        
        if(current_floor > max_floor)
        {
            max_floor = current_floor;
        }
        
        cout<<"Current Floor: "<<current_floor<<endl;
        
    }
    
    cout<<"\n---Simulation Ended---\n";
    cout<<"Lowest floor reached: "<<min_floor<<endl;
    cout<<"Highest floor reached: "<<max_floor<<endl;
    cout<<"Invalid moves: "<<invalid_moves<<endl;

    return 0;
}