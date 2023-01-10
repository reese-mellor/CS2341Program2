//
// Created by Reese Mellor on 10/19/22.
//

#ifndef ASSIGNMENT3_BRACKETS_CHECKER_H
#define ASSIGNMENT3_BRACKETS_CHECKER_H
#include "DSStack.h"
#include "DSList.h"
#include "DSStackList.h"

class checker {
private:
    DSStackList<char> stack;
    DSStack<char> character;
public:
    checker() = default;
    int checkingVector(string);
    int checkingLinkList(string);
    int acceptable(int, char, int);
};


#endif //ASSIGNMENT3_BRACKETS_CHECKER_H
