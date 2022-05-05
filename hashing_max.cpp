#include "hashing_max.h"

using namespace std;

// Implement hashing with open addressing

HashtableMax::HashtableMax() {
    hashTable = new int [3725000]();
}

HashtableMax::~HashtableMax() {
    delete [] hashTable;
}


void HashtableMax::insert(int x) {
    //if empty, wow I saved an instruction 
    //note: hash function for int k = k + i
    int index = x % 3725000;

    if (!hashTable[index]) {
        hashTable[index] = x;
    }
    else {
        int i = 1;
        while (hashTable[index]) {
            index = (x+ i*i + i + 1) % 3725000;
            i++;
        }
        hashTable[index]=x; //insert
    }
}

bool HashtableMax::query(int x) {
    int index = x % 3725000;
    //if where it should go is empty, aka 0
    if (!hashTable[index]) {
        return false;
    }
    //since hash function is hash(k) + quadratic probing, first check k
    else if (hashTable[index] == x) {
        return true;
    }
    //if not k, iterate
    else {
        //if current element is not x, and not 0, then keep looking
        int i = 1; 
        while(hashTable[index] != x && hashTable[index]) {
            index = (x+ i*i + i + 1) % 3725000;
            i++;
        }
        //two stop cases, if it is x or if it is 0.
        return (hashTable[index] == x);
    }

}