//
//  overview.cpp
//  bank
//
//  Created by Roza on 12/01/2020.
//  Copyright © 2020 Roza. All rights reserved.
//

#include "overview.hpp"
#include "listy_funkcje.hpp"
#include <chrono>
#include <thread>

using namespace std;


void bubbleSort(osoba* start)
{
    
    
    int swapped;
    struct osoba *ptr1;
    struct osoba *lptr = NULL;
    
    
    
    if (start == NULL)
        return ;
    
    do
    {
        swapped = 0;
        ptr1 = start;
        
        
        
        while (ptr1->next != lptr)
        {
            if (ptr1->info->type == 1 && ptr1->info->d.some_int > ptr1->next->info->d.some_int)
            {
                
                swapNode(&start,ptr1->info->d.some_int, ptr1->next->info->d.some_int);
                swapped = 1;
                ptr1 = ptr1->prev;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    
    while (swapped);
    
    
    return;
    
};


void overview()
{
    osoba * Check = NULL;

    int count = 0 ;
    string haslo, typed;
    fill_list(&Check, &count);
    
    if(count == 0){
        cout<< "No account exists, going back to menu"<<endl;
         delete_list(&Check);
        this_thread::sleep_for(chrono::milliseconds(1000));
        return;
    }
    
    bubbleSort(Check);
    
    
    osoba * temp = Check;
    while(temp->prev != NULL){
        temp = temp->prev;
    }
    Check = temp;
    
    int existing = 0;
    while( existing == 0){
        
        int liczba, l, p, s, num_found;
        
        l = 0;
        p = count-1;
        osoba* find = Check;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << "Enter your account number: ";
        cin >> liczba;
        
        while (true)
        {
            
            if (l > p)
            {
                break;
            }
            
            s = (l+p)/2;
            
            for(int x = 0; x < s; x++)
            {
                
                if(find->info->type == 1){
                    num_found = find->info->d.some_int;
                    if (num_found == liczba)
                    {
                        existing = 1;
                        cout << "Your account details "<< endl<< "name: "<< find->name << endl << "account type: "<< find->acc_type <<endl<< "account number: "<< find->info->d.some_int << endl << "account balance: "<< find->info->next->next->d.some_float <<"$"<<endl << "phone number: "<<find->info->next->d.some_int <<endl;
                        this_thread::sleep_for(chrono::milliseconds(5000));
                        break;
                    }
                }
                find = find->next;
            }
            
            
            if (num_found == liczba)
            {
                break;
            }
            
            else if (num_found < liczba)
                l = s+1;
            else
                p = s-1;
            
            
        }
        
        if(existing == 0){
            cout<< "No such account. To try again press 1, to go back to the menu press 2."<<endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            int choice;
            cin>>choice;
            if(choice == 2){
                 delete_list(&Check);
                existing = 1;
            }
            
        }
    }
     system("clear");
    delete_list(&Check);
    
};
