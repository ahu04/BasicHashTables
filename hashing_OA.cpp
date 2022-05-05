#include "hashing_OA.h"

#include <stdexcept>

using namespace std;

// Implement hashing with open addressing

HashtableOA::HashtableOA() {
    hashTable = new int [1000000]();
}

HashtableOA::~HashtableOA() {
    delete [] hashTable;
}

void HashtableOA::insert(int x) {
    //if empty, wow I saved an instruction 
    //note: hash function for int k = k + i
    int index = x % 1000000;
    if (!hashTable[index]) {
        hashTable[index] = x;
        return;
    }
    else {
        //keep looking using hash function h(k, i) = k + i
        //while there is something in the hash table, keep incrementing index
        while (hashTable[index]) {
            if (index < 999999) {
                index++;
            }
            else index=0;
        }
        hashTable[index]=x; //insert
    }
}

bool HashtableOA::query(int x) {
    int index = x % 1000000;
    //if where it should go is empty, aka 0
    if (!hashTable[index]) {
        return false;
    }
    //since hash function is k+i, first check k
    else if (hashTable[index] == x) {
        return true;
    }
    //if not k, iterate
    else {
        //if current element is not x, and not 0, then keep looking
        while(hashTable[index] != x && hashTable[index]) {
            if (index < 999999) {
                index++;
            }
            else index=0;
        }
        //two stop cases, if it is x or if it is 0.
        return (hashTable[index] == x);
    }

}