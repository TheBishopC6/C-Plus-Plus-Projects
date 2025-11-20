#include <iostream>
#include <iomanip>
using namespace std;

// ===== GLOBAL VARIABLES =====
float balance = 0.0f;
bool in_trip = false;

int current_start_zone = -1;
int current_start_hour = -1;

int last_start_zone = -1;
int last_end_zone = -1;
int last_start_hour = -1;
int last_end_hour = -1;
float last_fare = 0.0f;

// ===== GLOBAL FUNCTIONS =====

//see case 1
float read_recharge_amount() 
{
    float x;
    do
    {
        cout << "Enter recharge amount: ";
        cin >> x;
        if (x <= 0) cout << "Invalid amount! Please try again.\n";
    } while (x <= 0);
    return x;
}

//see case 2
int read_zone() 
{
    int z;
    do
    {
        cout << "Enter zone (1-3): ";
        cin >> z;
        if (z < 1 || z > 3) cout << "Invalid zone! Try again.\n";
    } while (z < 1 || z > 3);
    return z;
}

int read_hour() 
{
    int h;
    do
    {
        cout << "Enter hour (0-23): ";
        cin >> h;
        if (h < 0 || h > 23) cout << "Invalid hour! Try again.\n";
    } while (h < 0 || h > 23);
    return h;
}

float compute_fare(int sz, int ez, int sh, int eh) 
{
    float fare = 2.50;
    if ((sh >= 7 && sh <= 9) || (eh >= 17 && eh <= 19))
    {
        fare += 1.25;
    }
    if (sz != ez)
    {
       fare += 1.75; 
    }
    
    return fare;
}

void show_balance() 
{
    cout << "Your current balance is: $"<< fixed << setprecision(2) << balance << "\n";
}

void show_last_trip() 
{
    if (last_start_zone == -1)
    {
        cout << "No previous trip found.\n";
        return;
    }

    cout << "\nLast Trip Summary\n";
    cout << "Start Zone : " << last_start_zone << "\n";
    cout << "End Zone : " << last_end_zone << "\n";
    cout << "Start Hour : " << last_start_hour << "\n";
    cout << "End Hour : " << last_end_hour << "\n";
    cout << "Fare Paid : $" << fixed << setprecision(2) << last_fare << "\n";
}

void admin_debug()
{
    cout << "\n--- DEBUG INFO (POINTERS) ---\n";
    cout << "Balance addr: " << &balance << " | value: " << balance << "\n";
    cout << "In trip addr: " << &in_trip << " | value: " << in_trip << "\n";
    cout << "Last start zone addr: " << &last_start_zone << " | value: " << last_start_zone << "\n";
    cout << "Last end zone addr: " << &last_end_zone << " | value: " << last_end_zone << "\n";
    cout << "Last start hour addr: " << &last_start_hour << " | value: " << last_start_hour << "\n";
    cout << "Last end hour addr: " << &last_end_hour << " | value: " << last_end_hour << "\n";
    cout << "Last fare addr: " << &last_fare << " | value: " << last_fare << "\n";
}

// ===== MAIN PROGRAM =====
int main() 
{
    int choice;

    do 
    {
        cout << "\n=== SMART TRANSIT CARD ===\n";
        cout << "1. Recharge\n";
        cout << "2. Tap-In\n";
        cout << "3. Tap-Out\n";
        cout << "4. Show Balance\n";
        cout << "5. Show Last Trip\n";
        cout << "6. Admin/Debug\n";
        cout << "7. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                float amt = read_recharge_amount();
                balance += amt;
                cout << "Recharge successful. New balance: $"<< fixed << setprecision(2) << balance << "\n";
                break;
            }
            case 2: 
            {
                if (in_trip) cout << "You are already in a trip! Please tap out first.\n";
                else
                    {
                    current_start_zone = read_zone();
                    current_start_hour = read_hour();
                    in_trip = true;
                    cout << "Tap-In successful.\n";
                    }
                break;
            }
    
            case 3:
            {
                if (!in_trip) 
                {
                    cout << "No active trip detected. Penalty fare: $6.00\n";
                    if (balance >= 6.00f) 
                    {
                        balance -= 6.00f;
                        cout << "Penalty charged: $6.00\n";
                    } 
                    else cout << "Insufficient balance. Please recharge.\n";
                } 
                else 
                {
                    int end_zone = read_zone();
                    int end_hour = read_hour();
                    float fare = compute_fare(current_start_zone, end_zone, current_start_hour, end_hour);

                    if (balance >= fare) 
                    {
                        balance -= fare;
                        cout << "Fare charged: $" << fixed << setprecision(2) << fare << "\n";

                        last_start_zone = current_start_zone;
                        last_end_zone = end_zone;
                        last_start_hour = current_start_hour;
                        last_end_hour = end_hour;
                        last_fare = fare;
                    } 
                    else cout << "Insufficient balance. Please recharge.\n";
                }
                in_trip = false;
                break;
            }
            case 4: 
            {
                show_balance(); break;
            }
            case 5: 
            {
                show_last_trip(); break;
            }
            case 6:
            {
                admin_debug(); break;
            }

            case 7: 
            {
                cout << "Exiting...\n"; break;
            }

            default: 
            {
                cout << "Invalid choice. Try again.\n";
            }
        }

    } while (choice != 7);

return 0;
}