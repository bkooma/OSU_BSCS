/*
 * codetonics.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: bkooima
 */

#include <stdio.h>
#include <iostream>
#include <conio.h>

int data;

struct QueueNode
{
	int data;
	struct QueueNode *next;
	struct QueueNode *previous;

};

class Queue
{
private:
	QueueNode *front;
	QueueNode *back;
	QueueNode *temp;
public:
	Queue();
	~Queue();
	void addBack(int val);
	void displayQueue();
	void removeFront();
	int getFront();
	bool isEmpty();
};

int main()
{
	int choice;
	int val;
	int returnVal;
	Queue QL;
	while (1)
	{
		std::cout<<"\n-------------------------------"<<std::endl;
		std::cout<<"Operations on Doubly Circular linked list"<<std::endl;
		std::cout<<"\n-------------------------------"<<std::endl;
		std::cout<<"1.Enter a value to be added to the queue"<<std::endl;
		std::cout<<"2.Display first node (front) value"<<std::endl;
		std::cout<<"3.Remove first node (front) value"<<std::endl;
		std::cout<<"4.Display the queue contents"<<std::endl;
		std::cout<<"5.Exit"<<std::endl;
		std::cout<<"Enter your choice : ";
		std::cin>>choice;
		switch(choice)
		{
		case 1:
			std::cout << "Please enter an int to add to List.\n";
			std::cin>>val;
			QL.addBack(val);
			break;
		case 2:
			if (QL.isEmpty()) {
				std::cout << "The list is empty so no first node value exists\n" << std::endl;
			}
			else {
				returnVal = QL.getFront();
				std::cout << "The first node (front) value is: " << returnVal << std::endl;
			}
			break;
		case 3:
			QL.removeFront();
			break;
		case 4:
			QL.displayQueue();
			break;
		case 5:
			exit(1);
		default:
			std::cout <<"Wrong Choice"<<std::endl;
		}
	}
	QL.~Queue();
	return 0;
}

Queue::Queue() {
	front = NULL;
	back = NULL;
	temp = NULL;
}

Queue::~Queue() {
	delete front;
	delete back;
	delete temp;
}

bool Queue::isEmpty() {
	return (front == NULL);
}
void Queue::addBack(int val){
	struct QueueNode *temp;
	temp = new(struct QueueNode);
	temp->data = val;
	temp->next = NULL;
	temp->previous = NULL;

	if (isEmpty())
	{
		std::cout << "Value entered in empty list\n" << std::endl;
		front = back = temp;
		front->next = front;
		front->previous = front;
	}
	else
	{
		std::cout << "Value entered at back of List\n" << std::endl;
		back->next = temp;
		temp->previous = back;
		temp->next = front;
		front->previous = temp;
		back = temp;
	}
}

void Queue::displayQueue()
{
	struct QueueNode *dL;
	dL = front;
	int i = 0;
	if (isEmpty())
	{
		std::cout << "The list is empty.\n" << std::endl;
		return;
	}
	else
	{
		std::cout << "The List contains the following elements (from front to back)\n";

		do
		{
			std::cout << "Element " << i + 1 << ":  " << dL->data << std::endl;
			i++;
			dL = dL->next;
		} while (dL != front);
	}
}

void Queue::removeFront()
{
	if (isEmpty())
	{
		std::cout << "The list is empty. Nothing to delete\n" << std::endl;
		return;
	}

	if (front->next == front){
		front = NULL;
	}
	else{
		struct QueueNode *rF;
		rF = front;
		front = rF->next;
		front->previous = rF->previous;
		rF->previous->next = front;
		delete rF;
		std::cout << "The element was deleted." << std::endl;
	}
}

int Queue::getFront() {
	return front->data;
}
