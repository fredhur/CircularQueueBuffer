# SimpleBuffer DOCS (SimpleBuffer.h)

1. Concept
2. Template Parameters
3. Member Variables
4. Member Functions 
5. Constructor
6. Operator
7. Installation
8. Detail Usage


## 1. Concept
> **SimpleBuffer** is fixed size Queue which seems like FIFO queue. But difference between FIFO queue and SimpleBuffer is that unlike FIFO queue, SimpleBuffer shifts data when SimpleBuffer's size is maximum.
SimpleBuffer is developed by using this concept via circular queue concept.  
[Wiki : Circular Queue](https://en.wikipedia.org/wiki/Circular_buffer)

<img src="https://user-images.githubusercontent.com/7028314/169650472-868089e6-92e2-4554-a2ac-4c99e857325f.png" width="500" height="300"/>



## 2. Template parameters
### template <typename T , int bufferSize>

> ### **typename T** determines type in SimpleBuffer.<br>
> ### **bufferSize** is maximum data size. Shifting data occurs when SimpleBuffer is full.
> If you want to make SimpleBuffer which stores three integer types, declare like this.<br>
> **SimpleBuffer < int , 3 > simplebuffer;**


## 3. Member variables
|Member type|Definition|note|
|------|---|---|
|buffer_|the array of data|Not LinkedList but Array. SimpleBuffer is developed by using circular queue concept.|
|bufferSize_|maximum number of data in the buffer_||
|head_|index of the oldest data in the buffer_|starts from -1|
|tail_|index of the latest data in the buffer_|starts from -1|
|size_|the number of data in the buffer_|size<=bufferSize_|




## 4. Member functions

|function|definition|note|
|------|---|---|
|front()|return oldest data||
|tail()|return latest data||
|enqueue()|enqueuing data to buffer_|if size is maximum, dequeuing and then enqueuing|
|dequeue()|dequeuing data to buffer_|if empty, do nothing|
|IsFull()|check if data is full or not|[link](https://www.programiz.com/dsa/circular-queue)|
|isEmpty()|check if data is empty or not||


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

## 6. Operator
> Simple Buffer supports bracket opeartor. And also, support negative indexing. (like python)<br><br>
> [0], [1], [2] : The bigger the number, return the more recent value. [0] : oldest data <br>
> [-1]. [-2], [-3] : The smaller the number, return the older value. [-1] : latest data

## 7. Installation

> It is header-only file. Just copy "SimpleBuffer.h" to your project

## 8. Detail Usage

> Here are several examples of how to use <u>SimpleBuffer</u> class
> ### 1. Declaration<br>
> SimpleBuffer needs to template parameters. The one is class type ( or it could be primitive data type) and the other is size of SimpleBuffer. It seems like std::array.<br> Below code show if programmer wants to declare SimpleBuffer that saves integer type , and size is three
> ```cpp
> #include "SimpleBuffer.h"
> // SimpleBuffer which contains 3 integer type datas.
> int main()
> {
>     SimpleBuffer <int, 3> foo
> }```

>Or, if you want to SimpleBuffer that saves 3 integer types with all data is already enqueued with 3, declare like this

>```cpp
> #include "SimpleBuffer.h"
> // SimpleBuffer which contains 3 integer type datas and all data is already enqueued with 3
> int main()
> {
>     SimpleBuffer <int, 3> foo(3);
> }

> ### 2. Member functions
> Below code shows how to use public member functions.
> ```cpp
> #include "SimpleBuffer.h"
> #include 
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


