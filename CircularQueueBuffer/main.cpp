
#include "QueueBufferLinkedList.h"
#include "QueueBufferArray.h"
#include "SimpleBuffer.h"
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


	SimpleBuffer<int, 10> arr2;


	cout << "Enqueu" << endl;


	arr2.printAll();

	for (int i = 0; i < 15; i++)
	{
		arr2.enqueue(i);
		arr2.printAll();
		cout << "This is idx 3 : " << arr2[3] << endl;
		cout << "This is idx -2 : " << arr2[-2] << endl;
	}
	cout << "DEQUE" << endl;


	for (int i = 0; i < 6; i++)
	{
		arr2.dequeue();
		arr2.printAll();
		cout << "This is idx -2 : " << arr2[-2] << endl;
	}




	cout << "REAL TEST" << endl;


	AE_Buffer<int, 5> myBuffer;

	for (int i = 0; i < 10; i++)
	{
		cout << i << " th" << endl;
		myBuffer.enqueue(i, (i + 1000), 1);
		myBuffer.printAll();
	}


}