#pragma once
#include <iostream>

enum class FrameInfoIdx
{
	FRAME_CURRENT = -1,
	FRAME_MINUS_1 = -2,
	FRAME_MINUS_2 = -3,
	FRAME_MINUS_3 = -4,
	FRAME_MINUS_4 = -5,
	FRAME_MINUS_5 = -6,
	FRAME_MINUS_6 = -7,
	FRAME_MINUS_7 = -8,
	FRAME_MINUS_8 = -9,
	FRAME_MINUS_9 = -10,
	FRAME_MINUS_10 = -11,
	FRAME_MINUS_11 = -12,
	FRAME_MINUS_12 = -13,
	FRAME_MINUS_13 = -14,
	FRAME_MINUS_14 = -15,
	FRAME_MINUS_15 = -16,
	FRAME_MINUS_16 = -17,
	FRAME_MINUS_17 = -18,
	FRAME_MINUS_18 = -19,
	FRAME_MINUS_19 = -20,
	FRAME_MINUS_20 = -21,
	FRAME_MINUS_21 = -22,
	FRAME_MINUS_22 = -23,
	FRAME_MINUS_23 = -24,
	FRAME_MINUS_24 = -25,
	FRAME_MINUS_25 = -26,
	FRAME_MINUS_26 = -27,
	FRAME_MINUS_27 = -28,
	FRAME_MINUS_28 = -29,
	MAX_FRAME_NUM = 30
};


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




template <typename T, int size>
class AE_Buffer
{
public:
	AE_Buffer() :
		buffer_(0),
		frameNumber_(0),
		sensorPlace_(0)
	{
		static_assert(size <= static_cast<int>(FrameInfoIdx::MAX_FRAME_NUM) ,"AE_Buffer Size is limited to 30. So do not use more than 30, unless you should change FrameInfoIdx::MAX_FRAME_NUM");
	}
	AE_Buffer(const T& data) :
		buffer_(data),
		frameNumber_(0),
		sensorPlace_(0)
	{
		static_assert(size <= static_cast<int>(FrameInfoIdx::MAX_FRAME_NUM), "AE_Buffer Size is limited to 30, do not use more than 30, if not you should change FrameInfoIdx::MAX_FRAME_NUM");
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
	T GetDataByFrameIdx(FrameInfoIdx frameInfoIdx) const
	{
		const int idx = static_cast<int>(frameInfoIdx);

		return buffer_[idx];
	}
	int GetSenSorPlaceInfoFromIdx(FrameInfoIdx frameInfoIdx) const
	{
		const int idx = static_cast<int>(frameInfoIdx);
		return sensorPlace_[idx];
	}
	int GetFrameNumberInfoFromIdx(FrameInfoIdx frameInfoIdx) const
	{
		const int idx = static_cast<int>(frameInfoIdx);
		return frameNumber_[idx];
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