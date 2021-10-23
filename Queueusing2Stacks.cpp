#include <stdlib.h>
#include <iostream>

using namespace std;

struct nod
{ //node declaration
	int d;
	struct nod *n;
};

void push(struct nod **top_ref, int n_d); //functions prototypes.
int pop(struct nod **top_ref);

struct queue
{
	struct nod *s1;
	struct nod *s2;
};

void enQueue(struct queue *q, int m)
{
	push(&q->s1, m);
}

int deQueue(struct queue *q)
{
	int m;
	if (q->s1 == NULL && q->s2 == NULL)
	{
		cout << "Queue is empty";
		exit(0);
	}
	if (q->s2 == NULL)
	{
		while (q->s1 != NULL)
		{
			m = pop(&q->s1);
			push(&q->s2, m);
		}
	}
	m = pop(&q->s2);
	return m;
}

void push(struct nod **top_ref, int n_d)
{
	struct nod *new_node = (struct nod *)malloc(sizeof(struct nod));

	if (new_node == NULL)
	{
		cout << "Stack underflow \n";
		exit(0);
	}
	//put items on stack
	new_node->d = n_d;
	new_node->n = (*top_ref);
	(*top_ref) = new_node;
}

int pop(struct nod **top_ref)
{
	int res;
	struct nod *top;
	if (*top_ref == NULL)  {//if stack is null
		cout << "Stack overflow \n";
	exit(0);
}
else
{ //pop elements from stack
	top = *top_ref;
	res = top->d;
	*top_ref = top->n;
	free(top);
	return res;
}
}

int main()
{
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	q->s1 = NULL;
	q->s2 = NULL;
	cout << "Enqueuing..7";
	cout << endl;
	enQueue(q, 7);
	cout << "Enqueuing..6";
	cout << endl;
	enQueue(q, 6);
	cout << "Enqueuing..2";
	cout << endl;
	enQueue(q, 2);
	cout << "Enqueuing..3";
	cout << endl;
	enQueue(q, 3);

	cout << "Dequeuing...";
	cout << deQueue(q) << " ";
	cout << endl;
	cout << "Dequeuing...";
	cout << deQueue(q) << " ";
	cout << endl;
	cout << "Dequeuing...";
	cout << deQueue(q) << " ";
	cout << endl;
}
