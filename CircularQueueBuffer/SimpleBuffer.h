#pragma once
#include <iostream>
using namespace std;

template<typename T, int bufferSize>
class SimpleBuffer
{
public:

	SimpleBuffer()
	{
		head_ = -1;
		tail_ = -1;
		size_ = 0;
		bufferSize_ = bufferSize;
	}
	~SimpleBuffer() = default;
	SimpleBuffer(const T& initdata)
	{
		head_ = -1;
		tail_ = -1;
		size_ = 0;
		bufferSize_ = bufferSize;
		for (int i = 0; i < bufferSize_; i++)
		{
			enqueue(initdata);
		}
	}
	T front() const
	{
		if (isEmpty()) { return T(); }

		return buffer[head_];
	}
	T tail() const
	{
		if (isEmpty()) { return T(); }


		return buffer[tail_];
	}
	void enqueue(const T& data)
	{
		if (IsFull())
		{
			dequeue();
			enqueue(data);
			return;
		}
		else
		{
			if (head_ == -1) { head_ = 0; }

			tail_ = (tail_ + 1) % (bufferSize_);
			buffer[tail_] = data;
			size_++;
		}
	}
	T operator[](const int idx) const // don't want to return l-value. Queue's data only changed by enqueue and dequeue
	{

		if (idx >= 0)
		{
			return buffer[(head_ + idx) % bufferSize_];
		}
		else
		{
			return buffer[(head_ + size_ + idx) % bufferSize_];
		}
	}

	void dequeue()
	{
		if (isEmpty())
		{
			return;
		}
		else
		{
			if (head_ == tail_)
			{
				head_ = -1, tail_ = -1;
			}
			else
			{
				head_ = (head_ + 1) % bufferSize_;
			}
		}

		size_--;

	}
	void printAll()
	{
		int i = head_;
		if (isEmpty())
		{
		
			return;
		}


		int idx = head_;

		for (idx = head_; idx != tail_; idx = (idx + 1) % bufferSize_)
		{
			cout << buffer[idx] << " ";
		} cout << buffer[idx] << endl;


		return;
	}
private:

	int head_;
	int tail_;
	int size_;
	int bufferSize_;
	T buffer[bufferSize] = {};
	bool IsFull() const
	{

		if (head_ == 0 && tail_ == (bufferSize_ - 1))
		{
			return true;
		}
		if (head_ == tail_ + 1)
		{
			return true;
		}
		return false;

	}
	bool isEmpty() const
	{
		if (head_ == -1) { return true; }

		else { return false; }
	}

};