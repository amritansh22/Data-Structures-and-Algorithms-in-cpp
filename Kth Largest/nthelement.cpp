#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a = { 7, 4, 6, 3, 9, 1 };
	const std::size_t k = 2;

	std::nth_element(a.begin(), a.begin() + k, a.end(), std::greater<int>());
	std::cout << "K'th largest element in the array is " << a[k - 1];

	return 0;
}

//output K'th largest element in the array is 7
