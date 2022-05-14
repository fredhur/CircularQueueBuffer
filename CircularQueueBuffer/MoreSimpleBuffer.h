#pragma once
#include <iostream>
using namespace std;
template <typename T>
T ABS(T a)
{
	return a > 0 ? a : -a;
}

template<typename T,  int bufferSize>
class SimpleBuffer
{
public:
	SimpleBuffer()
	{
		head_ = 0;
		tail_ = 0;
		size_ = 0;
		bufferSize_ = bufferSize+1;
	}
	~SimpleBuffer() = default;
	SimpleBuffer(const T& initdata)
	{
		head_ = 0;
		tail_ = 0;
		size_ = 0;
		bufferSize_ = bufferSize+1;
		for (int i = 0; i < bufferSize_; i++)
		{
			enqueue(initdata);
		}
		
	}
	T front()
	{
		int i = head_;
		i = (i + 1) % bufferSize_;
		return buffer[i];
	}
	void enqueue(const T& data)
	{
		if (IsFull())
		{
			dequeue();
			// enqueue(data) 
			tail_ = (tail_ + 1) % bufferSize_;
			buffer[tail_] = data;
			size_++;
			return;
		}
		else
		{
			tail_ = (tail_ + 1) % bufferSize_;
			buffer[tail_] = data;
			size_++;
		}
	}
	T operator[](const int idx)
	{
		
		int cnt = ABS(idx);

		if (idx >= 0)
		{
			int i = head_;
			do
			{
				i = (i + 1) % bufferSize_;
				if (i == tail_)
					break;
			} while (i != head_ && cnt--);
			return buffer[i];
		}
		else
		{
			int i = tail_;
			
			if (cnt > size_-1)
			{

				return buffer[i];
			}

			while( cnt--)
			{
			 
				
				if (i < 0)
				{
					i = bufferSize - 1;
				}
				if (i == head_) break;
				
				i--;
			} 
			return buffer[i];
		}

		
	}
	
	void dequeue()
	{
		if (isEmpty())
		{
			return;
		}

		size_--;
		head_ = (head_ + 1) % bufferSize_;
	}
	void printAll()
	{
		int i = head_;
		if (isEmpty())
		{
			cout << "EMPTY" << endl;
			return;
		}
		cout << "HEAD val : " << front() << endl;
		cout << "TAIL val : " << buffer[tail_] << endl;
		cout << "PRINTALL : ";
		do
		{
			i = (i + 1) % bufferSize_;
			cout << buffer[i] << " ";
			if (i == tail_)
				break;
		} while (i != head_);
		cout << endl;
		return;
	}
private:

	int head_;
	int tail_;
	int size_;
	int bufferSize_;
	T buffer[bufferSize+1];
	bool IsFull()
	{
		return (tail_ + 1) % bufferSize_ == head_;
		
	}
	bool isEmpty()
	{
		return head_ == tail_;
	}
	
};


template <typename T, int size>
class AE_Buffer
{
public:
	AE_Buffer() :
		buffer_(0),
		frameNumber_(0),
		sensorPlace_(0)
	{
		
	}
	AE_Buffer(const T& data) : 
		buffer_(data),
		frameNumber_(0),
		sensorPlace_(0)
	{
		
	}
	~AE_Buffer() = default;
	void enqueue(const T& data)
	{
		buffer_.enqueue(data);
		frameNumber_.enqueue(0);
		sensorPlace_.enqueue(0);
	}
	void enqueue(const T& data, const int& frameNumber, const int& sensorPlace)
	{
		buffer_.enqueue(data);
		frameNumber_.enqueue(frameNumber);
		sensorPlace_.enqueue(sensorPlace);
	}
	T operator[](const int idx)
	{
		return buffer_[idx];
	}
	int GetFrameNumber(const int idx)
	{
		return frameNumber_[idx];
	}
	int GetSensorPlace(const int idx)
	{
		return sensorPlace_[idx];
	}
	void printAll()
	{
		buffer_.printAll();
		frameNumber_.printAll();
		sensorPlace_.printAll();
	}

private:
	SimpleBuffer<T, size> buffer_;
	SimpleBuffer<T, size> frameNumber_;
	SimpleBuffer<T, size> sensorPlace_;
};