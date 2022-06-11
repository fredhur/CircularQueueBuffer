#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node
{

	Node* prev_;
	Node* next_;
	T data_;
	Node()
	{
		prev_ = nullptr;
		next_ = nullptr;
		data_={};
	}
	~Node() = default;
	void alloc(Node* prev, Node* next, const T&data)
	{
		data_ = data;
		prev_ = prev;
		next_ = next;
		if (prev_)prev_->next_ = this;
		if (next_)next_->prev_ = this;
		
		return;
	}
	void pop()
	{
		if (prev_)prev_->next_ = next_;

		if (next_)next_->prev_ = prev_;

		return;
	}

	
};

template <typename T, int N>
class  QueueBufferLinkedList
{

public:
	QueueBufferLinkedList()
	{
		capacity = N;
		bcnt = 0;
		size = 0;
		head.next_ = &tail;
		tail.prev_ = &head;
	
	}
	QueueBufferLinkedList(const T& initData)
	{
		capacity = N;
		bcnt = 0;
		size = 0;
		head.next_ = &tail;
		tail.prev_ = &head;
		
		for (int i = 0; i < N; i++)
		{
			enqueue(initData);
		}		
	}
	void enqueue(const T& data)
	{

		if (size == capacity)
		{
			Node <T>* ptr = head.next_;
			ptr->pop();
			ptr->alloc(tail.prev_, &tail, data);
			return;
		}
		else
		{
			buf[bcnt++].alloc(tail.prev_, &tail, data);
			size++;
		}

		return;
	}
	T operator[](const int idx)const
	{
		if (idx >= 0)
		{
			Node<T>* ptr = head.next_;
			for (int i = 0; i < idx; i++)
			{
				ptr = ptr->next_;
			}
			return ptr->data_;
		}
		else
		{
			Node<T>* ptr = tail.prev_;
			for (int i = -1; i >idx; i--)
			{
				ptr = ptr->prev_;
			}
			return ptr->data_;
		}
	}
	void printAll()
	{
		Node<T>* ptr = (&head)->next_;
		
		
		while (ptr != &tail)
		{
			cout << ptr->data_ << " ";
			ptr = ptr->next_;
		}cout << endl;
	}
private:
	Node<T> buf[N + 1];// limit buffer
	int capacity;
	int size;
	int bcnt;
	Node<T>head;
	Node<T>tail;
	bool IsEmpty() const
	{
		return head.next_ == &tail;
	}
};