# SimpleBuffer DOCS (SimpleBuffer.h)

1. [Concept](#1-Concept)
2. [Template Parameters](#2-template-parameters)
3. [Member Variables](#3-Member-Vairables)
4. [Member Functions](#4-MemberFunctions) 
5. [Constructor](#5-Constructor)
6. [Operator](#6-Operator)
7. [Detail Usage](#7-detail-usage)


## 1. Concept
> **SimpleBuffer** use array to implement [CirQualrQueueBuffer](./README.md). The difference between QueueBufferArray is that **SimpleBuffer** use modulr operation. By using this, there is no shifting.





## 2. Template Parameters
### template <typename T , int bufferSize>

> **'typename T'** determines type in SimpleBuffer.<br>
> **'bufferSize'** determines maximum size of buffer_. Shifting data occurs when SimpleBuffer is full.
> If you want to make SimpleBuffer which stores three integer types, declare like this.<br>
> **SimpleBuffer < int , 3 > simplebuffer;**


## 3. Member Variables
|Member type|Definition|Note|
|------|---|---|
|buffer_|the array of data|Not LinkedList but Array. SimpleBuffer is developed by using circular queue concept.|
|bufferSize_|maximum size of buffer_||
|head_|index of the oldest data in the buffer_|starts from -1|
|tail_|index of the latest data in the buffer_|starts from -1|
|size_|the number of data in the buffer_|size_<=bufferSize_|




## 4. Member Functions

|Function|Definition|Note|
|------|---|---|
|front()|return the oldest data||
|tail()|return the latest data||
|enqueue()|enqueue data to buffer_|if buffer_ is full, SimpleBuffer calls dequeue() and enqueue()|
|dequeue()|dequeue data to buffer_|if buffer_ is empty, do nothing|
|IsFull()|check if buffer_ is full or not|[link](https://www.programiz.com/dsa/circular-queue)|
|isEmpty()|check if buffer_ is empty or not||


## 5. Constructor
SimpleBuffer supports two Constructors.


1. In this case, data is not enqueued to buffer during construction time.
```cpp
SimpleBuffer()
	{
		head_ = -1;
		tail_ = -1;
		size_ = 0;
		bufferSize_ = bufferSize;
	}
```


>2. In this case, **initdata** is enqueued to buffer until buffer_ is full.
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

## 6. Operator
> SimpleBuffer supports bracket opeartor and negative indexing. (like python)<br><br>
> [0], [1], [2] ... : bigger number returns more recent value. ( [0] : oldest data) <br>
> [-1]. [-2], [-3] ... : smaller number returns older value. ( [-1] : latest data)


## 7. Detail Usage

> Here are several examples of how to use <u>SimpleBuffer</u> class
> ### 1. Declaration<br>
> SimpleBuffer needs two template parameters. One is class type ( or it could be primitive data type) and the other is size of SimpleBuffer. It seems like std::array.<br> Below code shows how to declare SimpleBuffer that saves 3 integers.
> ```cpp
> #include "SimpleBuffer.h"
> // Declare SimpleBuffer that saves 3 integers.
> int main()
> {
>     SimpleBuffer <int, 3> foo
> }```

>If you need enqueuing initdata during construction time, declare like this.

>```cpp
> #include "SimpleBuffer.h"
> int main()
> {
>     SimpleBuffer <int, 3> foo(4);// 4 is enqueued to SimpleBuffer.
> }

> ### 2. Member functions
> Below code shows how to use public member functions.
> ```cpp
> #include "SimpleBuffer.h"
> int main()
> {
>   SimpleBuffer <int , 4> foo(5);
>  
>   auto front = foo.front();//get front data.
>   auto tail = foo.tail(); // get tail data.
>   foo.enqueue(7); // enqueue data 7.
>   foo.dequeue(); //  dequeue foo.
>   auto data_3rd = foo[3]; // read 3rd data of foo.
>   foo.printAll(); // print data from head to tail.
> }
> ```


