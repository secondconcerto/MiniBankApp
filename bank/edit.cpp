//
//  edit.cpp
//  bank
//
//  Created by Roza on 12/01/2020.
//  Copyright © 2020 Roza. All rights reserved.
//

#include "edit.hpp"
#include "listy_funkcje.hpp"
#include "new_account.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<cmath>
#include <chrono>
#include <thread>

using namespace std;


void edit()
{
    
    
    osoba* Check = NULL;
    osoba* pamietaj = NULL;
    int count = 0, x = 0 ;
    string haslo, typed;
    int phone = 0, wybor = 0, done = 0, choice = 0;
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
    
    

    int z = 0;
    while(z == 0){
        cout<<"To edit password type 1, to edit phone number type 2." << endl;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cin>>wybor;
        
        
        if(wybor == 1)
        {
            z = 1;
            while(done == 0){
                string nowe_h;
                cout<<"Type your new password: ";
                
                cin>>nowe_h;
                osoba* p = Check;
                while(p != NULL){
                    if( p->password.compare(nowe_h) == 0){
                        cout<<"Password already in use. Try again"<<endl;
                        this_thread::sleep_for(chrono::milliseconds(1000));
                        break;
                    }
                    p = p->next;
                }
                if(p == NULL){
                    pamietaj->password = nowe_h;
                    done = 1;
                    
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
                }
            }
        }
        
        else if (wybor == 2)
        {
            z = 1;
            while(done == 0){
                string nowe_n;
                osoba * w = Check;
                szuflada * v = w->info;
                
                
                int a = 0;
                int b = 0;
                while(b == 0){
                    cout<<"Type your new phone number: ";
                    cin>>nowe_n;
                    if(isNumber(nowe_n)){
                        b = 1;
                        phone = stoi(nowe_n);
                        w = Check;
                        while(w != NULL){
                            v = w->info;
                            while(v != NULL){
                                if(v->type == 2 ){
                                    if(v->d.some_int == phone){
                                        cout<<"Number already in use. Try again"<<endl;
                                        a = 1;
                                        break;
                                    }
                                }
                                if(v->next!= NULL)
                                    v = v->next;
                                else
                                    break;
                            }
                            if(a==1){
                                break;
                            }
                            else
                                w = w->next;
                        }
                        if(w == NULL){
                            done = 1;
                            pamietaj->info->next->d.some_int= phone;
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
                        }
                    }
                    else
                    {
                        cout<<"Wrong input. Try again!"<<endl;
                    }
                }
                
            }
        }
        
        else
        {
            cout<< "No such option. To go back to the menu press 1, to try again press any key."<<endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cin>>choice;
            if(choice == 1){
                 delete_list(&Check);
                return;
            }
            
        }
        
    }
     system("clear");
     delete_list(&Check);
    
};
