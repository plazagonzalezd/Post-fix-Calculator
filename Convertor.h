//
//  Convertor.h
//  Post-fix Calculator
//
//  Created by Alexis Plaza González on 10/4/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

//The converto class is used to convert an infix expression into postfix and evaluate it

class Convertor{
public:
    Stack operators;
    Queue output;
    Convertor();
    
    /*
     Convert uses a queue and a Stack to convert an iput expression into an postfix expression. 
     It starts by reading every element in the input. If the element is a number, it's enqueued.
     If the element is a operator, then the presedence is checked. If the current element has a 
     presedence higher than that of the element on top of the stack, the element is pushed. If the
     presedence is lower or equal, elements are poped and enqued until an element of lower presedence on the top
     of the stack is found.
     */
    Queue convert(string &str);
    
    /*isOperator checks if the current element is a operator*/
    bool isOperator(string current);
    
    /* isLower checks if the current element has a lower or equal presedence than that on the top of the stack*/
    bool isLower(string current);
    
    /*calculates an postfix expression. It takes a queue as a parameter and uses a stack to store the on going calculation.*/
    void calculate(Queue &output);
    
};


