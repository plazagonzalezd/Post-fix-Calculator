#include <iostream>
#include <cstdlib>
#include <cassert>
#include"Stack.h"

using namespace std;



Stack::Stack () {
    count = 0;
    head = NULL;
}

Stack::~Stack(){
    StackNode *temp;
    while (head != NULL){
        temp = head;
        head = head -> next;
        delete head;
    }
    count = 0;
}
    //inserts new element in stack
    void Stack::push(string value)
    {
        StackNode *temp = new StackNode;
        temp-> value = value;
        temp-> next = head;
        head = temp;
        count++;
    }

    //returns value stored at the head of the stack or "" if there the stack is empty, and deletes the head node, and repleaces it.
    string Stack::pop()
    {
        if(!isEmpty()){
        string value = head-> value;
        StackNode *temp = head;
        head = head -> next;
        delete temp;
        count--;
        return value;
        }
        return "";
    }
    //returns value stored in head node
    string Stack::top(){
        if(!isEmpty()){
        string value = head-> value;
        return value;
        }
        return "";
    }

    //check if it's empty
    bool Stack::isEmpty(){
        return (head == NULL);
    }
//print all the elements in the stack
void Stack::print(){
    StackNode *current = head;
    while(current != NULL){
        cout<< current ->value;
        cout<< endl;
        current = current -> next;
    }
}











