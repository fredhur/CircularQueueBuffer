#pragma once
#include <iostream>
using namespace std;


template <typename T, int bufferSize>
class QueueBufferArray
{
public:
	QueueBufferArray()
	{
		capacity_ = bufferSize;
		size_=head_ = tail_ = 0;
	}
	~QueueBufferArray() = default;
	QueueBufferArray(const T& data)
	{
		capacity_ = bufferSize;
		size_=head_ = tail_ = 0;

		for (int i = 0; i < bufferSize; i++)
		{
			enqueue(data);
		}
	}
	void enqueue(const T& data)
	{
		if (size_ == capacity_)
		{
			shiftBuffer();
			tail_--;
			buffer_[tail_++] = data;
			return;
		}

		buffer_[tail_++] = data;
		size_++;
	}
	T operator[](const int idx)const
	{
		return buffer_[idx];
	}
	void printAll()
	{
		for (int i = 0; i < tail_; i++)
		{
			cout << buffer_[i] << " ";
		}cout << endl;
	}
private:
	T buffer_[bufferSize + 1];

	int capacity_;
	int size_;
	int head_;
	int tail_;
	void shiftBuffer()
	{
		for (int i = 0; i < size_ - 1; i++)
		{
			buffer_[i] = buffer_[i + 1];
		}
	}
};