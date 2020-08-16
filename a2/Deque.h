#pragma once
#include <stdexcept>

template <class T>
class Node
{
public:
	T data;
	Node *pre;
	Node *next;
	Node(T val) : data(val), pre(nullptr), next(nullptr){};
};

template <class T>
class Deque
{
public:
	// default constructor
	// post: creates an empty Deque
	Deque();

	// copy constructor
	// param: constant Deque reference parameter
	// post: creates a deep copy of its constant Deque reference parameter
	Deque(const Deque &d);

	// destructor
	// post: deallocates dynamic memory allocated by the Deque
	~Deque();

	// overloaded assignment operator
	// param: constant Deque reference parameter
	// post: (deep) copies its constant Deque reference parameter into the calling object
	// and returns a reference to the calling object
	Deque &operator=(const Deque &d);

	// param: template parameter
	// post: inserts its template parameter at the front of the Deque
	void insertFront(T value);

	// param: template parameter
	// post: inserts its template parameter at the back of the Deque
	void insertBack(T value);

	// post: removes and returns the value at the front of the Deque,
	// if the Deque is empty throws a runtime_error
	T removeFront();

	// post:  removes and returns the value at the back of the Deque,
	// if theDeque is empty throws a runtime_error
	T removeBack();

	// post:  returns the value at the front of the Deque without removing it,
	// if the Deque is empty throws a runtime_error
	T peekFront();

	// post: returns the value at the back of the Deque without removing it,
	// if the Deque is empty throws a runtime_error
	T peekBack();

	// post: returns true if the Deque is empty, false otherwise
	bool empty();

	// post: returns the number of items stored in the Deque, as an int
	int size();

private:
	Node<T> *front;
	Node<T> *back;
	int DequeSize;

	// copy helper function
	// param: constant Deque reference parameter
	// post: creates a deep copy of its constant Deque reference parameter
	void copyDeque(const Deque &d);

	// delete helper function
	// post: deallocates dynamic memory allocated by the Deque
	void deleteDeque();
};

// Deque method implementations

// default constructor
// post: creates an empty Deque
template <class T>
Deque<T>::Deque()
{
	front = nullptr;
	back = nullptr;
	DequeSize = 0;
}

// copy constructor
// param: constant Deque reference parameter
// post: creates a deep copy of its constant Deque reference parameter
template <class T>
Deque<T>::Deque(const Deque &d)
{
	copyDeque(d);
}

// destructor
// post: deallocates dynamic memory allocated by the Deque
template <class T>
Deque<T>::~Deque()
{
	deleteDeque();
}

// overloaded assignment operator
// param: constant Deque reference parameter
// post: (deep) copies its constant Deque reference parameter into the calling object
// and returns a reference to the calling object
template <class T>
Deque<T> &Deque<T>::operator=(const Deque &d)
{
	if (this != &d)
	{
		deleteDeque();
		copyDeque(d);
	}
	return *this;
}

// param: template parameter
// post: inserts its template parameter at the front of the Deque
template <class T>
void Deque<T>::insertFront(T value)
{
	Node<T> *newNode = new Node<T>(value);
	if (front == nullptr)
	{
		back = front = newNode;
	}
	else
	{
		newNode->next = front;
		front->pre = newNode;
		front = newNode;
	}

	DequeSize++;
}

// post:  removes and returns the value at the back of the Deque,
// if theDeque is empty throws a runtime_error
template <class T>
void Deque<T>::insertBack(T value)
{
	Node<T> *newNode = new Node<T>(value);
	if (back == nullptr)
	{
		front = back = newNode;
	}
	else
	{
		newNode->pre = back;
		back->next = newNode;
		back = newNode;
	}

	DequeSize++;
}

// post: removes and returns the value at the front of the Deque,
// if the Deque is empty throws a runtime_error
template <class T>
T Deque<T>::removeFront()
{
	T value;

	if (front == nullptr)
	{
		throw std::runtime_error("This is empty");
	}
	else
	{
		Node<T> *temp = front;
		front = front->next;
		if (front == nullptr)
		{
			back = nullptr;
		}
		else
		{
			front->pre = nullptr;
		}
		value = temp->data;
		delete temp;
	}

	DequeSize--;
	return value;
}

// post:  removes and returns the value at the back of the Deque,
// if theDeque is empty throws a runtime_error
template <class T>
T Deque<T>::removeBack()
{
	T value;

	if (front == nullptr)
	{
		throw std::runtime_error("This is empty");
	}
	else
	{
		Node<T> *temp = back;
		back = back->pre;
		if (back == nullptr)
		{
			front = nullptr;
		}
		else
		{
			back->next = nullptr;
		}
		value = temp->data;
		delete temp;
	}

	DequeSize--;
	return value;
}

// post:  returns the value at the front of the Deque without removing it,
// if the Deque is empty throws a runtime_error
template <class T>
T Deque<T>::peekFront()
{
	if (front == nullptr)
	{
		throw std::runtime_error("This is empty");
	}
	else
	{
		return front->data;
	}
}

// post: returns the value at the back of the Deque without removing it,
// if the Deque is empty throws a runtime_error
template <class T>
T Deque<T>::peekBack()
{
	if (back == nullptr)
	{
		throw std::runtime_error("This is empty");
	}
	else
	{
		return back->data;
	}
}

// post: returns true if the Deque is empty, false otherwise
template <class T>
bool Deque<T>::empty()
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// post: returns the number of items stored in the Deque, as an int
template <class T>
int Deque<T>::size()
{
	return DequeSize;
}

// copy helper function
// param: constant Deque reference parameter
// post: creates a deep copy of its constant Deque reference parameter
template <class T>
void Deque<T>::copyDeque(const Deque &d)
{
	front = nullptr;
	back = nullptr;

	Node<T> *original = d.front;

	if (original != nullptr)
	{
		front = new Node<T>(original->data);
		original = original->next;
		Node<T> *copy = front;
		while (original != nullptr)
		{
			Node<T> *newNode = new Node<T>(original->data);
			newNode->pre = copy;
			copy->next = newNode;
			copy = copy->next;
			original = original->next;
		}
		back = copy;
	}
}

// delete helper function
// post:  deallocates dynamic memory allocated by the Deque
template <class T>
void Deque<T>::deleteDeque()
{
	Node<T> *temp = front;
	while (front != nullptr)
	{
		front = front->next;
		delete temp;
		temp = front;
	}
}