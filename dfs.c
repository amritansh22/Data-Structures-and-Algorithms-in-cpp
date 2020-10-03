#include <stdio.h>
#include <stdlib.h>

void input(void);
int stackUnderflow(void);
int pop(void);
void push(int );

int v , arr[20][20] , stack[20] , visit[20] , start,top=-1;

void input(void)
{
    for(int i = 0;i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
            scanf("%d",&arr[i][j]);
        *(visit+i) = 0;
    }
}
int pop(void){
    int r;
    r = stack[top];
    top--;
    return r;
}
void push(int pos){
    top++;
    stack[top] = pos;
    visit[pos] = 1;
}
int stackUnderflow(void){
    return top==-1 ? 1 : 0;
}

void dfs(){
    printf("\nDFS of the graph : ");
    push(start);
    while(!stackUnderflow()){
        int p = pop();
        printf("%d ",p);
        for(int i = 0 ; i < v ; i++){
            if(arr[p][i]!=0 && visit[i]==0){
                //printf("\n=======%d\n",i);
                push(i);
            }
        }
    }
}

int main()
{
    printf("\nEnter total no of vertices : ");
    scanf("%d",&v);
    
    printf("\nEnter the adj matrix : \n");
    input();
    printf("\nEnter the starting vertex : ");
    scanf("%d",&start);
    dfs();
}


/*
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0


0 1 1 0 0 0 0
1 0 0 1 1 0 0
1 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0
*/
