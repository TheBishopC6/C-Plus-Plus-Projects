/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

bool is_strong_code(int code)
{
   int original = code;
   int sum = 0;
   int last_digit = code % 10;
   
   while(code > 0)
   {
       sum += code % 10;
       code /= 10;
   }
   
   int first_digit = original;
   
   while(first_digit >= 10)
   {
       first_digit /= 10;
   }
   
   if(sum % 2 == 0 && first_digit != last_digit)
   {
       return true;
   }
   else
   {
       return false;
   }
}

int main()
{
    int code;
    
    cout<<"Enter a 4 digit code: ";
    cin>>code;
    
    if(is_strong_code(code))
    {
        cout<<"The Code is STRONG"<<endl;
    }
    else
    {
        cout<<"The Code is WEAK"<<endl;
    }

    return 0;
}