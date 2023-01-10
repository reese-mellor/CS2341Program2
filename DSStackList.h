//
// Created by Reese Mellor on 10/16/22.
//

#ifndef ASSIGNMENT3_BRACKETS_DSSTACKLIST_H
#define ASSIGNMENT3_BRACKETS_DSSTACKLIST_H
#include "DSList.h"
template <typename Object>
class DSStackList{
private:
    DSList<Object> list;
public:
    void push(Object obj){
        list.push_front(obj);
    }
    Object pop(){
        return list.pop_front();
    }
    Object top(){
        return list.gethead();
    }
    void display(){
        list.display();
    }
    void empty(){
        list.clear();
    }
    int size(){
        return list.size();
    }

};

#endif //ASSIGNMENT3_BRACKETS_DSSTACKLIST_H
