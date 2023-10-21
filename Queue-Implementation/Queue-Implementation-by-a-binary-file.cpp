#include <iostream>
#include <string>
#include <fstream>
using namespace std;
template <class T>
class MyQueue
{
public:
	// protocol for MyQueue operations
	virtual void clear() = 0;
	virtual T dequeue() = 0;
	virtual void enqueue(T value) = 0;
	virtual T front() = 0;
	virtual bool isEmpty() = 0;
	virtual ~MyQueue() {}
};
template <class T>
class QueueFile :public MyQueue<T>
{
	int queueSize = 10;
	int indexOfFirst = 0;
	int indexOfLast = 0;
	fstream data;
	bool isFull()
	{
		return indexOfFirst == indexOfLast + 1;
	}
public:
	QueueFile(int size = 100) :queueSize(size)
	{
		data.open("queue.dat", ios::out);
		T stam;
		for (int i = 0; i < size; i++)
		{
			data.write((char*)&stam, sizeof(T));
		}
		data.close();
		data.open("queue.dat", ios::out | ios::in);
		if (!data)
			throw "error in opening";
	}
	void clear()
	{
		indexOfFirst = 0;
		indexOfLast = 0;
	}
	bool isEmpty()
	{
		return indexOfFirst == indexOfLast;
	}
	T front()
	{
		if (this->isEmpty())
			throw "underflow";
		data.seekg(indexOfFirst * sizeof(T), ios::beg);
		T s;
		data.read((char*)&s, sizeof(T));
		return s;
	}
	T dequeue()
	{
		if (this->isEmpty())
			throw "underflow";
		data.seekg(indexOfFirst * sizeof(T), ios::beg);
		T s;
		data.read((char*)&s, sizeof(T));
		if (indexOfFirst == queueSize)
			indexOfFirst = 0;
		else
			indexOfFirst++;
		return s;
	}
	void enqueue(T value) {
		if (this->isFull())
			throw "overflow";
		data.seekp(indexOfLast * sizeof(T), ios::beg);
		data.write((char*)&value, sizeof(value));
		if (indexOfLast == queueSize)
			indexOfLast = 0;
		else
			indexOfLast++;
	}
	~QueueFile()
	{
		data.close();
	}
};
	int main() {
		try {
			QueueFile<int> queue(5);
			queue.enqueue(1);
			queue.enqueue(2);
			queue.enqueue(3);
			cout << queue.dequeue() << endl; // 1
			cout << queue.dequeue() << endl; 
			queue.enqueue(4);
			queue.enqueue(5);
			cout << queue.front() << endl; //  3
			// Clear the queue
			queue.clear();
			if (queue.isEmpty())
				cout << "Queue is empty" << endl; 
			queue.enqueue(4);
			queue.enqueue(5);
			cout << queue.front() << endl; 
			cout << queue.dequeue() << endl; 
			cout << queue.dequeue() << endl;
			cout << queue.dequeue() << endl;
		}
		catch (const char* error) {
			cout << error << endl;
		}
		return 0;
	}