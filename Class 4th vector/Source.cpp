#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int count;
	int capacity;

	T* container;

public:
	Vector()
	{
		count = 0;
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
		for (int i = 0; i < count; i++)
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

	void push_back(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (count >= capacity)
		{
			resize(capacity * 2);
		}

		container[count++] = data;
	}

	void pop_back()
	{
		if (count <= 0)
		{
			cout << "vector is empty " << endl;
		}
		else
		{
			container[--count] = NULL;

		}
	}

	const int& size()
	{
		return count;
	}

	const T& operator [](const int& index)
	{
		return container[index];
	}

	~Vector()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

};

int main()
{
	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);

	vector.pop_back();

	for (int i = 0;i < vector.size();i++)
	{
		cout << vector[i] << endl;
	}

	return 0;
}