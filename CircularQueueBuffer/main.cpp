
#include "QueueBufferLinkedList.h"
#include "QueueBufferArray.h"
int main()
{
	CircularQueueBuffer<int, 3> q;
	q.print();
	for (int i = 0; i < 10; i++)
	{
		
		q.enqueue(i);
		q.print();
	}

	for (int i = -1; i >=-3; i--)
	{
		cout << q[i] << endl;
	
	}
	
	QueueBufferArray<int, 3> arr;

	arr.print();
	for (int i = 0; i < 10; i++)
	{

		arr.enqueue(i);
		arr.print();
	}
	arr.print();
}