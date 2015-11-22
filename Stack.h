#ifndef __Post_fix_Calculator__Stack__
#define __Post_fix_Calculator__Stack__

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

struct StackNode {
    string value;
    StackNode *next;
};

class Stack {
public:
    Stack(); //default constructor
    ~Stack(); // default destructor
    void push (string value); //inserts an element into the stack.
    string pop(); //returns the top element of the stack and reduces count.
    string top(); // returns the top eleent of the stack
    void print();// prints all the elemets of the stack
    bool isEmpty();//returns true if the stack is empty

private:
    StackNode *head;
    int count;
    
};

#endif