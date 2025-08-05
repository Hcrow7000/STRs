#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;

		Node* left = nullptr;
		Node* right = nullptr;

		Node(T data)
		{
			this->data = data;
		}
	};

	Node* root;

public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		Node* newNode = new Node(data);

		if (root == nullptr)
		{
			root = newNode;
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				if (currentNode->data == data)
				{
					delete newNode;

					return;
				}
				else if (currentNode->data > data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = newNode;
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
					
				}
				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = newNode;
						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
			}

		}
	}

	void release(Node* root)
	{
		if (root != nullptr)
		{
			release(root->left);

			release(root->right);

			delete root;
		}
	}

	void erase(T data)
	{
		Node* currentNode = root;

		// 1. 자식 노드가 하나도 없을 때
		while(currentNode != nullptr && currentNode->data != data)
		{
			if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		// 2. 자식 노드가 하나만 있을 때

		// 3. 자식 노드가 두개 있을 때
	}

	~Set()
	{
		release(root);
	}

};

int main()
{
	Set<int> set;
	
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(4);
	set.insert(5);

	return 0;
}