#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};

	T* vertex; // ������ ����
	Node** list; // ���� ����Ʈ
	
	int size; // ������ ����
	int count; // ���� ����ũ ũ��
	int capacity; // �ִ�뷮

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		list = nullptr;
		vertex = nullptr;
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
			cout << "adjacency list is empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index out of range" << endl;
		}
		else
		{
			if (list == nullptr)
			{
				list = new Node * [size];

				for (int i = 0;i < size;i++)
				{
					list[i] = nullptr;
				}

				count = size;

			}

			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);
		}
	}

	
	~Graph()
	{
		for (int i = 0;i < size;i++)
		{
			Node* deleteNode = list[i];
			Node* nextNode = list[i];

			if (deleteNode == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}
		}

		delete[] list;

		delete[] vertex;
	}

};

int main()
{
	Graph<char> graph;
	
	graph.push('A');
	graph.push('B');
	graph.push('C');
	graph.push('D');

	graph.edge(0, 1);

	graph.push('F');

	graph.edge(1, 2);

	return 0;
}