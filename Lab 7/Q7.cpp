#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

int partition(int arr[], int low, int high, int pivotIndex) {
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, string type) {
    if (low < high) {
        int pivotIndex;
        if (type == "first") pivotIndex = low;
        else if (type == "random") pivotIndex = low + rand() % (high - low + 1);
        else if (type == "middle") pivotIndex = (low + high) / 2;
        else { int mid = (low + high) / 2;
            int a = arr[low], b = arr[mid], c = arr[high];
            pivotIndex = (a > b) ? ((a < c) ? low : ((b > c) ? mid : high))
                                 : ((b < c) ? mid : ((a > c) ? low : high));
        }
        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, type);
        quickSort(arr, pi + 1, high, type);
    }
}

void runTest(int base[], int n, string name) {
    int arr[100]; for (int i = 0; i < n; i++) arr[i] = base[i];
    comparisons = 0;
    quickSort(arr, 0, n - 1, name);
    cout << name << " pivot: " << comparisons << " comparisons\n";
}

int main() {
    srand(time(0));
    int arr[10] = {10, 7, 8, 9, 1, 5, 3, 4, 6, 2};
    runTest(arr, 10, "first");
    runTest(arr, 10, "random");
    runTest(arr, 10, "middle");
    runTest(arr, 10, "median");
}
