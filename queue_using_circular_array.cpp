#include <stdio.h>
#include <iostream>
#include <conio.h>

#define SIZE 4

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int);
int dequeue();

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    return 0;
}

void enqueue(int item)
{
    rear = (rear + 1) % SIZE;
    if (front == rear)
    {
        printf("queue is full.\n");
        if (rear == 0)
        {
            rear = SIZE - 1;
        }
        else
        {
            rear = rear - 1;
        }
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[rear] = item;
    printf("front : %d\trear : %d\tinserted : %d\n", front, rear, item);
    return;
}

int dequeue()
{
    int temp;
    if (front == rear)
    {
        printf("queue is empty.\n");
        return -1;
    }
    front = (front + 1) % SIZE;
    temp = queue[front];
    printf("front : %d\trear : %d\tdeleted : %d\n", front, rear, temp);
    return temp;
}
