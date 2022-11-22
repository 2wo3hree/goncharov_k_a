#ifndef QUEUEP
#define QUEUEP
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>


class QueueP {

private:
	struct Node
	{
		int num;
		std::unique_ptr<Node> next;
		Node(int _num, std::unique_ptr<Node> _next);
	};
	int size;
	std::unique_ptr<Node> first;

public:
	QueueP();
	QueueP(const int _num);
	QueueP(const QueueP& que);
	QueueP(QueueP&& que);
	~QueueP();

	bool is_empty();
	void push(int _num);

	QueueP& operator = (const QueueP& que);
	QueueP& operator = (QueueP&& que);

	void print();

	int top();
	void pop();

	//Node operator[] (const int index);
};
QueueP init();

#endif;