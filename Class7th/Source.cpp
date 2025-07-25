#include <iostream>

using namespace std;

#define SIZE 4

template<typename T>
class Queue
{
private:
	int rear;
	int front;

	T container[SIZE];

public:
	Queue()
	{
		rear = SIZE - 1;
		front = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (front == (rear + 1) % SIZE)
		{
			cout << "Circle queue overflow" << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;

			container[rear] = data;
		}
	}

	void pop()
	{
		if (empty())
		{
			cout << "linear queue is empty" << endl;
		}
		else
		{
			front = (front + 1) % SIZE;

			container[front] = NULL;
		}
	}

	const bool& empty()
	{
		return front == rear;
	}

	const T& peek()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return container[(front + 1) % SIZE];
		}
	}

};

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);

	while (queue.empty() == false)
	{
		cout << queue.peek() << endl;

		queue.pop();
	}

	queue.push(50);
	queue.push(60);
	queue.push(70);

	return 0;
}