#include<stdio.h> 
#include<conio.h>
void add(int a[][5],int b[][5]);
void multi(int a[][5],int b[][5]); 
int main() 
{ 
    int s1[5][5],s2[5][5],i,j,k=0,r1=0,r2=0;
	char x; 
    printf("Enter the 5x5 sparse matrix 1:\n");
    for(i=0;i<5;i++)
    {
    	for(j=0;j<5;j++)
    	{
    		scanf("%d",&s1[i][j]);
		}
	}
	printf("Enter the 5x5 sparse matrix 2:\n");
    for(i=0;i<5;i++)
    {
    	for(j=0;j<5;j++)
    	{
    		scanf("%d",&s2[i][j]);
		}
	}
    for (i = 0; i < 4; i++) 
    {
    	for (j = 0; j < 5; j++) 
    	{
    	 	if (s1[i][j] != 0) 
                r1++; 
		} 
	}
    int newM1[r1][3];  
    for (i = 0; i < 5; i++) 
        for (j = 0; j < 5; j++) 
        {
        	 if (s1[i][j] != 0) 
            { 
                newM1[k][0] = i; 
                newM1[k][1] = j; 
                newM1[k][2] = s1[i][j]; 
                k++; 
            } 
		}       
    for (i = 0; i < 4; i++) 
    {
    	for (j = 0; j < 5; j++) 
    	{
    	 	if (s2[i][j] != 0) 
                r2++; 
		} 
	}
    int newM2[r2][3];
	k=0;  
    for (i = 0; i < 5; i++) 
        for (j = 0; j < 5; j++) 
        {
        	if (s2[i][j] != 0) 
            { 
                newM2[k][0] = i; 
                newM2[k][1] = j; 
                newM2[k][2] = s2[i][j]; 
                k++; 
            }   
		} 		 	    
    printf("Sparse Matrix 1 in triplet form:\n");
    for (i=0; i<r1; i++) 
    { 
        for (j=0; j<3; j++) 
        {
            printf("%d ", newM1[i][j]);
		}
        printf("\n"); 
    } 
    printf("\n");
    printf("Sparse Matrix 2 in triplet form:\n");
    for (i=0; i<r2; i++) 
    { 
        for (j=0; j<3; j++) 
        {
            printf("%d ", newM2[i][j]);
		}
        printf("\n"); 
    } 
    printf("\n");
    fflush(stdin);
    printf("Press 'A' for addition and 'M' for multiplication: ");
    scanf("%c",&x);
    printf("\n");
    if(x=='a'|| x=='A')
        add(s1,s2);
    else
	   multi(s1,s2);		     
    
    
    return 0; 
} 

void add(int a[][5],int b[][5])
{
	int i,j,k=0,c[5][5],r=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for (i = 0; i < 4; i++) 
    {
    	for (j = 0; j < 5; j++) 
    	{
    	 	if (c[i][j] != 0) 
                r++; 
		} 
	}
	int d[r][3]; 
    for (i = 0; i < 5; i++) 
        for (j = 0; j < 5; j++) 
        {
        	if (c[i][j] != 0) 
            { 
                d[k][0] = i; 
                d[k][1] = j; 
                d[k][2] = c[i][j]; 
                k++; 
            }   
		} 
	printf("Addition of the Sparse Matrix is:\n");
	for (i=0; i<r; i++) 
    { 
        for (j=0; j<3; j++) 
        {
            printf("%d ", d[i][j]);
		}
        printf("\n"); 
    } 
}

void multi(int a[][5], int b[][5])
{
	int i,j,k,c[5][5],r=0;
	for(i=0;i<5;i++)
	   for(j=0;j<5;j++)
	      c[i][j]=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=0;k<5;k++)
			{
				c[i][j]= c[i][j] + a[i][k]*b[k][j];
			}
		}
	}
		for (i = 0; i < 4; i++) 
        {
    	    for (j = 0; j < 5; j++) 
    	    {
    	 	    if (c[i][j] != 0) 
                    r++; 
		    } 
	    }
	int d[r][3]; 
	k=0;
    for (i = 0; i < 5; i++) 
        for (j = 0; j < 5; j++) 
        {
        	if (c[i][j] != 0) 
            { 
                d[k][0] = i; 
                d[k][1] = j; 
                d[k][2] = c[i][j]; 
                k++; 
            }   
		} 
	printf("Multiplication of the Sparse Matrix is:\n");
	for (i=0; i<r; i++) 
    { 
        for (j=0; j<3; j++) 
        {
            printf("%d ", d[i][j]);
		}
        printf("\n"); 
    } 
}
