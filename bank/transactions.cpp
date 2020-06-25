//
//  transctions.cpp
//  bank
//
//  Created by Roza on 12/01/2020.
//  Copyright © 2020 Roza. All rights reserved.
//

#include "transactions.hpp"
#include "listy_funkcje.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<cmath>
#include <chrono>
#include <thread>

void transactions(){
    
    osoba* Check = NULL;
    osoba* pamietaj = NULL;
    int count = 0, x = 0, choice = 0, done = 0, done1 = 0;
    float amount = 0;
    string haslo, typed, typ_konta, s_amount;
    fill_list(&Check, &count);
    

    if(count == 0){
        cout<< "No account exists, going back to menu"<<endl;
         this_thread::sleep_for(chrono::milliseconds(1000));
         delete_list(&Check);
        //delay
        return;
    }
    
    while( x == 0){
        
        cout << "Type your password: " << endl;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cin >> typed;
        osoba * temp = Check;
        
        while(temp != NULL){
            if( temp->password.compare(typed) == 0){
                cout<<"Login successful!"<<endl;
                 this_thread::sleep_for(chrono::milliseconds(1000));
                pamietaj = temp;
                
                if((temp->acc_type.compare("fixed")) == 1 || (temp->acc_type.compare("Fixed")) == 1 ){
                    cout<<"Your account is fixed, you can not make any transactions! Going back to menu."<<endl;
                     this_thread::sleep_for(chrono::milliseconds(1000));
                     delete_list(&Check);
                    return;
                }
                else if(temp->info->next->next->d.some_float== 0){
                    cout<<"You have no money to to tranfser! Going back to menu."<<endl;
                                     this_thread::sleep_for(chrono::milliseconds(1000));
                     delete_list(&Check);
                    return;
                }
    
                x = 1;
                break;
            }
            temp = temp->next;
        }

        if(x == 0){
            cout<<"Wrong password, to go back to menu type '1', to try again press any key."<<endl;
            cin>>choice;
            if(choice == 1){
                 delete_list(&Check);
                return;
            }
        }
    }
    
    
    while(done == 0)
    {
        cout<<"Enter the amount you want to transfer: ($) "<<endl;

        cin>>s_amount;
        if(s_amount.find_first_not_of("1234567890.-") != string::npos ){
            cout<<"Wrong input. To go back to menu press '1', to try again press any key."<<endl;
            cin>>choice;
            if(choice == 1){
                 delete_list(&Check);
                return;
            }
        }
        else if( (amount = stof(s_amount)) == 0)
        {
            cout<<"You can not tranfer 0$ ! To go back to menu press '1', to try again press any key."<<endl;
            cin>>choice;
            if(choice == 1){
                 delete_list(&Check);
                return;
            }
        }
        else if(pamietaj->info->next->next->d.some_float < (amount = stof(s_amount) ))
        {
            cout<<"You do not have enough money to transfer this amount. Going back to menu."<<endl;
             delete_list(&Check);
            return;
        }
        else
        {
            done = 1;
            
        }
    }
    
    while( done1 == 0)
    {
        int a = 0, b = 0;
        cout<<"Enter the number of the account which receives the transfer."<<endl;
        int number;
        cin>>number;
        osoba* temp = Check;
        szuflada* n = temp->info;
        
        while(temp != NULL)
        {
            n = temp->info;
            while(n != NULL)
            {
                if(n->type == 1){
                    if(n->d.some_int == number){
                       if((temp->acc_type.compare("fixed")) == 1 || (temp->acc_type.compare("Fixed")) == 1 )
                       {
                           cout<<"This account is fixed, you can not make any transactions! Going back to menu."<<endl;
                                            this_thread::sleep_for(chrono::milliseconds(1000));
                            delete_list(&Check);
                           return;
                       }
                       else{
                            a = 1;
                            b = 1;
                            done1 = 1;
                            cout<<"Account found. Tranfser in a process..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(1000));
                            //delay
                            n->next->next->d.some_float = n->next->next->d.some_float + amount;
                            pamietaj->info->next->next->d.some_float = pamietaj->info->next->next->d.some_float - amount;
                           
                            cout<<"Trasnfer finished with a success!"<< endl;
                            this_thread::sleep_for(chrono::milliseconds(1000));
                           
                           ofstream Zapis;
                           Zapis.open ("Dane.txt", ios::out | ios::trunc);
                           system("clear");
                           
                           if(Zapis.is_open()){
                               osoba* q = Check;
                               while(q != NULL){
                                   Zapis<<q->name<<" "<<q->acc_type<<" "<<q->password<<" "<<q->info->d.some_int<<" "<<q->info->next->d.some_int<<" "<<q->info->next->next->d.some_float<<endl;
                                   q = q->next;
                               }
                           }
                           Zapis.close();

                            break;
                        }
                        
                    }
                    break;
                }
                
            }
            if (b == 1)
                break;
            temp = temp->next;
            
        }
        
        if(a == 0)
        {
            cout<<"No such account was found. Try again!"<<endl;
            
        }
        
        
  
        
    }
     system("clear");
     delete_list(&Check);
  
    
    
    
};
