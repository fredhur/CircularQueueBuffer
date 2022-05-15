# CircularQueueBuffer API DOCS ( only SimpleBuffer.h)

1. Concpet
2. Template parameters
3. Member variables
4. Member functions 
5. Constructor
6. Example


## 1. Concept
> CircularQueueBuffer is **fixed size Queue**. It seems like FIFO queue, but difference between FIFO queue is that if new data is enqueuing while queue size is full, dequeuing queue and then enqueueing new data. ( a.k.a shift data).
SimpleBuffer implements this concept as normal array.



## 2. Template parameters
### template <typename T , int bufferSize>

> #### T : type that saved in SimpleBuffer.<br>
> #### bufferSize : Maximum data size. If current size is bigger than bufferSize, shifting data.
> If you want to make SimpleBuffer which stores 3 int types, declare like this.
> **SimpleBuffer < int , 3 > simplebuffer;**


## 3. Member variables
|member type|defenition|note|
|------|---|---|
|head_|the index of oldest data in the buffer_||
|tail_|the index latest data in the buffer_||
|size_|the number of data in the buffer_|size<=bufferSize_|
|bufferSize_|maximum number of data in the buffer_|bufferSize_ = bufferSize+1 (since head_ and tail_ start from 0|
|buffer_|the array of data||


## 4. Member functions

|function|definition|note|
|------|---|---|
|front()|return oldest data|테스트3|
|tail()|return latest data|테스트3|
|enqueue()|enqueuing data to buffer_|if size is maximum, dequeuing and then enqueuing|
|dequeue()|dequeuing data to buffer_|if empty, do nothing|
|IsFull()|check if data is full or not||
|isEmpty()|check data is empty or not||


## 5. Constructor
SimpleBuffer supports two Constructor.


1. No parameters. In this case, start from empty buffer.
```cpp
SimpleBuffer()
	{
		head_ = 0;
		tail_ = 0;
		size_ = 0;
		bufferSize_ = bufferSize + 1;
	}
```


>2. Give initialize data. In this case, all valuees in the buffer initialized with this initdata.
```cpp
SimpleBuffer(const T& initdata)
	{
		head_ = 0;
		tail_ = 0;
		size_ = 0;
		bufferSize_ = bufferSize + 1;
		for (int i = 0; i < bufferSize_; i++)
		{
			enqueue(initdata);
		}

	}
```


## 6. Example

>See main.cpp for example.


