/*
Code For Trapping Rain Water Problem asked by many product based companies in C Language*/


#include <stdio.h>

int max(int x, int y) {
	return (x > y) ? x : y;
}

// Function to find amount of water that can be trapped within
// given set of bars in linear time and constant space
int trap(int heights[], int n)
{
	// maintain two pointers left and right pointing to leftmost and
	// rightmost index of the input array
	int left = 0, right = n-1, water = 0;

	int maxLeft = heights[left];
	int maxRight = heights[right];

	while (left < right)
	{
		if (heights[left] <= heights[right])
		{
			left++;
			maxLeft = max(maxLeft, heights[left]);
			water += (maxLeft - heights[left]);
		}
		else
		{
			right--;
			maxRight = max(maxRight, heights[right]);
			water += (maxRight - heights[right]);
		}
	}

	return water;
}

// Trapping Rain Water within given set of bars
int main(void)
{
	int heights[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };
	int n = sizeof(heights) / sizeof(heights[0]);

	printf("Maximum amount of water that can be trapped is %d",
			trap(heights, n));//output 25

	return 0;
}
