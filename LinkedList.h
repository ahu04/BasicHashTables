/* 
 * LinkedList.h
 * 
 * The most disgusting, lazy, unoptimized implementation of linked list (only supports ints)
 * you've ever seen. Sorry. 
 * 
 * Alex Hu
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
    public:
        // constructors
        LinkedList();
        LinkedList(int c); //very specific constructor because that's the way I implemented mine
        // destructor
        ~LinkedList();

        void pushAtBack(int c);
        bool isInList(int c);
        
    private:
        struct Node {
            int data;
            Node *prev;
            Node *next;
        };
        Node *front;

};

#endif