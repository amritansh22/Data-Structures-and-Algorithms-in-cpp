#include <stdio.h>
#include <limits.h>

int  prim(void);
void input(void);
int  visitLeft(void);
void printDetails(void);
void sort(void);
void swap(int * , int *);


int v,parent[400],vertex[400],weight[400],visit_[20],parent_[20],weight_[20],parent_[20],count = 0;

int krushkal()
{
    int c = 0;
    while(visitLeft() && c < count)
    {
        if(visit_[vertex[c]]==0)
        {
            parent_[vertex[c]] = parent[c];
            weight_[vertex[c]] = weight[c];
            visit_[vertex[c]]  = 1;
            visit_[parent[c]]  = 1;
        }
        c++;
    }
    int min_weight = 0;
    for(int i = 0 ; i < v; i++)
        //printf("\n====%d",weight_[i]);
        min_weight += weight_[i];
    printDetails();
    return min_weight;
}

int visitLeft(void)
{
    for(int i = 0 ; i < v ; i++)
    {
        if(visit_[i]==0)
            return 1;
    }
    return 0;
}

void printDetails(void)
{
    for(int i = 0 ; i < v ; i ++)
    {
        printf("\n%3d  ==  %d  --- %d",i,parent_[i],weight_[i]);
    }
}

void input()
{
    int val;
    printf("\nEnter the adjacency metrix :\n");
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
        {
            scanf("%d",&val);
            if(val)
            {
                vertex[count] = j;
                parent[count] = i;
                weight[count] = val;
                count ++;
            }
        }
        visit_[i]  = 0;
        weight_[i] = 0;
        parent_[i] = -2;
    }
    sort(); //on the basis of weight
}

void sort(void)
{
    for(int i = 0 ; i < count-1 ; i++)
    {
        for(int j = 0 ; j < count-i-1 ; j++)
        {
            if(weight[j]>weight[j+1])
            {
                swap(&weight[j] , &weight[j+1]);
                swap(&vertex[j] , &vertex[j+1]);
                swap(&parent[j] , &parent[j+1]);
            }
        }
    }
}

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    printf("Enter no of vertices : ");
    scanf("%d",&v);
    input();
    int min_weight = krushkal();
    printf("\nMin weight of the graph is : %d\n",min_weight);
    return 0;
}

/*

0 7 3 0 0
7 0 4 9 11
3 4 0 10 0
0 9 10 0 0
0 11 0 0 0

*/
