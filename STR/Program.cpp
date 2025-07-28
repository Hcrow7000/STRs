#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		Node* head;
		int count;
	};

	int size;
	Bucket* bucket;

public:
	HashTable()
	{
		size = 8;

		bucket = new Bucket[size];
	}

	unsigned int hash_function(KEY key)
	{
		int hash = (unsigned int)key % size;

		return hash;
	}

	void Insert(KEY key, VALUE value)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = hash_function(key);

		// 2. ���ο� ��带 ����
		Node* newNode = new Node;

		newNode->key = key;

		newNode->value = value;

		newNode->next = nullptr;

		// ��尡 1���� �������� ������
		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]�� head �����Ͱ� newNode�� ����Ű����
			bucket[hashIndex].head = newNode;
			
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		// bucket[hashIndex]�� count�� ������Ŵ.
		bucket[hashIndex].count++;
	}

	void erase(KEY key)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽú���
		int hashIndex = hash_function(key);

		// 2. Node�� Ž���� �� �ִ� ������ ���� ����
		Node* currentNode = bucket[hashIndex].head;

		// 3. ���� Node�� ������ �� �ִ� ������ ����
		Node* previousNode = nullptr;

		// 4. currentNode�� nullptr�� ���ٸ� �Լ� ����

		if (currentNode == nullptr)
		{
			cout << "not key found" << endl;

			return;
		}

	}	


	const int& bucket_count()
	{
		return size;
	}

};

int main()
{
	HashTable<const char*, int> hashtable;

	hashtable.Insert("Abyssal Mask", 3000);
	hashtable.Insert("bkaksks", 3000);
	hashtable.Insert("Abydpp kd", 3000);

	return 0;
}