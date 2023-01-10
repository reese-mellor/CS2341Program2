//
// Created by Reese Mellor on 10/19/22.
//
#include <iostream>
#include "checker.h"
#include "DSStackList.h"
#include <fstream>

//need function that uses vector stuff
int checker::checkingVector(string name){
    ifstream file(name);
    if (!file.is_open()) {
        cout << "Error. Files could not be opened." << endl;
        return -1;
    }
    string buffer;
    int newLine = 0;
    while(getline(file, buffer)){
        for (int i = 0; i < buffer.size(); i++){
            if(buffer[i] == '[') {
                //push onto stack
                character.push(buffer[i]);
            }
            if(buffer[i] == ']') {
                //check stack top and pop off
                if (character.top() == '['){
                    character.pop();
                }
                else {
                    return acceptable(1, ']', newLine); // error message
                }
            }
            if(buffer[i] == '{') {
                character.push(buffer[i]);
            }
            if(buffer[i] == '}') {
                if (character.top() == '{'){
                    character.pop();
                }
                else {
                    return acceptable(1, '}', newLine); // error message
                }
            }
            if(buffer[i] == '(') {
                character.push(buffer[i]);
            }
            if(buffer[i] == ')') {
                if (character.top() == '('){
                    character.pop();
                }
                else {
                    return acceptable(1, ')', newLine); // error message
                }
            }
        }
        newLine++;
    }//closes while
    file.close();
    if (character.size() == 0){
        return acceptable(0, '\0', newLine);
    }
    else {
        return acceptable(1, 'e', 0);
    }
} //closes function

int checker::checkingLinkList(string name) {
    ifstream file(name);
    if (!file.is_open()) {
        cout << "Error. Files could not be opened." << endl;
        return -1;
    }
    string buffer;
    int newLine = 0;
    while(getline(file, buffer)){
        for (int i = 0; i < buffer.size(); i++){
            if(buffer[i] == '[') {
                //push onto stack
                stack.push(buffer[i]);
            }
            if(buffer[i] == ']') {
                //check stack top and pop off
                if (stack.top() == '['){
                    stack.pop();
                }
                else {
                    return acceptable(1, '[', newLine); // error message
                }
            }
            if(buffer[i] == '{') {
                stack.push(buffer[i]);
            }
            if(buffer[i] == '}') {
                if (stack.top() == '{'){
                    stack.pop();
                }
                else {
                    return acceptable(1, '}', newLine); // error message
                }
            }
            if(buffer[i] == '(') {
                stack.push(buffer[i]);
            }
            if(buffer[i] == ')') {
                if (stack.top() == '('){
                    stack.pop();
                }
                else {
                    return acceptable(1, ')', newLine); // error message
                }
            } //closes if
        } //closes for
        newLine++;
    } //closes while
    file.close();
    if (stack.size() == 0){
        return acceptable(0, '\0', newLine);
    }
    else {
        return acceptable(1, 'e', newLine);
    }
} //closes function

int checker::acceptable(int declarer, char missingChar, int line){
    if (declarer == 1){
        cout << "<input_file>: Bracket mismatch detected" << endl;
        cout << "You are missing: " << missingChar;
        cout << " on line " << line << endl;
        return 1;
    }
    else {
        cout << "<input_file>: OK" << endl;
        return 0;
    }
}