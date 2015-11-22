

#include "Convertor.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>

using namespace std;
#include<sstream>
#include <string>


Convertor::Convertor(){
    
}

Queue Convertor::convert(string &str){
string current;
for(int i = 0; i<str.length(); ++i){ // loops over each character of the input expression
    current = str.substr(i,1);
    if(isOperator(current) || isdigit(*current.c_str())){ //is the expression valid?
        if( current == "(") { // if current is a ( push it into the stack
        operators.push(current);
            continue;
        }
        if(!isOperator(current)) { // if current is a operand, enqueue it.
            if(i < str.length()-1 && !isOperator(str.substr(i+1,1))){ //if the number has more that one digit
            int j = 1; //represents the length of the number.
            int temp = i; //the place of the first digit of the number.
            while(i < str.length() && !isOperator(str.substr(i+1,1))){//allow multiple digits
                ++i;
                ++j;
                current = str.substr(temp,j);
            }
            }
                output.enqueue(current);
                continue;
        } else {
            if(operators.isEmpty() || operators.top() == "("){ //if there's nothing in the stack or the top is a (, push operator
                operators.push(current);
                continue;
            }
            if(current == ")"){ //if current is ) enqueue the top of the stack until ( is found
                while(operators.top()!= "("){
                 output.enqueue(operators.pop());
                }
                operators.pop();
                continue;
            }
            if(!isLower(current)){ //if current is of higher precedence than top, push current in the stack
                operators.push(current);
                continue;
            } else { //if current is of lower or equal precedence than top, enqueue top until top is of lower precedence.
                while(!operators.isEmpty() && isLower(current)){
                output.enqueue(operators.pop());
                }
                operators.push(current);
                continue;
            }
        }
    } else cout<< "the expression is invalid"; // if current is neither a operator nor an operand
 }
    if(!operators.isEmpty()){ //if there's anything left in the stack after the input has been analyzed, enqueue what's left.
        while(!operators.isEmpty()) {
            output.enqueue(operators.pop());
        }
    }
    output.print();
    return output;
    
}

bool Convertor::isOperator(string current){ //checks if current is an operator
    if( current == "+" || current == "-" || current == "*" || current == "/" || current == "%" || current == ")" || current == "(") return true;
    return false;
}

bool Convertor::isLower(string current){ //checks if current is of equal or lower presedence than top.
    string top = operators.top();
    if(top == "*" || top == "/" || top == "%") return true;
    else if(current == "*" || current == "/" || current == "%") return false;
    return true;
}

void Convertor::calculate(Queue &output){ //calculates the postfix expression, which is stored in a queue and passed as a parameter.
    Stack stack;
    int result = 0;
    string current;
    while(!output.isEmpty()){ //while there's elements in the queue
        current = output.dequeue(); // analyse one by one the elements in the queue
        if(!isOperator(current)){ // if current is a number push into the stack
            stack.push(current);
            continue;
        } else { // pop the the stack twice, and perform operations with the poped elements depending on the current operator.
            int temp2 = stoi(stack.pop());
            int temp1 = stoi(stack.pop());
            if(current == "+") result = temp1 + temp2;
            if(current == "-") result = temp1 - temp2;
            if(current == "/") result = temp1 / temp2;
            if(current == "*") result = temp1 * temp2;
            if(current == "%") result = temp1 % temp2;
            }
            stack.push(to_string(result)); // push result on the stack.
        }
    cout << stack.top();
}


