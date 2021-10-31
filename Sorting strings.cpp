#include<stdio.h>  //preprocessordirective
#include<conio.h>
#include<string.h>
void main()
{
int n,i,j;
char name[10][10],temp[10];
clrscr();
printf("\n enter the n value");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n enter the names");
scanf("%s",&name[i]);
}
for(i=0;i<=n;i++)
{
for(j=i+1;j<=n;j++)
{
if(strcmp(name[i],name[j])>0)
{
strcpy(temp,name[i]);
strcpy(name[i],name[j]);
strcpy(name[j],temp);
}
}
}
printf("\n\t the string in alphabetical order");
for(i=0;i<=n;i++)
{
printf("\n\t%s",name[i]);
printf("\n");
}
getch();
}
