#include<stdio.h>
#include<stdlib.h>
struct element
{
	int i;
	int j;
	int x;
};
struct sparse
{
	int m;
	int n;
	int num;
	struct element* ele;
};
void create(struct sparse* s)
{
	int i;
	printf("enter dimensuions");
	scanf_s("%d%d", &s->m, &s->n);
	printf("number of non zero elements");
	scanf_s("%d", &s->num);
	s->ele = (struct element *)malloc(s->num * sizeof(struct element));
	for (i = 0; i < s->num; i++)
		scanf_s("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
}
void display(struct sparse s)
{
	int i, j, k = 0;
	for (i = 0; i < s.m; i++)
	{
		for (j = 0; j < s.n; j++)
		{
			if (i == s.ele[k].i && j == s.ele[k].j)
				printf("%d ", s.ele[k++].x);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
struct sparse* add(struct sparse* s1, struct sparse* s2)
{
	struct sparse* sum;
	int i, j, k;
	i = j = k = 0;
	sum = (struct sparse*)malloc(sizeof(struct sparse));
	sum->ele = (struct element*)malloc((s1->num + s2->num) * sizeof(struct element));
	while (i < s1->num && j < s2->num)
	{
		if (s1->ele[i].i < s2->ele[j].i)
			sum->ele[k++] = s1->ele[i++];
		else if (s1->ele[i].i > s2->ele[j].i)
			sum->ele[k++] = s2->ele[j++];
		else
		{
			if (s1->ele[i].j < s2->ele[j].j)
				sum->ele[k++] = s1->ele[i++];
			else if (s1->ele[i].j > s2->ele[j].j)
				sum->ele[k++] = s2->ele[j++];
			else
			{
				sum->ele[k] = s1->ele[i];
				sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
			}
		}
	}
	for (; i < s1->num; i++)
		sum->ele[k++] = s1->ele[i];
	for (; j < s2->num; j++)
		sum->ele[k++] = s2->ele[j];
	sum->m = s1->m;
	sum->n = s1->n;
	sum->num = k;
	return sum;
}
int main()
{
	struct sparse s1,s2,*s3;
	create(&s1);
	create(&s2);
	s3 = add(&s1, &s2);
	printf("first matrix\n");
	display(s1);
	printf("second matrix\n");
	display(s2);
	printf("add matrix\n");
	display(*s3);
	return 0;
}