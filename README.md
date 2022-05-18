# SimpleBuffer DOCS (SimpleBuffer.h)

1. Concpet
2. Template parameters
3. Member variables
4. Member functions 
5. Constructor
6. operator
7. Installation
8. Example


## 1. Concept
> SimpleBuffer is **fixed size Queue**. It seems like FIFO queue, but difference between FIFO queue is that if new data is enqueuing while queue size is full, dequeuing queue and then enqueueing new data. ( a.k.a shift data).
SimpleBuffer implements this concept as normal array and circular queue concept.

<img src="https://user-images.githubusercontent.com/7028314/168482819-55f8edca-3ff4-4955-9493-cb7fc30ab77b.png" width="400" height="300"/>



## 2. Template parameters
### template <typename T , int bufferSize>

> #### T : type that saved in SimpleBuffer.<br>
> #### bufferSize : Maximum data size. If current size is bigger than bufferSize, shifting data.
> If you want to make SimpleBuffer which stores three integer types, declare like this.<br>
> **SimpleBuffer < int , 3 > simplebuffer;**


## 3. Member variables
|member type|defenition|note|
|------|---|---|
|head_|the index of oldest data in the buffer_|starts from -1|
|tail_|the index of latest data in the buffer_|starts from -1|
|size_|the number of data in the buffer_|size<=bufferSize_|
|bufferSize_|maximum number of data in the buffer_||
|buffer_|the array of data||


## 4. Member functions

|function|definition|note|
|------|---|---|
|front()|return oldest data||
|tail()|return latest data||
|enqueue()|enqueuing data to buffer_|if size is maximum, dequeuing and then enqueuing|
|dequeue()|dequeuing data to buffer_|if empty, do nothing|
|IsFull()|check if data is full or not|head_==tail_+1 : happens when tail_ turn around array<br> https://www.programiz.com/dsa/circular-queue|
|isEmpty()|check data is empty or not||


## 5. Constructor
SimpleBuffer supports two Constructor.


1. In this case, Not any data is enqueuing to buffer.
```cpp
SimpleBuffer()
	{
		head_ = -1;
		tail_ = -1;
		size_ = 0;
		bufferSize_ = bufferSize;
	}
```


>2. In this case, all values in the buffer initialized with initdata.
```cpp
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
```

## 6. Operator []
> [0], [1], [2] : The smaller the number, return the older value. [0] : oldest data <br>
> [-1]. [-2], [-3] : The smaller the number, return the more recent value. [-1] : latest data

## 7. Installation

> It is header-only file. Just copy "Simplebuffer.h" to your project

## 8. Example

>See main.cpp for example.


