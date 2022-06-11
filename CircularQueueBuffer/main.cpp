
#include "QueueBufferLinkedList.h"
#include "QueueBufferArray.h"
#include "SimpleBuffer.h"

int main()
{

	cout << "Test QueueBufferLinekdList !! " << endl;
	QueueBufferLinkedList<int, 3> queueBufferLinkedList;
	queueBufferLinkedList.printAll();
	for (int i = 0; i < 10; i++)
	{
		
		queueBufferLinkedList.enqueue(i);
		queueBufferLinkedList.printAll();
	}

	for (int i = -1; i >=-3; i--)
	{
		cout << queueBufferLinkedList[i] << endl;
	
	}
	
	cout << "End of QueueBufferLinkedList test" << endl << endl << endl;;


	cout << "Test QueueBufferArray !!" << endl;


	QueueBufferArray<int, 3> queueBufferArray;

	queueBufferArray.printAll();
	for (int i = 0; i < 10; i++)
	{

		queueBufferArray.enqueue(i);
		queueBufferArray.printAll();
	}
	queueBufferArray.printAll();


	cout << "End of QueueBufferArray test" << endl << endl << endl;;


	cout << "Test SimpleBuffer !!" << endl;
	SimpleBuffer<int, 10> simpleBuffer;


	


	simpleBuffer.printAll();

	for (int i = 0; i < 15; i++)
	{
		simpleBuffer.enqueue(i);
		simpleBuffer.printAll();
	}
	


	for (int i = 0; i < 6; i++)
	{
		simpleBuffer.dequeue();
		simpleBuffer.printAll();
	
	}
	cout << "End of SimpleBuffer test" << endl << endl<< "All test is done " << endl;;


}