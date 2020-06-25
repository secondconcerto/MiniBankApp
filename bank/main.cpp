

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include "menu.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    

    int i = 0;
    int done = 0;
    int a = 0;

    ifstream Hasla;
    Hasla.open("password.txt");
    if (!Hasla) {
        cerr << "Unable to open file ";
        exit(1);   // call system to stop
    }

    string pass;
    string line;


    cout<<"\n\n\n\t\t\t\t   *** Bank Management System ***\n\t\t\t\t\t         User Login "<<endl;
    cout<<"\n\n\t\t\t\t    Enter the password to login: "<<endl;

    while(done == 0)
    {
        Hasla.clear();
        Hasla.seekg( 0, ios_base::beg );
  
        cin >> pass;
        while(getline(Hasla, line))
        {
            if(pass.compare(line) == 0)
            {
                a = 1;
                done = 1;
                cout<<"\n\nPassword Match!\nLOADING\n"<<endl;
                for (i = 0; i < 5; i++)
                {
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    cout<<"."<<endl;
                }
                system("clear");
                menu();
                
            }
            
        }
        if(a == 0)
        {
            done = 0;
            cout<<"\n\nWrong password! Try again\n"<<endl;
            
        }
        
    }
    cout<<"\nThank you for using our services!"<<endl;
    Hasla.close();

    return 0;
}

