# QueueBuuferArray


1. Concept
2. Template parameters
3. Member Variables
4. Member Functions
5. Constructor
6. Usage


## 1. Concept

> ```QueueBufferArray``` use array to implement CircularQueueBuffer. It is shifted when size is full.



## 2. Template Parameters
### template <typename T , int bufferSize>

> **'typename T'** determines type in QueueBufferArray.<br>
> **'bufferSize'** determines maximum size of buffer_. Shifting data occurs when QueueBufferArray is full.
> If you want to make QueueBufferArray which stores three integer types, declare like this.<br>
> **QueueBufferArray < int , 3 > simplebuffer;**



## 3. Member Vairables

|Vairables|Accessiblity|Note|
|---|---|---|
|```capacity_```|private|Save bufferSize as class member variable|
|```head_```|index of the oldest data in the buffer_|starts from -1|
|```tail_```|index of the latest data in the buffer_|starts from -1|
|```size_```|the number of data in the buffer_|size_<=bufferSize_|

## 4. Member Functions

|Function|Definition|Note|
|------|---|---|
|```enqueue()```|enqueue data to buffer_|if buffer_ is full, QueueBufferArray calls ```shiftBuffer()```|
|```shiftBuffer()```|shift all data in buffer_.|dequeue and then enqueue.|

## 5. Constructor

QueueBufferArray supports two Constructors.


1. In this case, data is not enqueued to buffer during construction time.
```cpp
QueueBufferArray()
{
	capacity_ = bufferSize;
	size_=head_ = tail_ = 0;
}
```


2. In this case, **data** is enqueued to buffer until buffer_ is full.
```cpp
QueueBufferArray(const T& data)
{
	capacity_ = bufferSize;
	size_=head_ = tail_ = 0;

	for (int i = 0; i < bufferSize; i++)
	{
		enqueue(data);
	}
}
```

