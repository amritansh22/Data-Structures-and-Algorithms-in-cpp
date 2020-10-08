#include<iostream.h>
#include<conio.h>

class sparse
{
struct sp
{
int r;
int c;
int v;
}
s[10];
public:
sparse()
{
s[0].r=0;
s[0].c=0;
s[0].v=0;
}
void create()
{
cout<<“\n no of rows & columns& elements”;
cin>>s[0].r;
cin>>s[0].c;
cin>>s[0].v;
for(int i=1;i<=s[0].v;i++)
{
cout<<“\n row & column & element”;
cin>>s[i].r;
cin>>s[i].c;
cin>>s[i].v;
}
}
void display()
{
cout<<“\n no of rows & columns& elements\n”;
for(int i=0;i<=s[0].v;i++)
{
cout<<s[i].r<<“\t”;
cout<<s[i].c<<“\t”;
cout<<s[i].v<<“\n”;
}
}
sparse operator +(sparse s2)
{
sparse s3;
int k=1;
s3.s[0].r=s[0].r;
s3.s[0].c=s[0].c;
int i=1,j=1;
while(i<=s[0].v || j<=s2.s[0].v)
{
if((s[i].r==s2.s[j].r)&&(s[i].c==s2.s[j].c))
{
s3.s[k].r=s[i].r;
s3.s[k].c=s[i].c;
s3.s[k].v=s[i].v+s2.s[j].v;
i++; j++; k++;
}
else if((s[i].r==s2.s[j].r)&&(s[i].c==s2.s[j].c))


 
}
s3.s[0].v=k;
return s3;
}
};
void main()
{
sparse s1,s2,s3;
s1.create();
s2.create();
s1.display();
s2.display();
s3=s1+s2;
s3.display();

getch();
}

