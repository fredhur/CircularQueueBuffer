#pragma once
#include <iostream>
using namespace std;


template <typename T, int bufferSize>
class QueueBufferArray
{
public:
	QueueBufferArray()
	{
		capacity = bufferSize;
		size=head = tail = 0;
	}
	~QueueBufferArray() = default;
	QueueBufferArray(const T& data)
	{
		capacity = bufferSize;
		size=head = tail = 0;

		for (int i = 0; i < bufferSize; i++)
		{
			enqueue(data);
		}
	}
	void enqueue(const T& data)
	{
		if (size == capacity)
		{
			shiftBuffer();
			tail--;
			buffer[tail++] = data;
			return;
		}

		buffer[tail++] = data;
		size++;
	}
	T operator[](const int idx)const
	{
		return buffer[idx];
	}
	void printAll()
	{
		for (int i = 0; i < tail; i++)
		{
			cout << buffer[i] << " ";
		}cout << endl;
	}
private:
	T buffer[bufferSize + 1];

	int capacity;
	int size;
	int head;
	int tail;
	void shiftBuffer()
	{
		for (int i = 0; i < size - 1; i++)
		{
			buffer[i] = buffer[i + 1];
		}
	}
};