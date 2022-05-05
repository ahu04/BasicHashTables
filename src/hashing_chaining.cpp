#include "hashing_chaining.h"
#include "LinkedList.h"
#include <stdexcept>
#include<vector>

using namespace std;

// Implement hashing with open addressing

HashtableChaining::HashtableChaining() {
    hashTable.resize(1000000);
    for (int i = 0; i < 1000000; i++) {
        LinkedList curr = LinkedList(0);
        hashTable[i] = curr;
    }
}

HashtableChaining::~HashtableChaining() {
//empty
}

void HashtableChaining::insert(int x) {
    int index = x % 1000000;
    hashTable[index].pushAtBack(x);
}


bool HashtableChaining::query(int x) {
    int index = x % 1000000;
    return hashTable[index].isInList(x);
}
