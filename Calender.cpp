 #include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
	clrscr();
	char ch;
	int no,n,i,num;
	float x[10],d[10],sigma,sum3=0,temp1,temp2,temp3;
	float y[10],s1=0,s2=0,s3=0,s4=0,s5=0,xbar,ybar,bxy,byx,r;
	cout<<"press a for measures of central tendency "<<endl;
	cout<<"press b for measures of dispersion "<<endl;
	cout<<"press c for correlation "<<endl;
	cout<<"press d for regression "<<endl;
	cin>>ch;
	switch(ch)
	{
		case 'a' :
		cout<<"press 1 for mean, 2 for median, 3 for mode ";
		cin>>no;
		cout<<"enter n values ";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x[i];
		}
		switch(no)
		{
			case 1 :
				 float xbar,sum=0,mean;
				 for(i=0;i<n;i++)
				 {
					sum=sum+x[i];
				 }
				 xbar=sum/n;
				 cout<<"mean is "<<xbar;
				 break;
			case…
[14:56, 10/1/2020] priyanka prasad: Or calendar wala
[14:56, 10/1/2020] priyanka prasad: Bi bejna
[14:56, 10/1/2020] Sanvi College: Ok
[15:02, 10/1/2020] Sanvi College: #include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int d,m,y,base=2001,diff,l,nl,total,final;
	cout<<"enter a date";
	cin>>d>>m>>y;
	diff=y-base;
	l=diff/4;
	nl=diff-l;
	total=l*2+nl*1;
	int i,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,td,d1,d2,a1,a2,total_sum;
	for(i=1;i<m;i++)
	{
		if(i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
		{
			td=31;
			sum1=sum1+td;
		}
		else if(i==4 || i==6 || i==9 || i==11 )
		{
			td=30;
			sum2=sum2+td;
		}
		else if(i==1)
		{
			td=31;
			sum3=sum3+(td-1);
		}
		else if(i==2)
		{
			if(y%4==0)
			{
				td=29;
				sum4=sum4+td;
			}
			else
			{
				td=28;
				sum4=sum4+td;
			}
		}
	}
	if(i==m)
	{
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
		{
			td=31;
			d1=td-d;
			sum5=sum5+(td-d1);
		}
		if(i==4 || i==6 || i==9 || i==11)
		{
			td=30;
			d1=td-d;
			sum5=sum5+(td-d1);
		}
		else if(i==2)
		{
			if(y%4==0)
			{
				td=29;
				d1=td-d;
				sum5=sum5+(td-d1);
			}
			else
			{
				td=28;
				d1=td-d;
				sum5=sum5+(td-d1);
			}
		 }
	}
	total_sum=sum1+sum2+sum3+sum4+sum5;
	a1=total%7;
	a2=total_sum%7;
	d2=a1+a2;
	if(d2>6)
	{
		final=d2-7;
	}
	else
	{
		final=d2;
	}
	cout<<"day is :";
	switch(final)
	{
		case 0 : cout<<"monday";
			 break;
		case 1 : cout<<"tuesday";
			 break;
		case 2 : cout<<"wednesday";
			 break;
		case 3 : cout<<"thursday";
			 break;
		case 4 : cout<<"friday";
			 break;
		case 5 : cout<<"saturday";
			 break;
		case 6 : cout<<"sunday";
			 break;
	  }
	  getch();
}
