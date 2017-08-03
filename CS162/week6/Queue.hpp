/*
 * Queue.hpp
 *
 *  Created on: Aug 2, 2017
 *      Author: bkooima
 */

#ifndef SRC_QUEUE_HPP_
#define SRC_QUEUE_HPP_

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
	int getFront();
	void removeFront();
	void displayQueue();
	bool isEmpty();
};

#endif /* SRC_QUEUE_HPP_ */
