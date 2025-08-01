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

	T* vertex; // 정점의 집합
	Node** list; // 인접 리스트
	
	int size; // 정점의 개수
	int count; // 인접 리스크 크기
	int capacity; // 최대용량

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
		// 1. capacity에 새로운 size값을 저장
		capacity = newSize;

		// 2. 새로운 포인터 변수를 생성
		// 새롭게 만들어진 메모리 공간을 가리킴
		T* container = new T[capacity];

		// 3.새로운 메모리공간의 값을 초기화
		for (int i = 0;i < capacity;i++)
		{
			container[i] = NULL;
		}

		// 4. 기존 배열에 있는 값 복사
		// 새로운 배열에 넣는다
		for (int i = 0; i < size; i++)
		{
			container[i] = vertex[i];
		}

		// 5. 기존 배열의 메모리 해제
		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		// 6. 기존에 배열을 가리키던 포인터 변수의 값을
		// 새로운 배열의 시작 주소로 가리킴
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