# CircularQueue Buffer DOCS 


## Index

1. Concept
2. Three types of Circular Queue Buffer
3. Installation




  


## 1. Concept
> **CircularQueue Buffer** is fixed size Queue which seems like FIFO queue. The difference between FIFO queue and CircularQueue Buffer is that unlike FIFO queue, CircularQueue Buffer shifts data when CircularQueue Buffer's size is maximum.
CircularQueue Buffer is developed by using this concept via circular queue concept.  
[Wiki : Circular Queue](https://en.wikipedia.org/wiki/Circular_buffer)

<img src="https://user-images.githubusercontent.com/7028314/169650472-868089e6-92e2-4554-a2ac-4c99e857325f.png" width="500" height="300"/>





## Three types of CircularQueue Buffer
<details open>
<summary> <span style="font-size:150%">Various Kinds of CircularQueue Buffer  </span> </summary>

1. [QueueBufferArray](./QueueBufferArray.md)
2. [QueueBufferLinkedList](./QueueBufferLinkedList.md)
3. [SimpleBuffer](./SimpleBuffer.md)
</details>

## 3. Installation
> It is header-only file. Just copy ```"SimpleBuffer.h"``` , ```"QueueBufferArray.h```, and ```"QueueBufferLinkedList.h"``` to your project.