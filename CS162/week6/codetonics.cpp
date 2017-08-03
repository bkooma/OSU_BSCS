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

}*start = nullptr, *end=nullptr;

class Queue
{
public:
	Queue(){}
	void addBack(int val);
	void displayList();
	void removeFront();
//	int getFront();
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
		std::cout<<"1.Insert at Last"<<std::endl;
		std::cout<<"2.Delete at Position"<<std::endl;
		std::cout<<"3.Search Element"<<std::endl;
		std::cout<<"4.Display List"<<std::endl;
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
			QL.removeFront();
			break;
		case 3:
//			returnVal = QL.getFront();
			break;
		case 4:
			QL.displayList();
			break;
		case 5:
			exit(1);
		default:
			std::cout <<"Wrong Choice"<<std::endl;
		}
	}
	return 0;
}

void Queue::addBack(int val){
	struct QueueNode *temp;
	temp = new(struct QueueNode);
	temp->data = val;
	temp->next = nullptr;
	temp->previous = nullptr;

	if (start == end && start == nullptr)
	{
		std::cout << "Value entered in empty list" << std::endl;
		start = end = temp;
		start->next = end->next = nullptr;
		start->previous = end->previous = nullptr;
	}
	else
	{
		end->next = temp;
		temp->previous = end;
		end = temp;
		start->previous = end;
		end->next = start;
	}
}

void Queue::displayList()
{
	struct QueueNode *dL;
	dL = start;
	if (start == nullptr)
	{
		std::cout << "The list is empty.\n" << std::endl;
		return;
	}
	else
	{
		if (start == end)
		{
			std::cout << "The list contains the following elements:\n";
			std::cout << dL->data << std::endl;
		}
		else
		{
			std::cout << dL->data<< std::endl;
			do
			{
				dL = dL->next;
				std::cout << dL->data<< std::endl;
			} while (dL != end);
		}
	}
}

void Queue::removeFront()
{
	if (start == nullptr)
	{
		std::cout << "The list is empty. Nothing to delete\n" << std::endl;
		return;
	}

	if (start == end){
		delete start;
		start = nullptr;
		delete end;
		end = nullptr;
	}
	else{
		struct QueueNode *rF;
		rF = start;
		start = rF->next;
		start->previous = rF->previous;
		rF->previous->next = start;
		delete rF;
		std::cout << "The element was deleted." << std::endl;
	}
}
