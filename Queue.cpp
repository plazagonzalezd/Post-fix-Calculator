
#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <cassert>


//The default Queue constructor.
Queue::Queue () {
    tail = NULL;
    queueSize = 0;
}


// The default Queue destructor.
Queue::~Queue () {
    QueueNode* temp;
    while(tail != NULL){
        temp = tail ->next;
        delete tail;
        tail = temp;
    }
    queueSize = 0;
}



// Enqueue inserts a new value into the queue.
void Queue::enqueue (string value) {
    QueueNode *temp = new QueueNode;
    temp->value = value;
    
    if (tail == NULL) {
        temp->next = temp;
    } else {
		temp->next = tail->next;
		tail->next = temp;
    }
    
    tail = temp;
    queueSize++;
}

//Dequeue returns to the user the value of head->value (if defined).
string Queue::dequeue () {
    string value;
    if (tail != NULL) {
		queueSize--;
        QueueNode *temp = tail->next;
        value = temp->value;
        
		if (temp == tail) {
	    	tail = NULL;
		} else {
	    	tail->next = temp->next;
		}
		delete temp;
    }
    
    return value;
}

//checks if queue is empty, return true if it is
bool Queue::isEmpty(){
    return (tail == NULL);
}


//First returns to the user the value of tail->next->value (if tail != NULL).

bool Queue::first (string &value) const {
    bool retValue = false;
    
    if (tail != NULL) {
		retValue = true;
		value = tail->next->value;
    }
    
    return (retValue);
}



//NumOfQueueEntries returns the number of values currently on the queue.
int Queue::numOfQueueEntries () const {
    return (queueSize);
}



//Print displays the contents of the queue.
void Queue::print () const {
    if(queueSize != 0){
        QueueNode* head = tail -> next;
        cout<< head -> value << " ";
        QueueNode* current = head -> next;
        while (current != head){
            cout << current -> value << " ";
            current = current -> next;
        }
    }
}