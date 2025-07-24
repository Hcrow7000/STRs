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

		for (int i=0; i<SIZE ; i++)	
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{

	}

};

int main()
{

	return 0;
}