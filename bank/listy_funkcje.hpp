/**
 * @file listy_funkcje.hpp
 * @brief The file is a set of all data structures and functions responsible for creation, manipulation and editing the list of lists. Those function are used throughout the program.
 * @author Oliwia Mlonek
 */

#ifndef listy_funkcje_hpp
#define listy_funkcje_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



using namespace std;


/**
 Union that helps store numeric data since it contains an integer and float variable. It is used inside the 'szuflada' nodes.
 */
union dane{

    int some_int;
    float some_float;
};

/**
 Structure which holds user numeric data - it uses a union to do so. It also cointains an integer variable which indicates number between 1-3.
 The number in this variable informs what kind of information is stored in union in the specific 'szuflada' node (1 for account number, 2 for phone number, 3 for account balance). Moreover, the structure has two 'szuflada' pointers for previous and next node of type 'szuflada'.
 */
struct szuflada {
    szuflada(){};
    struct szuflada *prev;
    int type;//1 for acc-num, 2 for phone, 3 for acc_balance
    union dane d;
    struct szuflada *next;
};

/**
 Structure which holds some of the user data (name, account type, password) as strings. It also contains a pointer of type 'szuflada'(it points to the first element of 'szuflada' list), and two pointers of type 'osoba' to point previous and next node of type 'osoba'.
 */
struct osoba{
    struct osoba *prev;
    string name;
    string acc_type;
    string password;
    struct osoba *next;
    struct szuflada *info ;
};


/**
 Function creates and inserts a node of type "osoba" at the end of the "osoba list" in created list of lists.
 @param head a pointer of type "osoba" to the first node of the "osoba" list.
 @param new_data1 a string variable which contains information about 'name'.
 @param new_data2 a string variable which contains information about 'acc_type' (selected type of account).
 @param new_data3 a string variable which contains information about 'password', created previously by the user.
 */
void insert_name(struct osoba** head,string new_data1, string new_data2, string new_data3);

/**
 Function creates and inserts a node of type "szuflada" at the end of the "szuflada" list in created list of lists. This will contain the information about account number.
@param head a pointer of type "szuflada" to the first node of the "szuflada" list.
@param new_data an integer variable which contains information about account number.
*/
void insert_a_num(struct szuflada** head, int new_data);

/**
 Function creates and inserts a node of type "szuflada" at the end of the "szuflada" list in created list of lists. This node will contain the information about phone number.
 @param start a pointer of type "szuflada" to the first node of the "szuflada" list.
 @param new_data an integer variable which contains information about account number.
 */
void insert_a_phone(struct szuflada** start, int new_data);

/**
 Function creates and inserts a node of type "szuflada" at the end of the "szuflada" list in created list of lists. This node will contain the information about account balance.
 @param start a pointer of type "szuflada" to the first node of the "szuflada" list.
 @param new_data a float variable which contains information about account balance.
 */
void insert_acc_balance(struct szuflada** start, float new_data);

/**
 Function that reads data from the database text file 'Dane' and creates a list of lists based on it. Additionally, it counts the number of "osoba" nodes in the created list of lists.
 @param head a pointer of type "osoba" to the first node of the "osoba" list.
 @param counter integer pointer which value is changed inside the function. Its final value is the number of nodes in the "osoba" list.
 */
void fill_list(struct osoba** head, int * counter);

/**
Function that deletes the given list of list.
 @param head a pointer of type "osoba" to the first node of the "osoba" list.
  */
void delete_list(struct osoba** head);


/**
Function that swaps "osoba" nodes in the list of list.
@param head_ref a pointer of type "osoba" to the first node of the "osoba" list.
@param x an integer variable that holds the account number of the account. Based on this infomation the first node to be swapped is found in the list.
@param y an integer variable that holds the account number of the account. Based on this infomation the second node to be swapped is found in the list.
*/
void swapNode(struct osoba** head_ref, int x, int y);
#endif /* listy_funkcje_hpp */
