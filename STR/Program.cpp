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
		// 1. capacity에 새로운 size값을 저장
		capacity = newSize;

		// 2. 새로운 포인터 변수를 생성
		// 새롭게 만들어진 메모리 공간을 가리킴
		T* temporary = new T[capacity];

		// 3.새로운 메모리공간의 값을 초기화
		for (int i = 0;i < capacity;i++)
		{
			temporary[i] = NULL;
		}

		// 4. 기존 배열에 있는 값 복사
		// 새로운 배열에 넣는다
		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		// 5. 기존 배열의 메모리 해제
		if (container != nullptr)
		{
			delete[] container;
		}

		// 6. 기존에 배열을 가리키던 포인터 변수의 값을
		// 새로운 배열의 시작 주소로 가리킴
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