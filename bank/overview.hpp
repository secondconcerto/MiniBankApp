/**
 * @file overview.hpp
 * @brief The file contains functions responsible for searching and displaying user data.
 * @author Oliwia Mlonek
 */


#ifndef overview_hpp
#define overview_hpp


#include "listy_funkcje.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<cmath>

using namespace std;

/**
 Function that allows to view and search user data.
 */
void overview();

/**
 Function that contains the "Bubble Sort" sorting algorithm. Sorts 'osoba' nodes (in ascending order) based on the account number in the 'szuflada' list inside this nodes.
 @param start a pointer of type "osoba" to the first node of the "osoba" list.
 */
void bubbleSort(osoba* start);

#endif /* overview_hpp */
