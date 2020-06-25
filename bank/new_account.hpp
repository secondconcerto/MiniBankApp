/**
 * @file new_account.hpp
 * @brief The file the functions that are responsible for creating a new user account and entering it into the database in a text file 'Dane'.
 * @author Oliwia Mlonek
 */


#ifndef new_account_hpp
#define new_account_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<cmath>
#include "listy_funkcje.hpp"
using namespace std;

/**
 Function that allows creating a new account in the 'application'.
 */
void new_account();


/**
 Bool function responsible for checking whether the text given by the user contains only numbers.
 @param s a string which contain a text typed by the user.
 @return true if there are no letters or symbols, false if a letter or symbol was found.
  */
bool isNumber(string s);



#endif /* new_account_hpp */
