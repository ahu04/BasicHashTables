#pragma once

#include"LinkedList.h"
#include<vector>

class HashtableChaining {
    public:
        HashtableChaining();
        ~HashtableChaining();
        void insert(int x);
        bool query(int x);
    private:
        std::vector<LinkedList> hashTable;
};