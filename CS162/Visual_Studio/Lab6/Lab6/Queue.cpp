/*************************************************************************************
** Queue.cpp is the Queue class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Lab 6
** The Queue class represents a doubly-linked circular structure. It allows the user to
** add values to the back of the Queue, remove values from the front of the Queue, and
** display the first value in the Queue. Additionally, the user can print the entire
** contents of the Queue.
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Queue.hpp"

/*********************************************************************
** Function: Queue::Queue
** Description: Default constructor for Queue. Sets all protected
**				QueueNode members to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Queue members set to default (NULL).
*********************************************************************/
Queue::Queue() {
	front = NULL;
	back = NULL;
	temp = NULL;
}

/*********************************************************************
** Function:		Queue::~Queue()
** Description:		Queue Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The dynamic memory pointers are deleted
*********************************************************************/
Queue::~Queue() {
	// Verify front is not equal to back
	while (front != back && front != NULL) {
		// Set temporary QueueNode to front (head)
		QueueNode* n = front;
		// Set front to the next node
		front = front->next;
		// Delete the QueueNode (front)
		delete n;
	}
	// Delete the final node left
	delete front;
	// Set all nodes to NULL
	front = NULL;
	back = NULL;
	temp = NULL;
}

/*********************************************************************
** Function:		Queue::addBack(int)
** Description:		Add value to the back of the Queue
** Parameters:		val		The int to add to the Queue
** Pre-Conditions:	N/A
** Post-Conditions: The int is added to the back of the Queue and the
** 					pointers are updated
*********************************************************************/
void Queue::addBack(int val){
	// Create a temporary node
//	struct QueueNode *temp;
	temp = new(struct QueueNode);
	temp->data = val;
	temp->next = NULL;
	temp->previous = NULL;

	// Check to see if the Queue is empty
	if (isEmpty())
	{
		std::cout << "Value entered in empty list\n" << std::endl;
		// For the first entry, front is back is temp
		front = back = temp;
		// Set front next pointer to itself
		front->next = front;
		// Set front previous pointer to itself
		front->previous = front;
	}
	// If there is already a node in the Queue
	else
	{
		std::cout << "Value entered at back of List\n" << std::endl;
		// Set the back node next pointer to the temp node
		back->next = temp;
		// Set the temp node previous pointer to the back node
		temp->previous = back;
		// Set the temp node next pointer to the front node
		temp->next = front;
		// Set the front previous pointer to the temp node
		front->previous = temp;
		// Set the back node to the temp node
		back = temp;
	}
}

/*********************************************************************
** Function:		Queue::getFront()
** Description:		Return the first node(head) value
** Parameters:		N/A
** Pre-Conditions:	The Queue is not empty
** Post-Conditions: The front (head) node value is returned
*********************************************************************/
int Queue::getFront() {
	return front->data;
}

/*********************************************************************
** Function:		Queue::removeFront()
** Description:		Remove the first node(head) in the Queue
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The front (head) node is removed and the remaining
** 					pointers are updated
*********************************************************************/
void Queue::removeFront()
{
	// Check to determine if the queue is empty
	if (isEmpty())
	{
		std::cout << "The Queue is empty. Nothing to delete\n" << std::endl;
		return;
	}

	// Determine if there is only a single node in the Queue
	if (front->next == front){
		// Set the front (head) node to NULL
		delete front;
		front = NULL;
	}
	// Remove the front (head) node and shift pointers
	else{
		// Create a temporary node
		struct QueueNode *rF;
		// Set temp node to the front (head)
		rF = front;
		// Set the front node to the next temp node
		front = rF->next;
		// Set the previous pointer to the temp previous pointer
		front->previous = rF->previous;
		// Set the temp previous node next pointer to front (head)
		rF->previous->next = front;
		// Delete the temporary node
		delete rF;
		// Confirm the deletion
//		std::cout << "The element was deleted." << std::endl;
	}
}

/*********************************************************************
** Function:		Queue::displayQueue()
** Description:		Print the current Queue values
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The output is displayed on the command prompt
*********************************************************************/
void Queue::displayQueue()
{
	// Create a QueueNode structure
	struct QueueNode *dL;
	// Set node to front (head)
	dL = front;
	// Variable to track which node we are displaying
	int i = 0;
	// Verify the queue is not empty
	if (isEmpty())
	{
		std::cout << "The Queue is empty.\n" << std::endl;
		return;
	}
	// Display the Queue elements
	else
	{
		std::cout << "The Queue contains the following nodes (from front to back)\n";
		// Step through the nodes to display the data
		do
		{
			// Output the node # and the current ode data
			std::cout << "Node " << i + 1 << ":  " << dL->data << std::endl;
			// Increase the node index
			i++;
			// Step to the next node
			dL = dL->next;
		} while (dL != front); // Continue until we loop around to the front (head)
	}
}

/*********************************************************************
** Function:		Queue::isEmpty()
** Description:		Check to see if there are any nodes in the Queue
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: A boolean flag is returned based on the existence
** 					of a node
*********************************************************************/
bool Queue::isEmpty() {
	return (front == NULL);
}
