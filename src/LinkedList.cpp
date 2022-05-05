/* 
 * LinkedList.cpp
 * 
 * The most disgusting, lazy, unoptimized implementation of linked list (only supports ints)
 * you've ever seen. Sorry. 
 * 
 * Alex Hu
 */

#include "LinkedList.h"

// for the print function
#include <iostream>

using namespace std;

/* Purpose: initializes an LinkedList, set to 0*/
LinkedList::LinkedList()
{
    front = nullptr;
}

/*    Purpose: initializes a LinkedList containing one character
 * Parameters: the character that should be stored in the new list
 */
LinkedList::LinkedList(int c)
{
    Node *temp = new Node;
    temp->data = c;
    temp->prev = nullptr;
    temp->next = nullptr;
    front = temp;
}


/* Purpose: destructor -- frees all memory associated with the list */
LinkedList::~LinkedList()
{
    Node *temp;
    Node *head;
    head = front;
    while (head != nullptr) {
        head = head->next;
    }
    
    while (head != nullptr)
    {
       temp = head;
       free(temp);
       head = head->prev;
    }
}

/* pushAtBack
 *    Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtBack(int c)
{
    //traverse our nodes until we reach the end. 
    Node *temp = front;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    Node *added = new Node;
    added->data = c;
    added->prev = temp;
    added->next = nullptr;
    temp->next = added;
}

bool LinkedList::isInList(int c) {
    Node *temp = front;
    while (temp->data != c && temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->data == c) {
        return true;
    }
    return false;
}



