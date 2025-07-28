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
		// 1. 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = hash_function(key);

		// 2. 새로운 노드를 생성
		Node* newNode = new Node;

		newNode->key = key;

		newNode->value = value;

		newNode->next = nullptr;

		// 노드가 1개라도 존재하지 않으면
		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]의 head 포인터가 newNode를 가리키게함
			bucket[hashIndex].head = newNode;
			
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		// bucket[hashIndex]의 count를 증가시킴.
		bucket[hashIndex].count++;
	}

	void erase(KEY key)
	{
		// 1. 해시 함수를 통해서 값을 받는 임시변수
		int hashIndex = hash_function(key);

		// 2. Node를 탐색할 수 있는 포인터 변수 선언
		Node* currentNode = bucket[hashIndex].head;

		// 3. 이전 Node를 저장할 수 있는 포인터 변수
		Node* previousNode = nullptr;

		// 4. currentNode가 nullptr과 같다면 함수 종료

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