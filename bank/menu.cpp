#include "menu.hpp"
#include "listy_funkcje.hpp"
#include "new_account.hpp"
#include "overview.hpp"
#include "edit.hpp"
#include "transactions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<cmath>



using namespace std;


void menu(void)
{
    int end = 0;
    
    int numer;
    string choice;
    
    while(end == 0){
        int y = 0;
 
        system("clear");
        cout<<"\n\n\t\t\t       BANKING MANAGEMENT SYSTEM"<<endl;
        cout<<"\n\n\n\t\t\t   WELCOME TO THE MAIN MENU"<<endl;
        cout<<"\n\n\t\t[1] Create a new account\n\t\t[2] Update information of existing account\n\t\t[3] Transactions\n\t\t[4] Check the details of existing account\n\t\t[5] Exit\n\n\n\t\t Enter your choice: "<<endl;
        while(y == 0)
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cin>>choice;
            

            if( choice.find_first_not_of("1234567") != string::npos  )
            {
                cout << "Wrong input. Try again!" << endl;
                
            }
            else if ( (numer = stoi(choice)) > 7)
            {
                cout << "Wrong input. Try again!" << endl;
                
                
            }
            else y = 1;
        }

            
        system("clear");
        
        switch(numer)
        {
            case 1:
                new_account();
                break;
            case 2:
                edit();
                break;
            case 3:
                transactions();
                break;
            case 4:
                overview();
                break;
            case 5:
                end = 1;
                break;
            
        }
    }
};
