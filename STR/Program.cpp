#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue
{
private:
	int index;
	int capacity;

	T* container;

public:
	PriorityQueue()
	{
		index = 0;
		capacity = 0;

		container = nullptr;
	}

	void resize(int newSize)
	{
		// 1. capacity�� ���ο� size���� ����
		capacity = newSize;

		// 2. ���ο� ������ ������ ����
		// ���Ӱ� ������� �޸� ������ ����Ŵ
		T* temporary = new T[capacity];

		// 3.���ο� �޸𸮰����� ���� �ʱ�ȭ
		for (int i = 0;i < capacity;i++)
		{
			temporary[i] = NULL;
		}

		// 4. ���� �迭�� �ִ� �� ����
		// ���ο� �迭�� �ִ´�
		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		// 5. ���� �迭�� �޸� ����
		if (container != nullptr)
		{
			delete[] container;
		}

		// 6. ������ �迭�� ����Ű�� ������ ������ ����
		// ���ο� �迭�� ���� �ּҷ� ����Ŵ
		container = temporary;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (index >= capacity)
		{
			resize(capacity * 2);
		}
		
		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				std::swap(container[parent], container[child]);

			}
			
			child = parent;
			parent = (child - 1) / 2;
		}

	}

	const bool& empty()
	{
		return index <= 0;
	}

	const int& size()
	{
		return index;
	}
	
	const T& top()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return container[0];
		}
	}

	~PriorityQueue()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

};

int main()
{
	PriorityQueue<int> priorityQueue;

	priorityQueue.push(5);
	priorityQueue.push(1);
	priorityQueue.push(11);
	priorityQueue.push(6);

	cout << priorityQueue.top() << endl;

	return 0;
}