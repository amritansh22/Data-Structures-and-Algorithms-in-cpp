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
			case 2 :
				 int med,m;
				 if(n%2==0)
				 {
					m=n/2;
					med=(x[m-1]+x[m])/2;
				 }
				 else
				 {
					m=(n+1)/2;
					med=x[m-1];
				 }
				 cout<<"median is "<<med;
				 break;
			 case 3 :
				 float max =0,pos=0,f[10];
				 cout<<"enter n terms ";
				 cin>>no;
				 for(i=0;i<no;i++)
				 {
					cin>>f[i];
				 }
				 max=f[0];
				 for(i=1;i<n;i++)
				 {
					if(f[i]>max)
					{
						max=f[i];
						pos=i;
					}
				 }
				 cout<<"mode is "<<x[pos];
				 break;
			 default :
				  cout<<"invalid choice";
		}
		break;
		case 'b' :
		cout<<"press 1 for mean deviation "<<endl;
		cout<<"press 2 for cofficient of mean deviation "<<endl;
		cout<<"press 3 for range "<<endl;
		cout<<"press 4 for cofficient of range "<<endl;
		cout<<"press 5 for standard deviation "<<endl;
		cout<<"press 6 for variance "<<endl;
		cin>>num;
		switch(num)
		{
			case 1 :
				 float md,sum1=0,xbar,sum=0;
				 cout<<"enter n values ";
				 cin>>n;
				 for(i=0;i<n;i++)
				 {
					cin>>x[i];
				 }
				 for(i=0;i<n;i++)
				 {
					sum=sum+x[i];
				 }
				 xbar=sum/n;
				 for(i=0;i<n;i++)
				 {
					d[i]=abs(x[i]-xbar);
				 }
				 for(i=0;i<n;i++)
				 {
					sum1=sum1+d[i];
				 }
				 md=sum1/n;
				 cout<<"mean deviation is "<<md<<endl;
				 break;
			case 2 :
				 float cmd,sum2=0;
				 cout<<"enter n values ";
				 cin>>n;
				 for(i=0;i<n;i++)
				 {
					cin>>x[i];
				 }
				 for(i=0;i<n;i++)
				 {
					sum=sum+x[i];
				 }
				 xbar=sum/n;
				 for(i=0;i<n;i++)
				 {
					d[i]=abs(x[i]-xbar);
				 }
				 for(i=0;i<n;i++)
				 {
					sum2=sum2+d[i];
				 }
				 md=sum2/n;
				 cmd=md/xbar;
				 cout<<"cmd is "<<cmd<<endl;
				 break;
			case 3 :
				int k,y[10],j;
				float l,s,r;
				 cout<<"enter n terms ";
				 cin>>n;
				 for(k=0;k<n;k++)
				 {
					cin>>y[k];
				 }
				 l=y[0];
				 for(k=0;k<n;k++)
				 {
					if(y[k]>l)
					{
						l=y[k];
					}
				 }
				 s=y[0];
				 for(k=0;k<n;k++)
				 {
					if(y[k]<s)
					{
						s=y[k];
					}
				 }
				 r=l-s;
				 cout<<"range is "<<r<<endl;
				 break;
			case 4 :
				 float cr;
				 cout<<"enter n terms ";
				 cin>>n;
				 for(k=0;k<n;k++)
				 {
					cin>>y[k];
				 }
				 l=y[0];
				 for(k=0;k<n;k++)
				 {
					if(y[k]>l)
					{
						l=y[k];
					}
				 }
				 s=y[0];
				 for(k=0;k<n;k++)
				 {
					if(y[k]<s)
					{
						s=y[k];
					}
				 }
				 cr=(l-s)/(l+s);
				 cout<<"coefficient of range is "<<cr<<endl;
				 break;
			case 5 :
				 cout<<"enter n terms ";
				 cin>>n;
				 for(i=0;i<n;i++)
				 {
					cin>>x[i];
				 }
				 for(i=0;i<n;i++)
				 {
					sum3=sum3+(x[i]*x[i]);
				 }
				 temp1=sum3/n;
				 for(i=0;i<n;i++)
				 {
					sum=sum+x[i];
				 }
				 xbar=sum/n;
				 temp2=(xbar)*(xbar);
				 temp3=temp1-temp2;
				 sigma=sqrt(temp3);
				 cout<<"standard deviation is "<<sigma<<endl;
				 break;
			case 6 :
				 float var;
				 cout<<"enter n terms ";
				 cin>>n;
				 for(i=0;i<n;i++)
				 {
					cin>>x[i];
				 }
				 for(i=0;i<n;i++)
				 {
					sum3=sum3+(x[i]*x[i]);
				 }
				 temp1=sum3/n;
				 for(i=0;i<n;i++)
				 {
					sum=sum+x[i];
				 }
				 xbar=sum/n;
				 temp2=(xbar)*(xbar);
				 temp3=temp1-temp2;
				 sigma=sqrt(temp3);
				 var=pow(sigma,2);
				 cout<<"variance is "<<var<<endl;
				 break;
			default :
				 cout<<"invalid choice ";
		}
		break;
		case 'c' :
			  cout<<"enter number of terms ";
			  cin>>n;
			  for(i=0;i<n;i++)
			  {
				cin>>x[i]>>y[i];
			  }
			  for(i=0;i<n;i++)
			  {
				s1=s1+x[i];
				s2=s2+y[i];
			  }
			  xbar=s1/n;
			  ybar=s2/n;
			  for(i=0;i<n;i++)
			  {
				s3=s3+(x[i]-xbar)*(y[i]-ybar);
				s4=s4+(y[i]-ybar)*(y[i]-ybar);
				s5=s5+(x[i]-xbar)*(x[i]-xbar);
			  }
			  bxy=s3/s4;
			  byx=s3/s5;
			  r=sqrt(bxy*byx);
			  cout<<"correlation coefficient is "<<r<<endl;
			  break;
		default :
			  cout<<"invalid choice ";
		case 'd' :
			  cout<<"enter number of terms ";
			  cin>>n;
			  for(i=0;i<n;i++)
			  {
				cin>>x[i]>>y[i];
			  }
			  for(i=0;i<n;i++)
			  {
				s1=s1+x[i];
				s2=s2+y[i];
			  }
			  xbar=s1/n;
			  ybar=s2/n;
			  for(i=0;i<n;i++)
			  {
				s3=s3+(x[i]-xbar)*(y[i]-ybar);
				s4=s4+(y[i]-ybar)*(y[i]-ybar);
				s5=s5+(x[i]-xbar)*(x[i]-xbar);
			  }
			  bxy=s3/s4;
			  byx=s3/s5;
			  cout<<"regression coefficient x on y is "<<bxy<<endl;
			  cout<<"regression coeffecient y on x is "<<byx<<endl;
			  break;
	}
	getch();
}
