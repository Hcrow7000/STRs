#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	int size; // ������ ����
	int count; // ���� ����� ũ��
	int capacity; // �ִ� �뷮

	T * vertex; // ������ ����
	int** matrix; // ���� ���

public:
	Graph()
	{
		size = 0;
		capacity = 0;
		count = 0;
		
		vertex = nullptr;
		matrix = nullptr;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}

		vertex[size++] = data;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "matrix is empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index out of range" << endl;
		}
		else
		{
			if (matrix == nullptr)
			{
				count = size;

				matrix = new int* [size];

				for (int i = 0; i < size;i++)
				{
					matrix[i] = new int[size];

					for (int j = 0; j < size; j++)
					{
						matrix[i][j] = 0;
					}

				}

			}

		}

	}

	void resize(int newSize)
	{
		// 1. capacity�� ���ο� size���� ����
		capacity = newSize;

		// 2. ���ο� ������ ������ ����
		// ���Ӱ� ������� �޸� ������ ����Ŵ
		T* container = new T[capacity];

		// 3.���ο� �޸𸮰����� ���� �ʱ�ȭ
		for (int i = 0;i < capacity;i++)
		{
			container[i] = NULL;
		}

		// 4. ���� �迭�� �ִ� �� ����
		// ���ο� �迭�� �ִ´�
		for (int i = 0; i < size; i++)
		{
			container[i] = vertex[i];
		}

		// 5. ���� �迭�� �޸� ����
		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		// 6. ������ �迭�� ����Ű�� ������ ������ ����
		// ���ο� �迭�� ���� �ּҷ� ����Ŵ
		vertex = container;
	}

	~Graph()
	{
		if (matrix != nullptr)
		{
			for (int i = 0;i < count;i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
		}

		delete[] vertex;
	}

};

int main()
{
	Graph<char> graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');
	
	graph.edge(5, 6);
	
	return 0;
}