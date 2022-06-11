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
		capacity_ = N;
		bcnt_ = 0;
		size_ = 0;
		head_.next_ = &tail_;
		tail_.prev_ = &head_;
	
	}
	QueueBufferLinkedList(const T& initData)
	{
		capacity_ = N;
		bcnt_ = 0;
		size_ = 0;
		head_.next_ = &tail_;
		tail_.prev_ = &head_;
		
		for (int i = 0; i < N; i++)
		{
			enqueue(initData);
		}		
	}
	void enqueue(const T& data)
	{

		if (size_ == capacity_)
		{
			Node <T>* ptr = head_.next_;
			ptr->pop();
			ptr->alloc(tail_.prev_, &tail_, data);
			return;
		}
		else
		{
			buf_[bcnt_++].alloc(tail_.prev_, &tail_, data);
			size_++;
		}

		return;
	}
	T operator[](const int idx)const
	{
		if (idx >= 0)
		{
			Node<T>* ptr = head_.next_;
			for (int i = 0; i < idx; i++)
			{
				ptr = ptr->next_;
			}
			return ptr->data_;
		}
		else
		{
			Node<T>* ptr = tail_.prev_;
			for (int i = -1; i >idx; i--)
			{
				ptr = ptr->prev_;
			}
			return ptr->data_;
		}
	}
	void printAll()
	{
		Node<T>* ptr = (&head_)->next_;
		
		
		while (ptr != &tail_)
		{
			cout << ptr->data_ << " ";
			ptr = ptr->next_;
		}cout << endl;
	}
private:
	Node<T> buf_[N + 1];// Memory pool.
	int capacity_;
	int size_;
	int bcnt_;
	Node<T>head_;
	Node<T>tail_;
	bool IsEmpty() const
	{
		return head_.next_ == &tail_;
	}
};