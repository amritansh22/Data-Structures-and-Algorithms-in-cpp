// Implementation of problem,
// array rotation counter-clockwise by k elements
// using juggling algorithm

#include <iostream>
using namespace std;

// calculate GCD
int calc_gcd(int a, int b)
{
    if (b == 0)
        return a;
    return calc_gcd(b, a % b);
}

// rotating array
void rotate_arr(int arr[], int size, int k)
{
    k = k % size; // how many times we have to rotate
                  // even if k is > size , we have to
    // rotate k%size times to get our desire output

    if (k != 0)
    {
        int set_size = calc_gcd(size, k);

        // loop till set_size
        for (int i = 0; i < set_size; i++)
        {
            int temp = arr[i];      // start swap
            int curr = i;
            while(true)
            {
                int next = (curr + k)%size;     
                if (next == i)
                    break;
                arr[curr] = arr[next];      // middle swap
                curr = next;
            }
            arr[curr] = temp;           // end swap
        }
    }

    return;
}

int main()
{
    int size;
    cout << "\nWhat's the size of the array ?(enter): ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    int k;
    cout << "\nRotate array by how many elements ?(enter): ";
    cin >> k;

    rotate_arr(arr, size, k);

    cout << "\nArray elements after rotating : \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}