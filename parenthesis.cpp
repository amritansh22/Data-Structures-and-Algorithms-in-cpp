#include<stdio.h>
#include<stdlib.h>
#include<string>
struct node
{
	int data;
	struct node* next;
}*top = NULL;
void display()
{
	struct node* p;
	p = top;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
void push( int x)
{
	struct node* t;
	t = (struct node*)malloc(sizeof(struct node));
	if (t == NULL)
		printf("stack is full\n");
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}
int pop()
{
	int x = -1;
	struct node* t;
	if (top == NULL)
		printf("stack is empty\n");
	else
	{
		t = top;
		top = top ->next;
		x = t->data;
		free(t);
	}
	return x;
}
int isbalanced(const char* exp)
{
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		push(exp[i]);
		else if (exp[i] == ')')
		{
			if (top == NULL)
				return 0;
			pop();
		}
	}
	if (top == NULL)
		return 1;
	else
		return 0;
}
int pre(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if(x=='*'||x== '/' )
		return 2;
	return 0;
}
int isoperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}
char* intopost(const char* infix)
{
	int i = 0, j = 0;
	char* postfix;
	int len = strlen(infix);
	postfix = (char*)malloc((len + 1) * sizeof(char));
	while (infix[i] != '\0')
	{
		if (isoperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (pre(infix[i]) > pre(top->data))
				push(infix[i++]);
			else
				postfix[j++] = pop();
		}
	}
	while (top != NULL)
		postfix[j++] = pop();
	postfix[j] = '\0';
	return postfix;
}
int eval(const char* postfix)
{
	int x1, x2, r;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		if (isoperand(postfix[i]))
			push(postfix[i]-'0');
		else
		{
			x2 = pop();
			x1 = pop();
			switch (postfix[i])
			{
			case '+':
				r = x1 + x2;
				break;
			case '-':
				r = x1 -x2;
				break;
			case '*':
				r = x1 *x2;
				break;
			case '/':
				r = x1 /x2;
				break;
			}
			push (r);
		}
	}
	return top->data;
}
int main()
{
	/*const char* infix = "a+b*c";
	push('#');
	char* postfix = intopost(infix);
	printf("%s", postfix);*/
	const char* postfix = "234*+82/-";
	printf("%d",eval(postfix));
	return 0;
}