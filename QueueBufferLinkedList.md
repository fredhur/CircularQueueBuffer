# QueueBufferLinkedList


1. [Concept](#1-concept)
2. [Template Parameters](#2-template-parmeters)
3. [Member Variables](#3-Member-variables)
4. [Member Functions](#4-member-functions)
5. [Constructor](#5-constructor)
6. [Operator](#6-operator)
7. [Memory Pool](#7-opeartor)

## 1. Concept
> QueueBufferLinkedList use implements QueueBufferLinkedList by using linkedlist. 
Unlike other linkedlist, it use memory pool. (```Node```)

## 2. Template Parameters
### template <typename T , int bufferSize>

> **'typename T'** determines type in QueueBufferArray.<br>
> **'bufferSize'** determines maximum size of buffer_. 
> If you want to make QueueBufferArray which stores three integer types, declare like this.<br>
> **QueueBufferLinkedList < int , 3 > simplebuffer;**

## 3. Member Variables
|Member type|Definition|Note|
|------|---|---|
|```capacity_```|private|Save bufferSize as class member variable|
|```size_```|the number of data in the buffer_|size_<=bufferSize_|
|```buf_```|memory pool||
|```bcnt_```|memory pool counter||
|```head_```|dummy head pointer|dummy node|
|```tail_```|dummy tail pointer|dummy node|

## 4. Member Functions

|Function|Definition|Note|
|------|---|---|
|enqueue()|enqueue data to buffer_|dequeue and enqueue|
|isEmpty()|check if buffer_ is empty or not||


## 5. Constructor
QueueBufferLinkedList supports two Constructors.


1. In this case, data is not enqueued to buffer during construction time.
```cpp
	QueueBufferLinkedList()
	{
		capacity_ = bufferSize;
		bcnt_ = 0;
		size_ = 0;
		head_.next_ = &tail_;
		tail_.prev_ = &head_;
	
	}
```


>2. In this case, **initdata** is enqueued to buffer until buffer_ is full.
```cpp
	QueueBufferLinkedList(const T& initData)
	{
		capacity_ = bufferSize;
		bcnt_ = 0;
		size_ = 0;
		head_.next_ = &tail_;
		tail_.prev_ = &head_;
		
		for (int i = 0; i < N; i++)
		{
			enqueue(initData);
		}		
	}
```

## 6. Operator
> QueueBufferLinkedList supports bracket opeartor and negative indexing. (like python)<br><br>
> [0], [1], [2] ... : bigger number returns more recent value. ( [0] : oldest data) <br>
> [-1]. [-2], [-3] ... : smaller number returns older value. ( [-1] : latest data)


## 7. Memory Pool

> [Wikipedia link](https://en.wikipedia.org/wiki/Memory_pool)

Since CircularQueueBuffer is fixed-size , we don't need memory allocation every time.
So use memory pool to achive memory optimization. ```Node``` is memory pool. 

```cpp
template <typename T> // by using template, Node can be used in all data types.
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
	void alloc(Node* prev, Node* next, const T&data) // memory allocation
	{
		data_ = data;
		prev_ = prev;
		next_ = next;
		if (prev_)prev_->next_ = this;
		if (next_)next_->prev_ = this;
		
		return;
	}
	void pop() // delete memory (free memory)
	{
		if (prev_)prev_->next_ = next_;

		if (next_)next_->prev_ = prev_;

		return;
	}

	
};
```


