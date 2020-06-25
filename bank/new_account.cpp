//
//  new_account.cpp
//  bank
//
//  Created by Roza on 12/01/2020.
//  Copyright © 2020 Roza. All rights reserved.
//

#include "new_account.hpp"
#include "listy_funkcje.hpp"
using namespace std;


bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    
    return true;
}

void new_account(){
    
    
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int done1 = 0;
    int done2 = 0;
    int done3 = 0;
    int done4 = 0;
    int done5 = 0;
    int done6 = 0;
    int done7 = 0;
    int done8 = 0;
    int done9 = 0;
    int imie_done = 0;
    int acc_num_done = 0;
    int phone_done = 0;
    int acc_bal_done = 0;
//    osoba* Person = NULL;
    osoba* Check = NULL;
    
    
    
    
    string name;
    string acc_type;
    string haslo;
    string num;
    string line;
    //    float x=0;
    int num_acc=0;
    int phone=0;
    float acc_balance = 0;
    
    int y = 0;
    
    
    fill_list(&Check, &y);
    ofstream Zapis;
    Zapis.open ("Dane.txt", ios::app);
    system("clear");
    
    
    
    while(done1 == 0){
        while(imie_done == 0){
            while(done2 ==0){
                a = 0;
                
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout<<"Enter your name: "<<endl;
                cin>>name;
                
                
                cout<<"\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice: \n"<<endl;
                cin>>acc_type;
                while(done9 == 0){
                    a = 0;
                    cout<<"Enter your password: "<<endl;
                    cin>>haslo;
                    
                    osoba*temp = Check;
                    while(temp != NULL){
                        if( temp->password.compare(haslo) == 0){
                            cout<<"Password already in use. Try again"<<endl;
                            a = 1;
                        }
                        temp = temp->next;
                    }
                    if(a == 0){
                        done9 = 1;
                    }
                }
                
                done2 = 1;
                imie_done = 1;
                if(Check == NULL){
                    Zapis<<name<<" "<<acc_type<<" "<<haslo<<" ";
                }
                else  Zapis<<endl<<name<<" "<<acc_type<<" "<<haslo<<" ";
//                insert_name(&Person,name, acc_type, haslo);
                
            }
            
            
            
            while(acc_num_done == 0){
                
                while(done3 == 0 || done4 == 0){
                    b = 0;
                    c = 0;
                    cout<<"Enter your account number: "<<endl;
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    cin>>num;
                    
                    if(isNumber(num)){
                        num_acc = stoi(num);
                        osoba*temp = Check;
                        //                        while(temp != NULL && temp->info != NULL){
                        while(temp != NULL){
                            if(temp->info->type == 1){
                                if( temp->info->d.some_int == num_acc){
                                    cout<<"Number already in use. Try again";
                                    b = 1;
                                    break;
                                }
                                
                            }
                            temp = temp->next;
                        }
                    }
                    else
                    {
                        cout<<"Wrong input. Try again!"<<endl;
                        c = 1;
                        
                    }
                    if(b == 0 && c == 0){
                        done3 = 1;
                        done4 = 1;
                        acc_num_done = 1;
                        Zapis<<num_acc<<" ";
//                        insert_a_num(&Person->info,num_acc);
                    }
                    
                }
                while(phone_done == 0){
                    
                    while(done5 == 0 || done6 == 0){
                        d = 0;
                        e = 0;
                        cout<<"Enter your phone number: "<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX,'\n');
                        cin>>num;
                        
                        if(isNumber(num)){
                            phone = stoi(num);
                            osoba*temp = Check;
                            szuflada* inner = temp -> info;
                            while(temp != NULL){
                                while( inner != NULL){
                                    if(inner->type == 2 ){
                                        if( inner->d.some_int == phone){
                                            cout<<"Number already in use. Try again";
                                            d = 1;
                                            break;
                                        }
                                        
                                    }
                                    inner = inner->next;
                                }
                                temp = temp->next;
                                if(temp != NULL)
                                    inner = temp->info;
                            }
                        }
                        else
                        {
                            cout<<"Wrong input. Try again!"<<endl;
                            e = 1;
                            
                        }
                        if(d == 0 && e == 0){
                            done5 = 1;
                            done6 = 1;
                            phone_done = 1;
                            Zapis<<phone<<" ";
//                            insert_a_phone(&Person->info,phone);
                        }
                        
                    }
                    while(acc_bal_done == 0){
                        while(done7 == 0 || done8 == 0){
                            f = 0;
                            cout<<"Enter your account balance: "<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX,'\n');
                            cin>>num;
                            if( num.find_first_not_of("1234567890.") != string::npos )
                            {
                                cout << "Wrong input. Try again!" << endl;
                                f = 1;
                                
                            }
                            if(f == 0){
                                done7 = 1;
                                done8 = 1;
                                done1 = 1;
                                acc_bal_done = 1;
                                acc_balance = stof(num);
                                Zapis<<acc_balance<<" ";
//                                insert_a_phone(&Person->info,phone);
                            }
                            
                        }
                    }
                }
            }
        }
    }
    
    
    
    
    Zapis.close();
    system("clear");
    delete_list(&Check);
//    delete_list(&Person);
};
