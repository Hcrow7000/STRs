#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{

		T data;
		Node* next;

	};

	int size;

	Node* head;


public:
	List()
	{
		size = 0;
		head = nullptr;

	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;

			head = newNode;
		}

		size++;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* currentNode = head;

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			currentNode->next = newNode;

		}

		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			head = deleteNode->next;

			delete deleteNode;

			size--;
		}

	}

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* previousNode = nullptr;
			Node* deleteNode = head;

			if (size == 1)
			{
				head = deleteNode->next;

				delete deleteNode;
			}
			else
			{
				while (deleteNode->next != nullptr)
				{
					previousNode = deleteNode;

					deleteNode = deleteNode->next;
				}

				previousNode->next = deleteNode->next;

				delete deleteNode;
			}

			size--;
		}
	}

	void remove(T data)
	{
		if (head == nullptr)
		{
			return;
		}
		else
		{
			Node* deleteNode = head;
			Node* previousNode = head;

			while (deleteNode != nullptr)
			{
				if (deleteNode->data == data)
				{
					if (deleteNode == head)
					{
						pop_front();

						deleteNode = head;
						previousNode = head;
					}
					else
					{
						previousNode->next = deleteNode->next;

						delete deleteNode;

						size--;

						deleteNode = head;

						previousNode = deleteNode;
					}
				}
				else
				{
					previousNode = deleteNode;

					deleteNode = deleteNode->next;
				}

			}

		}
	}

	bool empty()
	{
		return (head == nullptr);
	}

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}


};

