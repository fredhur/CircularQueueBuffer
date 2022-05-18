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
		bufferSize_ = bufferSize ;
	}
	~SimpleBuffer() = default;
	SimpleBuffer(const T& initdata)
	{
		head_ = -1;
		tail_ = -1;
		size_ = 0;
		bufferSize_ = bufferSize ;
		for (int i = 0; i < bufferSize_; i++)
		{
			enqueue(initdata);
		}
	}
	T front()
	{
		if (isEmpty()) { return T(); }
		return buffer[head_];
	}
	T tail()
	{
		if (isEmpty()) { return buffer[0]; }


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
			if (head_ == -1) head_ = 0;
			tail_ = (tail_ + 1) % (bufferSize_);
			buffer[tail_] = data;
			size_++;
		}
	}
	T operator[](const int idx)// don't want to return l-value 
	{
		if (idx >= 0)
		{
			return buffer[(head_+idx)%bufferSize_];
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
			cout << "EMPTY" << endl;
			return;
		}
		cout << "HEAD val : " << front() << endl;
		cout << "TAIL val : " << buffer[tail_] << endl;
		cout << "PRINTALL : ";
		
		
		int idx = head_;

		for (idx = head_; idx!=tail_; idx = (idx + 1) % bufferSize_)
		{
			cout << buffer[idx] << " ";
		}cout << buffer[idx] << endl;

	
		return;
	}
private:

	int head_;
	int tail_;
	int size_;
	int bufferSize_;
	T buffer[bufferSize];
	bool IsFull()
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
	bool isEmpty()
	{
		if (head_ == -1) { return true; }

		else { return false; }
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
	T GetCurrentData()
	{
		
		return buffer_.tail();
	}
	int GetFrameNumber(const int idx)
	{
		return frameNumber_[idx];
	}
	int GetCurrentFrameNumber()
	{
		return frameNumber_.tail();
	}
	int GetSensorPlace(const int idx)
	{
		return sensorPlace_[idx];
	}
	int GetCurrentSensorPlace()
	{
		return sensorPlace_.tail();
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