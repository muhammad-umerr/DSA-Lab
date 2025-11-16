#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void convertMinToMax(int arr[], int n)
{
    // convert to max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = 10;

    convertMinToMax(arr, n);

    cout << "Converted to Max Heap: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
