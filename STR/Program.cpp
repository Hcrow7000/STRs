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

	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentNode = nullptr;

		while (currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		// 1. 자식 노드가 하나도 없을 때
		if (currentNode == nullptr)
		{
			cout << "the data does not exist" << endl;
		}
		else if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode)
				{
					parentNode->left = nullptr;
				}
				else
				{
					parentNode->right = nullptr;
				}
			}
			else
			{
				root = nullptr;
			}
		}
		// 2. 자식 노드가 하나만 있을 때
		else if (currentNode->left == nullptr || currentNode->right == nullptr)
		{
			if (currentNode == root)
			{
				if (currentNode->left != nullptr)
				{
					root = currentNode->left;
				}
				else
				{
					root = currentNode->right;
				}
			}
			else
			{
				Node* childNode = nullptr;

				if (currentNode->left != nullptr)
				{
					childNode = currentNode->left;
				}
				else
				{
					childNode = currentNode->right;
				}

				if (parentNode->left == currentNode)
				{
					parentNode->left = childNode;
				}
				else
				{
					parentNode->right = childNode;
				}

			}
		}
		// 3. 자식 노드가 두개 있을 때
		

		delete currentNode;
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

	~Set()
	{
		release(root);
	}

};

int main()
{
	Set<int> set;
	
	set.insert(10);
	set.insert(5);
	set.insert(17);
	set.insert(3);
	set.insert(21);

	set.erase(10);

	return 0;
}