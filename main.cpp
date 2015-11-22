//
//  main.cpp
//  Post-fix Calculator
//
//  Created by Alexis Plaza González on 10/4/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#include <iostream>
#include "Convertor.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main()
{
    
    Convertor n;
    string expression;
    start:
    cout << "Please enter an arithmetic expression (no spaces), and press enter." << endl << "Or type q to quit.";
    cin >> expression;
    if(expression !=  "q"){
    Queue output = n.convert(expression); // converts expression from infix to postfix and prints the postfix
    cout << endl;
    n.calculate(output); // calculates the expression and prints it
    cout << endl << endl;
    goto start;
    }
    return 0;
}