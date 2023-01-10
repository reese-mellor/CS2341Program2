// Implement a class that provides a stack interface for your DSLists class.
#ifndef DSStack_H
#define DSStack_H
#include <vector>
using namespace std;
//Implement:
//push, pop, top, empty, size

template <typename Object>
class DSStack{ //wraps functionality to be specific to what the wrppaer needs
private:
    vector <Object> temp;
public:
    void push(Object obj){
        temp.insert(temp.begin(), obj);
    }
    Object pop(){
        Object tempValue = temp[0];
        temp.erase(temp.begin()); //erase it
        return tempValue;
    }

    Object top(){
        return temp[0];
    }
//    void display(){
//        for (int i = 0; i < temp.size(); i++){
//            cout << temp[i] << endl;
//        }
//    }
    void empty(){
        temp.clear();
    }
    int size(){
        return temp.size();
    }
    //element at

};

#endif