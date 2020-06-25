//
//  listy_funkcje.cpp
//  bank
//
//  Created by Roza on 11/12/2019.
//  Copyright © 2019 Roza. All rights reserved.
//

#include "listy_funkcje.hpp"
#include "menu.hpp"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



using namespace std;
void insert_name(struct osoba** head, string new_data1, string new_data2, string new_data3)
{
    struct osoba* newNode = new osoba;
    struct osoba* last = *head;
    
    newNode->name = new_data1;
    newNode->acc_type = new_data2;
    newNode->password = new_data3;
    newNode->info = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
            return;
        
    }
    
    else{
    
        while (last->next != NULL){
            last = last->next;
            }
        last->next = newNode;
        newNode->prev = last;

    return;
        }
    
};

void insert_a_num(struct szuflada** start, int new_data)
{

    struct szuflada* newNode = new szuflada;

    szuflada* last = *start;

    newNode->d.some_int= new_data;
    newNode->type = 1;
    newNode->next = NULL;

    
    if (*start == NULL) {
        newNode->prev = NULL;
        *start = newNode;
        return;
    }
    else {
        while (last->next != NULL){
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    
    return;
    }
    
};

void insert_a_phone(struct szuflada** start, int new_data)
{
    struct szuflada* newNode = new szuflada;

    szuflada* last = *start;

    newNode->d.some_int= new_data;
    newNode->type = 2;
    newNode->next = NULL;

    if (*start == NULL) {
        newNode->prev = NULL;
        *start = newNode;
        return;
    }
    else {
        while (last->next != NULL){
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
        
        return;
    }
    
};

void insert_acc_balance(struct szuflada** start, float new_data)
{
    struct szuflada* newNode = new szuflada;
    
    szuflada* last = *start;
  
    newNode->d.some_float= new_data;
    newNode->type = 3;
    newNode->next = NULL;
    
    
    if (*start == NULL) {
        newNode->prev = NULL;
        *start = newNode;
        return;
    }
    else {
        while (last->next != NULL){
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
        
        return;
    }
    
};

void fill_list(struct osoba**head, int *counter){
    
    string name, acc_type, haslo, typed;
    int num_acc, phone = 0;
    float acc_balance;
    ifstream Odczyt;
    Odczyt.open ("Dane.txt");
    Odczyt.seekg( 0, ios_base::beg );
    system("clear");

    
    if(Odczyt.is_open()){
        osoba* p = *head;
        while(Odczyt>>name>>acc_type>>haslo>>num_acc>>phone>>acc_balance){
            if(*head==NULL){
                insert_name(head,name, acc_type, haslo);
                (*counter)++;
                p=*head;
                insert_a_num(&p->info,num_acc);
                insert_a_phone(&p->info,phone);
                insert_acc_balance(&p->info,acc_balance);
            }
            else{
                insert_name(head,name, acc_type, haslo);
                (*counter)++;
                p=p->next;
                insert_a_num(&p->info,num_acc);
                insert_a_phone(&p->info,phone);
                insert_acc_balance(&p->info,acc_balance);
            }
            
        }
    }
    Odczyt.close();
    
};

void delete_list(struct osoba** head)
{
    osoba* temp = *head;
    szuflada* help = NULL;

    while(temp != NULL)
    {
        help = temp->info;
        while( help != NULL)
        {
            szuflada* pamietaj =  help->next;
            help->prev = NULL;
            help->next = NULL;
            delete(help);
            help = pamietaj;

        }

        osoba* pamietaj = temp->next;
        temp->prev = NULL;
        temp->next = NULL;
        delete(temp);
        temp = pamietaj;

    }
};

void swapNode(osoba** head_ref, int x, int y)
{
    

    osoba *prevX = NULL;
    osoba *currX = *head_ref;
    osoba *nextX = currX->next;
    while (currX && currX->info->d.some_int != x)
    {
        
        prevX = currX;
        currX = currX->next;
        nextX = currX->next;
        
    }
    
    

    osoba *prevY = NULL;
    osoba *currY = *head_ref;
    osoba *nextY = currY->next;
    while (currY && currY->info->d.some_int != y)
    {
        prevY = currY;
        currY = currY->next;
        nextY = currY->next;
        
    }
    
    

    if (currX == NULL || currY == NULL)
        return;
    
   
    if (prevX != NULL){
        prevX->next = currY;
        if(nextX)
            nextX->prev = currY;
    }
    
    else
    {
        *head_ref = currY;
        if(nextX)
            nextX->prev = currY;
    }
    
    
    if (prevY != NULL){
        prevY->next = currX;
        if(nextY)
            nextY->prev = currX;
        
    }
    else
    {
        *head_ref = currX;
        if(nextY)
            nextY->prev = currX;
    }

    osoba* temp_N = currY->next;
    currY->next = currX->next;
    currX->next = temp_N;
    
    osoba* temp_P = currY->prev;
    currY->prev = currX->prev;
    currX->prev = temp_P;
    
    return;
};


