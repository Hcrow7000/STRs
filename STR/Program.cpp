#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{

		Node* next;
		T data;
	};

	int size;
	Node* head;

public:
	List()
	{
		size = 0;
		head = nullptr;
	}

	void push_back(T data)
	{
		if (head == nullptr)
		{
			
		}
		else
		{

		}
	}

};

int main()
{


	return 0;
}