/*************************************************************************************
** Queue.hpp is the Queue class function specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Lab 6
** The Queue class represents a doubly-linked circular structure. It allows the user to
** add values to the back of the Queue, remove values from the front of the Queue, and
** display the first value in the Queue. Additionally, the user can print the entire
** contents of the Queue.
***************************************************************************************/

#ifndef SRC_QUEUE_HPP_
#define SRC_QUEUE_HPP_

// QueueNode structure definition
struct QueueNode
{
	int data;
	struct QueueNode *next;
	struct QueueNode *previous;

};

class Queue
{
private:
	// Create the QueueNode structures
	QueueNode *front;
	QueueNode *back;
	QueueNode *temp;
public:
	// Default constructor
	Queue();
	// Destructor
	~Queue();
	// Add value to the back of the Queue
	void addBack(int val);
	// Return the first node(head) value
	int getFront();
	// Remove the first node(head) in the Queue
	void removeFront();
	// Print the current Queue values
	void displayQueue();
	// Check to see if there are any nodes in the Queue
	bool isEmpty();
};

#endif /* SRC_QUEUE_HPP_ */
