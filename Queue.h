#ifndef _LLQUEUES_H
#define _LLQUEUES_H

#include <iostream>

using namespace std;


// Definition of a queue node.
struct QueueNode {
    string value;
    QueueNode *next;
};

class Queue {
    
public:
    /*--------------------------------------------------------------
     The default queue constructor provides the caller with an
     initially empty queue.
     --------------------------------------------------------------*/
    Queue ();
    
    /*--------------------------------------------------------------
     The default queue destructor: deallocates all dynamically
     allocated memory (i.e. QueueNodes).
     --------------------------------------------------------------*/
    ~Queue ();
    
    
    
    /*--------------------------------------------------------------
     The Enqueue method adds the provided value (value) to the queue.
     --------------------------------------------------------------*/
    void enqueue (string value);
    
    /*--------------------------------------------------------------
     The Dequeue methods removes the lest recently added element that has
     yet to be removed from the queue, and returns the value.
     --------------------------------------------------------------*/
    string dequeue ();
    
    /*--------------------------------------------------------------
     The First method does not alter the contents of the queue.  It
     returns to the caller the value
     that will be returned by the next Dequeue.
     --------------------------------------------------------------*/
    bool first (string &value) const;
    
   
    // NumOfQueueEntries is a constant member function that returns the number of values currently stored in the queue.
    int numOfQueueEntries () const;
	
    // Print displays the contents of the queue.
	void print () const;
    
    bool isEmpty();
    
private:
    // Object instance data
    QueueNode *tail;
    int queueSize;
};

#endif