#include <iostream>
#include <vector>
using namespace std;


template <typename K, typename V>
class Node
{
	K key;
	V value;
	Node* next;

	friend class List;

	Node(K k, V v, Node* next) : key(k), value(v), next(next) {}
};

template <typename K, typename V>
class List
{
	Node<K, V>* head;

public:
	List() : head(nullptr) {}

	List(K key, V value): head(new Node<K, V>(key, value, nullptr)) {}

	V get(K key)
	{
		Node<K, V>* tmp = this->head;

		while (tmp)
		{
			if (tmp->key == key)
			{
				return tmp->value;
			}
			tmp = tmp->next;
		}

		throw invalid_argument("Node with given key doesn't exist.");
	}

	void append(K key, V value)
	{
		Node<K, V>* new_element = new Node<K, V>(key, value, this->head);
		this->head = new_element;
	}

	void remove(K key)
	{
		Node<K, V>* current = this->head;
		Node<K, V>* prev = nullptr;

		while (current)
		{
			if (current->key == key)
			{
				if (prev)
				{
					prev->next = current->next;
					delete current;
				}

			}

			prev = current;
			current = current->next;
		}

		throw invalid_argument("Node with given key doesn't exist.");
	}

	~List()
	{
		Node<K, V>* prev;
		Node<K, V>* current = this->head;

		while (current)
		{
			prev = current;
			current = current->next;

			delete prev;
		}
	}
};

template <typename K, typename V>
class HashMap
{
	vector<List*> data;
	static const size_t default_size = 10000;
	static const size_t portion = 5000;
	size_t current_size, filled;

	size_t get_index(K key)
	{
		return hash(key) % current_size;
	}

	bool need_to_resize()
	{
		return filled / current_size > 0.7);
	}

	void resize()
	{
		this->data.resize(this->current_size + portion);
		this->current_size = this->current_size + portion;
	}

public:
	HashMap(): current_size(default_size)
	{
		data.resize(default_size);
		fill(data.begin(), data.end(), nullptr);
	}

	V get(K key)
	{
		size_t index = this->get_index(key);

		if (!this->data[index])
		{
			throw invalid_argument("Element with given key doesn't exist.")
		}
		else
		{
			return this->data[index]->get(key);
		}
	}

	void remove(K key)
	{
		size_t index = this->get_index(key);

		if (!this->data[index])
		{
			throw invalid_argument("Element with given key doesn't exist.")
		}
		else
		{
			this->data[index]->remove(key);
		}
	}

	void add(K key, V value)
	{
		size_t index = this->get_index(key);

		if (!this->data[index])
		{
			this->data[index] = new List<K, V>(key, value);
			filled++;

			if (this->need_to_resize())
			{
				this->resize();
			}
		}
		else
		{
			this->data[index]->append(key, value);
		}
	}

	~HashMap()
	{

	}
};