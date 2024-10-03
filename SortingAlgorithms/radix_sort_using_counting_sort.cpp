#include <stdio.h>
using namespace std;
int getMax(int array[], int n)
{
	int max=array[0];
	for (int i=1;i<n;i++)
		if(array[i]>max)
			max=array[i];
	return max;
}
void countingSort(int array[], int size, int place)
{
	int output[size+1];
	int max=(array[0]/place)%10;
	for(int i=1;i<size;i++)
		if(((array[i]/place)%10)>max)
			max=array[i];
	int count[max+1];
	for(int i=0;i<max;i++)
		count[i]=0;
	for(int i=0;i<size;i++)
		count[(array[i]/place)%10]++;
	for(int i=1;i<10;i++)
		count[i]+=count[i-1];
	for(int i=size-1;i>=0;i--)
	{
		output[count[(array[i]/place)%10]-1]=array[i];
		count[(array[i]/place)%10]--;
	}
	for(int i=0;i<size;i++)
		array[i]=output[i];
}
void radixsort(int array[], int size)
{
	int max=getMax(array,size);
	for(int place=1;(max/place)>0; place*=10)
		countingSort(array,size,place);
}
int main()
{
	int n=7,array[] = {21, 4372, 564, 13, 1, 45, 1788};       //Sample Input
	radixsort(array,n);
	printf("Sorted Order:\n");
	for (int i=0;i<n;i++)
		printf("%d  ",array[i]);
}