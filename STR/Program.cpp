#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;

		Node* left;
		Node* right;
	};

	Node* root;

public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		Node* currentNode = new Node;

		if (root = nulltpr)
		{
		
		}
		else
		{
			
		}
	}


};

int main()
{
	Set<int> set;
	
	set.insert(1);
	set.insert(2);
	set.insert(3);

	return 0;
}