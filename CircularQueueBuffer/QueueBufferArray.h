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
		
		//cout << "Size and Cap init: " << size << " " << capacity << endl;
	}
	~QueueBufferArray()
	{
		
		
	}
	QueueBufferArray(const T& data)
	{
		capacity = bufferSize;
		size=head = tail = 0;

		for (int i = 0; i < bufferSize; i++)
		{
			enqueue(data);
		}
	//	cout << "Size and Cap init: " << size << " " << capacity << endl;
	}
	void enqueue(const T& data)
	{
		//cout << "Size and Cap : " << size << " " << capacity << endl;
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
	void print()
	{
		cout << "DEBUG : " << endl;
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