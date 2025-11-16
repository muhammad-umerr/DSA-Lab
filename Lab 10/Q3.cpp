#include <iostream>
using namespace std;

int kthLargest(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    return arr[k - 1]; // k-th largest
}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = 7;
    int k = 3;

    cout << k << "rd Largest Value: " << kthLargest(arr, n, k) << endl;
    return 0;
}
