#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
	int count;
	int highset;
	int capacity;

	T* container;

public:
	Stack()
	{
		highset = -1;
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
		for (int i = 0; i < highset + 1; i++)
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
		else if (highset + 1 >= capacity)
		{
			resize(capacity * 2);
		}

		container[++highset] = data;
	}

	void pop()
	{
		if (empty())
		{
			cout << "stack is empty" << endl;
		}
		else
		{
			container[highset--] = NULL;
		}
	}

	const bool& empty()
	{
		return highset <= -1;
	}

	const int& size()
	{
		return highset + 1;
	}

	const T& top()
	{
		return container[highset];
	}

	~Stack()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

};

int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	cout << stack.size() << endl;

	while (stack.empty() == false)
	{
		cout << stack.top() << endl;

		stack.pop();
	}

	stack.pop();

	return 0;
}